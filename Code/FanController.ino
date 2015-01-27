// Fan pin - drives MOSFET using PWM
const int FAN_PIN = 4;	//PB4 (Pin 3)

// Potentiometer input pin
const int POT_PIN = 3;	//PB3 (Pin 2)

// LED output pin
const int LED_PIN = 0;	//PB0 (Pin 5)

// Minimum duty cycle that will turn on the fan
const int FAN_MIN_DUTY = 4;

void setup()
{
	pinMode(FAN_PIN, OUTPUT);
	pinMode(LED_PIN, OUTPUT);
	
	analogWrite(FAN_PIN, 0);
	analogWrite(LED_PIN, 0);
	
	// Set PWM rate as high as possible
	TCCR1 = TCCR1 & 0b11110000 | 0x01;
	//TCCR0B = TCCR0B & 0b11111000 | 0x01;
}


void loop()
{	
	int potReading = analogRead(POT_PIN);
	
	// Convert 10-bit pot reading into a 8-bit integer
	int fanDuty = potReading/4;
	
	// Write the PWM level to the LED
	analogWrite(LED_PIN, fanDuty);
	
	

	// Don't run the fan below the minimum switch-on level
	if(fanDuty < FAN_MIN_DUTY){
		fanDuty = 0;
	}
	
	
	
	// Write the PWM level to the MOSFET
	analogWrite(FAN_PIN, fanDuty);
	
	delay(50);
	
}