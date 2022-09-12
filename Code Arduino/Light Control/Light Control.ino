/*
  DỰ ÁN ĐIỀU KHIỂN ĐÈN BẬT TẮT TỰ ĐỘNG DỰA THEO CƯỜNG ĐỘ SÁNG CỦA MÔI TRƯỜNG
  Phần cứng cần thiết:
    + Arduino Nano
    + Dây cáp nạp code
    + Cảm biến ánh sáng
    + Relay điều khiển
    + Bóng đèn, phích cắm, dây điện
    + Breadboard và dây cắm mạch
  Cách thức hoạt động:
    + Cảm biến được kết nối đến chân Analog A0 để đo cảm biến và trả về giá trị cường độ ánh sáng dựa có giá trị số nguyên.
    + Mạch điểu khiển sẽ kiểm tra giá trị của cảm biến và so sánh điều kiện. Nếu giá trị trả về lớn hơn 100 thì sẽ bật đèn và nếu giá trị nhỏ hơn 30 sẽ tắt đèn.
    Chúng ta nên đặt giá trị như vậy
      để đèn bật tắt một cách ổn định hơn trong điều kiện ánh sáng yếu dần ngoài thực tế.
    + Khi relay đóng đèn sẽ bật, khi relay mở đèn sẽ tắt giống như cách hoạt động của công tắc.
    + Mạch điều khiển đồng thời in ra màn hình Serial giá trị của cảm biến trả về.
    + Delay 1 giây trước khi tiếp tục vòng lặp. Nếu muốn tăng độ nhạy có thể chỉnh giá trị delay thấp hơn.
    + Loại relay này có thể sử dụng Jumper để chuyển đổi giá trị cho đóng hoặc mở.
  Kết nối phần cứng:
    + Chân 3.3V --> Chân VCC của cảm biến.
    + Chân GND --> Chân GND của cảm biến.
    + Chân A0 --> Chân SIG của cảm biến.
    + Chân Vin --> Chân DC+ của Relay.
    + Chân GND --> Chân DC- của Relay.
    + Chân D6 --> Chan IN của Relay.
*/

//Khai báo chân cảm biến và relay
const int sensor = 0;
const int relay = 6;

//Khởi tạo các hàm và biến cần thiết
void setup() {
  //Khai báo kết nối Serial
  Serial.begin(9600);

  //Khai báo cho phép đọc giá trị của cảm biến
  pinMode(sensor, INPUT);

  //Khai báo cho phép ghi giá trị lên relay
  pinMode(relay, OUTPUT);

  //Khởi tạo giá trị cho relay là mở
  digitalWrite(relay, LOW);
  delay(100);
}

//Hàm xử lý điều khiển đèn
void lightControl(){
  //Lấy giá trị của cảm biến sau đó gán vào biến sensorValue
  int sensorValue = analogRead(sensor);
  
  //In giá trị ra màn hình Serial
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  
  //Nếu giá trị nhỏ hơn 30 sẽ đóng relay
  if(sensorValue < 30){
      digitalWrite(relay, HIGH);
  }

  //Nếu giá trị lớn hơn 100 sẽ mở relay
  else if(sensorValue > 100){
    digitalWrite(relay, LOW);
  }
}

//Vòng lặp
void loop() {
  // Gọi hàm điều khiển bật tắt đèn
  lightControl();
  
  //Đợi 1 giây trước khi bắt đầu vòng lặp tiếp theo
  delay(1000);
}
