#include "machine.h"

#define SELECT          (SELECT_BUTTON_PIN & SELECT_BUTTON_MASK)
#define NEXT            (NEXT_BUTTON_PIN & NEXT_BUTTON_MASK)
#define CHOICES_COUNT   4

Profile profiles[4] = {
    {"Ol' fashioned :)", 75,140,45,125,205,20},
    {"    Profile 2   ", 75,140,45,125,205,20},
    {"    Profile 3   ", 75,140,45,125,205,20},
    {"    Profile 4   ", 75,140,45,125,205,20}
};

void initIO(void) {
        SELECT_BUTTON_DDR &= ~SELECT_BUTTON_MASK;
        SELECT_BUTTON_PORT |= SELECT_BUTTON_MASK;
    
        NEXT_BUTTON_DDR &= ~NEXT_BUTTON_MASK;
        NEXT_BUTTON_PORT |= NEXT_BUTTON_MASK;
    
        BUZZER_DDR |= BUZZER_MASK;
        BUZZER_PORT &= ~BUZZER_MASK;
    
        initLCD();
        initHeater();
        SENSOR_DDR &= ~SENSOR_MASK;
        initSensor();
}

int main(void) {
    stopped = true;
    input = 0;
    selectedProfile = 0;
    profileSelected = false;
    isInitialState = true;
    isInitialChoiceState = true;

    initIO();
    
    while (1) {
        if (isInitialState){
            LCD_clear();
            lcdPrint("    Welcome     ", "  push to start ");
            while (((SELECT_BUTTON_PIN & SELECT_BUTTON_MASK) == 0) || ((NEXT_BUTTON_PIN & NEXT_BUTTON_MASK)== 0));
            isInitialState = false;
        }

        if (stopped) {
            if ((SELECT_BUTTON_PIN & SELECT_BUTTON_MASK) == 0){
                _delay_ms(150);
                stopped = false;
                input = 0;
            } else if ((NEXT_BUTTON_PIN & NEXT_BUTTON_MASK) == 0){
                _delay_ms(150);
                stopped = true;
                input = 0;
                isInitialState = true;
                lcdPrint("     Please     ", "  push to start ");
            } else {
                _delay_ms(10);
            }
        } else {\
            if (isInitialChoiceState) {
                //Start conversion, NOT set here, set during the program execution.
                lcdPrint("Select an option", "                ");
                _delay_ms(1200);
                LCD_changeAddress(0x40);
                LCD_sendString(profiles[selectedProfile].name);
                isInitialChoiceState = 0;
            }

            if ((SELECT_BUTTON_PIN & SELECT_BUTTON_MASK) == 0){
                _delay_ms(150);
                lcdPrint("Selected profile", "       was      ");
                _delay_ms(1000);
                lcdPrint(profiles[selectedProfile].name, "                ");
                _delay_ms(800);
                lcdPrint("  Starting Now  ", "                ");
                _delay_ms(900);
                input = 0;
                stopped = true;
                isInitialState = true;
                isInitialChoiceState = true;

                RELAY_PORT |= RELAY_MASK;
                action();
                selectedProfile = 0;
                lcdPrint("    All Done    ", "                ");
                _delay_ms(2000);
                beep();

            } else if ((NEXT_BUTTON_PIN & NEXT_BUTTON_MASK) == 0){
                _delay_ms(150);
                if (selectedProfile >= CHOICES_COUNT -1){
                    selectedProfile = 0;
                } else {
                    selectedProfile++;
                }
                LCD_changeAddress(0x40);
                LCD_sendString(profiles[selectedProfile].name);
            }
        }
    }
    
    
    return 0; // never reached
}

