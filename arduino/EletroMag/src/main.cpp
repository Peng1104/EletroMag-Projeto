#include <Arduino.h>

constexpr float PWM_FREQUENCY = 12602;  // 12602 Hz
constexpr uint16_t PERIOD = round(F_CPU / PWM_FREQUENCY);

void setup() {
    // Configure Timer 1 for PWM FREQUENCY on pin 9 = PB1 = OC1A.
    DDRB  |= _BV(PB1);    // set pin as output
    TCCR1B = 0;           // stop timer
    TCCR1A = _BV(COM1A1)  // non-inverting PWN on OC1A
           | _BV(WGM11);  // mode 14: fast PWM, TOP = ICR1
    TCCR1B = _BV(WGM12)   // ditto
           | _BV(WGM13)   // ditto
           | _BV(CS10);   // clock @ F_CPU
    ICR1   = PERIOD - 1;  // period
    OCR1A  = PERIOD / 2;  // duty cycle
}

void loop() {

}