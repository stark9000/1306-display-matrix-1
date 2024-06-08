#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* message1 = "Wake up Neo...";
const char* message2 = "The Matrix has you...";
const char* message3 = "Follow the white\n"
                       "rabbit.";
const char* message4 = "Knock, knock, Neo.";
void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println(F("Starting!"));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.println(F("Initialized!"));


  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40, 0);
  display.println("The Matrix");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();

}

void loop() {
  display.clearDisplay();
  displayMSG(message1);
  delay(1000);
  display.clearDisplay();
  displayMSG(message2);
  delay(1000);
  display.clearDisplay();
  displayMSG(message3);
  delay(1000);
  display.display();
  display.clearDisplay();
  displayMSG(message4);
  delay(1000);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  delay(5000);
}

void displayMSG(char* message) {
  display.setCursor(0, 0);
  for (int i = 0; message[i] != '\0'; i++) {
    display.print(message[i]);
    delay(100);
    display.display();
  }
}
