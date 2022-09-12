/*
  DỰ ÁN ĐIỀU KHIỂN ĐÈN THÔNG QUA BLYNK SERVER VÀ BLYNK MOBILE TRÊN ĐIỆN THOẠI
  Phần cứng cần thiết:
    + Mạch ESP8266
    + Dây cáp nạp code microUSB
    + Relay điều khiển
    + Bóng đèn, phích cắm, dây điện
    + Dây cắm mạch
  Cách thức hoạt động:
    + Mạch điều khiển ESP8266 có khả năng kết nối wifi tần số 2.4 GHz. Sau khi kết nối wif sẽ thực hiện kết nối đến Blynk Server.
    + Thông qua Blynk Server, có thể thiết lập trên ứng dụng Blynk Mobile để điều khiển thiết bị từ xa.
  Một số lưu ý:
    + Cần phải khởi tạo loại thiết bị trên app Blynk Mobile
    + Sau khi khởi tạo, lấy auth key trên Blynk Mobile và gán vào biến auth
    + Nhập tên và mật khẩu wifi vào biền ssid và pass
    + Trong màn hình Serial phải chọn tốc độ 115200 thay vì 9600 như trên Arduino
  Cài đặt phần cứng:
    + Chân Vin --> Chân DC+ trên Relay
    + Chân GND --> Chân DC- trên Relay
    + Chân D6 --> Chân IN trên Relay
  Cài đặt phần mềm:
    + Thư viện Blynk
    + Cài đặt addtional Board như sau: Chọn File --> Preferences. Trong phần Additional Boards Manager URLs,
    bạn paste dòng sau đây vào: http://arduino.esp8266.com/stable/package_esp8266com_index.json, sau đó chọn OK.
    + Sau đó chọn Tools --> Board: ..... --> Board Manager. Nhập ESP8266 vào ô tìm kiếm, chọn ESP8266 trong danh sách kết quả rồi nhấn Install.
    + Khi nạp code cần chọn đúng Board là NodeMCU 1.0
*/

//Khai báo thư viện
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Khai báo Blynk key lấy ở trong ứng dụng Blynk trên điện thoại sau khi đã tạo thiết bị
const char auth[] = "6sDPLUAf9HYcEy-_occBU8YaPOfEhJbE";

//Khai báo tên và mật khẩu wifi
const char ssid[] = "Thanh"; // nhập đúng từng kí tự viết hoa và viết thường
const char pass[] = "09031998"; // nhập đúng từng kí tự viết hoa và viết thường

//Hàm khởi tạo
void setup()
{
  //Khởi tạo giao tiếp Serial
  Serial.begin(115200);

  //Kết nối đến Blynk Server
  Blynk.begin(auth, ssid, pass);

  //Vòng lặp chờ kết nối wifi
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected!");
}

//Vòng lặp
void loop()
{
  //Duy trì kết nối đến Blynk Server
  Blynk.run();
}
