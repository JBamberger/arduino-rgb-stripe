#ifndef rgb_stripe
#define rgb_stripe


struct Color
{
    int r;
    int g;
    int b;
    Color(int r, int g, int b): r(r), g(g), b(b) {}
};

class RgbController
{
    bool _high_is_on;
    int _r_pin;
    int _g_pin;
    int _b_pin;

public:
    explicit RgbController(int r_pin, int g_pin, int b_pin, bool high_is_on = true);
    void set_color(Color color);
};

#include "colors.h"

#endif rgb_stripe