#ifndef _TASMANTIS_SIMPLEPIEZO_H_

#define _TASMANTIS_SIMPLEPIEZO_H_


#include <Arduino.h>

#include "TASMANTIS_SimplePiezo.h"


class TASMANTIS_SimplePiezo { /* -----------------------------------------------------------------------------------------------
* This CLASS ...
----------------------------------------------------------------------------------------------------------------------------- */

  public:

    TASMANTIS_SimplePiezo(int);

    bool beep(unsigned long, int);

    bool beep(unsigned long durat_ms)              { return beep(durat_ms, VOLUME_ON); }

    bool beep(void)                                { return beep(SHORT_MS); }

    bool longBeep(void)                            { return beep(LONG_MS); }

    bool rest(unsigned long durat_ms)              { return beep(durat_ms, VOLUME_OFF); }

    bool rest(void)                                { return rest(REST_MS); }

    bool beeps(unsigned long, unsigned long, int);

    bool beeps(int beep_n)                         { return beeps(SHORT_MS, REST_MS, beep_n); }

    bool longBeeps(int beep_n)                     { return beeps(LONG_MS, REST_MS, beep_n); }

    void off(bool);


  private:

    const int VOLUME_ON = 1010;

    const int VOLUME_OFF = 1023;

    const int SHORT_MS = 150;

    const int MED_MS = 300;

    const int LONG_MS = 500;

    const int REST_MS = 50;


    int piezo_pin;

    unsigned long time;

    bool is_beep,

         is_beeps;

    int beep_i;
};


#endif /* _TASMANTIS_SIMPLEPIEZO_H_ */
