///////////////////////////////////////////////////////// ALIEN EFFECT //////////////////////////////////////////////

// Global Brightness
int bright = 0;
int bright2 = 0;


// Global Mode
int mode2;

// Global Counter
int counter4;

// Pre-defined Brightness 
int lux4[] = {30,60,100,150,200,255};


 // Alien Effect Version #1 
 void AlienV1() {

  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 50;
    FastLED.clear();
  }

  // Declare Shapes
  const uint8_t AL[] = {0, 4, 28, 27, 26, 25, 24, 31, 33, 35, 55, 54, 53,
  60};
  
  const uint8_t RightG[] = { 10, 11, 12, 20, 14,
  37, 39, 41, 43, 50, 49, 45, 44, 63, 64, 66, 67};

  const uint8_t Right[] = {9, 13, 19, 18, 17, 16, 15, 38, 40, 42, 48, 47, 46, 65};

  const uint8_t Eyes7[] = {32, 34};

  // Increase Speed Here (i.e Mode+=5)
  mode2+=abs(sin8(mode2*15));


  // Alternate (Note: this can be improved alot)
  if (mode2%20 < 10) { bright = 255, bright2 = 0;}
  else if (mode2%20 > 10) { bright2 = 255, bright = 0;}
  
  // Draw & Loop through the Shapes
  for (int z = 0; z < 14; z++) {
       leds[AL[z]] = CHSV(cycleHue, 255, bright); }

       // Nifty trick
       if (counter4 % 200 > 100) {fadeAll(counter4+1);}

   for (int a = 0; a < 17; a++) {
       leds[RightG[a]] = CHSV(100, 200+sin8(counter4*15%255), sin8(a*counter4 / 40 %255)); }

       for (int y = 0; y < 14; y++) {
           leds[Right[y]] = CHSV(0, 255, bright2); }

          for (int b = 0; b < 2; b++) {
               leds[Eyes7[b]] = CHSV(0, 255, lux4[sin8(counter4*5) %6]); }

          // Increment Counter
          counter4++;
       
 }
 
 /////////////////////////////////////////////////////////// END OF CODE ///////////////////////////////////////////////////


/////////////////////////////////////////////////////// -- PSYCHIC ENERGY -- ///////////////////////////////////////////////
//////                                   SERIOUSLY KIDS DO NOT! I REPEAT DO NOT! TRY THIS AT HOME :)            ////////////
////////////////////////////////////////////////////////// NO SERIOUSLY! ///////////////////////////////////////////////////

// Globals
byte PSY = 0;
int counter2 = 0;


void PSY1() {

  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 5;
    PSY = 0;
  }

  // Just for good measure
  if (counter2 > 500) counter2 = 0;

  // Draw one frame of the animation into the LED array
  for (byte x = 0; x < kMatrixWidth; x++) {
    int brightness = abs(x * (256 / kMatrixWidth) - quadwave8(PSY) * (20 / (PSY) + 127)) * 3;
    
       if (brightness > 255) brightness = 255;
    
         CRGB riderColor = CHSV(sin8(counter2*50), 255, qmul8(brightness, --counter2));
         
    for (byte y = 0; y < kMatrixHeight; y++) {
      leds[XY(x, y)] = riderColor;
    }
  }

  PSY++; 
  counter2++;

}

 /////////////////////////////////////////////////////////// END OF CODE ///////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Slant Bars Mod :)

byte slantPos4 = 0;
int counter4=0;
void slantBars_mod4() {

  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 5;
  }


if (counter4 > 300) counter4=0;

 if (counter4 > 100 && counter4 < 150) {
  effectDelay = effectDelay + 1 % 150;
 }

 if (counter4 > 150 && counter4 < 225) {
 effectDelay = effectDelay + 3 % 300;
 }
 else {
  effectDelay = 5 + counter4 % 30;
 }
  for (byte x = 0; x < kMatrixWidth; x++) {
    for (byte y = 0; y < kMatrixHeight; y++) {
      leds[XY(x, y)] = CHSV(cycleHue, 255, cubicwave8(x * 10 + y * 10 + slantPos4));
    }
  }

  slantPos4 -= 8;
  counter4++;

}


void Flashing() {

  // startup tasks
  if (effectInit == false) {
    effectInit = true;
    effectDelay = 50;
    FastLED.clear();
  }
  
  const uint8_t Left[] = {0, 1, 2, 3, 4, 29, 28, 27, 26, 25, 24, 23, 30,
  31, 32, 33, 34, 35, 36, 57, 56, 55, 54, 53, 52, 51, 58, 59, 60, 61, 62};
  
  const uint8_t Right[] = {9, 10, 11, 12, 13, 20, 19, 18, 17, 16, 15, 14,
  37, 38, 39, 40, 41, 42, 43, 50, 49, 48, 47, 46, 45, 44, 63, 64, 65, 66, 67};

  // Increase Speed Here (i.e Mode+=5)
  mode+=5;

  if (mode%20 < 10) { bright = 255, bright2 = 0;}
  else if (mode%20 > 10) { bright2 = 255, bright = 0;}
  
  //Alternate
for (int z = 0; z < 31; z++) {
       leds[Left[z]] = CHSV(0, 255, bright); }


     for (int y = 0; y < 31; y++) {
           leds[Right[y]] = CHSV(150, 255, bright2); }
       
 }


