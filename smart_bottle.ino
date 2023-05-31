/*

         ___     ,---.                          ,----.                                                    ,----.           ,-.-.                   _,.----.       _.---.,_      ,-----.--.  
  .-._ .'=.'\   .--.'  \       _,..---._      ,-.--` , \            _..---.    ,--.-.  .-,--.           ,-.--` , \ ,-..-.-./  \==\   .-.,.---.    .' .' -   \    .'  - , `.-,   /` ` - /==/  
 /==/ \|==|  |  \==\-/\ \    /==/,   -  \    |==|-  _.-`          .' .'.-. \  /==/- / /=/_ /           |==|-  _.-` |, \=/\=|- |==|  /==/  `   \  /==/  ,  ,-'   / -  ,  ,_\==\  `-'-. -|==|  
 |==|,|  / - |  /==/-|_\ |   |==|   _   _\   |==|   `.-.         /==/- '=' /  \==\, \/=/. /            |==|   `.-. |- |/ |/ , /==/ |==|-, .=., | |==|-   |  .  |     .=.   |==|     | `|==|  
 |==|  \/  , |  \==\,   - \  |==|  .=.   |  /==/_ ,    /         |==|-,   '    \==\  \/ -/            /==/_ ,    /  \, ,     _|==| |==|   '='  / |==|_   `-' \ | -  :=; : _|==|     | -|==|  
 |==|- ,   _ |  /==/ -   ,|  |==|,|   | -|  |==|    .-'          |==|  .=. \    |==|  ,_/             |==|    .-'   | -  -  , |==| |==|- ,   .'  |==|   _  , | |     `=` , |==|     | `|==|  
 |==| _ /\   | /==/-  /\ - \ |==|  '='   /  |==|_  ,`-._         /==/- '=' ,|   \==\-, /              |==|_  ,`-._   \  ,  - /==/  |==|_  . ,'.  \==\.       /  \ _,    - /==/    .-','|==|  
 /==/  / / , / \==\ _.\=\.-' |==|-,   _`/   /==/ ,     /        |==|   -   /    /==/._/               /==/ ,     /   |-  /\ /==/   /==/  /\ ,  )  `-.`.___.-'    `.   - .`=.`    /     \==\  
 `--`./  `--`   `--`         `-.`.____.'    `--`-----``         `-._`.___,'     `--`-`                `--`-----``    `--`  `--`    `--`-`--`--'                    ``--'--'      `-----`---` 

*/


// Follow me on github https://github.com/EWRC01
//Connect with me on LinkedIn https://linkedin.com/in/ewrc01


// Include the library to manage better the ultrasonic sensor
#include <Ultrasonic.h>

// Define the pins of ultrasonic sensor
Ultrasonic ultrasonic(12, 14);

// Define the variables 
int led_red = 4;
int led_green = 5;
int buzzer = 13;

// Define a void to get the Distance and notify the user when the water reach zero or low level
void getDistance() {
  float distanceSensor = ultrasonic.distanceRead();
  float value = distanceSensor; // Read the value of ultrasonic
  
  // Init a conditional, if the value isnan print Failed to Read the data

  if (isnan(distanceSensor)) {
    Serial.println("Failed To Read the data");
    return;
  }

  // Init a conditional, based in the measures of the bottle, when it reach some value do some action

  if (value > 17) {
    digitalWrite(led_red, HIGH); //  Turn on the Red LED 
    digitalWrite(led_green, LOW); // Turn Off the Green LED
    tone(buzzer, 540,1000); // Beep the buzzer for 1 second
  } else {
    digitalWrite(led_green, HIGH); // Turn on the Green LED
    delay(1000); // Wait 1 second
    digitalWrite(led_red, LOW); // Turn off the Red LED
    //tone(buzzer, 523, 500); // Optional: Beep the Buzzer
  }

  Serial.print("Distance: "); // Print in serial the follow text
  delay(1000); // Wait 1 second
  Serial.print(value); // Print in Serial the value of the distance
  delay(1000); // Wait 1 second
  Serial.println(); // Line Break on Serial
  delay(1000); // Wait 1 second

  /* Advisory: It's important to test with the delays.
     because is probably the Serial and the ide in general
     can be stucked by the among of data every second */
}

void setup() {
  Serial.begin(9600); // Init the Serial in 9600 baud
  pinMode(led_red, OUTPUT); // Red Led as OUTPUT
  pinMode(led_green, OUTPUT); // Green Led as OUTPUT
  pinMode(buzzer, OUTPUT); // Buzzer pin as OUTPUT
}

void loop() {
  getDistance(); // Call the function in loop
}
