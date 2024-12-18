#include "NonBlockingTimer.h" 

NonBlockingTimer MyFirstTimer(2); //  parameters: duration, 's' (default) or 'u' for microseconds, false (default) or true for one-shot
NonBlockingTimer MySecondTimer(5000,'u',true);
NonBlockingTimer MyThirdTimer(6,'s');

int counter1 = 0;
int counter2 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  MyFirstTimer.start();
  MySecondTimer.start();
  MyThirdTimer.start();
  Serial.println("Delay of 5 sec before main loop starts");
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(MyFirstTimer.isLapsed()){
    Serial.print("Time of first timer is lapsed:"); Serial.println(counter1);
    counter1++;
  }

  if(MySecondTimer.isLapsed()){
    MyFirstTimer.setDuration(15);
    Serial.print("Time of second one-shot timer is lapsed and duration of first timer is changed");
  }

  if(MyThirdTimer.isLapsed()){
    Serial.print("Time of third timer is lapsed:"); Serial.println(counter2);
    counter2++;
  }

}
