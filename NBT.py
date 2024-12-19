import time

class NonBlockingTimer:
    def __init__(self, interval: int, unit: str = 's', oneshot: bool = False):
        """ Initialize the timer.
        Args:
            interval (int): Timer duration.
            unit (str, optional): Time unit. 's' for seconds, 'u' for microseconds. Defaults to 's'.
            oneshot (bool, optional): If True, timer will trigger only once. Defaults to False.
        """
        if unit not in ['s', 'u']:
            raise ValueError("Unit must be 's' for seconds or 'u' for microseconds.")
        
        self.interval = interval
        self.unit = unit
        self.oneshot = oneshot
        self.start_time = None
        self.lapsed = False

    def start(self):
        """ Start or restart the timer. """
        self.start_time = time.time()
        self.lapsed = False
        if self.unit == 'u':
            self.interval /= 1_000_000  # Convert microseconds to seconds if unit is microseconds.

    def reset(self):
        """ Reset the timer. """
        self.start_time = time.time()
        self.lapsed = False

    def isLapsed(self) -> bool:
        """ Check if the timer has lapsed. """
        if self.start_time is None:
            raise ValueError("Timer has not been started.")
        
        elapsed_time = time.time() - self.start_time
        if not self.oneshot:
            if elapsed_time >= self.interval:
                self.lapsed = True
                self.start_time = time.time()
                if self.oneshot:
                    self.reset()  # Reset the timer after it lapses if it's a oneshot timer.
                return True
            
            return False
    
    def currentValue(self) -> int:
        """ Returns the elapsed time since last restart"""
        return time.time() - elapsed_time
    
    def setDuration(self, duration: int, unit: str = 's'):
        self.interval = duration / (1_000_1000 if self.unit == 'u' else 1)