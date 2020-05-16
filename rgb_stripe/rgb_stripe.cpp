#include "rgb_stripe.h"
#include "Arduino.h"

RgbController::RgbController(int r_pin, int g_pin, int b_pin, bool high_is_on)
    : _r_pin(r_pin), _g_pin(g_pin), _b_pin(b_pin), _high_is_on(high_is_on) 
{
    pinMode(_r_pin, OUTPUT);
    pinMode(_g_pin, OUTPUT);
    pinMode(_b_pin, OUTPUT);

    set_color({0,0,0});
}

void RgbController::set_color(Color color)
{
    if (_high_is_on) {
        analogWrite(_r_pin, color.r);
        analogWrite(_g_pin, color.g);
        analogWrite(_b_pin, color.b);
    } else {
        analogWrite(_r_pin, 255 - color.r);
        analogWrite(_g_pin, 255 - color.g);
        analogWrite(_b_pin, 255 - color.b);
    }
}