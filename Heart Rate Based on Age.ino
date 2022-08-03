//Heart Rate Based on Age

int age;     //Age is given in integer form
int heart rate;   //Heart rate is given in integer form

lcd.print("Enter the age:"); //Display the age of the person in LCD Display
scanf("%u", &age);   //Take the input of the age from the user

if(age>=0 || age<=15){ //If the age is between 0 to 15 years old
if(heart_rate>=80 && heart_rate<=120)   //If the heart rate is between 80 BPM to 120 BPM
lcd.print("Heart Rate is normal"); //Display the heart rate of the person as “Normal” on the LCD Display if the condition is true

else{
lcd.print("Abnormal heart rate"); //If the condition is false, then the LCD Display would show “Abnormal heart rate”
}

if(age>=16 || age<=48){ //If the age is between 16 to 48 years old

if(heart_rate>=60 && heart_rate<=100) //If the heart rate is between 60 BPM to 100 BPM

lcd.print("Heart Rate is normal"); //Display the heart rate of the person as “Normal” on the LCD Display if the condition is true

else{
lcd.print("Abnormal heart rate"); //If the condition is false, then the LCD Display would show “Abnormal heart rate”

}

if(age>=49 || age<=75){ //If the age is between 49 to 75 years old

if(heart_rate>=50 && heart_rate<=80) //If the heart rate is between 50 BPM to 80 BPM

lcd.print("Heart Rate is normal"); //Display the heart rate of the person as “Normal” on the LCD Display if the condition is true

else{
lcd.print("Abnormal heart rate"); //If the condition is false, then the LCD Display would show “Abnormal heart rate”

}
lcd.clear(); //Clear the LCD Display window

