#include "driver/i2c.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#ifndef AHT20_H_
#define AHT20_H_

/*
 *
 * 	Large amount of code adapted from the I2C Driver for the Adafruit AHT10 / AHT20 Humidity and Temperature
 *Sensor library
 *
 * 	This is a library for the Adafruit AHT20 breakout:
 * 	https://www.adafruit.com/products/4566
 *
 * 	Adafruit invests time and resources providing this open source code,
 *  please support Adafruit and open-source hardware by purchasing products from
 * 	Adafruit!
 *
 *
 *	BSD license (see license.txt)
 */

#define AHT_TASK_SIZE 4096
#define AHT_TASK_PRIORITY 3
#define AHT_ADDR 0x38
/// PUlled from Adafruit drivers
#define AHTX0_CMD_CALIBRATE 0xE1     ///< Calibration command
#define AHTX0_CMD_TRIGGER 0xAC       ///< Trigger reading command
#define AHTX0_CMD_SOFTRESET 0xBA     ///< Soft reset command
#define AHTX0_STATUS_BUSY 0x80       ///< Status bit for busy
#define AHTX0_STATUS_CALIBRATED 0x08 ///< Status bit for calibrated

class AHT20
{
private:
    int _port;
    float temperature, humidity;
    static i2c_config_t *configSettings;
    void Initialize(i2c_config_t *config, int port);
    uint8_t data_h, datal;
    i2c_cmd_handle_t cmd;
    /* data */
public:
    // Functions

    int readAHT20();
    AHT20(/* args */);
    ~AHT20();
    float getHumidity();
    float getTemperature();
};
#endif