#include <SPI.h>
#include <Ethernet.h>
#include <RGBmatrixPanel.h>
#include "RTClib.h"
RTC_DS3231 rtc;
//kondisi Button saat diTekan:
//1. Button Start = ketika Standby dia HIGH(1)  dan  ketika  ditekan dia LOW(0)
//2. Button StOP = ketika Standby dia LOW(0)  dan  ketika  ditekan dia HIGH(1)
//setCursor(Baris,Kolom);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //MAC Address
String DataDuration;
String DataRemarks;
unsigned long byteCount = 0;
bool printWebData = true;  // set to false for better speed measurement
char server[] = "192.168.1.10";
IPAddress ip(192,168,1,177); //arduino IP
EthernetClient client; 

const int Start =6;
const int Stop =7;
const int hijau =3;
const int kuning =4;
const int merah =5;
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

int Ms = 00; // count hours
int S = 00; // count seconds 
int M = 00; // count minutes
String getS;
String getM;
String getMs;
String jam,menit,detik;
int mulai=0;
int berhenti=0;

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false,64); 


void setup() {
  Serial.begin(9600);
//  Ethernet.begin(mac, ip);
//  Serial.print("Local IP: ");
//  Serial.println(Ethernet.localIP());
  pinMode(Start, INPUT_PULLUP);
  pinMode(Stop, INPUT_PULLUP);
  pinMode(merah, OUTPUT); 
  pinMode(kuning, OUTPUT); 
  pinMode(hijau, OUTPUT); 
  matrix.begin(); 
  matrix.fillScreen(0); //to refresh
  matrix.setTextColor(matrix.Color333(7,0,0));
  matrix.setCursor(8,12);
  matrix.print("00");
  matrix.print(":");
  matrix.print("00");
  matrix.print(":");
  matrix.print("00");
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    }
  delay(2000);
}




void loop() {
Jam();
if (digitalRead(Start) == LOW) {
    mulai=1;
    berhenti=0;
  }

if (digitalRead(Stop) == HIGH) {
    mulai=0;
    berhenti=1;
  }

//cek apakah tombol sudah ditekan ?
if ((mulai == 1) && (berhenti == 0)) {
  Stopwatch();
  }
else if ((mulai == 0) && (berhenti == 1)) {
  matrix.setCursor(2,0);
  matrix.setTextColor(matrix.Color333(7,0,0));
  //matrix.print("Kirim Data");
  //SendtoDB();
  delay(1000);
  Ms=00; 
  M=00; 
  S=00;
  berhenti=0;
  mulai=0;
  digitalWrite(hijau,LOW);
  digitalWrite(kuning,LOW);
  digitalWrite(merah,LOW);
 }

}


void Stopwatch(){
  //------------------------------CHANGE TIME---------------------------------
    digitalWrite(hijau,HIGH);
    Ms++;
    delay(10);
    matrix.fillScreen(0); //to refresh
    matrix.setTextColor(matrix.Color333(7,0,0)); 
    if (Ms>25) //if miliseconds are up,
    {
      S++; // to addup minute by one
      Ms=0; // reset second section to 0
    }

    if (S>59) //if seconds are up,
    {
      M++; // to addup minute by one
      S=0; // reset second section to 0
    }

    if (M>59) //if minutes are up,
    {
      M=0; //reset minute to 59
    }
    //----------------------------DISPLAY TIME----------------------------- 
    matrix.setCursor(8,12);
    matrix.setTextColor(matrix.Color333(7,0,0)); 
       if (M <10 && M>=0){ 
      digitalWrite(hijau,HIGH);
      digitalWrite(kuning,LOW);
      digitalWrite(merah,LOW); 
      //LAMPU HIJAU      
    } else if (M <15 && M>=10){ 
      digitalWrite(hijau,LOW);
      digitalWrite(kuning,HIGH);
      digitalWrite(merah,LOW); 
      //LAMPU HIJAU      
    } 
     else if (M <59 && M>=16){
      digitalWrite(hijau,LOW);
      digitalWrite(kuning,LOW);
      digitalWrite(merah,HIGH);
      //LAMPU ORANGE
    } 
//else if ( S <59 && S>=16){
//      //LAMPU MERAH  
//      digitalWrite(hijau,HIGH);
//      digitalWrite(kuning,LOW);
//      digitalWrite(merah,HIGH);    
//    }
   
//    if (H < 10){
//      matrix.print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
//      matrix.print(H);
//      getH ="0" + String(H);
//    } else {
//      matrix.print(H);
//      getH =H;
//    }
//    
//    matrix.print(":");

    if (M < 10){
      matrix.print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
      matrix.print(M);
      getM ="0" + String(M);
    } else {
      matrix.print(M); 
      getM =M;
    }

    matrix.print(":");
    
    if (S < 10){
      matrix.print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
      matrix.print(S);
      Serial.print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
      Serial.println(S);
      getS ="0" + String(S);
    } else {
      matrix.print(S);
      Serial.println(S);
      getS =S; 
    }

    matrix.print(":");
    matrix.print(Ms);
    Serial.println(Ms);
    getMs =Ms; 
    
    DataDuration =getM+":"+getS+":"+getMs;
        
}
void Jam(){
  DateTime now = rtc.now();
  jam = now.hour();
  menit =now.minute();
  detik = now.second();
  matrix.setCursor(8,1);
  matrix.setTextColor(matrix.Color333(7,0,0)); 
  matrix.print(jam);
  matrix.print(":"); 
  matrix.print(menit);
  matrix.print(":");
  matrix.print(detik);
}
void SendtoDB(){
  if (client.connect(server, 80)) {
    Serial.println("");
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /JOBDURATION/control.php?dataDuration=");
    Serial.print(DataDuration);
    Serial.println("");
    
    client.print("GET /JOBDURATION/control.php?dataDuration=");     //YOUR URL
    client.print(DataDuration);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 192.168.1.177");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
}
 
