#ifndef _BUTTON_H    // Put these two lines at the top of your file.
#define _BUTTON_H    // (Use a suitable name, usually based on the file name.)

class Button {
  protected:
    unsigned short pin;
    unsigned long buttonPressTime = 0;
    unsigned long buttonRepeatCount = 0;
    bool previousButtonState = false;

  public:
    Button(unsigned short pin)
    {
        this->pin = pin;
        pinMode(pin, INPUT_PULLUP);
    };


    /* Check button state -- 
    ** return   0 if unpressed
    **          1 is single click
    **          2 is long click
    */
    unsigned short Check() 
    {
        bool buttonState = !digitalRead(pin);
        if (buttonState == previousButtonState) 
        {
            if (buttonPressTime) //ButtonClicked
            {
                double duration = millis() - buttonPressTime;
      
                if (((unsigned int)(duration / 500)) != buttonRepeatCount)
                {
                    buttonRepeatCount = duration/500;
                    return 2; //LongClick
                }
            }
            return 0;
        } else 
        {
            previousButtonState = buttonState;
            if (buttonState) //Pressed
            { 
                buttonPressTime = millis();
                return 0;
            }
            else //Released
            { 
                double duration = (millis() - buttonPressTime);
                buttonPressTime = 0; 
                if (duration > 2 && duration < 500) 
                {
                    return 1; //SingleClick
                } else 
                {
                    return 2; //LongClick
                }
            return 0;
            }
        }
    }
};

#endif // _BUTTON_H    // Put this line at the end of your file.
