//we want to monitor a signal from audio sorce (cell phone or bluetooth). When we detect a signal, we want to turn on a relay which turns on the stereo. 
//We want a 1 min delay before turnning off the relay when we see no signal. When we see no signal start timer to turn off. 2 second delay before turning on. 
int signal_in = A0;
int relay = 13;
float threshhold = .3;
int n;
int sample = 100;
float sum = 0;
float analog_sample;
float avg;

void setup() {
  // put your setup code here, to run once:
  pinMode(signal_in, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//Serial.println (analogRead (signal_in));

if (analogRead (signal_in) > threshhold) {
  digitalWrite (relay, HIGH);
}

if (n >= sample) {
  avg = sum/sample;
  Serial.print ("analog avg = ");
  Serial.println (avg);
  n = 0;
  sum = 0;


if (avg < threshhold) {
  delay (2000);
  n = 0;
  while (n < sample) {
  analog_sample = analogRead(signal_in);
  sum = sum + (analog_sample);
  n++;
  Serial.println (analog_sample);
  }
    if (n >= sample) {
          avg = sum/sample;
    }
      if (avg < threshhold) {
            digitalWrite (relay, LOW);
            Serial.println ("off");
      }

}
  
}

n++;
analog_sample = analogRead(signal_in);
sum = sum + (analog_sample);
delay(10);
//Serial.print ("sum = ");
//Serial.print (sum);
//Serial.print (" analog value = ");
//Serial.print (analog_sample);
//Serial.print (" sample number ");
//Serial.println (n);

}

