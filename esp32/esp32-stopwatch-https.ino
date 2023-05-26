
// on 3 pcs P5 Panels 64x32 LED matrix
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#define PANEL_RES_X 64      // Number of pixels wide of each INDIVIDUAL panel module. 
#define PANEL_RES_Y 32     // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 3      // Total number of panels chained one to another
 
//MatrixPanel_I2S_DMA dma_display;
MatrixPanel_I2S_DMA *dma_display = nullptr;


// Settingan ESP32 ke Panel P5 (HUB 75)
//#define R1_PIN 25
//#define G1_PIN 26
//#define B1_PIN 27
//#define R2_PIN 14
//#define G2_PIN 12
//#define B2_PIN 13
//#define A_PIN 23
//#define B_PIN 19
//#define C_PIN 5
//#define D_PIN 17
//#define E_PIN -1 // required for 1/32 scan panels, like 64x64px. Any available pin would do, i.e. IO32
//#define LAT_PIN 4
//#define OE_PIN 15
//#define CLK_PIN 16
// ada 3 Pin Ground , Minimal 2 pin HARUS terhubung ke ground kalau tidak LED jadi berbayang
//yaitu GND diantara pin G1 dan G2 (terhubungke GND ESP32 diantara p19 dan P21) satu lagi GND yg ada di sebrang OE ini terhubung ke GND esp32 diantara p12 dan p13.


const char WIFI_SSID[] = "Bravo"; //ganti ssid sesuai dengan ssid wifi yg tersedia
const char WIFI_PASSWORD[] = "123456789"; //gsnti password sesuai password wifi yg tersedia
String HOST_NAME = "https://192.168.195.121"; // ganti IP address sesuai ip address PC yg akan menerima data
String PATH_NAME   = "/JOBDURATION/control.php"; // ini lokasi file php untuk kirim datanya ada  di C:\xampp\htdocs\JOBDURATION\control.php
String queryString , DataDuration;
int Ms = 00; // count hours
int S = 00; // count seconds 
int M = 00; // count minutes
String getS;
String getM;
String getMs;
String jam,menit,detik;
int mulai=0;
int berhenti=0;
const int Start =2;
const int Stop =35;
const int hijau =0; //relay1
const int kuning =32; //relay2
const int merah =33; //relay3

void setup() {

  // Module configuration
  HUB75_I2S_CFG mxconfig(
    PANEL_RES_X,   // module width
    PANEL_RES_Y,   // module height
    PANEL_CHAIN    // Chain length
  );

  //mxconfig.gpio.e = 18;
  //mxconfig.clkphase = false;
  //mxconfig.driver = HUB75_I2S_CFG::FM6126A;

  // Display Setup
  Serial.begin(9600);
//awal stting WIFI

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
//akhir stting WIFI

//awal setting led matrix panel
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
//  dma_display->addLayer(jamlayer);
//  dma_display->addLayer(timerlayer);
  dma_display->begin();
  dma_display->setBrightness8(90); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(0);
  dma_display->setTextSize(3);
  dma_display->setCursor(25, 5);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color444(0,7,0));
  dma_display->println("00:00:00");
//  delay(1000);
//  dma_display->clearScreen();
//  dma_display->fillScreen(0);
//akhir setting led matrix panel  

//awal setup button dan relay
  pinMode(Start, INPUT_PULLUP);
  pinMode(Stop, INPUT_PULLUP);
  pinMode(merah, OUTPUT); 
  pinMode(kuning, OUTPUT); 
  pinMode(hijau, OUTPUT); 
  digitalWrite(hijau,LOW);
  digitalWrite(kuning,LOW);
  digitalWrite(merah,LOW);
//akhir setup button dan relay
}


void loop() {
  
 if ((digitalRead(Start) == LOW) && (digitalRead(Stop)) == LOW) {
    Serial.println("mulai1");
    mulai=1;
    berhenti=0;
  }

 if ((digitalRead(Stop) == HIGH) && (digitalRead(Start)) == HIGH){
    mulai=0;
    berhenti=1;
    Serial.println("mulai0");
  }
  //cek apakah tombol sudah ditekan ?
if ((mulai == 1) && (berhenti == 0)) {
  Stopwatch();
  }
else if ((mulai == 0) && (berhenti == 1)) {
  SendtoDB();
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
    //digitalWrite(hijau,HIGH);
    Ms++;
    delay(45);
   dma_display->fillScreen(0);
   dma_display->setTextSize(3);
   dma_display->setCursor(25, 5);   // start at top left, with 8 pixel of spacing
   dma_display->setTextColor(dma_display->color444(0,7,0));
  //Jam;//to refresh
    if (Ms>20) //if miliseconds are up,
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

    //dma_display->setCursor(8,12); 
       if (M <=9 ){ 
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
     else if (M <59 && M>=15){
      digitalWrite(hijau,LOW);
      digitalWrite(kuning,LOW);
      digitalWrite(merah,HIGH);
      //LAMPU ORANGE
    } 

    if (M < 10){
      //dma_display->setCursor(8,12);
      dma_display->print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
      dma_display->print(M);
      getM ="0" + String(M);
    } else {
      //dma_display->setCursor(8,12);
      dma_display->print(M); 
      getM =M;
    }

    //dma_display->setCursor(22,12);
    dma_display->print(":");
    
    if (S < 10){
      //dma_display->setCursor(29,12);
      dma_display->print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
      dma_display->print(S);
      Serial.print("0"); //Extra space is to ensure colons are in the same spot when theres only 1 digit
      Serial.println(S);
      getS ="0" + String(S);
    } else {
      //dma_display->setCursor(29,12);
      dma_display->print(S);
      Serial.println(S);
      getS =S; 
    }
    //dma_display->setCursor(43,12);
    dma_display->print(":");
    //dma_display->setCursor(48,12);
    dma_display->print(Ms);
    Serial.println(Ms);
    getMs =Ms; 
    
    DataDuration =getM+":"+getS+":"+getMs;
    
}

void SendtoDB(){
  HTTPClient http;
  queryString= "?duration=" + DataDuration;
  http.begin(HOST_NAME + PATH_NAME + queryString); //HTTP
  http.setAuthorization("username", "password");
  int httpCode = http.GET();
  // httpCode will be negative on error
  if(httpCode > 0) {
    // file found at server
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}
