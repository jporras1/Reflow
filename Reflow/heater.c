//
//  heater.c
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#include "machine.h"

volatile float seconds = 0;  // this will get incremented once a second
volatile long count = 0;
volatile int lcdCount = 0;
volatile float temp = 0;

enum States state = OFF;


void initHeater(void){
    //    RELAY_DDR |= RELAY_MASK;
    //    RELAY_PORT &= ~RELAY_MASK;
    //
    //    BUZZER_DDR |= BUZZER_MASK;
    //    BUZZER_PORT &= ~BUZZER_MASK;
    //
    //
    //    /*this is specific for the attiny84*/
    //    TCCR1A |= 0;                //This whole register is set to zeros,
    //    TCCR1B |= (1 << WGM12);     //Set this to enable CTC mode
    //    TCCR1B |= (1 << CS12) | (1 << CS10);        //setting the prescaler to 1024
    //    OCR1A = 244; //1,000,000[F_CPU] / (1024[prescaler] * 2 * (1Hz *2)
    //    TIMSK1 |= (1 << OCIE1A);
}

//void action(void){
//    started = true;
//    state = 1;
//
//    // TODO: Here I will remove a part of the timer setup code, and add it here so that the ISR code only runs when the action is called. But will need to figure out where to remove it again, Ideally in the OFF, and Default portion of the switch statment in ISR.
//
//}
//
//void beep(void){
//    BUZZER_PORT |= BUZZER_MASK;
//    _delay_ms(300);
//    BUZZER_PORT &= ~BUZZER_MASK;
//}


//ISR(TIM1_COMPA_vect){
//    float tempTemperature;
//    float previousTemp = temp;
////    uint8_t error;
//
//    count ++;
//    seconds = (float)count / 4;
//
////    tempTemperature = thermocouple1.readCelsius();
//    // TODO: replace with actual sensor read code.
//    tempTemperature = 0;
//    if (isnan(tempTemperature)){
//        temp = previousTemp;
//    }
//    else{
//        temp = tempTemperature;
//    }
//
//
////    lcd.setCursor(0,1);
////    lcd.print("Temp: ");
////    lcd.setCursor(6,1);
////    lcd.print(tempTemperature);
////    lcd.print(" C   ");
////    lcd.setCursor(15,1);
////    lcd.print(state);
//
//    switch (state) {
//        case OFF:
//            //set relay pin low.
//            RELAY_PORT &= ~RELAY_MASK;
//            break;
//        case Preheating:
//            //pwm relay pin to 75 (0-255) profile[0]
//            // TODO: need to implement the pwm here.
//
//            //check if temp >= profile[1], 140
//            if (temp >= profiles[selectedProfile].preheatTemp) {
//                //if true, state = 2; and count = 0;
//                state = Soaking;
//                count = 0;
//            }
//            break;
//        case Soaking:
//            //check if avgTemp < profile[1], 140, set relayPin high,
//            if (temp < profiles[selectedProfile].preheatTemp) {
//                RELAY_PORT |= RELAY_MASK;
//            } else {
//                // else set relayPin low
//                RELAY_PORT &= ~RELAY_MASK;
//            }
//            //check if seconds >= profile[2], 45, set state to 3.
//            if (seconds >= profiles[selectedProfile].soakDuration) {
//                state = Reflowing;
//            }
//            break;
//        case Reflowing:
//            //pwm relay pin to 125, (0-255) profile[3]
//            // TODO: need to implement the pwm here. Again.
//
//            //check if avgTemp >= profile[4], 205, set state = 4, count = 0
//            if (temp >= profiles[selectedProfile].reflowTemp) {
//                state = Cooling;
//                count = 0;
//            }
//            break;
//        case Cooling:
//            //check if avgTemp < profile[4], 205, set realayPin high.
//            if (temp < profiles[selectedProfile].reflowTemp) {
//                RELAY_PORT |= RELAY_MASK;
//            } else {
//                //if false, set relayPin low.
//                RELAY_PORT &= ~RELAY_MASK;
//            }
//            //check if seconds >= profile[5], 20, set state = 0, set relayPin LOW.
//            if (seconds >= profiles[selectedProfile].reflowDuration) {
//                state = OFF;
//                RELAY_PORT &= ~RELAY_MASK;
//            }
//            break;
//        default:
//            RELAY_PORT &= ~RELAY_MASK; //set relayPin low,
//            state = OFF;
//            count = 0;
//            break;
//    }
//}
