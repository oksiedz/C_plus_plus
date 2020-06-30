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

//biblioteki do czujnika temperatury, wilgotnosci i cisnienia
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>


// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


//definiowanie pod czujnik temperatury
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;



const byte ROWS = 4; //ile wierszy
const byte COLS = 4; //ile kolumn

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

char keys[ROWS][COLS] = {//mapowanie klawiatury
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

Keypad klawiatura = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);//inicjalizacja klawiatury

void i_a_c_display()
{
  
}

void button(char klawisz)
{
  display.clearDisplay();
  display.display();
  display.setCursor(0, 0);
  display.print("Wybrales ");
  display.print(klawisz);
  display.display();
}

void setup()
{
  Serial.begin(9600);//do tworzenia w monitorze systemowym





  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  // display a line of text
  display.setCursor(0, 0);
  display.print("Witaj w programie Artura i Tomka.");
  delay(3000);
  display.setCursor(0, 20);
  display.print("Wybierz jeden z przyciskow A, B, C, D.");
  // update display with all of the above graphics
  display.display();
}


void loop()
{
  char klawisz = klawiatura.getKey();
  if (klawisz) {
    Serial.println(klawisz);
  };
  if (klawisz == 'A') {
    button(klawisz);
  };
  if (klawisz == 'B') {
    button(klawisz);
  };
  if (klawisz == 'C') {
    button(klawisz);
  };
  if (klawisz == 'D') {
    button(klawisz);
  };

 }
  
