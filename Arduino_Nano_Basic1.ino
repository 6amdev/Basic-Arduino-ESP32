#include <SoftwareSerial.h>

#define ESP32_TX 6  // Arduino TX
#define ESP32_RX A2  // Arduino RX
SoftwareSerial espSerial(ESP32_RX, ESP32_TX);  // RX, TX

void setup() {
  Serial.begin(115200); // Serial สำหรับการสื่อสารกับคอมพิวเตอร์
  espSerial.begin(115200); // Serial สำหรับการสื่อสารกับ ESP32

  Serial.println("Arduino is ready");
}

void loop() {
  // ส่งข้อความไปยัง ESP32
  espSerial.println("Hello from Arduino");
  ///Serial.println("Sent: Hello from Arduino");

  // ตรวจสอบข้อความที่รับจาก ESP32
  if (espSerial.available()) {
    String msg = espSerial.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(msg);
  }

  delay(1000); // รอ 1 วินาที
}
