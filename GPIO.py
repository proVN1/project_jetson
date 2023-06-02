import time
import Jetson.GPIO as GPIO

###########################API function####################################

#function of set mode:

def GPIO_SetModePin(pin_number, modepin):
    if modepin == "input":
        GPIO.setup(pin_number, GPIO.IN)
    elif modepin == "output":
        GPIO.setup(pin_number, GPIO.OUT)
    else:
        print("Invalid mode. Please choose either 'input' or 'output'.")

###########################################################################

#function of set up:

def GPIO_SetUp(mode):
    if mode == "BCM":
        GPIO.setmode(GPIO.BCM)          # GPIO7 : GPIO7 (BCM)
    elif mode == "BOARD":
        GPIO.setmode(GPIO.BOARD)        #GPIO7: PIN7 
    else:
        print("Invalid mode. Please choose either 'BCM' or 'BOARD'.")

###########################################################################

#function of output mode:

def GPIO_Output(pin_number, state):
    if state == "HIGH":
        GPIO.output(pin_number,GPIO.HIGH)
    if state == "LOW":
        GPIO.output(pin_number,GPIO.LOW) 

###########################################################################

#function of input mode:

def GPIO_Input(pin_number):
    state = GPIO.input(pin_number)
    return state

###########################################################################

#function of add a new event:

def GPIO_Add_Event_Detect(pin_number, edge, callback):
    GPIO.setup(pin_number,GPIO.IN)
    GPIO.add_event_detect(pin_number, edge, callback) 

#function of event callback:
def event_callback(pin_number):
    print("the event took place in GPIO: ",pin_number)

###########################################################################

#function of remove event:

def GPIO_Remove_Event_Detect(pin_number):
    GPIO.remove_event_detect(pin_number)