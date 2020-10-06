#include "rgb_stripe.h"
#include "Arduino.h"

RgbController::RgbController(int r_pin, int g_pin, int b_pin, ColorEffect *effect, bool high_is_on)
    : _r_pin(r_pin), _g_pin(g_pin), _b_pin(b_pin),
      _high_is_on(high_is_on), _last_update(millis()), _effect(effect),
      _speed(1), _delta(0)
{
    pinMode(_r_pin, OUTPUT);
    pinMode(_g_pin, OUTPUT);
    pinMode(_b_pin, OUTPUT);

    set_color({0, 0, 0});
}

void RgbController::set_speed(unsigned int speed) {
    this->_speed = speed;
}

void RgbController::set_color(Color color)
{
    if (_high_is_on)
    {
        analogWrite(_r_pin, color.r);
        analogWrite(_g_pin, color.g);
        analogWrite(_b_pin, color.b);
    }
    else
    {
        analogWrite(_r_pin, 255 - color.r);
        analogWrite(_g_pin, 255 - color.g);
        analogWrite(_b_pin, 255 - color.b);
    }
}

void RgbController::set_effect(ColorEffect *effect)
{
    this->_effect = effect;
}

void RgbController::update()
{
    unsigned long time = millis();
    _delta += time - _last_update;
    _last_update = time;

    while (_delta > _speed) {
        _effect->update(*this);
        _delta -= _speed;
    }
}

ConstantColorEffect::ConstantColorEffect(Color color) : _color(color) {}

void ConstantColorEffect::update(RgbController &controller)
{
    controller.set_color(this->_color);
}

CrossFadeEffect::CrossFadeEffect(const Color *colors, int len)
    : _stops(colors), _len(len), _state(*colors), _position(1)
{
}

void CrossFadeEffect::update(RgbController &controller)
{
    const Color &target = *(_stops + _position);

    int r_diff = _state.r - target.r;
    int g_diff = _state.g - target.g;
    int b_diff = _state.b - target.b;

    if (r_diff == 0 && g_diff == 0 && b_diff == 0)
    {
        // roll over to next color
        _state = target;
        _position++;
        if (_position >= _len)
        {
            _position = 0;
        }
    } else {
        if (r_diff > 0)
            _state.r--;
        else if (r_diff < 0)
            _state.r++;

        if (g_diff > 0)
            _state.g--;
        else if (g_diff < 0)
            _state.g++;

        if (b_diff > 0)
            _state.b--;
        else if (b_diff < 0)
            _state.b++;
    }

    controller.set_color(_state);
};



CycleEffect::CycleEffect(const Color *colors, int len, int call_count)
    : _stops(colors), _len(len), _call_count(call_count), _count(call_count), _position(1)
{
}

void CycleEffect::update(RgbController &controller)
{
    _count--;
    if (_count <= 0) {
        _position++;
        if (_position >= _len)
        {
            _position = 0;
        }
        _count = _call_count;

        controller.set_color(*(_stops + _position));
    }
};