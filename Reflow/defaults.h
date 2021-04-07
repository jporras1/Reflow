//
//  defaults.h
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#ifndef defaults_h
//#define defaults_h

#ifdef DEFAULTS_GENERIC
// Generic default settings. Should work across different machines.
#define DEFAULT_THING_1 255
#endif // End of DEFAULTS_GENERIC

volatile uint8_t started;
volatile uint8_t stopped;
uint8_t input;
uint8_t selectedProfile;
uint8_t profileSelected;
uint8_t isInitialState;
uint8_t isInitialChoiceState;

typedef struct {
    char name[17];
    uint8_t preheatPWM;
    uint8_t preheatTemp;
    uint8_t soakDuration;
    uint8_t reflowPWM;
    uint8_t reflowTemp;
    uint8_t reflowDuration;
} Profile;

Profile profiles[4];

#endif /* defaults_h */
