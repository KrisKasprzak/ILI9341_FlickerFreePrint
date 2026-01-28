<b><h2><center>ILI9341 FlickerFreePrint Library</center></h1></b>

This library will let programmers paint data to TFT LCD's using a Teensy and the ILI9341_t3 driver in a flicker free manner. A common practice in clearing old data is to draw a rectangle over old data then draw new. This approach is a must when characters are proportional (character widths are NOT fixed). This library intelligently paints changed text in background color before painting new text.

![header image](https://raw.github.com/KrisKasprzak/ILI9341_FlickerFreePrint/master/Images/LeftRight.jpg)

<b><h3>General code usage</b></h3> 

1. #include the library 
       <br>
#include <ILI9341_FlickerFreePrint.h>
       <br>
2. create a FlickerFreePrint object for each data to be drawn and pass in your display object proceeded with "&" and set the fore color and back color)
       <br>
ILI9341_FlickerFreePrint Data1(&YOUR DISPLAY OBJECT NAME, 0xFFFF, 0X0000);
       <br>
3. set optional right justification
       <br>
  Data1.setJustification(JUSTIFY_RIGHT);
       <br>
 if you need to restore left justification, call
       <br>
 Data1.setJustification(JUSTIFY_LEFT);
       <br>
3. Print the data similar to the Print object except call print on the create flicker free data object
       <br>
   Display.setCursor(x, y);
       <br>
  Data1.setTextColor(0xFFFF, 0X0000);
       <br>
  float j = some data;
       <br>
  Data1.print(j, 4);
       <br>
<b><h3>Tips on usage</b></h3> 

  1. This library is specific to the ILI9341_t3 driver as it uses display.measureTextWidth(...) methods. This method is specific to the ILI9341_t3 driver. The Adafruit display libraries use a completely different method Display.getTextBounds(...). Adapting this library to accommodate Adafruit_GFX calls is simple just replace 6 or sp calls.
  the driver supports getCursorX() methods
  3. this library will not paint correctly if a background gradient is used
  4. this library can work with int, float, char, and other data types
  5. this library has no capability to print DEX, HEX or Println() functions (use sprintf and pass a char to the lib)
  6. this libary was not tested with LCD (20x4 type)
  
  <br>
<br>

