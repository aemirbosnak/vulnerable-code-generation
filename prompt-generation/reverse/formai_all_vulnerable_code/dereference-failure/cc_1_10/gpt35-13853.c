//FormAI DATASET v1.0 Category: Smart home automation ; Style: invasive
#include<stdio.h>
#include<time.h>

// function to check if someone is present in the room
int isSomeonePresent(int presence_sensor) {
    if (presence_sensor == 1) {
        printf("Someone is present in the room.\n");
        return 1;
    }
    else {
        printf("No one is present in the room.\n");
        return 0;
    }
}

// function to turn on/off the lights based on presence
void autoLightControl(int presence_sensor, int light_switch) {
    if (isSomeonePresent(presence_sensor)) {
        light_switch = 1;
        printf("Turning on the lights.\n");
    }
    else {
        light_switch = 0;
        printf("Turning off the lights.\n");
    }
}

// function to regulate the temperature based on presence and time
void autoTemperatureControl(int presence_sensor, int temperature_sensor, int ac_switch, int heater_switch) {
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_hour = tm.tm_hour;
    
    if (isSomeonePresent(presence_sensor)) {
        if (current_hour >= 6 && current_hour <= 21) {
            ac_switch = 1;
            heater_switch = 0;
            printf("Regulating temperature with AC on.\n");
        }
        else {
            ac_switch = 0;
            heater_switch = 1;
            printf("Regulating temperature with heater on.\n");
        }
    }
    else {
        ac_switch = 0;
        heater_switch = 0;
        printf("Regulating temperature without AC or heater.\n");
    }
}

int main() {

    // initializing presence sensor, temperature sensor and switches
    int presence_sensor = 0; // 0 for no presence, 1 for presence
    int temperature_sensor = 25; // temperature in Celsius
    int light_switch = 0; // 0 for off, 1 for on
    int ac_switch = 0; // 0 for off, 1 for on
    int heater_switch = 0; // 0 for off, 1 for on
    
    // testing auto light control function
    printf("\nTesting auto light control function.\n");
    autoLightControl(presence_sensor, light_switch);
    presence_sensor = 1;
    autoLightControl(presence_sensor, light_switch);
    
    // testing auto temperature control function
    printf("\nTesting auto temperature control function.\n");
    presence_sensor = 0;
    autoTemperatureControl(presence_sensor, temperature_sensor, ac_switch, heater_switch);
    presence_sensor = 1;
    autoTemperatureControl(presence_sensor, temperature_sensor, ac_switch, heater_switch);
    
    return 0;
}