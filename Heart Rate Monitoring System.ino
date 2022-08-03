//Heart Rate Monitoring System 

#include<LiquidCrystal.h> //Includes Liquid Crystal Library 


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Set the pins in the LCD


int in = 8; //Assign an integer variable ‘in’ and initialize the value 8 inside it.


int Reset=6; //Assign an integer variable ‘Reset’ and initialize the value 6 inside it.



int start=7; //Assign an integer variable ‘start’ and initialize the value 7 inside it.



int count=0; //Assign an integer variable ‘count’ and initialize the value 0 inside it.




int i=0; //Assign an integer variable ‘i’ and initialize the value 0 inside it.




int k=0;//Assign an integer variable ‘k’ and initialize the value 0 inside it.




int rate=0;//Assign an integer variable ‘rate’ and initialize the value 0 inside it.






unsigned long time2,time1; //Unsigned are the positive numbers and ‘unsigned long variables’ creates a number of storage of 4 bytes, which is equivalent to 32 bits

unsigned long time;

//LCD create character code
byte heart[8] = 

{

  0b00000,

  0b01010,

  0b11111,

  0b11111,

  0b11111,

  0b01110,

  0b00100,

  0b00000

};



void setup() { //Start of the program

  lcd.createChar(1, heart); //lcd icon for declaring a character


  lcd.begin(16,2); //16*2 LCD means that it can display 16 characters per line and there are 2 such lines   

  lcd.print("Heart Beat "); //Prints data to the LCD Display. Function is same as serial.print()


  lcd.write(1); //Writes the data to the LCD Display

  lcd.setCursor(0,1);  //Controls the LCD displays


  lcd.print("Monitoring"); ; //Prints data to the LCD Display. Function is same as serial.print()


  pinMode(in, INPUT); //Sets the Pin as input. Here the pin is 8 as the variable ‘in’ is assigned an integer value of 8



  pinMode(Reset, INPUT); //Sets the Pin as input. Here the pin is 6 as the variable ‘reset’ is assigned an integer value of 6 



  pinMode(start, INPUT);  //Sets the Pin as input. Here the pin is 7 as the variable ‘start’ is assigned an integer value of 7 


  digitalWrite(Reset, LOW); //Write a HIGH or LOW value to digitalWrite.But here we need to reset the value when it is LOW

  digitalWrite(start, HIGH);  //Write a HIGH or LOW value to digitalWrite.But here we need to reset the value when it is HIGH


  delay(1000); //Pauses the program for an amount of time. Here, the program will be paused for 1000ms

  pinMode(2, INPUT); //Sets Pin 2 as the INPUT

 Serial.begin(9600); //Implies how fast a data is sent. Sets “Serial Communication” so that the Arduino can sent out commands through USB Connection

}

void loop() {  //Mandatory in Arduino and the code will run/repeat multiple times
 
  if(!(digitalRead(start)))  //If the digitalRead does not read the value from the ‘start’ variable, which was assigned as 7

  {

    k=0;

    lcd.clear(); //Clears the LCD Screen and positions the Cursor in the upper-left corner

    lcd.print("Please wait.......");

    while(k<5)

    {

     if(digitalRead(in)) //Read the value from ta specified digital pin, either HIGH/LOW 

     {

      if(k==0) //If the value of k is equals to 0 or assigned as 0 in if-else loop

      time1=millis();

      k++; //The value of k will be post incremented if the value is true

      while(digitalRead(in)); //Read the value from a specified digital pin named as ‘in’ variable, where the value is assigned as 8

     }

  
     time2=millis();

//Formula for Measuring the Heart Rate

      rate=time2-time1;

      rate=rate/5;

      rate=60000/rate;


      lcd.clear(); //Clears the LCD Screen and positions the Cursor in the upper-left corner



      lcd.print("Heart Beat Rate:");

      lcd.setCursor(0,1); //Set the cursor of the LCD display to the pins 0 and 1

      lcd.print(rate);

      lcd.print(" ");

      lcd.write(1);
       
      

      if  (rate>100 or rate<60) //If the heart rate is greater than 100bpm and less than 60bpm 
      { lcd.clear();   

        lcd.print("Abnormal BPM");

        lcd.setCursor(0,1);  //Set the cursor of the LCD display to the pins 0 and 1


        lcd.print(rate);

       }

      

      k=0;

      rate=0; //The heart rate is assigned as 0


    }

  if(!digitalRead(Reset)) //If the digitalRead does not read the value from the reset variable, which was assigned as 6

  {

    rate=0; //The heart rate is assigned as 0

     lcd.clear();  //Clears the LCD Screen and positions the Cursor in the upper-left corner


      lcd.print("Heart Beat Rate:"); 

      lcd.setCursor(0,1);  //Set the cursor of the LCD display to the pins 0 and 1

      lcd.write(1);

      lcd.print(rate); //Print the Heart Rate that is shown on the LCD display

      k=0;

  }
}
