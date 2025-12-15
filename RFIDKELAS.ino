#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  
#define RST_PIN 9

#define GREEN_LED 2
#define RED_LED 3  
#define RELAY_PIN 4 

const String validCardIDs[] = {
  "E3E17A1D", "22E0837B", "08F80B45", "5ACD4503", "FE723D02", "21F33C02","00000000","C02E19B1","E978F54B","0409236A556D80","B55EA095","058F581491B100","41B3AC5C","188235E282CDAA","F50E63C6","82D195D3",
  "802D19B1","C2E494D3","609F16B1","72D182D3","827182D3","624C84D3","126681D3","128C83D3","C2A90FD4","62EC95D3","E29995D3","920013D4","B24A12D4","324D96D3","A25D93D3","726911D4","F2A78DD3","123884D3",
  "622290D3","12EA8ED3","C20F8ED3","72B88FD3","B21CA0D3","222E0FD4","527E0DD4","921C12D4","B22E84D3","72D182D3","D24C90D3","327911D4","C28D13D4","52BC94D3","A2DF8DD3","32A713D4","B29994D3","22E080D3","92E011D4"
};

const int numValidIDs = sizeof(validCardIDs) / sizeof(validCardIDs[0]);

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  nvrvnr
  SPI.begin(); 
  mfrc522.PCD_Init();

  pinMode(GREEN_LED, OUTPUT); 
  pinMode(RED_LED, OUTPUT);   
  pinMode(RELAY_PIN, OUTPUT); 

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  String cardID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    cardID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    cardID += String(mfrc522.uid.uidByte[i], HEX);
  }
  cardID.toUpperCase();

  Serial.print("Kartu ID: ");
  Serial.println(cardID);

   
  bool isValid = false;
  for (int i = 0; i < numValidIDs; i++) {
    if (cardID == validCardIDs[i]) {
      isValid = true;
      break;
    }
  }

  if (isValid) {
    Serial.println("Akses Diterima");
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(RED_LED, LOW);   
    digitalWrite(RELAY_PIN, HIGH);
    
    delay(5000);

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(RED_LED, LOW);
    
  } else {
    Serial.println("Akses Ditolak");
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH); 
    delay(2000);
    digitalWrite(GREEN_LED, LOW);   
    digitalWrite(RED_LED, LOW);
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  delay(1000);
  
}
