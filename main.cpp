#include "mbed.h"

namespace {
#define PERIOD_MS 1000ms
}

InterruptIn button(BUTTON1);  // USER_BUTTON est généralement défini dans la bibliothèque mbed
DigitalOut led(LED1);           // LED1 est généralement défini dans la bibliothèque mbed

void on_button_rise()
{
    led = 1; // Allumer la LED lorsque le bouton est enfoncé
}

void on_button_fall()
{
    led = 0; // Éteindre la LED lorsque le bouton est relâché
}


int main()
{

	button.rise(&on_button_rise);  // attacher l'adresse de la fonction on_button_rise à la montée du bouton
    button.fall(&on_button_fall);  // attacher l'adresse de la fonction on_button_fall à la descente du bouton

    while (true) {
        ThisThread::sleep_for(PERIOD_MS / 8);
    }

}
