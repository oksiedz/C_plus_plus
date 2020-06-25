//biblioteki do wyswietlacza start
#include <Adafruit_GFX.h>
#include <Adafruit_MonoOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
//bitblioteki do wyswietlacza koniec
#include <Keypad.h> //biblioteka od klawiatury

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif



const byte ROWS = 4; //ile wierszy
const byte COLS = 4; //ile kolumn

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

char keys[ROWS][COLS] = {//mapowanie klawiatury
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad klawiatura = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);//inicjalizacja klawiatury

void setup()
{
  Serial.begin(9600);//do tworzenia w monitorze systemowym
  
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,31);
  display.print("Witaj w programie Artura i Tomka");
  

  // update display with all of the above graphics
  display.display();
}


void loop()
{
  char klawisz = klawiatura.getKey();
  if (klawisz) {
    Serial.println(klawisz);
  };
  if (klawisz == '1')
  {
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Wcisnales przycisk 1");
    display.display();
  }
}
