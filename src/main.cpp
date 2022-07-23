
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "string.h"
#include "AHT20.h"


#define LED_PIN 25


#define PIN_SCL 5
#define PIN_SDA 35 
#define I2C_MASTER_FREQ_HZ 100000

//// Current int erh

static char* TerminalMsg;  
static char msg[3];
static int NumBlinks = 0; 
static int MeasuredTemperature;


static AHT20 sensor; 

void app_main()
{   


   TerminalMsg = "LED has blinked "; 

    if(!SystemInit)
    {
       printf("Application has failed to initialize");      
       return;  
    }
   
   xTaskCreate(&led_blink,"LED_BLINK",1024,NULL,5,NULL);
    
    // do the portion of the code that handles the I2C bus and the temperature fetch functions

    printf("Building I2C Params");

}  


void led_blink(void *pvParams) {
    gpio_num_t LedPin = LED_PIN; //convert this into an actual LED structure
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction (LedPin,GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(LedPin,0);
        vTaskDelay(1000/portTICK_RATE_MS);
        gpio_set_level(LedPin,1);
        vTaskDelay(1000/portTICK_RATE_MS);
        
        

        printf(TerminalMsg);
        printf(" ");
        printf(itoa(NumBlinks++,msg,10)); 
        printf("\n"); 
        vTaskDelay(100/portTICK_RATE_MS);        
    }
}

  


///this is the initialization function for the I2C and power stuff
bool SystemInit()
{     
    return true;
}