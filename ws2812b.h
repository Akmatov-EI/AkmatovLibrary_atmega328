#include <avr/io.h>
#include <util/delay.h>

// Initialization function
void InitLedOne();
void InitLedTwo();
void InitLedThree();

// Send zero
void send_zero_One();
void send_zero_Two();
void send_zero_Three();

//Send one
void send_one_One();
void send_one_Two();
void send_one_Three();

// Send byte
void send_byteOne(uint8_t byte);
void send_byteTwo(uint8_t byte);
void send_byteThree(uint8_t byte);

// Color change
void send_led_colorOne(uint8_t red, uint8_t green, uint8_t blue);
void send_led_colorTwo(uint8_t red, uint8_t green, uint8_t blue);
void send_led_colorThree(uint8_t red, uint8_t green, uint8_t blue);

// Reset
void send_reset();