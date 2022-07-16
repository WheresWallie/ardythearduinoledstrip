#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// LED strip
#define PIN        6
#define NUMPIXELS 30

// 4 digital keypad. pins are pulled HIGH, and go LOW when pressed.
#define KEY1       4
#define KEY2       5
#define KEY3       2
#define KEY4       3

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100


// the setup function runs once when you press reset or power the board
void setup() {
  // set the keypad keys to inputs with pull-up resistors.
  pinMode(KEY1, INPUT_PULLUP);
  pinMode(KEY2, INPUT_PULLUP);
  pinMode(KEY3, INPUT_PULLUP);
  pinMode(KEY4, INPUT_PULLUP);

  pixels.begin();

  Serial.begin(19200);
  Serial.println("Starting...");
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("starting loop");

  pixels.clear();

  // for(int i=0; i<NUMPIXELS; i++) {

  //   pixels.setPixelColor(i, pixels.Color(50, 150, 75));
  //   pixels.show();
  //   delay(DELAYVAL);   
  // }               
  for (int brightness = 0; brightness < 256; brightness++) {
  
    for (int led = 0; led < NUMPIXELS; led++)
    {
      pixels.setPixelColor (led, pixels.Color(brightness, brightness, 50));
    }
    pixels.show();

    delay(DELAYVAL);
  } 
}