//
//  machine.h
//  Reflow
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#ifndef machine_h
#define machine_h

// Grbl versioning system
#define MACHINE_VERSION "0.1h"
#define MACHINE_VERSION_BUILD "20210214"

#define __DELAY_BACKWARD_COMPATIBLE__

// Define standard libraries used by Grbl.
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


/*---------------------------------------------------------------------------------*/

// Define the machine system include files. NOTE: Do not alter organization.
#include "nuts_bolts.h"
#include "config.h"
#include "defaults.h"
#include "cpu_map.h"
#include "liquid_crystal.h"
#include "sensor.h"
#include "heater.h"


/*---------------------------------------------------------------------------------*/

#endif
