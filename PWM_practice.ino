int led = 7;           
int E_period = 100;    
int E_duty = 0;    


void set_period(int period) {
  E_period = period >= 100 && period <= 10000 ? period : E_period;
}

void set_duty(int duty) {
  E_duty = duty >= 0 && duty <= 100 ? duty : E_duty;
}

void blinking() {
  for(int cnt = 0; cnt <= 5000/E_period; cnt++) {
    digitalWrite(led, LOW);
    delayMicroseconds(E_period*E_duty/100);
    digitalWrite(led, HIGH);
    delayMicroseconds(E_period*(100-E_duty)/100);
  }
}

void setup() {
  pinMode(led, OUTPUT);
  set_period(100);
}

void loop() {
  for (int count = 0; count < 100; count++) {
    set_duty(count);
    blinking();
  }
  for (int count = 100; count > 0; count--) {
    set_duty(count);
    blinking();
  }
}
