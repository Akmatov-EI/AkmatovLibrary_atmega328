#include "ws2812b.h"

void InitLedOne()
{
DDRB|=(1<<1);
}

void InitLedTwo()
{
DDRB|=(1<<2);
}

void InitLedThree()
{
DDRB|=(1<<3);
}

void send_zero_One()
{
    // Отправка логического нуля
    PORTB |= (1 << PB1); // Устанавливаем PB0
                         // delay_ns(250);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //  asm volatile ("nop");
    PORTB &= ~(1 << PB1); // Сбрасываем PB0
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

void send_one_One()
{
    // Отправка логической единицы
    PORTB |= (1 << PB1); // Устанавливаем PB0
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
    PORTB &= ~(1 << PB1); // Сбрасываем PB0
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

void send_byteOne(uint8_t byte)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (byte & (1 << (7 - i)))
        {
            send_one_One();
        }
        else
        {
            send_zero_One();
        }
    }
}

void send_led_colorOne(uint8_t red, uint8_t green, uint8_t blue)
{
    send_byteOne(green); // Данные для зелёного
    send_byteOne(red);   // Данные для красного
    send_byteOne(blue);  // Данные для синего
}

///////////////////////////////////////////////////////////////////////

void send_zero_Two()
{
    // Отправка логического нуля
    PORTB |= (1 << PB2); // Устанавливаем PB0
                         // delay_ns(250);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //  asm volatile ("nop");
    PORTB &= ~(1 << PB2); // Сбрасываем PB0
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

void send_one_Two()
{
    // Отправка логической единицы
    PORTB |= (1 << PB2); // Устанавливаем PB0
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
    PORTB &= ~(1 << PB2); // Сбрасываем PB0
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

void send_byteTwo(uint8_t byte)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (byte & (1 << (7 - i)))
        {
            send_one_Two();
        }
        else
        {
            send_zero_Two();
        }
    }
}

void send_led_colorTwo(uint8_t red, uint8_t green, uint8_t blue)
{
    send_byteTwo(green); // Данные для зелёного
    send_byteTwo(red);   // Данные для красного
    send_byteTwo(blue);  // Данные для синего
}



/////////////////////////////////////////////////////////////////////////////////////


void send_zero_Three()
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

void send_one_Three()
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

void send_byteThree(uint8_t byte)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (byte & (1 << (7 - i)))
        {
            send_one_Three();
        }
        else
        {
            send_zero_Three();
        }
    }
}

void send_led_colorThree(uint8_t red, uint8_t green, uint8_t blue)
{
    send_byteThree(green); // Данные для зелёного
    send_byteThree(red);   // Данные для красного
    send_byteThree(blue);  // Данные для синего
}


void send_reset()
{
    // Отправка сигнала сброса
    _delay_us(50); // Продолжительность сигнала сброса более 50 мкс
}

