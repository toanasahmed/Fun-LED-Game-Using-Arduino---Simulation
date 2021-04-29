int sequence[4];
int sequenceU[4];
int DT = 1000;
int UserValue = 0;
int counter = 0;

const int ResetButton = 2;
const int TrueLED = 3;
const int FalseLED = 4;

const int RedLED = 5;
const int GreenLED = 6;
const int BlueLED = 7;
const int YellowLED = 8;

const int RedButton = 9;
const int GreenButton = 10;
const int BlueButton = 11;
const int YellowButton = 12;


void setup() {

  Serial.begin(9600);

  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);

  pinMode(RedButton, INPUT);
  pinMode(GreenLED, INPUT);
  pinMode(BlueButton, INPUT);
  pinMode(YellowButton, INPUT);

  pinMode(ResetButton, INPUT);
  pinMode(TrueLED, OUTPUT);
  pinMode(FalseLED, OUTPUT);
}

void loop() {

  if (UserValue == 0) {
    Serial.println("STARTING......");

    for (int i = 0; i < 4; i++) {
      int ledFlow = random(-1, 4);
      sequence[i] = ledFlow;

      //Serial.print("Random Number:"); Serial.println(ledFlow);
      delay(100);
      switch (ledFlow) {
        case 0:
          digitalWrite(RedLED, HIGH);
          Serial.println("RedLED TURN ON");
          break;
        case 1:
          digitalWrite(GreenLED, HIGH);
          Serial.println("GreenLED TURN ON");
          break;
        case 2:
          digitalWrite(BlueLED, HIGH);
          Serial.println("BlueLED TURN ON");
          break;
        case 3:
          digitalWrite(YellowLED, HIGH);
          Serial.println("YellowLED TURN ON");
          break;
      }
      delay(DT);
      digitalWrite(RedLED, LOW);
      digitalWrite(GreenLED, LOW);
      digitalWrite(BlueLED, LOW);
      digitalWrite(YellowLED, LOW);

    }

  }
  //Serial.print("UserValue = "); Serial.println(UserValue);
  UserValue = 1;
  //Serial.print("UserValue = "); Serial.println(UserValue);
  if (UserValue == 1) {
    if (digitalRead(RedButton) == HIGH) {
      sequenceU[counter] = 0;
      counter = counter + 1;
      Serial.print("RedButton Pressed -- Counter:"); Serial.println(counter);

    }
    if (digitalRead(GreenButton) == HIGH) {
      sequenceU[counter] = 1;
      counter = counter + 1;
      Serial.print("GreenButton Pressed -- Counter:"); Serial.println(counter);
    }
    if (digitalRead(BlueButton) == HIGH) {
      sequenceU[counter] = 2;
      counter = counter + 1;
      Serial.print("BlueButton Pressed -- Counter:"); Serial.println(counter);
    }
    if (digitalRead(YellowButton) == HIGH) {
      sequenceU[counter] = 3;
      counter = counter + 1;
      Serial.print("YellowButton Pressed -- Counter:"); Serial.println(counter);
    }
    if (digitalRead(ResetButton) == HIGH) {
      UserValue = 0;
      digitalWrite(TrueLED, LOW);
      digitalWrite(FalseLED, LOW);
      Serial.print("ResetButton Pressed -- Lets Start"); Serial.println(counter);
    }

    if (counter >= 4) {
      counter = 0;
      UserValue = 2;
    }
  }


  if (UserValue == 2) {
    bool they_match = true;
    for ( int i = 0; i < 4; i++ ) {
      if ( sequence[i] != sequenceU[i] ) {
        they_match = false;
        break;
      }
    }
    if (they_match == true) {
      digitalWrite(TrueLED, HIGH);
      DT = DT - (DT * 0.2);
      Serial.println("TRUE");
      Serial.print("DT value:");
      Serial.println(DT);
    }
    else if (they_match == false) {
      digitalWrite(FalseLED, HIGH);
      Serial.println("FALSE");
      DT = 1000;
      UserValue = 1;
    }


  }
  delay(500);
}
