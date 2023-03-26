
#include <LiquidCrystal.h> //Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal
#include <Keypad.h> //Header file for Keypad from https://github.com/Chris--A/Keypad

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
int MS1 = 40;
int MS2 = 42;
const int stepPin = 32; 
const int dirPin = 34;
int V ;
const float P = 1.25;
float L ;
const float Tl = 0.001;
int S = 400;
float Q=0.0;
float T = 0;
float Tf = 0;  
float Vp =0;
float Num4 = 0;
float Num5 = 0;
float Numm = 0;
float st = 0;
float ptMillis = 0;
char dec;
int buzz = 24;

 


 

// Define the Keymap
char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','.'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = { 33, 35, 37, 39 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 41, 43, 45, 47 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 2; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 long Num1,Num2;
float Number;
float Num3;
float Num6;
 char key,action;
 boolean result = false;
float curMillis;
 
void setup() {
  lcd.begin(16, 2); //We are using a 16*2 LCD display
      lcd.cursor();
  lcd.setCursor(2,0);
  lcd.print("SYRINGE PUMP"); //Display a intro message
 Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(buzz, OUTPUT);
   pinMode(stepPin, OUTPUT);
  digitalWrite(MS1,HIGH);
  digitalWrite(MS2,LOW);
   delay(3000); //Wait for display to show info
    lcd.clear(); //Then clean it
  Serial.println ("please enter the volume then Press A to Enter Syringe SIZE");
  lcd.setCursor(0, 0);
  lcd.print("Enter Vol.(ml)");
  lcd.setCursor(0,1);
  lcd.print("Then Press A");
delay(2000);
lcd.clear();

}

void(* resetFunc) (void) = 0;
void loop() {
     digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 400 pulses for making one full cycle rotation
   if (result==true)
 {
  
 Serial.println(curMillis);
    Serial.println(st);
    curMillis = millis();
    if (curMillis == st )
  {
    resetFunc();
    //break;
  }
   
  for(int lm = 0; lm<S; lm++) {

    
    
    
   
    digitalWrite(stepPin,HIGH);
    digitalWrite(stepPin,LOW);
    delay(Tf); 

    


    
   
    
    lcd.leftToRight();
    key = kpd.getKey();
if( key == 'D')

  {
    for(int bz=0;bz<3;bz++){
    tone(buzz,10000);
delay(500);
noTone(buzz);
 delay(500);}
    resetFunc();

  }




  
   // key = kpd.getKey();
else if (key == 'C')
    {lcd.clear();
      Serial.println ("Bolus");
    lcd.print("Bolus");
    while(1) {


      
    digitalWrite(dirPin,HIGH);
  
    digitalWrite(stepPin,HIGH);  
    digitalWrite(stepPin,LOW); 
    delay(1);
   
      key = kpd.getKey();

  if( key == 'D')

  {
    resetFunc();
  }
  
}}

 
  } 


  
}

key = kpd.getKey(); //storing pressed key value in a char
if (key!=NO_KEY)
DetectButtons();

if (result==true)
results();



}

void DetectButtons()
{ 
          
    if (key=='*') //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {Serial.println ("Button 1");
     lcd.print('1'); 
    if (Number==0)
    {
      if (dec == '.')
      {
      Number=1;
      Num6=Number / 10;
      }
      else
      Number=1;
    }
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4");
      
      lcd.print('4'); 
    if (Number==0)
    {
      if (dec == '.')
      {
      Number=4;
      Num6=Number / 10;
      }
      else
      Number=4;
    }
    else
    Number = (Number*10) + 4; //Pressed twice
    }

    if (key == 'C')
    {Serial.println ("Bolus");
    lcd.print("Bolus");
    while(1) {

      
    digitalWrite(dirPin,HIGH);
    //if (result==true)
  
    digitalWrite(stepPin,HIGH);  
    //delay(1);
    digitalWrite(stepPin,LOW); 
    delay(1);
   
      key = kpd.getKey();

  if( key == 'D')

  {
    resetFunc();
  }
  
}}


 
    if (key == '*')
    {    
      Serial.println ("BACKWARD");
    lcd.print("BACKWARD");
    
 
   while(1) {


    digitalWrite(dirPin,LOW);
    
    digitalWrite(stepPin,HIGH);  
    digitalWrite(stepPin,LOW); 
    delay(1);
      key = kpd.getKey();

  if( key == 'D')

  {
    resetFunc();
  }


  }
      
  
  }
    
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
        lcd.print("7");
    if (Number==0)
    {
      if (dec == '.')
      {
      Number=7;
      Num6=Number / 10;
      }
      else
      Number=7;
    }
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0')
    {Serial.println ("Button 0"); //Button 0 is Pressed
        lcd.print("0");
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2");
        lcd.print("2"); 
     if (Number==0)
    {
      if (dec == '.')
      {
      Number=2;
      Num6=Number / 10;
      }
      else
      Number=2;
    }
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {Serial.println ("Button 5");
        lcd.print("5"); 
     if (Number==0)
    {
      if (dec == '.')
      {
      Number=5;
      Num6=Number / 10;
      }
      else
      Number=5;
    }
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8')
    {Serial.println ("Button 8");
        lcd.print("8"); 
     if (Number==0)
    {
      if (dec == '.')
      {
      Number=8;
      Num6=Number / 10;
      }
      else
      Number=8;
    }
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '#')
    {Serial.println ("Button Equal"); 
    ptMillis = millis();
    
    Num3= Number;
    Number=0;
    Serial.println (Num3);
    Serial.println (Num6);
    result = true;
    lcd.clear();
    if (dec == '.')
    lcd.print(Num6);
    else
    lcd.print(Num3);
    lcd.print(" ml/h");
    Num4= Num3/Num1;
    Num5=3600/Num4;
    Numm = (Num5 * 1000);
    st = Numm + ptMillis;
    
    }
    
     if (key == '3')
    {Serial.println ("Button 3");
        lcd.print("3"); 
     if (Number==0)
    {
      if (dec == '.')
      {
      Number=3;
      Num6=Number / 10;
      }
      else
      Number=3;
    }
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6')
    {Serial.println ("Button 6");
        lcd.print("6"); 
    if (Number==0)
    {
      if (dec == '.')
      {
      Number=6;
      Num6=Number / 10;
      }
      else
      Number=6;
    }
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    lcd.print("9");
    if (Number==0)
    {
      if (dec == '.')
      {
      Number=9;
      Num6=Number / 10;
      }
      else
      Number=9;
    }
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key == 'A') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Enter length of syringe then Press B to enter flowrate");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ent. Flow Rate(ml/h).");
    lcd.setCursor(0,1);
    lcd.print("then Press #");}
     

  }

  if( key == '.')

  {
    
    dec='.';
    lcd.print(".");
  Serial.println (".");
    
    
 }
  
  
}



void results()
{
  float L =0;
  if (Num1 == 50)
  {
    L = 75;
    }
  else if (Num1 == 10)
   {
      L = 57;
      }
      else if (Num1 == 20)

      {
        L = 68;
        }

      else if (Num1 == 30)
      {
        L = 79;
        }

       else
       {
        resetFunc();
        }

        if (dec == '.')
        {
          T= (((Num1 * 1.25) * 3600) - (L - 0.001)) / ((L* 400) * Num6);
  
   Tf = (T * 1000);
        }
else
{
    T= (((Num1 * 1.25) * 3600) - (L - 0.001)) / ((L* 400) * Num3);
  
   Tf = (T * 1000);
}


}
