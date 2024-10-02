#define F_CPU 16000000UL // Тактовая частота 16 МГц
#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
// void Timer0_Init(void);
long unsigned time = 0;
long unsigned timer = 0;
// unsigned long time = 0;
unsigned long timeForled = 0;
unsigned long countColor = 0;
unsigned long time_led = 0;
uint32_t TimerLed = 0;
uint8_t Red = 20;
 uint8_t Green = 64;
 uint8_t Blue = 55;

 uint8_t valueR = 1;
uint8_t valueG = 3;
 uint8_t valueB = 2;
/*
void send_zero()
{
    // Отправка логического нуля
    PORTB |= (1 << PB3); // Устанавливаем PB0
                         // delay_ns(250);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //  asm volatile ("nop");
    PORTB &= ~(1 << PB3); // Сбрасываем PB0
                          // _delay_us(1);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //  asm volatile ("nop");
}

void send_one()
{
    // Отправка логической единицы
    PORTB |= (1 << PB3); // Устанавливаем PB0
                         // delay_ns(600);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    // asm volatile ("nop");
    PORTB &= ~(1 << PB3); // Сбрасываем PB0
                          // delay_ns(650);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    // asm volatile ("nop");
}

void send_byte(uint8_t byte)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (byte & (1 << (7 - i)))
        {
            send_one();
        }
        else
        {
            send_zero();
        }
    }
}

void send_led_color(uint8_t red, uint8_t green, uint8_t blue)
{
    send_byte(green); // Данные для зелёного
    send_byte(red);   // Данные для красного
    send_byte(blue);  // Данные для синего
}

void send_reset()
{
    // Отправка сигнала сброса
    _delay_us(50); // Продолжительность сигнала сброса более 50 мкс
}
*/
void ShipPillar();
int main(void)
{
    InitLedOne();
    InitLedTwo();
    InitLedThree();
    Init_step_forStepeOne();
    // DDRB |= (1 << PB3) | (1 << PB5); // Устанавливаем PB0 как выход
    Timer0_Init();
    // DDRB |= (1 << 1) | (1 << 2);
    int16_t count = 1000;
    int16_t step = 3;
    int16_t count1 = 1000;
    int16_t step1 = 5;
    uint16_t stepColorChange = 1;
    uint16_t Color = 0;
    // DDRB |= (1 << PB3);
    uint8_t arrayRed[26] = {0};
    uint8_t arrayGreen[26] = {0};
    uint8_t arrayBlue[26] = {0};
    uint8_t ledsOff = 0;
    uint8_t x = 0;
    uint8_t countT = 0;
    On_Off_stepper_1(Off_step1);
    while (1)
    {
        //SpeedControlOne(5);
        ShipPillar();
        for (uint8_t i = 0; i < 26; i++)
        {
            if (i == ledsOff)
            {
                arrayBlue[i] = 0;
                arrayRed[i] = 0;
                arrayGreen[i] = 0;
            }
            else if (i == ledsOff + 1)
            {
                arrayBlue[i] = 0;
                arrayRed[i] = 0;
                arrayGreen[i] = 0;
            }
            else if (i == ledsOff + 2)
            {
                arrayBlue[i] = 0;
                arrayRed[i] = 0;
                arrayGreen[i] = 0;
            }
            else if (i == ledsOff + 3)
            {
                arrayBlue[i] = 0;
                arrayRed[i] = 0;
                arrayGreen[i] = 0;
            }

            else
            {
                arrayBlue[i] = 64;
                arrayRed[i] = 14;
                arrayGreen[i] = 44;
            }
        }
        if (HAL_GetTick() - time >= 50)
        {
            if (ledsOff <= 26)
            {
                ledsOff++;
            }
            else
            {
                ledsOff = 0;
            }
            time = HAL_GetTick();
        }

        uint8_t length = sizeof(arrayRed) / sizeof(arrayRed[0]);
        for (uint8_t i = 0; i < length; i++)
        {
            send_led_colorOne(arrayRed[i], arrayGreen[i], arrayBlue[i]);
        }
        PORTB&=~(1<<1);
        send_reset();
        for (uint8_t i = 0; i < length; i++)
        {
            send_led_colorTwo(arrayRed[i], arrayGreen[i], arrayBlue[i]);
        }
        PORTB&=~(1<<2);
        send_reset();

        //
    }
}

void ShipPillar()
{
    for (uint8_t i = 0; i < 60; i++)
    {
        send_led_colorThree(Red, Green, Blue);
    }
    PORTB&=~(1<<3);
    send_reset();

    if (HAL_GetTick() - TimerLed >= 50)
    {
        Red += valueR;
        Green += valueG;
        Blue += valueB;
        if (Red <= 1 || Red >= 21)
        {
            valueR = -valueR;
            valueG = -valueG;
            valueB = -valueB;
        }
        TimerLed = HAL_GetTick();
    }
}