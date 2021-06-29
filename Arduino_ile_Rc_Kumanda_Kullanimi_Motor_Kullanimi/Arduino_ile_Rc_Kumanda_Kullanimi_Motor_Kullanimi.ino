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
