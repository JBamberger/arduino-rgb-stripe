#include <rgb_stripe.h>

RgbController light_controller(2, 3, 4, false);
int color = 0;

void setup()
{
    Serial.begin(9600);
    delay(2000);
    while (!Serial)
        ; //delay for Leonardo
}
void loop()
{

    switch (color)
    {
    case 0:
        light_controller.set_color(RED);
        break;
    case 1:
        light_controller.set_color(GREEN);
        break;
    case 2:
        light_controller.set_color(BLUE);
        break;
    }

    Serial.println(color);

    wait(1000);
    color++;
    if (color > 2)
        color = 0;
}