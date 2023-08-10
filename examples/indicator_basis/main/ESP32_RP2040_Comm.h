#ifndef ESP32_RP2040_COMM_H
#define ESP32_RP2040_COMM_H

#include<stdint.h>

#define SENSOR_COMM_DEBUG    0

#define ESP32_RP2040_TXD (19)
#define ESP32_RP2040_RXD (20)
#define ESP32_RP2040_RTS (UART_PIN_NO_CHANGE)
#define ESP32_RP2040_CTS (UART_PIN_NO_CHANGE)

#define ESP32_COMM_PORT_NUM      (2)
#define ESP32_COMM_BAUD_RATE     (115200)
#define ESP32_RP2040_COMM_TASK_STACK_SIZE    (1024*4)
#define BUF_SIZE (512)

#define ACK_PKT_PARA "ACK"


enum  pkt_type {

    PKT_TYPE_CMD_COLLECT_INTERVAL = 0xA0, //uin32_t 
    PKT_TYPE_CMD_BEEP_ON  = 0xA1,  //uin32_t  ms: on time 
    PKT_TYPE_CMD_BEEP_OFF = 0xA2,
    PKT_TYPE_CMD_SHUTDOWN = 0xA3, //uin32_t 
    PKT_TYPE_CMD_POWER_ON = 0xA4,

    PKT_TYPE_SENSOR_SCD41_TEMP  = 0xB0, // float
    PKT_TYPE_SENSOR_SCD41_HUMIDITY = 0xB1, // float
    PKT_TYPE_SENSOR_SCD41_CO2 = 0xB2, // float

    PKT_TYPE_SENSOR_SHT41_TEMP = 0xB3, // float
    PKT_TYPE_SENSOR_SHT41_HUMIDITY = 0xB4, // float

    PKT_TYPE_SENSOR_TVOC_INDEX = 0xB5, // float

    PKT_TYPE_SENSOR_DPS310_PA = 0xB6, // float

    //todo
};


extern uint8_t erc_buf[BUF_SIZE];   //recv 
extern uint8_t erc_data[BUF_SIZE];  //decode

#endif /* ESP32_RP2040_COMM_H */
