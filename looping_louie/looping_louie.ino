/////////////////////////////////////////////////////////////////////////////
// author: trickster-117                                                   //
//https://github.com/trickster-117/Random-Looping-Louie                    //
// Everybody is free to use this piece of code and change it how they like //
// Have Fun :D                                                             //
/////////////////////////////////////////////////////////////////////////////

int led_pin = 13;
int out_pin = 5;
int max_val = 100; // 0...255 
int min_val = 10; // 120 max 10 min
int t_min = 100;
int t_max = 2000;
int factor = t_max/max_val;
int chance_race_mode = 5;
int race = 0;

float v_rand = 0;
float t_rand = 0;

int max_voltage = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(out_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // Check if race mode enabled
  race = random(0, 100);
  if (race < chance_race_mode) {
    
    // wait till louie stops
    analogWrite(out_pin, 0);
    delay(1500);
    
    // Beep x times
    for(int i=0; i<3; i++){
      digitalWrite(led_pin, HIGH);
      analogWrite(out_pin, 10);
      delay(300);
      digitalWrite(led_pin, LOW);
      analogWrite(out_pin, 0);
      delay(300);
    }
    // Race!
    analogWrite(out_pin, 150);
    delay(3000);
  }
  
  // Sample random speed value
  v_rand = random(min_val, max_val);

  // avoid beeping when voltage is too low to turn motor, turn it off completely
  if (v_rand < 15) {
    v_rand = 0;
    t_rand = random(t_min+500, t_max+500);
    
  } else {
      // the faster, the shorter it runs
      t_rand = t_min + (max_val - v_rand)*factor;
  }

  // Run
  analogWrite(out_pin, v_rand);
  
  // Rand delay
  delay(t_rand);
}
