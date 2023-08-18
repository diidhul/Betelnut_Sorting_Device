#include <HX711_ADC.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>

Servo mainServo1;

int in1 = 9;
int in2 = 8;
int ConA = 10;
const int HX711_dout = 16;
const int HX711_sck = 5;

char auth[] = "9h_AEua0xnTXdIjsPGSzVu-NaXHQ3SXt";
char ssid[] = "lektopfadhil";
char pass[] = "12345678";

BlynkTimer timer;
HX711_ADC LoadCell(HX711_dout, HX711_sck);
const int calVal_eepromAdress = 0;
unsigned long t = 0;
int pos = 0;

void setup() {
  mainServo1.attach(19);
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println("Starting...");
  Blynk.begin(auth, ssid, pass);
  LoadCell.begin();

  float calibrationValue;
  calibrationValue = -450.05;

  unsigned long stabilizingtime = 2000;
  boolean _tare = true;
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  } else {
    LoadCell.setCalFactor(calibrationValue);
    Serial.println("Startup is complete");
  }

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ConA, OUTPUT);
}

void TurnMotorA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA, 80);
}

void TurnOFFA() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(ConA, 0);
}

void TurnMotorA2() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ConA, 80);
}

void loop() {
  TurnMotorA();
  delay(160);

  TurnOFFA();
  delay(3500);

  TurnMotorA2();
  delay(160);

  TurnOFFA();
  delay(3500);

  static boolean newDataReady = 0;
  const int serialPrintInterval = 0;

  if (LoadCell.update()) newDataReady = true;

  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      Serial.print("Load_cell output val: ");
      Serial.println(i);
      Blynk.virtualWrite(V2, i);
      newDataReady = 0;
      t = millis();
    }
  }

  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }

  Blynk.run();
  timer.run();
  for (pos = 0; pos <= 0; pos += 1) {
    mainServo1.write(pos);
    delay(25);
  }
  for (pos = 180; pos >= 90; pos -= 1) {
    mainServo1.write(pos);
    delay(50);
  }
}
