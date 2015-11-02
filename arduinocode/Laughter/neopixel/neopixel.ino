// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!

// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

// You can also use software SPI
//Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(13, 12, 11, 10, 9);
// Or hardware SPI! In this case, only CS pins are passed in
//Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(10, 9);

void setupSensor()
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);
  
  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  
  while (!Serial); // flora & leonardo
  delay(2000);
  Serial.begin(9600);
  Serial.println("LSM raw read demo");
  
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS0 9DOF");
  Serial.println("");
  Serial.println("");
  
}

int Zinput = 0;
int stage = 0;
int TRESHOLD1 = 9500;
int TRESHOLD2 = 13000;


  
void loop() {


  

  
  lsm.read();

  Serial.print("z: "); Serial.print((int)lsm.accelData.z);       Serial.print(" ");
  Serial.println(" ");

  Zinput = (int)lsm.accelData.z;

if(Zinput > TRESHOLD2){
    stage = 2;
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.setPixelColor(1, pixels.Color(255,0,0));
    pixels.setPixelColor(2, pixels.Color(255,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware. 
  } else if ( Zinput > TRESHOLD1){
    stage = 1;
    pixels.setPixelColor(0, pixels.Color(204/2,0,0));
    pixels.setPixelColor(1, pixels.Color(230/20,0,0));
    pixels.setPixelColor(2, pixels.Color(204/2,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
  } else {   
    stage = 0;
    pixels.setPixelColor(2, pixels.Color(10,0,0));
    pixels.setPixelColor(1, pixels.Color(10,0,0));
    pixels.setPixelColor(0, pixels.Color(10,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }

  Serial.print(stage);
  Keyboard.println(stage);
  delay(750);

  if(!lsm.begin()){
    Setup();
    setupSensor();
  }
  
 Serial.print("I am still printing");     Serial.println(" ");
 
}
