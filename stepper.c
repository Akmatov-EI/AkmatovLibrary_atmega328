#include "main.h"
uint32_t timer1 = 0;
uint32_t timer2 = 0;
uint16_t countspeedOne = 0;
uint16_t countspeedTwo = 0;
void Init_step_forStepeOne()
{
    DDRC |= (1 << 3);
    DDRC |= (1 << 2);
}

void Init_step_forStepeTwo()
{
    DDRC |= (1 << 1);
    DDRC |= (1 << 0);
}

void Clockwise_rotationStep_One()
{
    PORTC |= (1<<2);
}

void CounterClockwise_rotationStep_One()
{
    PORTC &=~(1<<2);
}

void Clockwise_rotationStep_Two()
{
    PORTC |= (1<<0);
}

void CounterClockwise_rotationStep_Two()
{
    PORTC &=~(1<<0);
}

void SpeedControlOne(uint16_t speed)
{
    if (HAL_GetTick() - timer1 >= speed)
    {
        moveTo1();
        timer1 = HAL_GetTick();
        countspeedOne++;
    }
}

void SpeedControlTwo(uint16_t speed)
{
    if (HAL_GetTick() - timer2 >= speed)
    {
        moveTo2();
        timer2 = HAL_GetTick();
        countspeedTwo++;
    }
}

uint16_t ReturnCountSpeedOne()
{
    return countspeedOne;
}

uint16_t ChangeCountSpeedOne(uint16_t speed)
{
    countspeedOne = speed;
}

uint16_t ReturnCountSpeedTwo()
{
    return countspeedTwo;
}

uint16_t ChangeCountSpeedTwo(uint16_t speed)
{
    countspeedTwo = speed;
}

void moveTo1()
{
    PORTC |= (1 << 3);
    _delay_us(17);
    PORTC &= ~(1 << 3);
}

void moveTo2()
{
    PORTC |= (1 << 1);
    _delay_us(17);
    PORTC &= ~(1 << 1);
}

void On_Off_stepper_1(uint8_t status)
{
    if (status == On_step1)
    {
        DDRD |= (1 << 2);
        PORTD &= ~(1 << 2);
    }
    else if (status == Off_step1)
    {
        DDRD |= (1 << 2);
        PORTD |= (1 << 2);
    }
}

void On_Off_stepper_2(uint8_t status)
{
    if (status == On_step2)
    {
        DDRC |= (1 << 5);
        PORTC &= ~(1 << 5);
    }
    else if (status == Off_step2)
    {
        DDRC |= (1 << 5);
        PORTC |= (1 << 5);
    }
}