#include <ILI9341_t3.h>           // fast display driver lib
#include <ILI9341_FlickerFreePrint.h>     // library to draw w/o flicker
#include <font_ComicSansMS.h>           // custom fonts for the ILI9341_t3.h https://github.com/PaulStoffregen/ILI9341_fonts

// some defines for pins
#define TFT_CS        9
#define TFT_DC        2

// setup some colors
#define C_BLACK      0x0000
#define C_BLUE        0x001F
#define C_RED         0xF800
#define C_GREEN       0x07E0
#define C_CYAN        0x07FF
#define C_MAGENTA     0xF81F
#define C_YELLOW      0xFFE0
#define C_WHITE       0xFFFF

// create the display object
ILI9341_t3 Display(TFT_CS, TFT_DC);

// create a flicker free pnject for each data to be printed with the flicker free option
// the library used template scheme so you need to pass the data type in <>
ILI9341_FlickerFreePrint Data1(&Display, C_WHITE, C_BLACK);
ILI9341_FlickerFreePrint Data2(&Display, C_WHITE, C_BLACK);

// setup some variables
int i = 0;
float j = 0.0f;
char buf[50];
void setup() {

  // you know the drill
  Serial.begin(9600);

  // typical display begin
  Display.begin();
  Display.setRotation(3);
  Display.fillScreen(C_BLACK);

  // using proportional fonts, a download in addition to the ILI9341_t3 lib
  Display.setFont(ComicSansMS_28);

  // draw some info headers
  Display.fillRect(0, 0, 319, 60, C_RED);
  Display.setCursor(10, 10);
  Display.setTextColor(C_WHITE, C_RED);
  Display.print("Left Justified: ");

  Display.fillRect(0, 120, 319, 60, C_BLUE);
  Display.setCursor(10, 130);
  Display.setTextColor(C_WHITE, C_BLUE);
  Display.print("Right Justified: ");
  
  // default printing is left justified
  // optional you can print right justified. Warning when the least significant digit changes
  // the entire number will repaint--this will cause flicker on the most significant digits
  // it's most obvious when non proportional (fixed width) font's are used, this is because 
  // to get righ justification, characters must be drawn
  // from the right to left, hence any change in right digits cause a repaint of all  
  // but if you really want right, at least you have it
  Data2.setJustification(JUSTIFY_RIGHT);
  // option as default is left but need to call if setting back from right to left
  // Data2.setJustification(JUSTIFY_LEFT);

  // similar to how you draw text this lib mimics that process
  // Display.setCursor(x, y);
  // YourFlickerFreeObject.setTextColor(C_WHITE, C_BLACK);
  // YourFlickerFreeObject.print(data, <decimals>);


}

void loop() {

  // get some data to draw
  j += 0.0013;
i++;
  // draw the default left justified
  Display.setCursor(20, 70);
  Data1.setTextColor(C_WHITE, C_BLACK);
  Data1.print(j, 4);

  // now let's draw the optional right justified
  Display.setCursor(300, 190);
  Data2.setTextColor(C_WHITE, C_BLACK);

  sprintf(buf, "Datapoint: %d", i);
  Data2.print(buf);

  delay(100);

}