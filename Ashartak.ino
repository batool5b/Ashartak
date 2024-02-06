/*
NAME OF THE PROJECT: Ashartak

This project reads sensor value and understand symbols generted from Arab sign-language chart and display it.

-------PIN CONFIGURATION----------------
A0-A4 : flex sensor

*/


//defining led and flex sensor pins
// #define led_pin 9
#define flex_pin A0 //index
#define flex_pin2 A1 //middle
#define flex_pin3 A2 //ring
#define flex_pin4 A3 //little
#define flex_pin5 A4 //thumb
//variables for flex sensor readings and led brightness output
int flex_thumb;
int flex_index;
int flex_middle;
int flex_ring;
int flex_little;
//int led_brightness;

void setup() {
  // put your setup code here, to run once:
  pinMode(flex_pin, INPUT);
  pinMode(flex_pin2, INPUT);
  pinMode(flex_pin3, INPUT);
  pinMode(flex_pin4, INPUT);
  pinMode(flex_pin5, INPUT);
  Serial.begin(9600); //setup serial monitor 
}

void loop() {
  Serial.println("------");
  Serial.println();
  // put your main code here, to run repeatedly:
  flex_thumb = analogRead(A4);
  flex_index = analogRead(A0);
  flex_middle = analogRead(A1);
  flex_ring = analogRead(A2);
  flex_little = analogRead(A3);
  Serial.println("------");
  Serial.print("flex_index = ");
  Serial.println(flex_index);
  Serial.print("flex_middle = ");
  Serial.println(flex_middle);
  Serial.print("flex_ring = ");
  Serial.println(flex_ring);
  Serial.print("flex_little = ");
  Serial.println(flex_little);
  Serial.print("flex_thumb = ");
  Serial.println(flex_thumb); 

  flex_index = flex_index > 700;
  flex_middle = flex_middle > 1000;
  flex_ring = flex_ring > 1010;
  flex_little = flex_little > 940;
  flex_thumb = flex_thumb > 800;
  Serial.println("------");
  Serial.print("flex_index = ");
  Serial.println(flex_index);
  Serial.print("flex_middle = ");
  Serial.println(flex_middle);
  Serial.print("flex_ring = ");
  Serial.println(flex_ring);
  Serial.print("flex_little = ");
  Serial.println(flex_little);
  Serial.print("flex_thumb = ");
  Serial.println(flex_thumb);
/*
  if (flex_index && flex_middle && flex_ring && flex_little && flex_thumb){
    Serial.println("hi");
  }
*/
  if (flex_index && ~flex_middle && ~flex_ring  && ~flex_little && ~flex_thumb){
    Serial.println("ب");
  } else if (flex_index && flex_middle && ~flex_ring && ~flex_little && ~flex_thumb){
    Serial.println("ت");
  } else if (flex_index && flex_middle && flex_ring && ~flex_little && ~flex_thumb){
    Serial.println("ث");
  } else if (flex_index && flex_middle && flex_ring && flex_little && flex_thumb){
    Serial.println("س");
  } else if (flex_index && flex_middle && flex_ring && flex_little && ~flex_thumb){
    Serial.println("ك");
  } else if (flex_index && ~flex_middle && ~flex_ring && ~flex_little && flex_thumb){
    Serial.println("ل");
  } else if (flex_index && ~flex_middle && ~flex_ring && flex_little && ~flex_thumb){
    Serial.println("لا");
  } else if (~flex_index && ~flex_middle && ~flex_ring && flex_little && ~flex_thumb){
    Serial.println("م");
  } else if (~flex_index && ~flex_middle && ~flex_ring && flex_little && flex_thumb){
    Serial.println("ي");
  } else if (~flex_index && ~flex_middle && ~flex_ring && ~flex_little && flex_thumb){
    Serial.println("ي");
  } else {
    Serial.println("Nothing");
  }
/*
  if (flex_index > 600){
    if (flex_index  > 600 && flex_middle > 700){
      if (flex_index > 600 && flex_middle > 700 && flex_ring > 500){
        if (flex_index > 600 && flex_middle > 700 && flex_ring > 500 && flex_little > 900){
          if (flex_index > 600 && flex_middle > 700 && flex_ring > 500 && flex_little > 900 && flex_thumb > 800){
            Serial.println("س");
          } else {
            Serial.println("ك");
          }
        } else {
          Serial.println("ث");
        }
      } else if (flex_index > 600 && flex_thumb > 800){
        Serial.println("ل");
      } else if (flex_index > 600 && flex_little > 900){
        Serial.println("لا");
      } else {
        Serial.println("ت");
      }
      
    } else {
      Serial.println("ب");
    }
  } else if (flex_little > 1000){
    if (flex_little > 1000 && flex_thumb > 800){
      Serial.println("ي");
    } else {
      Serial.println("م");
    }
  } else if (flex_thumb > 800){
    Serial.println("أ");
  } else {
    Serial.println("Nothing");
  }
*/
  delay(1000);
}