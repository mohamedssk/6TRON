#include "mbed.h"

I2C bus(I2C1_SDA, I2C1_SCL);

const int addr8bit = 0x76 << 1; // 8bit I2C address, 0x90

int main()
{
    char cmd[1];
    
    printf("Initialisation du capteur BME280...\n");
    
    ThisThread::sleep_for(100ms); // Attente après la mise sous tension
    
    while (1) {
        cmd[0] = 0xD0;
        bus.write(addr8bit, cmd, 1);

        ThisThread::sleep_for(500ms);

        bus.read(addr8bit, cmd, 1);

        printf("ca marche ? : %x\n", cmd[0]);
        
        ThisThread::sleep_for(2000ms); // Attente avant la prochaine lecture
    }
}