#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(60, A2);
//======================================
int stripIndex = 0;
String inMessage;
unsigned long endTime;
unsigned long startTime;
int interval;
boolean isOn;
//======================================
uint32_t color;
uint32_t color1 = strip.Color(255, 50, 100);
uint32_t color2 = strip.Color(100, 255, 50);
uint32_t color3 = strip.Color(0, 0, 255);
uint32_t color4 = strip.Color(255, 0, 255);
uint32_t color5 = strip.Color(255, 255, 0);
uint32_t color6 = strip.Color(0, 255, 255);
uint32_t color7 = strip.Color(255, 255, 255);
uint32_t color8 = strip.Color(175, 175, 175);
uint32_t colorC = strip.Color(0, 255, 0);
uint32_t colorW = strip.Color(255, 0, 0);

//======================================
unsigned long val1;
int val2;
int val3;
int val4;
int arrayEnd = 6;
//===============================
// arrayEnd starts from zero => {0, 1, 2, 3, ...........
int sol1[] = {0, 4, 1, 3, 2, 1, 5};
int index = 0;
void setup() {
  Serial.begin(9600);
  startTime = millis();
  strip.begin();
  strip.clear();
  strip.show();
  isOn = false;
  //1 = 1 SECOND
  interval = 1000;
}

void loop() {
  recieve();
  lightMe();
  endTime = millis();
  strip.setBrightness(val3);
  //array

  switch (val1) {

    case 0:
      for (int i = 0; i < 7; i++) {
        strip.setPixelColor(i, color1);
      }
      break;

    case 1:
      for (int i = 7; i < 14; i++) {
        strip.setPixelColor(i, color2);
      }
      break;

    case 2:
      for (int i = 14; i < 21; i++) {
        strip.setPixelColor(i, color3);
      }
      break;

    case 3:
      for (int i = 21; i < 28; i++) {
        strip.setPixelColor(i, color4);
      }
      break;

    case 4:
      for (int i = 28; i < 35; i++) {
        strip.setPixelColor(i, color5);
      }
      break;

    case 5:
      for (int i = 35; i < 40; i++) {
        strip.setPixelColor(i, color6);
      }
      break;

    case 6:
      endTime = millis();
      strip.setBrightness(val3);
      if (endTime - startTime >= interval) {
        //    stripIndex += 1;
        if (stripIndex <= strip.numPixels()) {
          if (isOn == true) {
            isOn = false;
          } else if (isOn == false) {
            isOn = true;
          }
          startTime = millis();
        }
        if (isOn == true) {
          for (int i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color2);
          }
        }
        else if (isOn == false) {
        }

        startTime = millis();
        strip.show();
      }
      break;

    case 7:


      for (int i = 0; i < 60; i++) {

        strip.setPixelColor(i, colorW);
      }


      break;

    case 8:

      for (int i = 0; i < 60; i++) {
        strip.setPixelColor(i, colorC);
      }

      break;
  }
  strip.show();
  strip.clear();

}

//Recieve func
void recieve() {
  char startChar = '?';
  char endChar = '!';

  // check to see if anything is available over the serial port
  if (Serial.available() > 0) {
    char currentChar = Serial.read();

    //Serial.println(currentChar); //for testing
    if (currentChar == startChar) {
      inMessage = Serial.readStringUntil(endChar);

      //if the message is not equal to the null string
      if (inMessage != "\0") {
        // Serial.print("test: ");
        //Serial.println(inMessage);
        parseMessage();

        if (val1 == sol1[index]) {
          index += 1;
        }
        else {
          val1  = 7;
        }
        if (index > arrayEnd) {
          val1 = 8;
        }
      }
    }
  }
}



void parseMessage() {
  int commaIndex = inMessage.indexOf(',');
  val1 = inMessage.substring(0, commaIndex).toInt();
  //Serial.println(val1);

  inMessage = inMessage.substring(commaIndex + 1);
  commaIndex = inMessage.indexOf(',');

  val2 = inMessage.substring(0, commaIndex).toInt();
  // Serial.println(val2);

  inMessage = inMessage.substring(commaIndex + 1);
  commaIndex = inMessage.indexOf(',');

  val3 = inMessage.substring(0, commaIndex).toInt();
  //Serial.println(val3);

  inMessage = inMessage.substring(commaIndex + 1);

  val4 = inMessage.toInt();
  //Serial.println(val4);
}


void lightMe() {
  if (val4 == 1) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color1);
    //    }
    color = color1;
  }

  if (val4 == 2) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color2);
    //    }
    color = color2;
  }

  if (val4 == 3) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color3);
    //    }
    color = color3;
  }

  if (val4 == 4) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color3);
    //    }
    color = color4;
  }

  if (val4 == 5) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color3);
    //    }
    color = color5;
  }

  if (val4 == 6) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color3);
    //    }
    color = color6;
  }

  if (val4 == 7) {
    //    for (int i = 0; i < strip.numPixels(); i++) {
    //      strip.setPixelColor(i, color3);
    //    }
    color = color7;
  }
}
