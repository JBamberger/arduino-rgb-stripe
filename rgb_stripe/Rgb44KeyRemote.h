#ifndef rgb44keyremote
#define rgb44keyremote

#include <colors.h>
#include <rgb_stripe.h>

enum Rgb44RemoteColorComponent {
    red, green, blue
};

enum Rgb44RemoteColor {
    red, green, blue, white
};

enum Rgb44RemoteColorShade {
    level1, level2, level3, level4, level5
};

enum Rgb44RemoteDiyColor {
    diy1, diy2, diy3, diy4, diy5, diy6
};

Color _colors_flash[] = {WHITE, BLACK};
Color _colors3[] = {RED, GREEN, BLUE};
Color _colors7[] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE};

CycleEffect _effect_flash(_colors_flash, 2);
CycleEffect _effect_jump3(_colors3, 3);
CycleEffect _effect_jump7(_colors7, 7);
CrossFadeEffect _effect_fade3(_colors3, 3);
CrossFadeEffect _effect_fade7(_colors7, 7);

class Rgb44KeyRemote {



    RgbController _controller;

public:
    explicit Rgb44KeyRemote(RgbController controller) : _controller(controller){

    }

    void toggle_power() {}
    void toggle_play() {}
    void increase_brightness() {}
    void decrease_brightness() {}
    void set_color(Rgb44RemoteColor color, Rgb44RemoteColorShade shade) {}
    void increase_component(Rgb44RemoteColorComponent component) {}
    void decrease_component(Rgb44RemoteColorComponent component) {}
    void increase_speed() {}
    void decrease_speed() {}
    void set_diy(int index) {}
    void set_auto() {}

    void set_flash() {
        _controller.set_effect(&_effect_flash);
    }

    void set_effect_jump3() {
        _controller.set_effect(&_effect_jump3);
    }
    
    void set_effect_jump7() {
        _controller.set_effect(&_effect_jump7);
    }
    
    void set_effect_fade3() {
        _controller.set_effect(&_effect_fade3);
    }
    
    void set_effect_fade7() {
        _controller.set_effect(&_effect_fade7);
    }


};


#endif rgb44keyremote