# NonBlockingTimer
C++ library files to implement non-blocking timers

# Installation/usage
1. Either add the .h and .cpp files to your sketch and use ```#include "NonBlockingTimer.h"``` in your sketch <br>
2. Or install the files in your library for the Arduino IDE.
   - Make a folder with name ```NonBlockingTimer``` in your Arduino libraries folder and add the .h and .cpp files to it. By default Documents\Arduino\libraries
   - Include in your sketch with ```#include <myPrint.h>```
  
# Create object
Example: ```NonBlockingTimer MyFirstTimer(2000,'u',true);```

| Parameter | Required | Default | Values                                                                                     |
|-----------|----------|---------|--------------------------------------------------------------------------------------------|
| duration  | yes      |         | integer                                                                                    |
| Units     | no       | 's'     | String 's' for seconds or 'u' for microseconds. ('s' is used by default if not specified)  |
| One-shot  | no       | false   | boolean true or false (false is used by default if not specified)                          |
# Methods
| Method           | Purpose
|------------------|-----------------------------------------------|
| .start()         | Start running                                 |
| .isLapsed()      | Returns ```true``` if duration is lapsed      |
| .reset()         | Restarts the duration                         |
| .currentValue()  | Returns the lapsed duration time in µSeconds  |


