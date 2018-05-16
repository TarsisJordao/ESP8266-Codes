#include <ESP8266WiFi.h>

#define entradaAnalogica ADC0

//Definir o SSID da rede WiFi
const char* ssid = "PEF";
//Definir a senha da rede WiFi
const char* password = "84395119";
 
//Colocar a API Key para escrita neste campo
//Ela é fornecida no canal que foi criado na aba API Keys
String apiKey = "E9C2PDFD6P4XPNGM"; // Chave de Escrita 1º Key do site
const char* server = "api.thingspeak.com";

WiFiClient client;
 
void setup() 
{
    //Configuração da UART
    Serial.begin(9600);
    //Inicia o WiFi
    WiFi.begin(ssid, password);
   
    //Espera a conexão no router
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
   
    //Logs na porta serial
    Serial.println("");
    Serial.print("Conectado na rede ");
    Serial.println(ssid);
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

void loop()
{

    delay(8000);
    
    float valorAnalog=3;
      
    if (client.connect(server,80)) 
    {
        String postStr = apiKey;
               postStr +="&amp;field1=";
               postStr += String(valorAnalog);
               postStr += "\r\n";
     
         client.print("POST /update HTTP/1.1\n");
         client.print("Host: api.thingspeak.com\n");
         client.print("Connection: close\n");
         client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
         client.print("Content-Type: application/x-www-form-urlencoded\n");
         client.print("Content-Length: ");
         client.print(postStr.length());
         client.print("\n\n");
         client.print(postStr);
     
         //Logs na porta serial
         Serial.print("Leitura Analogica: ");
         Serial.print(valorAnalog);
         Serial.println();
    
      }
  client.stop();
}
