#ifndef _VARIANT_BLUEFI_
#define _VARIANT_BLUEFI_

// Master clock frequency
#define VARIANT_MCK       (64000000ul)
#define USE_LFRC    // Board uses RC for LF

#define _PINNUM(port, pin)    ((port)*32 + (pin))

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (47)
#define NUM_DIGITAL_PINS     (47)
#define NUM_ANALOG_INPUTS    (7)
#define NUM_ANALOG_OUTPUTS   (0)

// LEDs
#define PIN_LED1             (17)
#define PIN_NEOPIXEL         (18)

#define LED_BUILTIN          PIN_LED1
#define BUILTIN_LED          PIN_LED1

#define LED_RED              PIN_LED1
#define LED_WHITE            44

#define LED_STATE_ON         1      // State when LED is litted

// Buttons
#define PIN_BUTTON1          (5)    // Button A
#define PIN_BUTTON2          (11)   // Button B

// Microphone
#define PIN_PDM_DIN           22
#define PIN_PDM_CLK           21
#define PIN_PDM_PWR           -1  // not used

// Buzzer
#define PIN_BUZZER            46

// Analog pins
#define PIN_A0               (0)
#define PIN_A1               (1)
#define PIN_A2               (2)
#define PIN_A3               (3)
#define PIN_A4               (4)
#define PIN_A5               (14)
#define PIN_A6               (20)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;

#define ADC_RESOLUTION       14

// Serial interfaces (UART)
#define PIN_SERIAL1_RX       (0)
#define PIN_SERIAL1_TX       (1)

// SPI Interfaces
#define SPI_INTERFACES_COUNT 3

// nRF52840 has only one SPIM3 runing at highspeed 32Mhz
// This assign SPIM3 to either: SPI (0), SPI1 (1).
// If not defined, default to 0 or SPI.
#define SPI_32MHZ_INTERFACE  1

// SPI (P13~P16)
#define PIN_SPI_SCK          (13)
#define PIN_SPI_MISO         (14)
#define PIN_SPI_MOSI         (15)

static const uint8_t SS   = (16);
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

// SPI1 (TFT-LCD)
#define PIN_SPI1_SCK          (23)
#define PIN_SPI1_MOSI         (24)
#define PIN_SPI1_MISO         (28)

static const uint8_t SS1   = (25);
static const uint8_t MOSI1 = PIN_SPI1_MOSI ;
static const uint8_t MISO1 = PIN_SPI1_MISO ;
static const uint8_t SCK1  = PIN_SPI1_SCK ;

// On-board TFT display
#define PIN_TFT_CS            25
#define PIN_TFT_DC            26
#define PIN_TFT_LITE          27
#define PIN_TFT_RST           -1  // not used

// On-board WiFi

// Wire Interfaces (I2C)
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SCL        (19)
#define PIN_WIRE_SDA        (20)

static const uint8_t SCL  = PIN_WIRE_SCL ;
static const uint8_t SDA  = PIN_WIRE_SDA ;

#define PIN_WIRE1_SCL       (41)
#define PIN_WIRE1_SDA       (42)

static const uint8_t SCL1 = PIN_WIRE1_SCL ;
static const uint8_t SDA1 = PIN_WIRE1_SDA ;

// QSPI Pins
#define PIN_QSPI_SCK         28
#define PIN_QSPI_CS          29
#define PIN_QSPI_IO0         30
#define PIN_QSPI_IO1         31
#define PIN_QSPI_IO2         32
#define PIN_QSPI_IO3         33

// On-board QSPI Flash
#define EXTERNAL_FLASH_DEVICES   W25Q16JV_IM
#define EXTERNAL_FLASH_USE_QSPI

#ifdef __cplusplus
}
#endif

#endif