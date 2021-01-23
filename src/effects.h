#ifndef _EFFECTS_H    // Put these two lines at the top of your file.
#define _EFFECTS_H    // (Use a suitable name, usually based on the file name.)

class Effect {
  protected:
    const int led[4] = {D5, D6, D7, D8};
  public:
    Effect(){};
    virtual void Action() = 0;
    virtual void SecondaryAction() = 0;
    virtual void Reset() =0;
};

class AllLedCycle : public Effect {
    int pwr[4];
    int change[4];
    int spd;

  public:
    AllLedCycle() {
      Reset();
    }

    void Action() {
      for (int i = 0; i < 4; i++)
      {
        if (pwr[i] < 0) {
          change[i] = -change[i];
        }
        if (pwr[i] > 512) {
          change[i] = -change[i];
        }
        pwr[i] += change[i] * spd;
        analogWrite(led[i], pwr[i]);
      }
      delay(10);
    }

    void SecondaryAction() {
      spd+=1;    
      if (spd>20) {
        spd=2;
      }
    }

    void Reset() {
      pwr[0] = 0;
      pwr[1] = 256;
      pwr[2] = 512;
      pwr[3] = 256;
      change[0] = 1;
      change[1] = 1;
      change[2] = -1;
      change[3] = -1;
      spd = 2;
    }
};

class AllLedOn : public Effect {
  int force = 256;
    public:
    AllLedOn() {
      Reset();  
    }
    void Action () {
      delay(100);
    }
    void SecondaryAction() {
      force = force + 256;
      if (force > 1024) 
      {
        force = 256;
      }
      Reset();
    }
    void Reset() {
      for (int i = 0; i < 4; i++) {
        analogWrite(led[i], force);
      }
    }
};

class AllLedOff : public Effect {
    public:
    AllLedOff() {
      Reset();  
    }
    void Action () {
      delay(100);
    }
    void SecondaryAction() {
    }
    void Reset() {
      for (int i = 0; i < 4; i++) {
        digitalWrite(led[i], false);
      }
    }
};

class FirstLedOn : public Effect {
  int force = 256;
  public:
    FirstLedOn() {};
    void Action () {
      delay(100);
    }
    void SecondaryAction() {
      force = force + 256;
      if (force > 1024) 
      {
        force = 256;
      }
      Reset();
    }
    void Reset() {
      analogWrite(led[0], force);
      digitalWrite(led[1], false);
      digitalWrite(led[2], false);
      digitalWrite(led[3], false);
    }
};

class SecondLedOn : public Effect {
  int force = 256;
  public:
    SecondLedOn() {};
    void Action () {
      delay(100);
    }
    void SecondaryAction() {
      force = force + 256;
      if (force > 1024) 
      {
        force = 256;
      }
      Reset();
    }
    void Reset() {
      analogWrite(led[1], force);
      digitalWrite(led[0], false);
      digitalWrite(led[2], false);
      digitalWrite(led[3], false);
    }
};

class ThirdLedOn : public Effect {
  int force = 256;
  public:
    ThirdLedOn() {};
    void Action () {
      delay(100);
    }
    void SecondaryAction() {
      force = force + 256;
      if (force > 1024) 
      {
        force = 256;
      }
      Reset();
    }
    void Reset() {
      analogWrite(led[2], force);
      digitalWrite(led[0], false);
      digitalWrite(led[1], false);
      digitalWrite(led[3], false);

    }
};

class FourthLedOn : public Effect {
  int force = 256;
  public:
    FourthLedOn() {};
    void Action () {
      delay(100);
    }
    void SecondaryAction() {
      force = force + 256;
      if (force > 1024) 
      {
        force = 256;
      }
      Reset();
    }
    void Reset() {
      analogWrite(led[3], force);
      digitalWrite(led[0], false);
      digitalWrite(led[1], false);
      digitalWrite(led[2], false);
    }
};


#endif // _EFFECTS_H    // Put this line at the end of your file.
