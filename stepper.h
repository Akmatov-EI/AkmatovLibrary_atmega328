#include <avr/io.h>
#define stepPin_stepper1 3
#define stepPin_stepper2 1
#define direction_stepper1 2
#define direction_stepper2 0


#define On_step1 1 // включение первого драйвера
#define Off_step1 0 // выключение первого драйвера

#define On_step2 1 // включение второго драйвера
#define Off_step2 0 // выключение второго драйвера

#define j_2 // деление шагов на 2
#define j_4 // деление шагов на 4
#define j_8 // деление шагов на 8

/// @brief Функция инициализации первого шагового драйвера
void Init_step_forStepeOne();

/// @brief функция инициализации второго драйвера
void Init_step_forStepeTwo();

/// @brief Функция управления питанием первого драйвера
/// @param status установка состояния мотора(on - включенное состояние, off - выключенное состояние)
void On_Off_stepper_1(uint8_t status);

/// @brief Функция управления питанием второго драйвера
/// @param status установка состояния мотора(on - включенное состояние, off - выключенное состояние)
void On_Off_stepper_2(uint8_t status);

void SpeedControlOne(uint16_t speed);

void SpeedControlTwo(uint16_t speed);

/// @brief Функция возвращающая шаги
/// @return 
uint16_t ReturnCountSpeedOne();

uint16_t ChangeCountSpeedTwo(uint16_t speed);

uint16_t ReturnCountSpeedTwo();

/// @brief Функция для изминения шагов
/// @param step устанавливается количесвто шагов(целочисленное безнаковое размером в 4 байта)
/// @return 
uint16_t ChangeCountSpeedOne(uint16_t speed);

/// @brief Функция для установки направления вращения (почасовой)
void CounterClockwise_rotationStep_One();

/// @brief Функция для установки направления вращения (против часовой)
void Clockwise_rotationStep_One();

/// @brief Функция для установки направления вращения (почасовой)
void CounterClockwise_rotationStep_Two();

/// @brief Функция для установки направления вращения (против часовой)
void Clockwise_rotationStep_Two();