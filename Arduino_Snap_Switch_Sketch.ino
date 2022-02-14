const int switch1pin1=3;//set up digital pin 2 for controlling switch 1
const int switch1pin2=4;//set up digital pin 3 for controlling switch 1
const int button=A0;//set up analog pin A0 for reading button 1
int State1=0;//Sets our value for the state of switch 1

void setup() {
  Serial.begin(9600);//sets up our readings in the serial monitor and the baud rate of 9600
  pinMode(switch1pin1,OUTPUT);
  pinMode(switch1pin2,OUTPUT);
  
}
enum SWITCHSTATES
{
  ST_OFF,
  ST_STRAIGHT,
  ST_TURN,
};//Sets up states that arduino can hop between

SWITCHSTATES switchState=ST_OFF;

void loop(){
  Serial.println("State 1");
  Serial.println(State1);//display in serial monitor what the State of State 1 is with the text "State 1" in front.
int ButtonRead=analogRead(button);//Stores value for button1

  Serial.println("Button");
  Serial.println(ButtonRead);//display in serial monitor what the State of Button 1 is with the text "Button 1" in front.
  delay(200);// 0.2 second pause between readings
  switch(switchState)
  {
    case ST_OFF:
    switchoff(ButtonRead,State1);
    break;
    case ST_STRAIGHT:
    switchstraight(ButtonRead);
    break;
    case ST_TURN:
    switchturn(ButtonRead);
    break;
    
  }
}

void switchoff(int ButtonRead, int State1){
  digitalWrite(switch1pin1,HIGH);
  digitalWrite(switch1pin2,HIGH);

 
  if ((ButtonRead>500) && (State1==1)){
    switchState=ST_STRAIGHT;//sends to straight 1 with button press
  }
  if ((ButtonRead>500) && (State1==0)){
    switchState=ST_TURN;//sends to turn 1 with button press
  }
}

void switchstraight(int ButtonRead){
  digitalWrite(switch1pin1,HIGH);
  digitalWrite(switch1pin2,LOW);
  delay(500);
  digitalWrite(switch1pin1,HIGH);
  digitalWrite(switch1pin2,HIGH);
  State1=0;//sets value to 0
  switchState=ST_OFF;//sends program back to off
  }
    

void switchturn(int ButtonRead){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,HIGH);
  delay(500);
  digitalWrite(switch1pin1,HIGH);
  digitalWrite(switch1pin2,HIGH);
  State1=1;//sets value to 1
  switchState=ST_OFF;//sends program back to off
   
  }
