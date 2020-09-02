int targetLed = 13;		// 켤 LED 핀 번호
int loopCount = 0;

const int LEVEL = 50;	// 난이도

int score = 0;

bool isCountUp = false;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  loopCount++;
  Serial.println(score);
  
  // 다른 불 켜는 조건
  if (loopCount % LEVEL == 0) {
  	targetLed = random(11, 14);
    // 점수 카운팅
    if (isCountUp == true) {
      score++;
      isCountUp = false;
    }
  }
  
  // 불이 켜지는 로직
  switch(targetLed) {
  	case 13:
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      break;
    case 12:
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      break;
    case 11:
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      break;
  }
  
  // 스위치와 조건을 만족하는지 검사
  if ((targetLed == 13 && digitalRead(4)) || 
     (targetLed == 12 && digitalRead(3)) || 
     (targetLed == 11 && digitalRead(2))) {
    // 눌렸는지
    isCountUp = true;
  }
}
