#include "mbed.h"

DigitalOut led(LED1);
Mutex led_mutex;

void ping() {
    for (int i = 0; i < 100; i++) {
        led_mutex.lock();
        printf("Ping\n");
        led_mutex.unlock();
        ThisThread::sleep_for(100ms);
    }
}

void pong() {
    for (int i = 0; i < 100; i++) {
        led_mutex.lock();
        printf("Pong\n");
        led_mutex.unlock();
        ThisThread::sleep_for(100ms);
    }
}

int main() {
    Thread pingThread(osPriorityNormal, 1024); // Priorité normale
    Thread pongThread(osPriorityAboveNormal, 1024); // Priorité supérieure

    pingThread.start(callback(ping));
    pongThread.start(callback(pong));

    while (1) {
        led_mutex.lock();
        led = !led;
        printf("Alive!\n");
        led_mutex.unlock();
        ThisThread::sleep_for(500ms);
    }
}
