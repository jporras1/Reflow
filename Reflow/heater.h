//
//  heater.h
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#ifndef heater_h
#define heater_h

enum States{
    OFF = (uint8_t)0,
    Preheating = (uint8_t)1,
    Soaking = (uint8_t)2,
    Reflowing = (uint8_t)3,
    Cooling = (uint8_t)4
};
//
//volatile float seconds = 0;  // this will get incremented once a second
//volatile long count = 0;
//volatile int lcdCount = 0;
//volatile float temp = 0;
//
//enum States state = OFF;
int targetTemperature; //the current temperature
float summation;       //global variable...
int relay_state;

////////////////////////Variables init////////////////////////

void initHeater(void);

void action(void);

void beep(void);

#endif /* heater_h */
