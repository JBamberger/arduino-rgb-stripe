#ifndef rgb_stripe
#define rgb_stripe

struct Color
{
    int r;
    int g;
    int b;
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
};
#include "colors.h"

class RgbController;
class ColorEffect
{

public:
    virtual void update(RgbController &controller);
};

class RgbController
{
    unsigned long _last_update;
    bool _high_is_on;
    int _r_pin;
    int _g_pin;
    int _b_pin;
    ColorEffect *_effect;

public:
    explicit RgbController(
        int r_pin, int g_pin, int b_pin,
        ColorEffect *effect, bool high_is_on = true);
    void set_color(Color color);
    void set_effect(ColorEffect *effect);
    void update();
};

class ConstantColorEffect : public ColorEffect
{
    Color _color;

public:
    ConstantColorEffect(Color color);
    virtual void update(RgbController &controller);
};

class CrossFadeEffect : public ColorEffect
{
    const int _len;
    const Color *_stops;
    int _position;
    Color _state;

public:
    CrossFadeEffect(const Color *colors, int len);
    virtual void update(RgbController &controller);
};

#endif rgb_stripe