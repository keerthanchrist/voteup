#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define sw1 15
#define sw2 16
#define sw3 17
#define sw4 18
#define sw5 19

#define buzzerPin 7  // Define the pin for the buzzer
#define ledPin 6     // Define the pin for the LED

int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;

void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as output
  pinMode(ledPin, OUTPUT);    // Set the LED pin as output

  lcd.begin(16, 2);
  lcd.print("Voting Machine");
  lcd.setCursor(0, 1);
  lcd.print("Circuit Digest");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("student1");
  lcd.setCursor(4, 0);
  lcd.print("Student2");
  lcd.setCursor(8, 0);
  lcd.print("Student3");
  lcd.setCursor(12, 0);
  lcd.print("No one in list");
}

void loop() {
  lcd.setCursor(1, 1);
  lcd.print(vote1);
  lcd.setCursor(5, 1);
  lcd.print(vote2);
  lcd.setCursor(9, 1);
  lcd.print(vote3);
  lcd.setCursor(13, 1);
  lcd.print(vote4);

  if (digitalRead(sw1) == LOW) {
    vote1++;
    digitalWrite(ledPin, HIGH); // Turn on LED when button is pressed
    delay(200); // Debounce delay
    digitalWrite(ledPin, LOW); // Turn off LED after debounce
  }

  if (digitalRead(sw2) == LOW) {
    vote2++;
    digitalWrite(ledPin, HIGH); // Turn on LED when button is pressed
    delay(200); // Debounce delay
    digitalWrite(ledPin, LOW); // Turn off LED after debounce
  }

  if (digitalRead(sw3) == LOW) {
    vote3++;
    digitalWrite(ledPin, HIGH); // Turn on LED when button is pressed
    delay(200); // Debounce delay
    digitalWrite(ledPin, LOW); // Turn off LED after debounce
  }

  if (digitalRead(sw4) == LOW) {
    vote4++;
    digitalWrite(ledPin, HIGH); // Turn on LED when button is pressed
    delay(200); // Debounce delay
    digitalWrite(ledPin, LOW); // Turn off LED after debounce
  }

  if (digitalRead(sw5) == LOW) {
    int totalVotes = vote1 + vote2 + vote3 + vote4;
    if (totalVotes > 0) {
      lcd.clear();
      if (vote1 > vote2 && vote1 > vote3 && vote1 > vote4) {
        lcd.print("BJP Wins");
        tone(buzzerPin, 1000, 1000); // Play a 1-second tone with a frequency of 1000 Hz
      } else if (vote2 > vote1 && vote2 > vote3 && vote2 > vote4) {
        lcd.print("INC Wins");
        tone(buzzerPin, 1000, 1000); // Play a 1-second tone with a frequency of 1000 Hz
      } else if (vote3 > vote1 && vote3 > vote2 && vote3 > vote4) {
        lcd.print("AAP Wins");
        tone(buzzerPin, 1000, 1000); // Play a 1-second tone with a frequency of 1000 Hz
      } else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3) {
        lcd.print("OTH Wins");
        tone(buzzerPin, 1000, 1000); // Play a 1-second tone with a frequency of 1000 Hz
      } else {
        lcd.print("Tie Up Or No Result");
        tone(buzzerPin, 500, 1000); // Play a 1-second tone with a frequency of 500 Hz
      }
    } else {
      lcd.clear();
      lcd.print("No Voting....");
    }
    delay(2000); // Display the result for 2 seconds
    noTone(buzzerPin); // Stop the buzzer
    vote1 = 0;
    vote2 = 0;
    vote3 = 0;
    vote4 = 0;
    lcd.clear();
  }
}
