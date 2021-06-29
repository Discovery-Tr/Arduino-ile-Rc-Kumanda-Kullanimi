#define Sag_Motor 14 //D5 NodeMCU pinout
#define Sol_Motor 12 //D6 NodeMCU pinout
int ch2=0;
int ch3=0;

void setup() {
pinMode(Sag_Motor,INPUT);
pinMode(Sol_Motor,INPUT);
Serial.begin(9600); //9600 Baund bir seri haberleşme başlatıyoruz
}
void loop() {
ch2= pulseIn(Sag_Motor,HIGH,20000);
Serial.println("CH2"); //Okunan değer seri monitörde mesaj olarak gönderilir
Serial.println(ch2);
delay(100); //Bu işlem 100 milisaniye aralıklarla yapılır

ch3= pulseIn(Sol_Motor,HIGH,20000);
Serial.println("CH3"); //Okunan değer seri monitörde mesaj olarak gönderilir
Serial.println(ch3);
delay(100); //Bu işlem 100 milisaniye aralıklarla yapılır.

}
