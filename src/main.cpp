#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS 30

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100



// the setup function runs once when you press reset or power the board
void setup() {
  pixels.begin();

}

// the loop function runs over and over again forever
void loop() {
  pixels.clear();

  // for(int i=0; i<NUMPIXELS; i++) {

  //   pixels.setPixelColor(i, pixels.Color(50, 150, 75));
  //   pixels.show();
  //   delay(DELAYVAL);   
  // }               
  for (int brightness = 0; brightness < 256; brightness++) 
  {
  
    for (int led = 0; led < NUMPIXELS; led++)
    {
      pixels.setPixelColor (led, pixels.Color(brightness, brightness, 50));
    }
    pixels.show();
    delay(DELAYVAL);

  } 

}