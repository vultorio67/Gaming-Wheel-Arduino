#pragma once
//---------------------------Constants, do not change--------------------
#define ST_ENCODER  0
#define ST_TLE5010  1
#define ST_AS5600   2
#define ST_MLX90316 3

#define PT_INTERNAL     0
#define PT_HC164        1
#define PT_MCP3204_4W   2
#define PT_MCP3204_SPI  3
#define PT_ADS1015      4
#define PT_ADS7828      5

#define BT_74HC165      0
#define BT_MCP23017     1
#define BT_CD4021B      2
#define BT_PCF857x      3
#define BT_NONE         0xFF
//-----------------------------------------------------------------------

//---------------------------Configuration-------------------------------

#define SERIAL_BAUDRATE 2000000

//---------------------------Steering axis-------------------------------
//different types of wheel sensor. Choose only one!
//#define STEER_TYPE POTENTIOMETER 
#define STEER_TYPE ST_ENCODER
//#define STEER_TYPE ST_TLE5010
//#define STEER_TYPE ST_AS5600
//#define STEER_TYPE ST_MLX90316

//settings for encoder
#define ENCODER_PIN1  0       //encoder pins must be interrupt pins:[0, 1, 2, 3]
#define ENCODER_PIN2  1    
#define ENCODER_PPR   400    //PPR = CPR/4

//settings for TLE5010
#define TLE5010_PIN_CS 1

//settings for MLX90316
#define MLX90316_PIN_CS 1

//wheel sensor bitdepth. Not supposed to be changed.
#define STEER_BITDEPTH 13
//default wheel range in degrees.
#define WHEEL_RANGE_DEFAULT 540

//transmission ratio (see readme)
//#define STEER_TM_RATIO_ENABLED       //Uncomment to enable feature
#define STEER_TM_RATIO_MUL       1   //Multiplication factor
#define STEER_TM_RATIO_DIV       1   //Division factor

//---------------------------I2C----------------------------------------
//bitbang I2С pins - for MCP23017 and ADS1015
#define I2C_PIN_SDA   12  //any free pins
#define I2C_PIN_SCL   13

#define I2C_DELAY 1
//---------------------------analog axes---------------------------
//aux analog axes pins
//If aux axis is not needed, comment out corresponding line.
#define PIN_AUX1    A3
#define PIN_AUX2    A8
#define PIN_AUX3    A6
#define PIN_AUX4    A7


//different ways of connecting pedals. Choose only one!
#define PEDALS_TYPE PT_INTERNAL           //use internal ADC
//#define PEDALS_TYPE PT_HC164              //use analog multiplexer 74HC4051/74HC4052/74HC4067 + 74HC164
//#define PEDALS_TYPE PT_MCP3204_4W         //use external ADC MCP3204 (4-wire)
//#define PEDALS_TYPE PT_MCP3204_SPI        //use external ADC MCP3204 (6-wire SPI)
//#define PEDALS_TYPE PT_ADS1015            //use external ADC ADS1015
//#define PEDALS_TYPE PT_ADS7828            //use external ADC ADS7828

//settings for internal ADC
//analog axes pins

#define PIN_ACC     A1
#define PIN_BRAKE   A2
#define PIN_CLUTCH  A0

//#define AA_PULLUP              //internal ADC with pullups for analog axes
//#define AA_PULLUP_LINEARIZE    //uncomment if need to linearize

//settings for analog multiplexer + 74HC164
#define MP_HC164_PIN_ADATA  A0       //analog pin
#define MP_HC164_PIN_SCK    15       

//settings for MCP3204
#define MCP3204_CH_ACC     0     //channels for axes
#define MCP3204_CH_BRAKE   1
#define MCP3204_CH_CLUTCH  2

//settings for MCP3204 (SPI)
//#define MCP3204_PIN_CS    A0

//settings for MCP3204 (4wire)
//v1
//#define MCP3204_4W_PIN_SCK  A0
//#define MCP3204_4W_PIN_MOSI 16
//#define MCP3204_4W_PIN_MISO 14

//v2 
//#define MCP3204_4W_PIN_SCK  15
//#define MCP3204_4W_PIN_MOSI A0
//#define MCP3204_4W_PIN_MISO A0

//v3
//#define MCP3204_4W_PIN_SCK  A1
//#define MCP3204_4W_PIN_MOSI A0
//#define MCP3204_4W_PIN_MISO A0

//settings for ADS1015
#define ADS1015_CH_ACC     0     //channels for axes
#define ADS1015_CH_BRAKE   1
#define ADS1015_CH_CLUTCH  2

//---------------------------Smoothing-----------------------------------
/*
 * Smoothing is performed with moving average filter.
 * Level means filter window size as power of 2.
 * 2 means averaging 4 values, 3 - 8 values and so on.
 */
//Smoothing for wheel axis. 
#define MA_LEVEL_WHEEL_POSITION       2
#define MA_LEVEL_WHEEL_VELOCITY       2
#define MA_LEVEL_WHEEL_ACCELERATION   3

//Level of smoothing for analog axes. 
#define MA_LEVEL_AXIS_ACC     4
#define MA_LEVEL_AXIS_BRAKE   4
#define MA_LEVEL_AXIS_CLUTCH  4
#define MA_LEVEL_AXIS_AUX1    0
#define MA_LEVEL_AXIS_AUX2    0
#define MA_LEVEL_AXIS_AUX3    0
#define MA_LEVEL_AXIS_AUX4    0

//----------------------------Buttons-------------------------------------
//different ways of connecting buttons. Choose only one!
//#define BUTTONS_TYPE BT_74HC165       //Use 74HC165 shift registers
//
//#define BUTTONS_TYPE BT_MCP23017    //Use MCP23017 I2C port expanders
//#define BUTTONS_TYPE BT_CD4021B     //Use CD4021B shift registers
//#define BUTTONS_TYPE BT_PCF857x     //Use PCF857x I2C port expanders
//#define BUTTONS_TYPE BT_NONE          //No buttons


//settings for 74HC165
#define HC165_PIN_SCK     15
#define HC165_PIN_DATA1   2          //pin for DATA#1
#define HC165_PIN_DATA2   7          //pin for DATA#2
#define HC165_PIN_PL      3          //pin for PL (comment this line if using RC to omit PL line)

//settings for CD4021
#define CD4021_PIN_SCK     15
#define CD4021_PIN_DATA1   2          //pin for DATA#1
#define CD4021_PIN_DATA2   7          //pin for DATA#2
#define CD4021_PIN_PL      3          //pin for PL (comment this line if using RC to omit PL line)

//settings for MCP23017
#define MCP23017_ADDR1  0x20
#define MCP23017_ADDR2  0x21

//settings for PCF857x
#define PCF857x_L1_TYPE   PCF8575
#define PCF857x_L1_ADDR1  0x20
#define PCF857x_L1_ADDR2  0x21

#define PCF857x_L2_TYPE   PCF8574
#define PCF857x_L2_ADDR1  0x22
#define PCF857x_L2_ADDR2  0x23


//analog pin buttons
#define APB
#define APB_PIN        A4
#define APB_BTN_COUNT  6
#define APB_VALUES     0,83,125,151,169,181
#define APB_TOLERANCE  10
#define APB_BTNS       10,11,12,13,14,15

//buttons directly connected to pins 
#define DPB        //Enable
#define DPB_PINS       3,4
#define DPB_1ST_BTN    2

#define H_SCHIFTER_START_PIN 8


//button matrix
//#define BM            //enable
#define BM_COL_PINS   2,3,4
#define BM_ROW_PINS   5,6,7
#define BM_1ST_BTN    1


//analog H-shifter
//#define ASHIFTER                //uncomment to enable feature
#define ASHIFTER_PINX     A4    //analog pin for potentiometer X
#define ASHIFTER_PINY     A5    //analog pin for potentiometer Y
#define ASHIFTER_POS      8     //number of positions, 6 or 8
#define ASHIFTER_Y1       50    //zone bounds (0-255)
#define ASHIFTER_Y2       200
#define ASHIFTER_X1       64  
#define ASHIFTER_X2       128  
#define ASHIFTER_X3       192
#define ASHIFTER_1ST_BTN  25    

//Hat switch
//#define HATSWITCH
#define HAT_BTN_UP     13
#define HAT_BTN_DOWN   15
#define HAT_BTN_LEFT   14
#define HAT_BTN_RIGHT  16
#define HAT_CLR_BTNS   //clear buttons state

//----------------------------FFB settings-------------------------------
#define MOTOR_ENABLE_PIN_WATCH      5  //if is set, selected pin will output 1 when FFB is active and 0 otherwise.
#define MOTOR_ENABLE_PIN_ANTI_WATCH      6

//default FFB PWM bitdepthé  
#define DEFAULT_FFB_BITDEPTH     9

//Effect parameters
#define DEFAULT_MAX_VELOCITY        500
#define DEFAULT_MAX_ACCELERATION    500

#define DEFAULT_ENDSTOP_OFFSET         0        //force level endstop effect will start from (0-16383). Increasing will make endstop harder.
#define DEFAULT_ENDSTOP_WIDTH          1024     //length of excess position where endstop effect will rise to maximum level. Decreasing makes endstop harder.

//Auto find center
//#define AFC_ON                                //Uncomment to enable autofind center at start. Requires presence of mechanical limiters (see description)
#define AFC_FORCE     9000                      //Force [0...16383] to exert when finding center. 
#define AFC_PERIOD    50                        //Position check period in milliseconds
#define AFC_TRESHOLD  10                        //Minimum position change to detect movement
//#define AFC_NORANGE                           //Uncomment to disable range setting
#define AFC_RANGE_FIX 1                         //range will be decreased by this value (in degrees), to prevent wheel kicking on limiters.
#define AFC_BUTTON    0    

#define H_SHIFTER_WIRE



                     //Button # to start (1-32, 0 if not needed)
