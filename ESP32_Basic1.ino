#include <WiFi.h>
#include <BluetoothSerial.h>

// ตั้งค่าชื่อและรหัสผ่านสำหรับ WiFi
const char* ssid = "GreenPow.co";
const char* password = "GreenPow.co";

// ตั้งค่าชื่อสำหรับ Bluetooth
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("GreenPow.co"); // ชื่อของอุปกรณ์ Bluetooth

  Serial2.begin(115200, SERIAL_8N1, 16, 17); // RX, TX ของ ESP32
  Serial.println("ESP32 is ready");
}

void loop() {
  // ตรวจสอบข้อความที่รับจาก Arduino
  if (Serial2.available()) {
    String msg = Serial2.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(msg);

    // ส่งข้อความกลับไปยัง Arduino
    Serial2.println("Hello from ESP32");
    ///Serial.println("Sent: Hello from ESP32");
  }

  delay(1000); // รอ 1 วินาที
}
