#ifndef GPIO_API_H
#define GPIO_API_H

void GPIO_SetUp(int mode);
void GPIO_SetModePin(int pin_number, int modepin);
void GPIO_Output(int pin_number, int state);
void GPIO_Input(int pin_number);
void GPIO_Add_Event_Detect(int pin_number,int edge, void (*event_callback)(int));
void GPIO_Remove_Event_Detect(int pin_number);

#endif /* GPIO_API_H */