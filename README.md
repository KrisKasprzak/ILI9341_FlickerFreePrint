<b><h2><center>ILI9341 FlickerFreePrint Library</center></h1></b>

This library will let programmers paint data to TFT LCD's using a Teensy and the ILI9341_t3 driver in a flicker free manner. A common practice in clearing old data is to draw a rectangle over old data then draw new, this approach is a must when charactgers that are porportional (character widths are NOT fixed). This library intelligently paints changed text in background color before painting new text.

<b><h3>
WARNING
</b><br>
This library is intended to be used with a wide variety of MCU's. A special library (dtostrf.h) is needed for some MCU's and is delivered with certian MCU's that require it, but not all. If you get a compile error "no such file or directory: dtostrf.h", uncomment this line in FlickerFreePrint.h (around line 50 or so) so the compiler can include it. I have this commented out as few MCU's need it.
// #include <avr/dtostrf.h>

  </b></h3>

<b><h3>General code usage</b></h3> 

1. #include the library 
       <br>
#include <ILI9341_FlickerFreePrint.h>

2. create a FlickerFreePaint object for each data to be drawn
(put the <object type netween the brackets>, pass in your display object and set fore color and back color)
        <br>
ILI9341_FlickerFreePrint Data1(&YOUR DISPLAY OBJECT NAME, 0xFFFF, 0X0000);

3. set optional right justification
  Data1.setJustification(JUSTIFY_RIGHT);
  // if left but needed call if setting back from right to left
  // Data1.setJustification(JUSTIFY_LEFT);

  // similar to how you draw text this lib mimics that process
  // Display.setCursor(x, y);
  // YourFlickerFreeObject.setTextColor(C_WHITE, C_BLACK);
  // YourFlickerFreeObject.print(data, <decimals>);
  

3. Print the data similar to the Print object except call print on the data object
   <br>
   Display.setCursor(x, y);
   <br>
  Data1.setTextColor(0xFFFF, 0X0000);
   <br>
  float j = some data;
        <br>
  Data1.print(j, 4);
  
<b><h3>Tips on usage</b></h3> 

  1. This library is template based so it should work with most display drivers provided
  the driver supports getCursorX() methods
  2. this linbrary will not paint correctly if a background gradient is used
  3. this library can work with int, float, char, and other data types
  4. this library has no capability to print DEX, HEX or Println() functions
  5. this libary was not tested with LCD (20x4 type)
  
  <br>
<br>

