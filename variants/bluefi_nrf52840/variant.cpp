#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

#define _PINNUM(port, pin)     ((port)*32 + (pin))

const uint32_t g_ADigitalPinMap[] =
{
  // D0 .. D20
  _PINNUM(0, 28),   // D0  is P0.28 (GPIO D0 / AI0 / UART RX)
  _PINNUM(0, 2),    // D1  is P0.02 (GPIO D1 / AI1 / UART TX)
  _PINNUM(0, 29),   // D2  is P0.29 (GPIO D2 / AI2)
  _PINNUM(0, 30),   // D3  is P0.30 (GPIO D3 / AI3)
  _PINNUM(0, 3),    // D4  is P0.03 (GPIO D4 / AI4)
  _PINNUM(1, 7),    // D5  is P1.07 (GPIO D5 / Left button)
  _PINNUM(0, 8),    // D6  is P0.08 (GPIO D6)
  _PINNUM(0, 25),   // D7  is P0.25 (GPIO D7)
  _PINNUM(0, 23),   // D8  is P0.23 (GPIO D8)
  _PINNUM(0, 21),   // D9  is P0.21 (GPIO D9)
  _PINNUM(0, 19),   // D10 is P0.19 (GPIO D10)
  _PINNUM(1, 9),    // D11 is P1.09 (GPIO D11 / Right Button)
  _PINNUM(0, 16),   // D12 is P0.16 (GPIO D12)
  _PINNUM(0, 6),    // D13 is P0.06 (GPIO D13 / SCK)
  _PINNUM(0, 4),    // D14 is P0.04 (GPIO D14 / MISO / AI5)
  _PINNUM(0, 26),   // D15 is P0.26 (GPIO D15 / MOSI)
  _PINNUM(0, 1),    // D16 is P0.01 (GPIO D16)

  _PINNUM(1, 12),   // D17 is P1.12 (GPIO D17 / Red LED  [not exposed])
  _PINNUM(1, 10),   // D18 is P1.10 (GPIO D18 / NeoPixel [not exposed])

  _PINNUM(0, 0),    // D19 is P0.00 (GPIO D19 / SCL)
  _PINNUM(0, 31),   // D20 is P0.31 (GPIO D20 / SDA / AI6)

  // D21 & D22 - PDM mic (not exposed via any header / test point)
  _PINNUM(0, 9),    // D21 is P0.09 (MICROPHONE_CLOCK)
  _PINNUM(0, 10),   // D22 is P0.10 (MICROPHONE_DATA)

  // D23 .. D27 - TFT control (not exposed via any header / test point)
  _PINNUM(0, 7),    // D23 P0.07 (TFT SCK)
  _PINNUM(1, 8),    // D24 P1.08 (TFT MOSI)
  _PINNUM(0, 5),    // D25 P0.05 (TFT CS)
  _PINNUM(0, 27),   // D26 P0.27 (TFT DC)
  _PINNUM(1, 13),   // D27 P1.13 (TFT LITE)

  // QSPI pins (not exposed via any header / test point)
  _PINNUM(1, 3),    // D28 is P1.03 (QSPI SCK)
  _PINNUM(1, 2),    // D29 is P1.02 (QSPI CS)
  _PINNUM(1, 1),    // D30 is P1.01 (QSPI Data 0)
  _PINNUM(1, 4),    // D31 is P1.04 (QSPI Data 1)
  _PINNUM(1, 6),    // D32 is P1.06 (QSPI Data 2)
  _PINNUM(1, 5),    // D33 is P1.05 (QSPI Data 3)

  // ESP32SPI WiFi pins (not exposed via any header / test point)
  _PINNUM(0, 22),   // D34 is P0.22 (WIFI SCK)
  _PINNUM(0, 17),   // D35 is P0.17 (WIFI MISO)
  _PINNUM(0, 20),   // D36 is P0.20 (WIFI MOSI)
  _PINNUM(0, 15),   // D37 is P0.15 (WIFI BUSY)
  _PINNUM(0, 24),   // D48 is P0.24 (WIFI CS)
  _PINNUM(1, 0),    // D39 is P1.00 (WIFI RESET)
  _PINNUM(0, 13),   // D40 is P0.13 (WIFI PWR)

  // D41 .. D44 - on board sensors pins (not exposed via any header / test point)
  _PINNUM(0, 11),   // D41 is P0.11 SENSORS_SCL
  _PINNUM(0, 12),   // D42 is P0.12 SENSORS_SDA
  _PINNUM(0, 14),   // D43 is P0.14 LSM6DS33 IRQ (ACCELEROMETER_INTERRUPT / IMU_IRQ)

  _PINNUM(1, 14),   // D44 is P1.14 White LED (WHITE LED)

  // D45 & D46, on board Buzzer pins (not exposed via any header / test point)
  _PINNUM(1, 11),   // D45 is P1.11 Audio Amplifier Enable (SPEAKER ENABLE)
  _PINNUM(1, 15),   // D46 is P1.15 Speaker/Audio
};

void initVariant()
{
  // LED1
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  // Disable TFT LITE powering up
  pinMode(PIN_TFT_LITE, OUTPUT);
  digitalWrite(PIN_TFT_LITE, LOW);
}