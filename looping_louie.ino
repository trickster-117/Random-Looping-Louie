int out_pin = 5;

int max_val = 100; // 0...255 
int min_val = 10; // 120 max 10 min
int t_min = 100;
int t_max = 2000;
int factor = t_max/max_val;

float v_rand = 0;
float t_rand = 0;

int max_voltage = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(out_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  v_rand = random(min_val, max_val);

  if (v_rand < 15)
    v_rand = 0;
    
  //t_rand = random(t_min, t_max);

  // oder je schneller, desto kürzer
  t_rand = t_min + (max_val - v_rand)*factor;

  //PWM signal
  analogWrite(out_pin, v_rand);

  Serial.println(t_rand);
  
  //Rand delay
  delay(t_rand);
  delay(50);

}
