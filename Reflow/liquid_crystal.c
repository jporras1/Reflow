//
//  liquid_crystal.c
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#include "machine.h"

#define INIT_STEPS 12
uint8_t initial[INIT_STEPS] = {
    0x3, 0x3, 0x3,
    0x2, 0x2, 0x8,
    0x0, 0xC, 0x0,
    0x1, 0x0, 0x6
};

uint8_t dataPort[4] = {
    LCD_D0_BIT,
    LCD_D1_BIT,
    LCD_D2_BIT,
    LCD_D3_BIT
};

//Only words if the LCD all in one port.
void initLCD(){
    uint8_t b;
    LCD_DDR |= (LCD_RS_MASK | LCD_EN_MASK | LCD_DATA_BIT_MASK);
    LCD_PORT &= ~(LCD_RS_MASK | LCD_EN_MASK | LCD_DATA_BIT_MASK);
    _delay_ms(4);
    
    //actual init
    uint8_t n;
    for (n = 0; n<INIT_STEPS; n++) {
        LCD_PORT = 0;
        
        for (b =0 ; b < 4; b++) {
            if (((initial[n] >> b) & 0x1) == 0x1) {
                LCD_PORT |= (1 << dataPort[b]);
            }
        }
        _delay_ms(2);
        LCD_PORT |= LCD_EN_MASK;
        _delay_ms(2);
        LCD_PORT &= ~LCD_EN_MASK;
        _delay_ms(2);
    }
}

/**************************************************************************/


void LCD_send(uint8_t data, uint8_t isInstruction){
    uint8_t upperNibble = ((data >> 4) & LOWER_NIBBLE_MASK);
    uint8_t lowerNibble = (data & LOWER_NIBBLE_MASK);
    uint8_t b;
    
    //Sending Upper Nibble
    LCD_PORT &= ~LCD_DATA_BIT_MASK;
    for (b = 0; b < 4; b++) {
        if (((upperNibble >> b) & 0x1) == 0x1){
            LCD_PORT |= (1 << dataPort[b]);
        }
    }
    delayMicroseconds(200);
    
    if (!isInstruction) { LCD_PORT |= LCD_RS_MASK; }
    LCD_PORT |= LCD_EN_MASK;
    delayMicroseconds(200);
    
    LCD_PORT &= ~LCD_EN_MASK;
    if (!isInstruction) { LCD_PORT &= ~LCD_RS_MASK; }
    
    //sending lowerNibble
    LCD_PORT &= ~LCD_DATA_BIT_MASK;
    for (b = 0; b < 4; b++) {
        if (((lowerNibble >> b) & 0x1) == 0x1){
            LCD_PORT += (1 << dataPort[b]);
        }
    }
    if (!isInstruction) { LCD_PORT |= LCD_RS_MASK; }
    LCD_PORT |= LCD_EN_MASK;
    delayMicroseconds(200);
    
    LCD_PORT &= ~LCD_EN_MASK;
    if (!isInstruction) { LCD_PORT &= ~LCD_RS_MASK; }
    delayMicroseconds(200);
}

/*************************************************************************/

void LCD_clear(){
    LCD_send(0x01, true);
    _delay_ms(10);
}
void LCD_changeAddress(uint8_t address){
    address |= 0x80;
    LCD_send(address, true);
}
void LCD_sendString(char string[]){
    uint8_t n;
    uint8_t size;
    
    size = strlen(string);
    
    for(n = 0; n<size; n++){
        LCD_send(string[n], false);
    }
}

/************************************************************************/
/*               Program Specific LCD code below                        */

void lcdPrint(char* top, char* bottom){
    LCD_changeAddress(0x00);
    LCD_sendString(top);
    LCD_changeAddress(0x40);
    LCD_sendString(bottom);
}

void lcdUpdateTemp(char* temp){
    LCD_changeAddress(0x46);
    LCD_sendString(temp);
}

void lcdStateUpate(uint8_t state){
    char symbol_on_off;
    if (state){
        symbol_on_off = '0';
    } else {
        symbol_on_off = '#';
    }
    LCD_changeAddress(0x4F);
    LCD_sendString(symbol_on_off);
}


void lcdPrintNumber(int number){
    char numberToPrint[5];
    itoa(number, numberToPrint, 10);
    //dtostrf(double __val, signed char __width, unsigned char __prec, char *__s)
    //    LCD_send('5', 0);
    LCD_sendString(numberToPrint);
}

void lcdPrintDouble(float number){
    char numberToPrint[5];
    dtostrf(number, 5, 2, numberToPrint);
    LCD_sendString(numberToPrint);
}

