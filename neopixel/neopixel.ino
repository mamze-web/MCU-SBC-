#include <Adafruit_NeoPixel.h>

#define LED_PIN 8
#define LED_COUNT 60

Adafruit_NeoPixel strip(LED_COUNT , LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
    strip.begin();

    strip.show(); //네오픽셀 빛 출력을 위해 , 여기서는 모든네오픽셀 off 를 위해 사용

    strip.setBrightness(50); //밝기 조절
}

void loop(){
    colorWipe(strip.Color(255, 0 , 0),50);//빨간색, 50의 딜레이로 켜짐

    rainbow(10);

}

void colorWipe(unit32_t color, int wait){
    for (int i=0; i < strip.numPixels(); i++){
        strip.setPixelColor(i,color);

        strip.show();

        delay(wait);
    }
}

void rainbow(int wait) {  
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());      
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

