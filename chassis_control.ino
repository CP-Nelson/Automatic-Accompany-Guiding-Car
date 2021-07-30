#define Enable_2  PB1
#define High_2 PB12     // MOTOR 2
#define Low_2 PB13

#define Enable_4 PB0
#define High_4 PB14       //MOTOR 4
#define Low_4 PB15

#define Enable_3 PA7
#define High_3 PB6      // MOTOR 3
#define Low_3 PB7

#define Enable_1 PA6
#define High_1 PB8     //MOTOR 1
#define Low_1 PB9

#define LED_BUILTIN PC13 //test for running

char inputData = '0' ;

int speed = 255;

void setup() {
  
Serial2.begin(9600);
Serial2.println("HC-05 Bluetooth with STM32");
pinMode(LED_BUILTIN, OUTPUT);


pinMode(Enable_2, OUTPUT);
pinMode(High_2, OUTPUT);
pinMode(Low_2, OUTPUT);
  
pinMode(Enable_4, OUTPUT);
pinMode(High_4, OUTPUT);
pinMode(Low_4, OUTPUT);

pinMode(Enable_1, OUTPUT);
pinMode(High_1, OUTPUT);
pinMode(Low_1, OUTPUT);
  
pinMode(Enable_3, OUTPUT);
pinMode(High_3, OUTPUT);
pinMode(Low_3, OUTPUT);

}

void blink()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  
}

void motor_1_forward()
{
  digitalWrite(High_1, LOW);
  digitalWrite(Low_1, HIGH);
  analogWrite(Enable_1,speed);
}

void motor_2_forward()
{
  digitalWrite(High_2, LOW);
  digitalWrite(Low_2, HIGH);
  analogWrite(Enable_2,speed);
}

void motor_3_forward()
{
  digitalWrite(High_3, LOW);
  digitalWrite(Low_3, HIGH);
  analogWrite(Enable_3,speed);
}

void motor_4_forward()
{
  digitalWrite(High_4, LOW);
  digitalWrite(Low_4, HIGH);
  analogWrite(Enable_4,speed);
}

void motor_1_backward()
{
  digitalWrite(High_1, HIGH);
  digitalWrite(Low_1, LOW);
  analogWrite(Enable_1,speed);
}

void motor_2_backward()
{
  digitalWrite(High_2, HIGH);
  digitalWrite(Low_2, LOW);
  analogWrite(Enable_2,speed);
}

void motor_3_backward()
{
  digitalWrite(High_3, HIGH);
  digitalWrite(Low_3, LOW);
  analogWrite(Enable_3,speed);
}

void motor_4_backward()
{
  digitalWrite(High_4, HIGH);
  digitalWrite(Low_4, LOW);
  analogWrite(Enable_4,speed);
}


void Forward()
{
  motor_1_forward();
  motor_2_forward();
  motor_3_forward();
  motor_4_forward();
}

void Backward()
{
  motor_1_backward();
  motor_2_backward();
  motor_3_backward();
  motor_4_backward();
}

void Rightmove()
{
  // 1 4 前转
  // 2 3 后转
  digitalWrite(High_1, LOW);
  digitalWrite(Low_1, HIGH);
  analogWrite(Enable_1,speed);
  
  digitalWrite(High_2,HIGH);
  digitalWrite(Low_2, LOW);
  analogWrite(Enable_2,speed);

  digitalWrite(High_3, HIGH);
  digitalWrite(Low_3, LOW);
  analogWrite(Enable_3,speed);

  digitalWrite(High_4, LOW);
  digitalWrite(Low_4, HIGH);
  analogWrite(Enable_4,speed);
}

void Lefttmove()
{
  // 1 4 后转
  // 2 3 前转
  motor_1_backward();
  motor_4_backward();
  motor_2_forward();
  motor_3_forward();
}
void Stop()
{
  digitalWrite(High_1, LOW);
  digitalWrite(Low_1, LOW);
  analogWrite(Enable_1,0);
  
  digitalWrite(High_2,LOW);
  digitalWrite(Low_2, LOW);
  analogWrite(Enable_2,0);

  digitalWrite(High_3, LOW);
  digitalWrite(Low_3, LOW);
  analogWrite(Enable_3,0);

  digitalWrite(High_4, LOW);
  digitalWrite(Low_4, LOW);
  analogWrite(Enable_4,0);
}

void Rightforward()
{
  motor_2_forward();
  motor_3_forward();
 }
  
void Leftforward()
{
  motor_1_forward();
  motor_4_forward();
}

void loop() 
{
   
  // Serial2.println("sending is working"); // check for sending
   
  if(Serial2.available() > 0)
  {
    inputData = Serial2.read();
    Serial2.println(inputData);  // debug: check for the working of RX port
 
    if (inputData =='0'){ Stop();} 
    
    if (inputData =='1'){ Forward();} 
    if (inputData =='2'){ Backward();}

    if (inputData =='3'){Rightmove();} 
    if (inputData =='4'){Lefttmove();} 
    
    if (inputData =='5'){Rightforward();} 
    if (inputData =='6'){Leftforward();} 
  }

}
