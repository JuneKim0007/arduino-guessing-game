#include <M5Core2.h>
/*
 *     M5.begin();
    M5.Lcd.print("Hello, world!");
    delay(10);
    M5.Lcd.setCursor(0,50);
    M5.Lcd.setTextFont(2);
    M5.Lcd.println("Starting WPS");
    M5.Lcd.setTextFont(0);
    M5.Lcd.setTextColor(0xFFFF);
    M5.Lcd.drawString("ImageViewer : " + mi->path, 10, 10, 2);
 */

void setup() {
  M5.begin();
    M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(65, 10);
  M5.Lcd.println("Prises Commandees");
  M5.Lcd.setCursor(3, 35);
  M5.Lcd.println("Presser le bouton B pour   700ms");
  M5.Lcd.println("Pour tout nettoyer.");
  M5.Lcd.setTextColor(WHITE);
  delay(5100);
  M5.Lcd.drawRect(0,0,100,200, WHITE);
  M5.Lcd.setTextFont(0);
  M5.Lcd.setTextColor(0x8410,0);
  M5.Lcd.drawString("- LovyanLauncher -", 207, 191, 1);
  M5.Lcd.drawString("@lovyan03    v0.2.3", 204, 201, 1);
  M5.Lcd.drawString("http://git.io/fhdJV", 204, 211, 1);

}

void loop() {
    M5.update();
   if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
    delay(100); 
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 0);
  }
}
