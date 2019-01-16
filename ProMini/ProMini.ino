/*
Initializes the library and turns the motor in alternating directions.
*/
#define EN_PIN    7
#define DIR_PIN   8
//#define STEP_PIN  9
#define X_CS_PIN    9
#define Y_CS_PIN    10

#define SDI_PIN   11
#define SDO_PIN   12
#define SCK_PIN   13

bool dir = true;
bool on = true;


#include <TMC2130Stepper.h>
//TMC2130Stepper(pinEN, pinDIR, pinStep, pinCS, pinMOSI, pinMISO, pinSCK);
//TMC2130Stepper X_TMC2130 = TMC2130Stepper(EN_PIN, DIR_PIN, STEP_PIN, CS_PIN, SDI_PIN, SDO_PIN, SCK_PIN);

TMC2130Stepper X_Axis = TMC2130Stepper(X_CS_PIN);
TMC2130Stepper Y_Axis = TMC2130Stepper(Y_CS_PIN);


void configureTMC2130(){
  X_Axis.begin(); // Initiate pins and registeries
  X_Axis.SilentStepStick2130(700); // Set stepper current to 700mA
  X_Axis.hold_current(16);
  X_Axis.stealthChop(1); // Enable extremely quiet stepping
  X_Axis.chopper_mode(0);
  X_Axis.microsteps(16);
  X_Axis.interpolate(1);

  Y_Axis.begin(); // Initiate pins and registeries
  Y_Axis.SilentStepStick2130(700); // Set stepper current to 700mA
  Y_Axis.hold_current(16);
  Y_Axis.stealthChop(1); // Enable extremely quiet stepping
  Y_Axis.chopper_mode(0);
  Y_Axis.microsteps(16);
  Y_Axis.interpolate(1);
}

void printGCONF(){
  Serial.println("## GCONF ##");
  Serial.print("X-Axis: ");
  Serial.println(X_Axis.GCONF(), BIN);
  Serial.print("Y-Axis: ");
  Serial.println(Y_Axis.GCONF(), BIN);
  Serial.println("-----------");
}

void printCHOPCONF(){
  Serial.println("## CHOPCONF ##");
  Serial.print("X-Axis: ");
  Serial.println(X_Axis.CHOPCONF(), BIN);
  Serial.print("Y-Axis: ");
  Serial.println(Y_Axis.CHOPCONF(), BIN);
  Serial.println("--------------");
}

void setup() {
  Serial.begin(38400);
  configureTMC2130();
}

void loop() {
//  printGCONF();
  printCHOPCONF();
  
  delay(5000);
}
