# ARDUİNO İLE RC KUMANDA KULLANIMI


https://www.kirmiziyuz.com/arduino/arduino-ile-rc-kumanda-kullanimi.html

<p align="center">
  <img width="508" height="385" src="https://kirmiziyuz.com/wp-content/uploads/2021/06/Arduino_ile_Rc_Kumanda_Kullanimi_1.jpg">
</p>

<p align="center">
  <a href="www.youtube.com/watch?v=yP7OLZXwMiY">
  <img src="https://kirmiziyuz.com/wp-content/uploads/2021/06/youtube.jpg"/>
 </a>
</p>

                                     
İhtiyacım üzerine  Drone ve Rc araçlarda kullanılan FYLSKY kumanda mı Arduino veya NodeMCU da nasıl kullanabilirim diye bir araştırmada bulundum. Fakat tam istediğim bilgiye bir türlü ulaşamadım. Yabancı kaynaklar ve yerli kaynaklarda bulamadığımdan bu yazıyı paylaşıyorum. Umarım işinize yarar.

 

Öncelikle Arduino veya NodeMCU bağlantılarını yapalım.
<p align="center">
  <img src="https://kirmiziyuz.com/wp-content/uploads/2021/06/Arduino_ile_Rc_Kumanda_Kullanimi.jpg"/>
</p>

Flysky kumandasının iki kolu yani CH2 ve CH3  kanalına bağlı olan yön çubuklarını NodeMCU ile bağladım. Farklı pinlerini kullanmak için yine aynı programı kullanabilirsiniz. Bir Tank projemde kullanacağım için bana bu iki kanal yeterli olacak.

Öncelikle kol bağlantılarından gelen minimum ve max. değerleri okuyarak buna göre hız kontrolü yapacağım.

<p align="center">
  <img src="https://kirmiziyuz.com/wp-content/uploads/2021/06/Sinyal_Tablo.jpg"/>
</p>

Ölçüm yaparken tek kanal için çalışmanızı öneririm. Sağ ve Sol motoru bağlayacağım kanalları tek tek ölçtüm minimum ve max. değerlerini birde çubupu bırakında orta değeri olan durma değerini ölçtüm ve bu değerleri dur,  yavaş orta ve hızlı şeklinde ortak aralıklara bölerek hız kontrolü için hazır hale getirdim.

# Nodemcu Pinout.
<p align="center">
  <img src="https://kirmiziyuz.com/wp-content/uploads/2021/06/NodeMCUv3.0-pinout.jpg"/>
</p>

# Ölçüm için gerekli Kodlar:

```
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
```
Kanalları Tektek ayarladıktan sonra Motorun hız kontrolü için hazırladığım kod ta aşağıda sunuyorum.

# Motor hız kontrolü için gerekli Kodlar:
```
#define Sag_Motor 14 //D5
#define Sol_Motor 12 //D6
int ch2 = 0;
int ch4 = 0;

void setup() {
pinMode(Sag_Motor, INPUT);
pinMode(Sol_Motor, INPUT);
Serial.begin(9600); //9600 Baund bir seri haberleşme başlatıyoruz
}
void loop() {
ch2 = pulseIn(Sag_Motor, HIGH, 40000);
//Serial.println("CH2"); //Okunan değer seri monitörde mesaj olarak gönderilir
//Serial.println(ch2);
//delay(1000); //Bu işlem 100 milisaniye aralıklarla yapılır

ch4 = pulseIn(Sol_Motor, HIGH, 40000);
//Serial.println("ch4"); //Okunan değer seri monitörde mesaj olarak gönderilir
//Serial.println(ch4);

switch (ch4)
{
case 1858 ... 2100:
Serial.print("Sol Motor - İleri - Hızlı: ");
Serial.println(ch4);
break;

case 1715 ... 1857:
Serial.print("Sol Motor - İleri - Orta: ");
Serial.println(ch4);
break;

case 1601 ... 1714:
Serial.print("Sol Motor - İleri - Yavas: ");
Serial.println(ch4);
break;

case 1391 ... 1600:
Serial.print("");
break;

case 1286 ... 1390:
Serial.print("Sol Motor - Geri - Yavas: ");
Serial.println(ch4);
break;

case 1143 ... 1285:
Serial.print("Sol Motor - Geri - Orta: ");
Serial.println(ch4);
break;

case 900 ... 1142:
Serial.print("Sol Motor - Geri - Hızlı: ");
Serial.println(ch4);
break;

default: printf(""); break;
}

switch (ch2)
{
case 1858 ... 2100:
Serial.print("\t\t\t\t\t");
Serial.print("Sag Motor - İleri - Hızlı: ");
Serial.println(ch2);
break;

case 1715 ... 1857:
Serial.print("\t\t\t\t\t");
Serial.print("Sag Motor - İleri - Orta: ");
Serial.println(ch2);
break;

case 1601 ... 1714:
Serial.print("\t\t\t\t\t");
Serial.print("Sag Motor - İleri - Yavas: ");
Serial.println(ch2);
break;

case 1391 ... 1600:
Serial.print("");
break;

case 1286 ... 1390:
Serial.print("\t\t\t\t\t");
Serial.print("Sag Motor - Geri - Yavas: ");
Serial.println(ch2);
break;

case 1143 ... 1285:
Serial.print("\t\t\t\t\t");
Serial.print("Sag Motor - Geri - Orta: ");
Serial.println(ch2);
break;

case 900 ... 1142:
Serial.print("\t\t\t\t\t");
Serial.print("Sag Motor - Geri - Hızlı: ");
Serial.println(ch2);
break;

default: printf(""); break;
}
}
```
