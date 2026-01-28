/*
  The MIT License (MIT)
  Copyright (c) 2020 Kris Kasrpzak
  Permission is hereby granted, free of charge, to any person obtaining a copy of
  this software and associated documentation files (the "Software"), to deal in
  the Software without restriction, including without limitation the rights to
  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  the Software, and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  On a personal note, if you develop an application or product using this library 
  and make millions of dollars, I'm happy for you!
*/

/* 
  Code by Kris Kasprzak kris.kasprzak@yahoo.com
  This library is intended to be used with any display library to eliminate the need 
  to first paint a solid rectangle to fully draw numbers and letters.

  This library intelligently finds changed characters and repaints them in background 
  color before drawing new text


  notes:
  1. This library is template based so it should work with most display drivers provided
  the driver supports getCursorX() methods
  2. this library will not paint correctly if a background gradient is used
  3. this library can work with int, float, char, and other data types
  
  ver 		date 			author			comments
  1.0		1/2026			kasprzak		initial code dedicated to the ILI9341 (which includes right justification)
 
*/

#ifndef ILI9341_FLICKER_FREE_PRINT
#define ILI9341_FLICKER_FREE_PRINT

#define ILI9341_FLICKER_FREE_PRINT 1.0

#define JUSTIFY_LEFT 0
#define JUSTIFY_RIGHT 1


#if ARDUINO >= 100
  #include "Arduino.h"
  #include "Print.h"
  
#else
  #include <avr/dtostrf.h>
  #include "WProgram.h"
#endif

#ifdef __cplusplus
  #include "Arduino.h"
#endif

#define BUF_LEN 30

class ILI9341_FlickerFreePrint {

  public:

     ILI9341_FlickerFreePrint(ILI9341_t3 *disp, uint16_t ForeColor = 65535, uint16_t BackColor = 0)
    {
      d = disp;
	  fc = ForeColor;
      bc = BackColor;
    }
	
	void setJustification(uint8_t Justification = JUSTIFY_LEFT){
		tjust = JUSTIFY_RIGHT;
		if (Justification == JUSTIFY_LEFT){
			tjust = JUSTIFY_LEFT;
		}
	}

	void print(char buf[]){
		
		olen = strlen(obuf);
		len = strlen(buf);
	
		blanked = false;

		c = d->getCursorX();
		
		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;
		
	}

	void print(byte Data){

		dtostrf(Data, 0, 0, buf);

		olen = strlen(obuf);
		len = strlen(buf);

		blanked = false;
		c = d->getCursorX();


		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;
		

	}

	void print(short Data){

		dtostrf(Data, 0, 0, buf);

		olen = strlen(obuf);
		len = strlen(buf);

		blanked = false;
		c = d->getCursorX();
		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;
		

	}

	void print(int Data){

		dtostrf(Data, 0, 0, buf);

		olen = strlen(obuf);
		len = strlen(buf);

		blanked = false;
		c = d->getCursorX();

		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;

	}

	void print(unsigned int Data){

		dtostrf(Data, 0, 0, buf);

		olen = strlen(obuf);
		len = strlen(buf);
		blanked = false;
		c = d->getCursorX();

		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;
		
	}

	void print(long Data){

		dtostrf(Data, 0, 0, buf);

		olen = strlen(obuf);
		len = strlen(buf);
		blanked = false;
		c = d->getCursorX();
				if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;

	}

	void print(unsigned long Data){
		dtostrf(Data, 0, 0, buf);

		olen = strlen(obuf);
		len = strlen(buf);
		blanked = false;
		c = d->getCursorX();
				if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;

	}

	void print(float Data, int Dec = 2){

		dtostrf(Data, 0, Dec, buf);

		olen = strlen(obuf);
		len = strlen(buf);

		blanked = false;
		c = d->getCursorX();
		

		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;
		
	}
	
		void print(double Data, int Dec = 2) {

		dtostrf(Data, 0, Dec, buf);

		olen = strlen(obuf);
		len = strlen(buf);	
		blanked = false;
		c = d->getCursorX();
		
		if (tjust == JUSTIFY_RIGHT){
			DrawRJ(buf, obuf);
		}
		else {
			DrawLJ(buf, obuf);
		}
		return;

		}
	void DrawLJ(char buf[],char obuf[]) {		
	
		blanked = false;
		c = d->getCursorX();
		
		for (i = 0; i < len; i++) {
			if (buf[i] != obuf[i]) {
				c = d->getCursorX();
				if (!blanked) {
					blanked = true;
					for (j = i; j < olen; j++) {
						d->setTextColor(bc, bc);
						d->print(obuf[j]);
					}
				}
				
				d->setCursor(c, d->getCursorY());
			}
	
			d->setTextColor(fc, bc);
			d->print(buf[i]);

		}

        strcpy(obuf,buf);
		
	}
	
	void DrawRJ(char buf[], char obuf[]) {	
	
		for (i = len-1; i >= 0 ; i--) {				
			if ( (len < olen) && !blanked){	
				blanked = true;
				for (j = 0; j <= olen; j++){	
					d->setCursor(c - d->measureTextWidth(&obuf[j]), d->getCursorY());	
					d->setTextColor(bc, bc);
					d->print(obuf[j]);						
				}
			}
			
			if ( (d->measureTextWidth(&buf[i]) != d->measureTextWidth(&obuf[i])) && !blanked){	
				blanked = true;
				for (j = 0; j <= i; j++){	
					d->setCursor(c - d->measureTextWidth(&obuf[j]), d->getCursorY());	
					d->setTextColor(bc, bc);
					d->print(obuf[j]);
				}	

			}
			else if ( (buf[i] != obuf[i]) && !blanked){	
				d->setCursor(c - d->measureTextWidth(&obuf[i]), d->getCursorY());	
				d->setTextColor(bc, bc);
				d->print(obuf[i]);
				
			}
		
		
		d->setCursor(c - d->measureTextWidth(&buf[i]), d->getCursorY());
		d->setTextColor(fc, bc);
		d->print(buf[i]);
			
		}
/*		
		if ( ((buf[i] != obuf[i])   || (d->measureTextWidth(&buf[i]) != d->measureTextWidth(&obuf[i]))) && !blanked){	
				blanked = true;
				for (j = 0; j <= i; j++){	
					d->setCursor(c - d->measureTextWidth(&obuf[j]), d->getCursorY());	
					d->setTextColor(bc, bc);
					d->print(obuf[j]);
				}
			}
			
			d->setCursor(c - d->measureTextWidth(&buf[i]), d->getCursorY());
			d->setTextColor(fc, bc);
			d->print(buf[i]);
		}	
*/

		
        strcpy(obuf, buf);	
	}
		
    void setTextColor(uint16_t ForeColor , uint16_t BackColor) {
      fc = ForeColor;
	  bc = BackColor;
    }

  protected:

    ILI9341_t3	*d;
    char		obuf[BUF_LEN];
    int			c;
    uint16_t	fc;
	uint16_t	bc;
    int16_t	i;
	int16_t	j;
    char		buf[BUF_LEN];
    uint16_t    len;
	uint16_t    olen;
	bool		n = true;
	bool		blanked = false;
	uint8_t tjust = JUSTIFY_LEFT;
	
};


#endif



/////////////////////////////
