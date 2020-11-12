#include <FastLED.h>
#define LED_PIN     7
CRGB leds[471];

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int button = 2;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, 471);
  FastLED.setBrightness(64);
  lcd.begin(16, 2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light
  //lcd.backlight();// To Power OFF the back light
  pinMode(button, INPUT);

  int random;
}
void loop() {

/*
  int axz[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int bxz[] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
  int cxz[] = {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54};
  int dxz[] = {55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91};
  int exz[] = {92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138};
  int fxz[] = {139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166};
  int gxz[] = {167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198};
  int hxz[] = {199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234};

  int ayu[] = {235, 236, 237, 238, 239};
  int byu[] = {240, 241, 242, 243, 244, 245, 246, 247, 248};
  int cyu[] = {249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262};
  int dyu[] = {263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280};
  int eyu[] = {281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304};
  int fyu[] = {305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318};
  int gyu[] = {319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334};
  int hyu[] = {335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352};

  int ayd[] = {353, 354, 355, 356, 357};
  int byd[] = {358, 359, 360, 361, 362, 363, 364, 365, 366};
  int cyd[] = {367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380};
  int dyd[] = {381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398};
  int eyd[] = {399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
  int fyd[] = {423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436};
  int gyd[] = {437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452};
  int hyd[] = {453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470};
  */

  byte proton = 0;
  byte function = 0;
  byte n = 0;
  byte l = 0;
  byte ns[12];
  byte axis = 0;
  byte e = -1;
  
  for (uint16_t i = 0; i <=  471 ; i++)
    {
      leds[471] = CRGB(0, 0, 0);
    }
   FastLED.show();
    
  while (digitalRead(button) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Enter the # of ");
    lcd.setCursor(0, 1);
    lcd.print("Proton:         ");
    sensorValue = analogRead(sensorPin) / 93.5 + 1.5;
    lcd.setCursor(9, 1);
    lcd.print(sensorValue);
    if (sensorValue < 10)
    {
      lcd.setCursor(10, 1);
      lcd.print(" ");
    }
  }
  proton = sensorValue;
  delay(500);


  while (digitalRead(button) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Choose Function");
    lcd.setCursor(0, 1);
    lcd.print("W/P:            ");
    sensorValue = analogRead(sensorPin) / 512 + 1;
    if (sensorValue <= 1)
    {
      lcd.setCursor(5, 1);
      lcd.print("Wave    ");
    }
    if (sensorValue >= 2)
    {
      lcd.setCursor(5, 1);
      lcd.print("Particle");
    }
  }
  function = sensorValue;
  delay(500);

  if (function == 1)
  {
    while (digitalRead(button) == LOW)
    {
      lcd.setCursor(0, 0);
      lcd.print(" Which Orbital? ");
      lcd.setCursor(0, 1);
      lcd.print("n =             ");
      sensorValue = analogRead(sensorPin) / 341.1 + 1;
      lcd.setCursor(5, 1);
      lcd.print(sensorValue);
    }
    n = sensorValue;
    delay(500);

    while (digitalRead(button) == LOW)
    {
      lcd.setCursor(0, 0);
      lcd.print(" Which Part? ");
      lcd.setCursor(0, 1);
      lcd.print("n = ");
      lcd.setCursor(5, 1);
      lcd.print(n);
      lcd.setCursor(6, 1);
      lcd.print(", l =      ");
      sensorValue = analogRead(sensorPin) / 512;
      lcd.setCursor(12, 1);
      lcd.print(sensorValue);
    }
    l = sensorValue+1; //Instead of l=0, l=1 is s due to the mistake I made.
    delay(500);
  }


  
/*
  int five = CRGB(0, 0, 80);
  int ten = CRGB(10, 10, 70);
  int twenty = CRGB(10, 20, 60);
  int thirty = CRGB(10, 30, 50);
  int forty = CRGB(40, 30, 40);
  int fifty = CRGB(50, 30, 30);
  int sixty = CRGB(60, 20, 20);
  int seventy = CRGB(50, 20, 10);
  int eighty = CRGB(60, 20, 10);
  int ninety = CRGB(70, 20, 10);
  int hundred = CRGB(80, 0, 0);
  */
  
  int five = CRGB(30, 0, 100);
  int ten = CRGB(0, 0, 180);
  int twenty = CRGB(0, 110, 170);
  int thirty = CRGB(0, 170, 110);
  int forty = CRGB(0, 110, 0);
  int fifty = CRGB(70, 100, 30);
  int sixty = CRGB(110, 100, 0);
  int seventy = CRGB(100, 60, 0);
  int eighty = CRGB(100, 30, 30);
  int ninety = CRGB(80, 0, 0);
  int hundred = CRGB(50, 50, 50);

  
  if (function == 1)
    {
      for (uint16_t i = 0; i <  471 ; i++)
    {
      leds[i] = CRGB(0, 0, 0);
    }
    
    if (proton == 1)
    {
     
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i] = CRGB(0, 170, 110);
      }
      for (uint16_t i = 0; i <=  4 ; i++)
      {
        leds[i+235] = CRGB(0, 170, 110);
        leds[i+353] = CRGB(0, 170, 110);
      }
      
      for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 110, 0);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 110, 0);
        leds[i+358] = CRGB(0, 110, 0);
      }
      
      for (uint16_t i = 0; i <=  27 ; i++)
      {
        leds[i+27] = CRGB(0, 110, 170);
      }
      for (uint16_t i = 0; i <=  13 ; i++)
      {
        leds[i+249] = CRGB(0, 110, 170);
        leds[i+367] = CRGB(0, 110, 170);
      }
      
      for (uint16_t i = 0; i <=  36 ; i++)
      {
        leds[i+55] = CRGB(30, 0, 100);
      }
      for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+263] = CRGB(30, 0, 100);
        leds[i+381] = CRGB(30, 0, 100);
      }
      
      FastLED.show();
    }
  
    
    
     else if (proton == 2)
    {
     
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i] = CRGB(100, 60, 0);
      }
      for (uint16_t i = 0; i <=  4 ; i++)
      {
        leds[i+235] = CRGB(100, 60, 0);
        leds[i+353] = CRGB(100, 60, 0);
      }
      
      for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 170, 110);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 170, 110);
        leds[i+358] = CRGB(0, 170, 110);
      }
  
      FastLED.show();
    }
  
  
  
    else if (proton == 3)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(80, 0, 0);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(80, 0, 0);
          leds[i+353] = CRGB(80, 0, 0);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i+240] = CRGB(0, 0, 180);
          leds[i+358] = CRGB(0, 0, 180);
        }
        
      }
  
      else if (n == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(30, 0, 100);
          leds[i+353] = CRGB(30, 0, 100);
        }
        
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+249] = CRGB(0, 0, 180);
          leds[i+367] = CRGB(0, 0, 180);
        }
        
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+263] = CRGB(0, 110, 170);
          leds[i+381] = CRGB(0, 110, 170);
        }
  
        for (uint16_t i = 0; i <=  46 ; i++)
        {
          leds[i+92] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  23 ; i++)
        {
          leds[i+281] = CRGB(0, 110, 170);
          leds[i+399] = CRGB(0, 110, 170);
        }
    
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+139] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+305] = CRGB(0, 110, 170);
          leds[i+423] = CRGB(0, 110, 170);
        }
    
        for (uint16_t i = 0; i <=  31 ; i++)
        {
          leds[i+167] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 0; i <=  15 ; i++)
        {
          leds[i+319] = CRGB(0, 0, 180);
          leds[i+437] = CRGB(0, 0, 180);
        }
      }
      
      FastLED.show();
    }



    else if (proton == 4)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }
  
      else if (n == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(30, 0, 100);
          leds[i+353] = CRGB(30, 0, 100);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i+240] = CRGB(0, 0, 180);
          leds[i+358] = CRGB(0, 0, 180);
        }
        
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 170, 110);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+249] = CRGB(0, 170, 110);
          leds[i+367] = CRGB(0, 170, 110);
        }
        
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(0, 170, 110);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+263] = CRGB(0, 170, 110);
          leds[i+381] = CRGB(0, 170, 110);
        }
  
        for (uint16_t i = 0; i <=  46 ; i++)
        {
          leds[i+92] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  23 ; i++)
        {
          leds[i+281] = CRGB(0, 110, 170);
          leds[i+399] = CRGB(0, 110, 170);
        }
    
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+139] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+305] = CRGB(30, 0, 100);
          leds[i+423] = CRGB(30, 0, 100);
        }
    
      }
      
      FastLED.show();
    }
  
  
  
    else if (proton == 5)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(30, 0, 100);
          leds[i+353] = CRGB(30, 0, 100);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 170, 110);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 170, 110);
        leds[i+358] = CRGB(0, 170, 110);
      }
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 110, 0);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+249] = CRGB(0, 110, 0);
          leds[i+367] = CRGB(0, 110, 0);
        }
        
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+263] = CRGB(0, 110, 170);
          leds[i+381] = CRGB(0, 110, 170);
        }
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(0, 0, 180);
          leds[i+353] = CRGB(0, 0, 180);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(0, 110, 0);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(0, 110, 0);
          leds[i+358] = CRGB(0, 110, 0);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 170, 110);
        }
          
        for (uint16_t i = 5; i <=  9 ; i++)
        {
          leds[i+249] = CRGB(0, 170, 110);
          leds[i+367] = CRGB(0, 170, 110);
        }
          leds[253] = CRGB(0, 0, 180);
          leds[259] = CRGB(0, 0, 180);
          leds[252] = CRGB(30, 0, 100);
          leds[260] = CRGB(30, 0, 100);
          leds[371] = CRGB(0, 0, 180);
          leds[377] = CRGB(0, 0, 180);
          leds[370] = CRGB(30, 0, 100);
          leds[378] = CRGB(30, 0, 100);
  
         
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 5; i <=  12 ; i++)
        {
          leds[i+263] = CRGB(0, 0, 180);
          leds[i+381] = CRGB(0, 0, 180);
        }
          leds[267] = CRGB(30, 0, 100);
          leds[276] = CRGB(30, 0, 100);
          leds[385] = CRGB(30, 0, 100);
          leds[394] = CRGB(30, 0, 100);
  
        for (uint16_t i = 0; i <=  46 ; i++)
        {
          leds[i+92] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 6; i <=  17 ; i++)
        {
          leds[i+281] = CRGB(30, 0, 100);
          leds[i+399] = CRGB(30, 0, 100);
        }
    
      }
      
      FastLED.show();
    }




    else if (proton == 6)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(0, 0, 180);
          leds[i+353] = CRGB(0, 0, 180);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(70, 100, 30);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(70, 100, 30);
        leds[i+358] = CRGB(70, 100, 30);
      }
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 170, 110);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+249] = CRGB(0, 170, 110);
          leds[i+367] = CRGB(0, 170, 110);
        }
        
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+263] = CRGB(30, 0, 100);
          leds[i+381] = CRGB(30, 0, 100);
        }
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(0, 110, 170);
          leds[i+353] = CRGB(0, 110, 170);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(70, 100, 30);
          leds[i+358] = CRGB(70, 100, 30);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 110, 170);
        }
          
        for (uint16_t i = 5; i <=  9 ; i++)
        {
          leds[i+249] = CRGB(0, 110, 170);
          leds[i+367] = CRGB(0, 110, 170);
        }
          leds[253] = CRGB(30, 0, 100);
          leds[259] = CRGB(30, 0, 100);
          leds[371] = CRGB(30, 0, 100);
          leds[377] = CRGB(30, 0, 100);
  
         
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 5; i <=  12 ; i++)
        {
          leds[i+263] = CRGB(30, 0, 100);
          leds[i+381] = CRGB(30, 0, 100);
        }
          
    
      }
      
      FastLED.show();
    }




    else if (proton == 7)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(0, 110, 170);
          leds[i+353] = CRGB(0, 110, 170);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(110, 100, 0);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(110, 100, 0);
        leds[i+358] = CRGB(110, 100, 0);
      }
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+249] = CRGB(0, 110, 170);
          leds[i+367] = CRGB(0, 110, 170);
        }
  
      }
      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 170, 110);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(0, 170, 110);
          leds[i+353] = CRGB(0, 170, 110);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(70, 100, 30);
          leds[i+358] = CRGB(70, 100, 30);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(30, 0, 100);
        }
          
        for (uint16_t i = 5; i <=  9 ; i++)
        {
          leds[i+249] = CRGB(30, 0, 100);
          leds[i+367] = CRGB(30, 0, 100);
        }
          leds[253] = CRGB(30, 0, 100);
          leds[259] = CRGB(30, 0, 100);
          leds[371] = CRGB(30, 0, 100);
          leds[377] = CRGB(30, 0, 100);
  
    
      }
      
      FastLED.show();
    }




    else if (proton == 9)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 110, 0);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(0, 110, 0);
          leds[i+353] = CRGB(0, 110, 0);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(70, 100, 30);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(70, 100, 30);
        leds[i+358] = CRGB(70, 100, 30);
      }
      
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(70, 100, 30);
          leds[i+353] = CRGB(70, 100, 30);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(0, 110, 00);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(0, 110, 00);
          leds[i+358] = CRGB(0, 110, 00);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      
  
    
      }
      
      FastLED.show();
    }




    else if (proton == 8)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(0, 170, 110);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(0, 170, 110);
          leds[i+353] = CRGB(0, 170, 110);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(110, 100, 0);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(110, 100, 0);
        leds[i+358] = CRGB(110, 100, 0);
      }
      
        for (uint16_t i = 0; i <=  27 ; i++)
        {
          leds[i+27] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 0; i <=  13 ; i++)
        {
          leds[i+249] = CRGB(0, 0, 180);
          leds[i+367] = CRGB(0, 0, 180);
        }
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(70, 100, 30);
          leds[i+353] = CRGB(70, 100, 30);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(70, 100, 30);
          leds[i+358] = CRGB(70, 100, 30);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      }




      
      
      FastLED.show();
    }




    else if (proton == 10)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(70, 100, 30);
          leds[i+353] = CRGB(70, 100, 30);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 170, 110);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 170, 110);
        leds[i+358] = CRGB(0, 170, 110);
      }
      
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(100, 60, 0);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(100, 60, 0);
          leds[i+353] = CRGB(100, 60, 0);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(70, 100, 30);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(70, 100, 30);
          leds[i+358] = CRGB(70, 100, 30);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      
        
    
      }
      
      FastLED.show();
    }




    else if (proton == 11)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(110, 100, 0);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(110, 100, 0);
          leds[i+353] = CRGB(110, 100, 0);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 110, 0);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 110, 0);
        leds[i+358] = CRGB(0, 110, 0);
      }
      
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(100, 30, 0);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(100, 30, 0);
          leds[i+353] = CRGB(100, 30, 0);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(0, 110, 170);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(0, 110, 170);
          leds[i+358] = CRGB(0, 110, 170);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      }

      else if (n == 3 && l == 1)
      {
        

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(30, 0, 100);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(30, 0, 100);
        leds[i+358] = CRGB(30, 0, 100);
      }
        
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(30, 0, 100);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+263] = CRGB(30, 0, 100);
          leds[i+381] = CRGB(30, 0, 100);
        }

        for (uint16_t i = 0; i <=  46 ; i++)
    {
      leds[i+92] = CRGB(0, 110, 170);
    }
    for (uint16_t i = 0; i <=  23 ; i++)
    {
      leds[i+281] = CRGB(0, 110, 170);
      leds[i+399] = CRGB(0, 110, 170);
    }

        for (uint16_t i = 0; i <=  27 ; i++)
    {
      leds[i+139] = CRGB(0, 110, 170);
    }
    for (uint16_t i = 0; i <=  13 ; i++)
    {
      leds[i+305] = CRGB(0, 110, 170);
      leds[i+423] = CRGB(0, 110, 170);
    }

      for (uint16_t i = 0; i <=  31 ; i++)
    {
      leds[i+167] = CRGB(0, 110, 170);
    }
    for (uint16_t i = 0; i <=  15 ; i++)
    {
      leds[i+319] = CRGB(0, 110, 170);
      leds[i+437] = CRGB(0, 110, 170);
    }

      for (uint16_t i = 0; i <=  35 ; i++)
    {
      leds[i+199] = CRGB(0, 110, 170);
    }
    for (uint16_t i = 0; i <=  17 ; i++)
    {
      leds[i+335] = CRGB(0, 110, 170);
      leds[i+453] = CRGB(0, 110, 170);
    }

  
      }
      
      FastLED.show();
    }




    else if (proton == 12)
    {
      if (n == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(50, 50, 50);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(50, 50, 50);
          leds[i+353] = CRGB(50, 50, 50);
        }
        
      }


      else if (n == 2 && l == 1)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(100, 60, 0);
        }
        for (uint16_t i = 0; i <=  4 ; i++)
        {
          leds[i+235] = CRGB(100, 60, 0);
          leds[i+353] = CRGB(100, 60, 0);
        }

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 170, 110);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 170, 110);
        leds[i+358] = CRGB(0, 170, 110);
      }
      
  
      }

      
      else if (n == 2 && l == 2)
      {
        
        for (uint16_t i = 0; i <=  8 ; i++)
        {
          leds[i] = CRGB(80, 0, 0);
        }
        for (uint16_t i = 1; i <=  3 ; i++)
        {
          leds[i+235] = CRGB(80, 0, 0);
          leds[i+353] = CRGB(80, 0, 0);
        }
  
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+9] = CRGB(0, 0, 180);
        }
        for (uint16_t i = 3; i <=  5 ; i++)
        {
          leds[i+240] = CRGB(0, 0, 180);
          leds[i+358] = CRGB(0, 0, 180);
        }
          leds[242] = CRGB(30, 0, 100);
          leds[246] = CRGB(30, 0, 100);
          leds[360] = CRGB(30, 0, 100);
          leds[364] = CRGB(30, 0, 100);
        
      }

      else if (n == 3 && l == 1)
      {
        

        for (uint16_t i = 0; i <=  17 ; i++)
      {
        leds[i+9] = CRGB(0, 0, 180);
      }
      for (uint16_t i = 0; i <=  8 ; i++)
      {
        leds[i+240] = CRGB(0, 0, 180);
        leds[i+358] = CRGB(0, 0, 180);
      }

      for (uint16_t i = 0; i <=  27 ; i++)
      {
        leds[i+27] = CRGB(30, 0, 180);
      }
      for (uint16_t i = 0; i <=  13 ; i++)
      {
        leds[i+249] = CRGB(30, 0, 180);
        leds[i+367] = CRGB(30, 0, 180);
      }
        
        for (uint16_t i = 0; i <=  36 ; i++)
        {
          leds[i+55] = CRGB(0, 170, 110);
        }
        for (uint16_t i = 0; i <=  17 ; i++)
        {
          leds[i+263] = CRGB(0, 170, 110);
          leds[i+381] = CRGB(0, 170, 110);
        }

        for (uint16_t i = 0; i <=  46 ; i++)
    {
      leds[i+92] = CRGB(0, 170, 110);
    }
    for (uint16_t i = 0; i <=  23 ; i++)
    {
      leds[i+281] = CRGB(0, 170, 110);
      leds[i+399] = CRGB(0, 170, 110);
    }

        for (uint16_t i = 0; i <=  27 ; i++)
    {
      leds[i+139] = CRGB(0, 110, 170);
    }
    for (uint16_t i = 0; i <=  13 ; i++)
    {
      leds[i+305] = CRGB(0, 110, 170);
      leds[i+423] = CRGB(0, 110, 170);
    }

      for (uint16_t i = 0; i <=  31 ; i++)
    {
      leds[i+167] = CRGB(30, 0, 180);
    }
    for (uint16_t i = 0; i <=  15 ; i++)
    {
      leds[i+319] = CRGB(30, 0, 180);
      leds[i+437] = CRGB(30, 0, 180);
    }

  
      }
      
      FastLED.show();
    }
    }





  else if(function==2)
  {
    while (true)
    {
      for (uint16_t i = 0; i <  471 ; i++)
    {
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    delay(200);
    for (int i = 0; i < proton; i++)
      {
        ns[i] = random(1, 101);
        axis = random(1,5);




        if(proton==1)
        {
          if(i<=1)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=32)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32 && ns[i]<=32+44)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>32+44 && ns[i]<=32+44+18)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32+44+18 && ns[i]<=32+44+18+6)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28] = CRGB(30, 0, 100);
                   
                }
                else if(leds[e+9+18+28] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
          }
          if(axis==3)
          {
            if(ns[i]<=32)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32 && ns[i]<=32+44)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32+44 && ns[i]<=32+44+18)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32+44+18 && ns[i]<=32+44+18+6)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+235] ==  CRGB(0, 0, 0))
                {
                 
                  leds[e+5+9+14+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+9+14+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          if(axis==4)
          {
            if(ns[i]<=32)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32 && ns[i]<=32+44)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32+44 && ns[i]<=32+44+18)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>32+44+18 && ns[i]<=32+44+18+6)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+14+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+9+14+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          }
        }




        else if(proton==2)
        {
          if(axis<=2)
          {
            if(ns[i]<=66)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  if(i<=1)
                  {
                    leds[e] = CRGB(30, 0, 100);
                  }
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>66 && ns[i]<=66+34)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  if(i<=1)
                  {
                    leds[e+9] = CRGB(30, 0, 100);
                  }
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
          if(axis==3)
          {
            if(ns[i]<=66)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  if(i<=1)
              {
                  leds[e+235] = CRGB(30, 0, 100);
              }
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>66 && ns[i]<=66+34)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  if(i<=1)
              {
                  leds[e+5+235] = CRGB(30, 0, 100);
              }
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
          if(axis==4)
          {
            if(ns[i]<=66)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  if(i<=1)
              {
                  leds[e+353] = CRGB(30, 0, 100);
              }
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>66 && ns[i]<=66+34)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  if(i<=1)
              {
                  leds[e+5+353] = CRGB(30, 0, 100);
              }
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
        }




        else if(proton==3)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=90)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>90 && ns[i]<=90+10)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
          if(axis==3)
          {
            if(ns[i]<=90)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>90 && ns[i]<=90+10)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
          if(axis==4)
          {
            if(ns[i]<=90)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>90 && ns[i]<=90+10)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=5)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+1)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>5+1 && ns[i]<=5+1+10)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+1+10 && ns[i]<=5+1+10+22)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              else if(ns[i]>5+1+10+22 && ns[i]<=5+1+10+22+23+22)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28+37] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28+37] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28+37] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              else if(ns[i]>5+1+10+22+23+22 && ns[i]<=5+1+10+22+23+22+17)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28+37+47] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28+37+47] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28+37+47] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
          }
          if(axis==3)
          {
            if(ns[i]<=5)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+1)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+1 && ns[i]<=5+1+10)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+1+10 && ns[i]<=5+1+10+84)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+235] ==  CRGB(0, 0, 0))
                {
                 
                  leds[e+5+9+14+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          if(axis==4)
          {
            if(ns[i]<=5)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+1)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+1 && ns[i]<=5+1+10)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+1+10 && ns[i]<=5+1+10+84)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+14+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          }
        }





        else if(proton==4)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=5)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+10)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>5+10 && ns[i]<=5+10+34)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+10+34 && ns[i]<=5+10+34+29)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              else if(ns[i]>5+10+34+29 && ns[i]<=5+10+34+29+22)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28+37] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28+37] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28+37] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
          }
          if(axis==3)
          {
            if(ns[i]<=5)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+10)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+10 && ns[i]<=5+10+34)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+10+34 && ns[i]<=5+10+34+51)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+235] ==  CRGB(0, 0, 0))
                {
                 
                  leds[e+5+9+14+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          if(axis==4)
          {
            if(ns[i]<=5)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+10)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+10 && ns[i]<=5+10+34)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+10+34 && ns[i]<=5+10+34+51)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+14+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          }
        }




        else if(proton==5)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=5)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+32)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>5+32 && ns[i]<=5+32+41)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+32+41 && ns[i]<=5+32+41+22)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=5)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+32)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+32 && ns[i]<=5+32+41)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+32+41 && ns[i]<=5+32+41+22)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+235] ==  CRGB(0, 0, 0))
                {
                 
                  leds[e+5+9+14+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          if(axis==4)
          {
            if(ns[i]<=5)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5 && ns[i]<=5+32)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+32 && ns[i]<=5+32+41)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+32+41 && ns[i]<=5+32+41+22)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+14+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          }


          else if(i>3 && i<=9)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=10)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10 && ns[i]<=10+43)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>10+43 && ns[i]<=10+43+32)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10+43+32 && ns[i]<=10+43+32+15)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28] = CRGB(0, 110, 0);
                   
                }
                else if(leds[e+9+18+28] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=10)
            {
              e = random(1,4);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10 && ns[i]<=10+43)
            {
              e = random(2,7);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10+43 && ns[i]<=10+43+32)
            {
              e = random(3,11);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10+43+32 && ns[i]<=10+43+32+15)
            {
              e = random(4,14);
              
                if(leds[e+5+9+14+235] ==  CRGB(0, 0, 0))
                {
                 
                  leds[e+5+9+14+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+14+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          if(axis==4)
          {
            if(ns[i]<=10)
            {
              e = random(1,4);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10 && ns[i]<=10+43)
            {
              e = random(2,7);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>10+43 && ns[i]<=10+43+32)
            {
              e = random(3,11);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>5+43+32 && ns[i]<=5+43+32+15)
            {
              e = random(4,14);
              
                if(leds[e+5+9+14+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+14+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+14+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          }
        }




        else if(proton==6)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=9)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9 && ns[i]<=9+52)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>9+52 && ns[i]<=9+52+32)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9+52+32 && ns[i]<=9+52+32+7)
            {
              e = random(0,37);
              
                if(leds[e+9+18+28] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9+18+28] = CRGB(0, 0, 180);
                   
                }
                else if(leds[e+9+18+28] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=9)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9 && ns[i]<=9+52)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9+52 && ns[i]<=9+52+32)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9+52+32 && ns[i]<=9+52+32+7)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+235] ==  CRGB(0, 0, 0))
                {
                 
                  leds[e+5+9+14+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          if(axis==4)
          {
            if(ns[i]<=9)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9 && ns[i]<=9+52)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9+52 && ns[i]<=9+52+42)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>9+52+32  && ns[i]<=9+52+32+7)
            {
              e = random(0,18);
              
                if(leds[e+5+9+14+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+14+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+14+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            }
          }


          else if(i>3 && i<=9)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=21)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>21 && ns[i]<=21+54)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>21+54 && ns[i]<=21+54+25)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=21)
            {
              e = random(1,4);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>21 && ns[i]<=21+54)
            {
              e = random(2,7);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>21+54 && ns[i]<=21+54+25)
            {
              e = random(3,11);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          if(axis==4)
          {
            if(ns[i]<=21)
            {
              e = random(1,4);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>21 && ns[i]<=21+54)
            {
              e = random(2,7);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>21+54 && ns[i]<=21+54+25)
            {
              e = random(3,11);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          }
        }




        else if(proton==7)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=15)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>15 && ns[i]<=15+63)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>15+63 && ns[i]<=15+63+22)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=15)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>15 && ns[i]<=15+63)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>15+63 && ns[i]<=15+63+22)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          if(axis==4)
          {
            if(ns[i]<=15)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>15 && ns[i]<=15+63)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>15+63 && ns[i]<=15+63+22)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          }


          else if(i>3 && i<=9)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=34)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>34 && ns[i]<=34+54)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>34+54 && ns[i]<=34+54+12)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=34)
            {
              e = random(1,4);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>34 && ns[i]<=34+54)
            {
              e = random(2,7);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>34+54 && ns[i]<=34+54+12)
            {
              e = random(3,11);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          if(axis==4)
          {
            if(ns[i]<=34)
            {
              e = random(1,4);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>34 && ns[i]<=34+54)
            {
              e = random(2,7);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>34+54 && ns[i]<=34+54+12)
            {
              e = random(3,11);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          }
        }




        else if(proton==8)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=26)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>26 && ns[i]<=26+64)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            else if(ns[i]>26+64 && ns[i]<=26+64+10)
            {
              e = random(0,28);
              
                if(leds[e+9+18] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+9+18] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9+18] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=26)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>26 && ns[i]<=26+64)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>26+64 && ns[i]<=26+64+10)
            {
              e = random(0,14);
              
                if(leds[e+5+9+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          if(axis==4)
          {
            if(ns[i]<=26)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>26 && ns[i]<=26+64)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>26+64 && ns[i]<=26+64+10)
            {
              e = random(0,14);
              
                if(leds[e+5+9+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+9+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+9+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            }
          }


          else if(i>3 && i<=9)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=46)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>46 && ns[i]<=46+54)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
          }
          if(axis==3)
          {
            if(ns[i]<=46)
            {
              e = random(1,4);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>46 && ns[i]<=46+54)
            {
              e = random(2,7);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          if(axis==4)
          {
            if(ns[i]<=46)
            {
              e = random(1,4);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>46 && ns[i]<=46+54)
            {
              e = random(2,7);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          }
        }







        else if(proton==9)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=38)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>38 && ns[i]<=38+62)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            
            
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=38)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>38 && ns[i]<=38+62)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          if(axis==4)
          {
            if(ns[i]<=38)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>38 && ns[i]<=38+62)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          }


          else if(i>3 && i<=9)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=58)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>58 && ns[i]<=58+42)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
          }
          if(axis==3)
          {
            if(ns[i]<=58)
            {
              e = random(1,4);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>58 && ns[i]<=58+42)
            {
              e = random(2,7);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          if(axis==4)
          {
            if(ns[i]<=58)
            {
              e = random(1,4);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>58 && ns[i]<=58+42)
            {
              e = random(2,7);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          }
        }




        else if(proton==10)
        {
          if(i<=1)
            {
              
            if(axis<=2)
            {
            
                  
            if(ns[i]<=100)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(30, 0, 100);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==3)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
          }
          if(axis==4)
          {
            if(ns[i]<=100)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(30, 0, 100);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
          }
            
          }


          else if(i>1 && i<=3)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=49)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>49 && ns[i]<=49+51)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 0, 180);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }

            
            
              
              
          }
          if(axis==3)
          {
            if(ns[i]<=49)
            {
              e = random(0,5);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>49 && ns[i]<=49+51)
            {
              e = random(0,9);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          if(axis==4)
          {
            if(ns[i]<=49)
            {
              e = random(0,5);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>49 && ns[i]<=49+51)
            {
              e = random(0,9);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 0, 180);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          }


          else if(i>3 && i<=9)
          {
                  
          if(axis<=2)
          {
            if(ns[i]<=68)
            {
              e = random(0,9);
              
                if(leds[e] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>68 && ns[i]<=68+32)
            {
              e = random(0,18);
              
                if(leds[e+9] ==  CRGB(0, 0, 0))
                {
                  
                    leds[e+9] = CRGB(0, 110, 0);
                  
                }
                else if(leds[e+9] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
              
          }
          if(axis==3)
          {
            if(ns[i]<=68)
            {
              e = random(1,4);
              
                if(leds[e+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>68 && ns[i]<=68+51)
            {
              e = random(2,7);
              
                if(leds[e+5+235] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+235] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+235] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          if(axis==4)
          {
            if(ns[i]<=58)
            {
              e = random(1,4);
              
                if(leds[e+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            else if(ns[i]>68 && ns[i]<=68+51)
            {
              e = random(2,7);
              
                if(leds[e+5+353] ==  CRGB(0, 0, 0))
                {
                  
                  leds[e+5+353] = CRGB(0, 110, 0);
              
                }
                else if(leds[e+5+353] != CRGB(0, 0, 0))
                {
                  i = i-1;
                }
              }
            
            
            }
          }
        }
        
      }
    FastLED.show();
    delay(5000);
    }
  }
/*

if (function == 2)
  {
    for (uint16_t i = 0; i <  471 ; i++)
    {
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    while (true)
    {
      for (int i = 0; i < proton; i++)
      {
        np[i] = random(1, 100);
        int e[proton];
        /*for(int i=0;i<proton;i++)
          {
          e[i] = random(1,100)
          for(i
          for(int q=0;q<proton;q++)
          {
            if(e[q]==e[i])
            {
              e[i] = random(1,100)
            }
          }
          }*/
      /*}
      if (proton == 1)
      {
        if (np[0] <= 33)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            axz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 74)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            bxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 94)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            cxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 100)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            dxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyd[e] = CRGB(80, 0, 0);
          }
        }
      }

      if (proton == 2)
      {
        if (np[0] <= 33)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            axz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 74)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            bxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 94)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            cxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 100)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            dxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyd[e] = CRGB(80, 0, 0);
          }
        }
      }


    }
  }

  if (proton == 3)
  {
    if (n == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(70, 20, 10);
        ayu[i] = CRGB(70, 20, 10);
        ayd[i] = CRGB(70, 20, 10);
      }
      for (uint16_t i = 0; i <  8 ; i++)
      {
        bxz[i] = CRGB(10, 10, 70);
        byu[i] = CRGB(10, 10, 70);
        byd[i] = CRGB(10, 10, 70);
      }
    }
    if (n == 2 && l == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(0, 0, 80);
        ayu[i] = CRGB(0, 0, 80);
        ayd[i] = CRGB(0, 0, 80);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        cxz[i] = CRGB(10, 10, 70);
        cyu[i] = CRGB(10, 10, 70);
        cyd[i] = CRGB(10, 10, 70);
      }
      for (uint16_t i = 0; i <  36 ; i++)
      {
        dxz[i] = CRGB(10, 20, 60);
        dyu[i] = CRGB(10, 20, 60);
        dyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  46 ; i++)
      {
        exz[i] = CRGB(10, 20, 60);
        eyu[i] = CRGB(10, 20, 60);
        eyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        fxz[i] = CRGB(10, 20, 60);
        fyu[i] = CRGB(10, 20, 60);
        fyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  31 ; i++)
      {
        gxz[i] = CRGB(10, 10, 70);
        gyu[i] = CRGB(10, 10, 70);
        gyd[i] = CRGB(10, 10, 70);
      }
    }
    FastLED.show();
  }



  if (proton == 4)
  {
    if (n == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(80, 0, 0);
        ayu[i] = CRGB(80, 0, 0);
        ayd[i] = CRGB(80, 0, 0);
      }
    }
    if (n == 2 && l == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(0, 0, 80);
        ayu[i] = CRGB(0, 0, 80);
        ayd[i] = CRGB(0, 0, 80);
      }
      for (uint16_t i = 0; i <  17 ; i++)
      {
        bxz[i] = CRGB(10, 10, 70);
        byu[i] = CRGB(10, 10, 70);
        byd[i] = CRGB(10, 10, 70);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        cxz[i] = CRGB(10, 30, 50);
        cyu[i] = CRGB(10, 30, 50);
        cyd[i] = CRGB(10, 30, 50);
      }
      for (uint16_t i = 0; i <  36 ; i++)
      {
        dxz[i] = CRGB(10, 30, 50);
        dyu[i] = CRGB(10, 30, 50);
        dyd[i] = CRGB(10, 30, 50);
      }
      for (uint16_t i = 0; i <  46 ; i++)
      {
        exz[i] = CRGB(10, 20, 60);
        eyu[i] = CRGB(10, 20, 60);
        eyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        fxz[i] = CRGB(0, 0, 80);
        fyu[i] = CRGB(0, 0, 80);
        fyd[i] = CRGB(0, 0, 80);
      }
    }
    FastLED.show();
  }



  if (proton == 5)
  {
    if (n == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(80, 0, 0);
        ayu[i] = CRGB(80, 0, 0);
        ayd[i] = CRGB(80, 0, 0);
      }
      if (n == 2 && l == 1)
      {
        for (uint16_t i = 0; i <  8 ; i++)
        {
          axz[i] = CRGB(60, 20, 20);
          ayu[i] = CRGB(60, 20, 20);
          ayd[i] = CRGB(60, 20, 20);
        }
      }
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(40, 30, 40);
        ayu[i] = CRGB(40, 30, 40);
        ayd[i] = CRGB(40, 30, 40);
      }
    }
    FastLED.show();
  }



  if (proton == 6)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 7)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 8)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 9)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 10)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 11)
  {
    if (n == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(80, 0, 0);
        ayu[i] = CRGB(80, 0, 0);
        ayd[i] = CRGB(80, 0, 0);
      }
      if (n == 2 && l == 1)
      {
        for (uint16_t i = 0; i <  8 ; i++)
        {
          axz[i] = CRGB(60, 20, 20);
          ayu[i] = CRGB(60, 20, 20);
          ayd[i] = CRGB(60, 20, 20);
        }
      }
      for (uint16_t i = 0; i <  17 ; i++)
      {
        bxz[i] = CRGB(40, 30, 40);
        byu[i] = CRGB(40, 30, 40);
        byd[i] = CRGB(40, 30, 40);
      }
    }
    if (n == 2 && l == 2)
    {
      for (uint16_t i = 0; i <  17 ; i++)
      {
        bxz[i] = CRGB(10, 10, 70);
        byu[i] = CRGB(10, 10, 70);
        byd[i] = CRGB(10, 10, 70);
      }
      for (uint16_t i = 0; i <  36 ; i++)
      {
        dxz[i] = CRGB(0, 0, 80);
        dyu[i] = CRGB(0, 0, 80);
        dyd[i] = CRGB(0, 0, 80);
      }
      for (uint16_t i = 0; i <  46 ; i++)
      {
        exz[i] = CRGB(10, 20, 60);
        eyu[i] = CRGB(10, 20, 60);
        eyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        fxz[i] = CRGB(10, 30, 50);
        fyu[i] = CRGB(10, 30, 50);
        fyd[i] = CRGB(10, 30, 50);
      }
      for (uint16_t i = 0; i <  31 ; i++)
      {
        gxz[i] = CRGB(10, 20, 60);
        gyu[i] = CRGB(10, 20, 60);
        gyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  35 ; i++)
      {
        hxz[i] = CRGB(10, 10, 70);
        hyu[i] = CRGB(10, 10, 70);
        hyd[i] = CRGB(10, 10, 70);
      }

    }
    FastLED.show();
  }



  if (proton == 12)
  {
    if (n == 1)
    {
      for (uint16_t i = 0; i <  8 ; i++)
      {
        axz[i] = CRGB(80, 0, 0);
        ayu[i] = CRGB(80, 0, 0);
        ayd[i] = CRGB(80, 0, 0);
      }
      if (n == 2 && l == 1)
      {
        for (uint16_t i = 0; i <  8 ; i++)
        {
          axz[i] = CRGB(50, 20, 10);
          ayu[i] = CRGB(50, 20, 10);
          ayd[i] = CRGB(50, 20, 10);
        }
      }
      for (uint16_t i = 0; i <  17 ; i++)
      {
        bxz[i] = CRGB(10, 30, 50);
        byu[i] = CRGB(10, 30, 50);
        byd[i] = CRGB(10, 30, 50);
      }
    }
    if (n == 2 && l == 2)
    {
      for (uint16_t i = 0; i <  17 ; i++)
      {
        bxz[i] = CRGB(10, 10, 70);
        byu[i] = CRGB(10, 10, 70);
        byd[i] = CRGB(10, 10, 70);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        cxz[i] = CRGB(0, 0, 80);
        cyu[i] = CRGB(0, 0, 80);
        cyd[i] = CRGB(0, 0, 80);
      }
      for (uint16_t i = 0; i <  36 ; i++)
      {
        dxz[i] = CRGB(10, 30, 50);
        dyu[i] = CRGB(10, 30, 50);
        dyd[i] = CRGB(10, 30, 50);
      }
      for (uint16_t i = 0; i <  46 ; i++)
      {
        exz[i] = CRGB(10, 30, 50);
        eyu[i] = CRGB(10, 30, 50);
        eyd[i] = CRGB(10, 30, 50);
      }
      for (uint16_t i = 0; i <  27 ; i++)
      {
        fxz[i] = CRGB(10, 20, 60);
        fyu[i] = CRGB(10, 20, 60);
        fyd[i] = CRGB(10, 20, 60);
      }
      for (uint16_t i = 0; i <  31 ; i++)
      {
        gxz[i] = CRGB(0, 0, 80);
        gyu[i] = CRGB(0, 0, 80);
        gyd[i] = CRGB(0, 0, 80);
      }


    }
    FastLED.show();
  }



  if (proton == 13)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 14)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 15)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 16)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 17)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }



  if (proton == 18)
  {
    for (uint16_t i = 0; i <  8 ; i++)
    {
      axz[i] = hundred;
      ayu[i] = hundred;
      ayd[i] = hundred;
    }
    FastLED.show();
  }


  if (function == 2)
  {
    for (uint16_t i = 0; i <  471 ; i++)
    {
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    while (true)
    {
      for (int i = 0; i < proton; i++)
      {
        np[i] = random(1, 100);
        int e[proton];
        /*for(int i=0;i<proton;i++)
          {
          e[i] = random(1,100)
          for(i
          for(int q=0;q<proton;q++)
          {
            if(e[q]==e[i])
            {
              e[i] = random(1,100)
            }
          }
          }*/
      /*}
      if (proton == 1)
      {
        if (np[0] <= 33)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            axz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 74)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            bxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 94)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            cxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 100)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            dxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyd[e] = CRGB(80, 0, 0);
          }
        }
      }

      if (proton == 2)
      {
        if (np[0] <= 33)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            axz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            ayd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 74)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            bxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            byd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 94)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            cxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            cyd[e] = CRGB(80, 0, 0);
          }
        }
        if (np[0] <= 100)
        {
          int o = random(1, 3);
          if (o == 1)
          {
            int e = random(0, 8);
            dxz[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyu[e] = CRGB(80, 0, 0);
          }
          if (o == 2)
          {
            int e = random(0, 4);
            dyd[e] = CRGB(80, 0, 0);
          }
        }
      }


    }
  }
  */
}
