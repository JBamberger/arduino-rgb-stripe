#include <colors.h>
#include <rgb_stripe.h>

const int RED_PIN = 3;
const int GREEN_PIN = 4;
const int BLUE_PIN = 5;

// ConstantColorEffect r_effect(RED);
// ConstantColorEffect g_effect(GREEN);
// ConstantColorEffect b_effect(BLUE);

Color colors[] = {
  RED, GREEN, BLUE
};

CycleEffect effect(colors, 3, 1024);

RgbController controller(RED_PIN, GREEN_PIN, BLUE_PIN, &effect, false);


void setup() {
  Serial.begin(115200);
  Serial.println("1=Red, 2=Green, 3=Blue");
}

void loop() {
  // if (Serial.available()) {
  //   int input = Serial.read();
  //   switch (input) {
  //     case '1': controller.set_effect(&r_effect); break;
  //     case '2': controller.set_effect(&g_effect); break;
  //     case '3': controller.set_effect(&b_effect); break;
  //     case '\r':
  //     case '\n':
  //       break;
  //     default:
  //       Serial.println("Invalid input.");
  //       Serial.println(input);
  //       break;
  //   }
  // }
  controller.update();
}