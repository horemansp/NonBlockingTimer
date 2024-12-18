# NonBlockingTimer
C++ library files to implement non-blocking timers

# Installation/usage
1. Either add the .h and .cpp files to your sketch and use ```#include "NonBlockingTimer.h"``` in your sketch <br>
2. Or install the files in your library for the Arduino IDE.
   - Make a folder with name ```NonBlockingTimer``` in your Arduino libraries folder and add the .h and .cpp files to it. By default Documents\Arduino\libraries
   - Include in your sketch with ```#include <NonBlockingTimer.h>```
  
# Create object
Example: ```NonBlockingTimer MyFirstTimer(2000,'u',true);```

| Parameter | Required | Default | Values                                                                                     |
|-----------|----------|---------|--------------------------------------------------------------------------------------------|
| duration  | yes      |         | integer                                                                                    |
| Units     | no       | 's'     | String 's' for seconds or 'u' for microseconds. ('s' is used by default if not specified)  |
| One-shot  | no       | false   | boolean true or false (false is used by default if not specified)                          |
# Methods
| Method           | Type       |   Purpose                                                                                      |
|------------------|-----------------------|------------------------------------------------------------------------------------------------|
| .start()         | NA                    | Start running                                                                                  |
| .isLapsed()      | Boolean               | Returns ```true``` if duration is lapsed                                                       |
| .reset()         | NA                    | Restarts the duration                                                                          |
| .currentValue()  | long int              | Returns the lapsed duration time in µSeconds                                                   |
| .setDuration()   | int,(optional String) | Change the duration of a timer for example ```.setDuration(2000,'u')``` or ```.setDuration(2)```<br> If not specified default is 's'               | 


