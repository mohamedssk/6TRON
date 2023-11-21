using namespace sixtron;
#include "mbed.h"

I2C i2c(I2C1_SDA, I2C1_SCL);
BME280 capteur();


const int addr8bit = 0x76 << 1; // 8bit I2C address, 0x90

int main()
{
    char cmd[1];
    char temp_data[3]; // Tableau pour stocker les valeurs brutes de température


    while (1) {
        // Lecture des registres de température en une seule opération
        cmd[0] = 0xFA; // Adresse du registre temp_msb
        i2c.write(addr8bit, cmd, 1);
        i2c.read(addr8bit, temp_data, 3);

        // Combinaison des valeurs brutes avec prise en compte du bit de signe
        int raw_temp = (temp_data[0] << 12) | (temp_data[1] << 4) | temp_data[2];

       

        float temperature = raw_temp / 16384.0; // La valeur 16384 correspond à 2^14, selon la datasheet

        // Affichage de la température
       // printf("Température brute: %d\n", raw_temp);
        printf("Température calculée: %.2f °C\n", temperature);

        ThisThread::sleep_for(1000ms); // Attente avant la prochaine lecture
    }
}
