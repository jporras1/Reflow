//
//  heater.h
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#ifndef heater_h
#define heater_h

#define TEMP_CONVERSION_FACTOR 0.004887585533

enum States{
    OFF         = (uint8_t)0,
    Preheating  = (uint8_t)1,
    Soaking     = (uint8_t)2,
    Reflowing   = (uint8_t)3,
    Cooling     = (uint8_t)4
};

////////////////////////Variables init////////////////////////

int targetTemperature; //the current temperature
float summation;       //global variable...
int relay_state;


/// This will initialize timer 0, and timer 1
void initHeater(void);

/// This controls the heating, and timing
void action(void);

/// This beep goes off to alert the user.
void beep(void);

#endif /* heater_h */
