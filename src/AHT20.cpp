
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2c.h"

#include "AHT20.h"

AHT20::AHT20(i2c_config_t *config, int port)
{
    Initialize(config, port);
}

AHT20::~AHT20()
{
    i2c_master_stop();
    i2c_driver_delete(port);
}

esp_err_t AHT20::Initialize(i2c_config_t *config, int port)
{
    esp_err_t ret = ESP_OK;
    if (port < 0 || port > 1)
    {
        ret = ESP_FAIL;
    }
    else
    {
        // build out the i2c object
        _port = port;
        i2c_param_config(_port, config);
        i2c_driver_install(_port, config->mode, 16, 16, 0);
        cmd = i2c_cmd_link_create();

        //check calibration
        
        printf("Initialization OK");
    }

    return ret;
}

/// this reads the values into the internal static values
/// it needs to be called from within a task or it won't work right.
esp_err_t AHT20::readAHT20()
{
    // read
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd,AHT_ADDR | I2C_MASTER_WRITE);
    i2c_master_write_byte(cmd,)

        vTaskDelay(80 / portTICK_RATE_MS);
}

float AHT20::getHumidity()
{
    return humidity;
}
float AHT20::getTemperature()
{
    return temperature;
}
