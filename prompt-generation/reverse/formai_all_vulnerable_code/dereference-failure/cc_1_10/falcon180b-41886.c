//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>

/* Define the structure of a smart home device */
typedef struct SmartDevice {
    char* name;
    int status;
    int* power;
} SmartDevice;

/* Initialize the smart home with devices */
void initSmartHome(SmartDevice* devices, int numDevices) {
    for(int i = 0; i < numDevices; i++) {
        devices[i].name = (char*)malloc(100 * sizeof(char));
        devices[i].status = 0;
        devices[i].power = (int*)malloc(sizeof(int));
        *devices[i].power = 0;
    }
}

/* Print the current state of the smart home */
void printSmartHomeState(SmartDevice* devices, int numDevices) {
    for(int i = 0; i < numDevices; i++) {
        printf("%s: %s, Power: %d\n", devices[i].name, devices[i].status? "On" : "Off", *devices[i].power);
    }
}

/* Toggle the power of a smart home device */
void toggleSmartDevice(SmartDevice* devices, int numDevices, int deviceId) {
    if(deviceId >= 0 && deviceId < numDevices) {
        int newPower =!*devices[deviceId].power;
        *devices[deviceId].power = newPower;
        devices[deviceId].status = newPower? 1 : 0;
    }
}

/* Turn on all smart home devices */
void turnOnAllSmartDevices(SmartDevice* devices, int numDevices) {
    for(int i = 0; i < numDevices; i++) {
        *devices[i].power = 1;
        devices[i].status = 1;
    }
}

/* Turn off all smart home devices */
void turnOffAllSmartDevices(SmartDevice* devices, int numDevices) {
    for(int i = 0; i < numDevices; i++) {
        *devices[i].power = 0;
        devices[i].status = 0;
    }
}

int main() {
    SmartDevice devices[3];
    initSmartHome(devices, 3);

    devices[0].name = "Living Room Light";
    devices[1].name = "Bedroom Light";
    devices[2].name = "Kitchen Light";

    printSmartHomeState(devices, 3);

    toggleSmartDevice(devices, 3, 0);
    printSmartHomeState(devices, 3);

    turnOnAllSmartDevices(devices, 3);
    printSmartHomeState(devices, 3);

    turnOffAllSmartDevices(devices, 3);
    printSmartHomeState(devices, 3);

    return 0;
}