#include "TASMANTIS_SimplePiezo.h"


TASMANTIS_SimplePiezo::TASMANTIS_SimplePiezo(int piezo_pin) { /* ---------------------------------------------------------------
* This CONSTRUCTOR ...
* --------------------------------------------------------------------------------------------------------------------------- */

    this->piezo_pin = piezo_pin;


    pinMode(piezo_pin, OUTPUT);

    off(true);
}


bool TASMANTIS_SimplePiezo::beep(unsigned long durat_ms, int vol) { /* ---------------------------------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    if (!is_beep) {

        is_beep = true;

        time = millis();

    } else {

        analogWrite(piezo_pin, vol);


        if(millis() >= (time + durat_ms)) {

            off(false);

            return true;

        } else

            return false;
    }

    return false;
}


bool TASMANTIS_SimplePiezo::beeps(unsigned long beep_ms, unsigned long rest_ms, int beep_n) { /* -------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    if (!is_beeps) {

        is_beeps = true;

        beep_i = 0;

    } else {

        if ((beep_i % 2) == 0) {

            if (beep(beep_ms)) beep_i++;

        } else {

            if (rest(rest_ms)) beep_i++;
        }


        if (beep_i == (beep_n * 2)) {

            off(true);

            return true;
            
        } else

            return false;
    }

    return false;
}


void TASMANTIS_SimplePiezo::off(bool is_full) { /* -----------------------------------------------------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    analogWrite(piezo_pin, VOLUME_OFF);


    is_beep = false;

    if (is_full) is_beeps = false;
}
