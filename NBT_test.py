import NBT

first_timer = NBT.NonBlockingTimer(2)
second_timer = NBT.NonBlockingTimer(30,'s',True)
third_timer = NBT.NonBlockingTimer(25)


first_timer.start()
second_timer.start()
third_timer.start()

counter = 0
while True:
    
    if first_timer.isLapsed():
        print("first timer lapsed!",counter)
        counter +=1
        
    if second_timer.isLapsed():
        print("second timer lapsed, set time of first timer")
        first_timer.setDuration(10)
        
    if third_timer.isLapsed():
        print("third timer is lapsed")
        
    