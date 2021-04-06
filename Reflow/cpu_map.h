//
//  cpu_map.h
//  Reflow
//
//  Created by Javier Porras jr on 4/6/21.
//  Copyright © 2021 Javier Porras jr. All rights reserved.
//

#ifndef cpu_map_h
#define cpu_map_h

#ifdef CPU_MAP_ATTINY84

/************** LCD ****************************/
#define LCD_DDR                     DDRA
#define LCD_PORT                    PORTA

#define LCD_RS_BIT                  2
#define LCD_EN_BIT                  3
#define LCD_D0_BIT                  4
#define LCD_D1_BIT                  5
#define LCD_D2_BIT                  6
#define LCD_D3_BIT                  7
#define LCD_RS_MASK                 (1 << LCD_RS_BIT)
#define LCD_EN_MASK                 (1 << LCD_EN_BIT)
#define LCD_DATA_BIT_MASK           ((1 << LCD_D0_BIT) | (1 << LCD_D1_BIT) | (1 << LCD_D2_BIT) | (1 << LCD_D3_BIT))

#define UPPER_NIBBLE_MASK           0xF0
#define LOWER_NIBBLE_MASK           0x0F

//This works only really in this case, because the data bits are set to be the upper nibble.
#define LOWER_SHIFT                 0
#define UPPER_SHIFT                 4

/*********** OTHER STUFF *********************/

#define SELECT_BUTTON_DDR           DDRB
#define SELECT_BUTTON_PORT          PORTB
#define SELECT_BUTTON_PIN           PINB  //for reading button inputs
#define SELECT_BUTTON_BIT           1
#define SELECT_BUTTON_MASK          (1 << SELECT_BUTTON_BIT)

#define NEXT_BUTTON_DDR             DDRB
#define NEXT_BUTTON_PORT            PORTB
#define NEXT_BUTTON_PIN             PINB  //for reading button inputs
#define NEXT_BUTTON_BIT             0
#define NEXT_BUTTON_MASK            (1 << NEXT_BUTTON_BIT)


#define RELAY_DDR                   DDRB
#define RELAY_PORT                  PORTB
#define RELAY_BIT                   2
#define RELAY_MASK                  (1 << RELAY_BIT)

#define BUZZER_DDR                  DDRA
#define BUZZER_PORT                 PORTA
#define BUZZER_BIT                  0
#define BUZZER_MASK                 (1 << BUZZER_BIT)

#define SENSOR_DDR                  DDRA
#define SENSOR_BUTTON_PORT          PORTA
#define SENSOR_BIT                  1
#define SENSOR_MASK                 (1 << SENSOR_BIT)

#endif //End of CPU_MAP_ATMEGA328P define


#ifdef CPU_MAP_ATMEGA328P

/************** LCD ****************************/
#define LCD_DDR                     DDRB
#define LCD_PORT                    PORTB  ////////////////////?Fix

#define LCD_RS_BIT                  4
#define LCD_EN_BIT                  5
#define LCD_D0_BIT                  3
#define LCD_D1_BIT                  2
#define LCD_D2_BIT                  1
#define LCD_D3_BIT                  0
#define LCD_RS_MASK                 (1 << LCD_RS_BIT)
#define LCD_EN_MASK                 (1 << LCD_EN_BIT)
#define LCD_DATA_BIT_MASK           ((1 << LCD_D0_BIT) | (1 << LCD_D1_BIT) | (1 << LCD_D2_BIT) | (1 << LCD_D3_BIT))

#define UPPER_NIBBLE_MASK           0xF0
#define LOWER_NIBBLE_MASK           0x0F

//This works only really in this case, because the data bits are set to be the upper nibble.
#define LOWER_SHIFT                 0
#define UPPER_SHIFT                 4

/*********** OTHER STUFF *********************/

#define SELECT_BUTTON_DDR           DDRD
#define SELECT_BUTTON_PORT          PORTD
#define SELECT_BUTTON_PIN           PIND  //for reading button inputs
#define SELECT_BUTTON_BIT           3
#define SELECT_BUTTON_MASK          (1 << SELECT_BUTTON_BIT)

#define NEXT_BUTTON_DDR             DDRD
#define NEXT_BUTTON_PORT            PORTD
#define NEXT_BUTTON_PIN             PIND  //for reading button inputs
#define NEXT_BUTTON_BIT             2
#define NEXT_BUTTON_MASK            (1 << NEXT_BUTTON_BIT)


#define RELAY_DDR                   DDRD
#define RELAY_PORT                  PORTD
#define RELAY_BIT                   6
#define RELAY_MASK                  (1 << RELAY_BIT)

#define BUZZER_DDR                  DDRA
#define BUZZER_PORT                 PORTA
#define BUZZER_BIT                  0
#define BUZZER_MASK                 (1 << BUZZER_BIT)

#define SENSOR_DDR                  DDRA
#define SENSOR_BUTTON_PORT          PORTA
#define SENSOR_BIT                  0
#define SENSOR_MASK                 (1 << SENSOR_BIT)

#endif //End of CPU_MAP_ATMEGA328P define

#endif /* cpu_map_h */
