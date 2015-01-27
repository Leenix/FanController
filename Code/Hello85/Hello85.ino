const int FLASH_PIN = 0;
const int ALOG_PIN = 3;

void setup()
{
	pinMode(FLASH_PIN, OUTPUT);
	digitalWrite(FLASH_PIN, HIGH);
	
	analogWrite(ALOG_PIN, 200);

}

void loop()
{

	//delay(1000);
	//digitalWrite(FLASH_PIN, LOW);
	//delay(1000);
	//digitalWrite(FLASH_PIN, HIGH);
	
	for(int i = 0; i < 255; i++){
		analogWrite(FLASH_PIN, i);
		analogWrite(ALOG_PIN, i);
		delay(2);
	}
	
	for(int i = 255; i > 0; i--){
		analogWrite(FLASH_PIN, i);
		analogWrite(ALOG_PIN, i);
		delay(2);
	}
}
