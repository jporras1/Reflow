//
//  sensor.h
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#ifndef sensor_h
#define sensor_h

#define ADMUX_MASK 0x80

//#include <stdio.h>


typedef struct {
    uint8_t low;
    uint8_t high;
} ADCvalueStruct;

union ADCvalue {
    ADCvalueStruct adcValue;
    int value;
};

volatile union ADCvalue adc;

///////////////////variables inititialized////////////////

void initSensor(void);

void analogRead(void);


#endif /* sensor_h */
