#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// LED strip
#define PIN 6
#define NUMPIXELS 30

// 4 digital keypad. pins are pulled HIGH, and go LOW when pressed.
#define KEY1 4
#define KEY2 5
#define KEY3 2
#define KEY4 3

#define NUMEFFECTS 3

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100

// the setup function runs once when you press reset or power the board
void setup()
{
  // set the keypad keys to inputs with pull-up resistors.
  pinMode(KEY1, INPUT_PULLUP);
  pinMode(KEY2, INPUT_PULLUP);
  pinMode(KEY3, INPUT_PULLUP);
  pinMode(KEY4, INPUT_PULLUP);

  pixels.begin();

  Serial.begin(19200);
  Serial.println("Starting...");
}

// 1-2
int effect = 2;
int brightness = 0;
unsigned long when_last_updated = millis();
void doEffect1()
{

  for (int led = 0; led < NUMPIXELS; led++)
  {
    pixels.setPixelColor(led, pixels.Color(50, 100, brightness));
  }
  pixels.show();
  if (millis() - when_last_updated > DELAYVAL)
  {
    brightness++;
    if (brightness >= 256)
      brightness == 0;

    when_last_updated = millis();
  }
}

void doEffect2()
{
  for (int led = 0; led < NUMPIXELS; led++)
  {
    pixels.setPixelColor(led, pixels.Color(255, 0, 0));
  }
  pixels.show();
}

int e3led = 0;

void doEffect3()
{
  for (int led = 0; led < NUMPIXELS; led++)
  {
    if (led == e3led)
    {
      pixels.setPixelColor(led, pixels.Color(0, 255, 0));
    }
    else
    {
      pixels.setPixelColor(led, pixels.Color(0, 25, 0));
    }
  }
  pixels.show();
  if (millis() - when_last_updated > 500)
  {
    e3led++;
    if (e3led == NUMPIXELS)
    {
      e3led = 0;
    }
    when_last_updated = millis();
  }
}

int holdingButton = false;

void checkEffectChange()
{
  int button1Pressed = digitalRead(KEY1);
  if (button1Pressed == LOW)
  { // == means "is it equal?"
    Serial.println("button1 down");
    if (holdingButton == false)
    {

      effect++;
      if (effect > NUMEFFECTS)
      {
        effect = 1;
      }
      holdingButton = true;
    }
    // effect = 1;  // = means "it becomes"
  }
  else
  {
    holdingButton = false;
    Serial.println("button1 up");
  }
}

// the loop function runs over and over again forever
void loop()
{
  checkEffectChange();
  // Serial.println("starting loop");

  pixels.clear();

  if (effect == 1)
  {
    doEffect1(); // SLOW AF
  }
  else if (effect == 2)
  {
    doEffect2();
  }
  else
  {
    doEffect3();
  }
}
