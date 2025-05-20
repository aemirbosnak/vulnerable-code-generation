//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
// Smart Home Automation Example Code
// Configurable Style

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for various home appliances
#define LIGHTS 1
#define FAN 2
#define AC 3

// Define the structure for the smart home device
typedef struct {
    int deviceType; // Type of device (1 - Lights/2 - Fan/3 - AC)
    int deviceId;   // Id of the device (1, 2, 3 etc)
    bool isOn;      // Status of device (true/false)
    int intensity;  // Intensity of device (1 - 100)
} SmartHomeDevice;

// Function to create a new SmartHomeDevice object 
SmartHomeDevice* createSmartDevice(int deviceType, int deviceId, bool isOn, int intensity) {
    SmartHomeDevice* device = (SmartHomeDevice*) malloc(sizeof(SmartHomeDevice));
    device->deviceType = deviceType;
    device->deviceId = deviceId;
    device->isOn = isOn;
    device->intensity = intensity;
    return device;
}

// Function to turn on a smart home device
void turnOnDevice(SmartHomeDevice* device) {
    device->isOn = true;
    printf("Device %d turned on\n", device->deviceId);
}

// Function to turn off a smart home device
void turnOffDevice(SmartHomeDevice* device) {
    device->isOn = false;
    printf("Device %d turned off\n", device->deviceId);
}

// Function to set the intensity of a device
void setDeviceIntensity(SmartHomeDevice* device, int intensity) {
    if(device->isOn) {
        device->intensity = intensity;
        printf("Device %d intensity set to %d\n", device->deviceId, intensity);
    } else {
        printf("Device %d is turned off, cannot set intensity\n", device->deviceId);
    }
}

// Main function
int main() {
    // Create some smart home devices
    SmartHomeDevice* light1 = createSmartDevice(LIGHTS, 1, false, 0);
    SmartHomeDevice* light2 = createSmartDevice(LIGHTS, 2, false, 0);
    SmartHomeDevice* fan1 = createSmartDevice(FAN, 1, false, 0);
    SmartHomeDevice* ac1 = createSmartDevice(AC, 1, false, 0);
    
    // Turn on some devices
    turnOnDevice(light1);
    turnOnDevice(fan1);
    
    // Set intensity for some devices
    setDeviceIntensity(light1, 80);
    setDeviceIntensity(fan1, 50);
    
    // Turn off devices
    turnOffDevice(light1);
    turnOffDevice(fan1);
    
    return 0;
}