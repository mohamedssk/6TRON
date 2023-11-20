#include "mbed.h"

namespace {
#define PERIOD_MS 2000ms
}

// Déclarer un objet DigitalIn pour le bouton et un objet DigitalOut pour la LED
DigitalIn button(BUTTON1);  // USER_BUTTON est généralement défini dans la bibliothèque mbed
DigitalOut led(LED1);           // LED1 est généralement défini dans la bibliothèque mbed

int main()
{
    while (true) {
        // Lire l'état du bouton (0 lorsque le bouton est enfoncé, 1 lorsque le bouton est relâché)
        if (button == 0) {
            // Allumer la LED lorsque le bouton est enfoncé
            led = 0;
        } else {
            // Éteindre la LED lorsque le bouton est relâché
            led = 1;
        }

        ThisThread::sleep_for(PERIOD_MS / 2);
    }
}
