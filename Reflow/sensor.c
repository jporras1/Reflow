//
//  sensor.c
//  Index
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#include "machine.h"

void initSensor(void){
    //Specific to the Attiny84
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);     //Prescaler
    ADCSRA |= (1 << ADEN);      //Enable ADC
    
    ADMUX  |= (1 << MUX0);
    
    sei();                      //Set global Interupt bit
    //Start conversion, NOT set here, set during the program execution.
    //    ADCSRA |= (1 << ADSC);
}

void analogRead(){
    ADCSRA |= (1 << ADSC);

    while (ADCSRA & (1 << ADSC));
    adc.adcValue.low = ADCL;
    adc.adcValue.high = ADCH;
}

