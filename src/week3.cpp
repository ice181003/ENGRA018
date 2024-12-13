#include <Arduino.h>
// กำหนดพอร์ตที่ใช้สำหรับ LED
int L1 = 23;
int L2 = 19;
int L3 = 18;
int L4 = 5;
int L5 = 17;
int L6 = 16;
int L7 = 4;
int L8 = 0;

// การตั้งค่าในฟังก์ชัน setup()
void setup() {
  // ตั้งค่า LED ทุกตัวให้ทำงานในโหมด PWM
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  
  // ตั้งค่าพอร์ตของ Potentiometer
  pinMode(36, INPUT);  // Potentiometer เชื่อมต่อกับ GPIO36 (A0)
}

void loop() {
  // อ่านค่าจาก Potentiometer (0 ถึง 4095)
  int potValue = analogRead(36);
  
  // ปิด LED ทั้งหมดก่อน
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);
  digitalWrite(L8, LOW);

  // ตรวจสอบค่าจาก Potentiometer และเปิด LED ตามช่วงค่าที่กำหนด
  if (potValue >= 0 && potValue <= 500) {
    // ถ้าค่า Potentiometer อยู่ในช่วง 0-500 ให้ L1 ติด
    digitalWrite(L1, HIGH);
  }
  else if (potValue >= 501 && potValue <= 1000) {
    // ถ้าค่า Potentiometer อยู่ในช่วง 501-1000 ให้ L2 และ L3 ติด
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
  }
  else if (potValue >= 1001 && potValue <= 2000) {
    // ถ้าค่า Potentiometer อยู่ในช่วง 1001-2000 ให้ L4 และ L5 ติด
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
  }
  else if (potValue > 2000) {
    // ถ้าค่า Potentiometer อยู่ในช่วงมากกว่า 2000 ให้ L6, L7, L8 ติด
    digitalWrite(L1, HIGH);
    digitalWrite(L2, HIGH);
    digitalWrite(L3, HIGH);
    digitalWrite(L4, HIGH);
    digitalWrite(L5, HIGH);
    digitalWrite(L6, HIGH);
    digitalWrite(L7, HIGH);
    digitalWrite(L8, HIGH);
  }

  // หน่วงเวลาเพื่อให้การอ่านค่ามีความเสถียร
  delay(100);
}