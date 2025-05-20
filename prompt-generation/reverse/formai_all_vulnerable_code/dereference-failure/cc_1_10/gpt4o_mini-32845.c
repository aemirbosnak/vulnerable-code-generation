//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a smart device
typedef struct SmartDevice {
    char name[50];
    int status; // 0 = OFF, 1 = ON
    int brightness; // For smart lights, 0-100%
} SmartDevice;

// Function prototypes
void initializeDevice(SmartDevice *device, const char *name);
void turnOnDevice(SmartDevice *device);
void turnOffDevice(SmartDevice *device);
void setDeviceBrightness(SmartDevice *device, int brightness);
void displayDeviceStatus(SmartDevice *device);
void scheduleDevice(SmartDevice *device, int hour, int minute, int action);

// Mathematical functions for scheduling
int isTimeEqual(int hour1, int minute1, int hour2, int minute2);
int isTimeInFuture(int currentHour, int currentMinute, int hour, int minute);
void runSchedule(SmartDevice *device, int currentHour, int currentMinute, int action);

// Main function
int main() {
    SmartDevice light;
    SmartDevice thermostat;

    initializeDevice(&light, "Living Room Light");
    initializeDevice(&thermostat, "Home Thermostat");

    // Turn on the light
    turnOnDevice(&light);
    setDeviceBrightness(&light, 75);
    displayDeviceStatus(&light);

    // Turn on the thermostat
    turnOnDevice(&thermostat);
    displayDeviceStatus(&thermostat);

    // Schedule the light to turn off at 22:00
    scheduleDevice(&light, 22, 0, 0); // 0 = action OFF 

    // Schedule the thermostat to adjust temp at 7:00
    scheduleDevice(&thermostat, 7, 0, 1); // 1 = action ON

    // Current time simulation (e.g. fetch the current time)
    time_t now;
    struct tm *tm_info;
    
    time(&now);
    tm_info = localtime(&now);
    int currentHour = tm_info->tm_hour;
    int currentMinute = tm_info->tm_min;

    // Run scheduled actions
    runSchedule(&light, currentHour, currentMinute, 0);
    runSchedule(&thermostat, currentHour, currentMinute, 1);
    
    return 0;
}

// Initialize a smart device
void initializeDevice(SmartDevice *device, const char *name) {
    snprintf(device->name, sizeof(device->name), "%s", name);
    device->status = 0; // Initially OFF
    device->brightness = 0; // Initially off for light
}

// Turn on a smart device
void turnOnDevice(SmartDevice *device) {
    device->status = 1; // Set status to ON
    printf("%s is turned ON.\n", device->name);
}

// Turn off a smart device
void turnOffDevice(SmartDevice *device) {
    device->status = 0; // Set status to OFF
    device->brightness = 0; // Reset brightness for lights
    printf("%s is turned OFF.\n", device->name);
}

// Set brightness for smart light
void setDeviceBrightness(SmartDevice *device, int brightness) {
    if (brightness >= 0 && brightness <= 100) {
        device->brightness = brightness;
        printf("Brightness of %s is set to %d%%.\n", device->name, brightness);
    } else {
        printf("Invalid brightness value. It must be between 0 and 100.\n");
    }
}

// Display the status of the smart device
void displayDeviceStatus(SmartDevice *device) {
    printf("Device: %s\n", device->name);
    printf("Status: %s\n", device->status ? "ON" : "OFF");
    if (device->status == 1) {
        printf("Brightness: %d%%\n", device->brightness);
    }
}

// Schedule a device action based on time
void scheduleDevice(SmartDevice *device, int hour, int minute, int action) {
    printf("Scheduled %s to %s at %02d:%02d.\n", 
           device->name, action ? "turn on" : "turn off", hour, minute);
}

// Check if two times are equal
int isTimeEqual(int hour1, int minute1, int hour2, int minute2) {
    return (hour1 == hour2 && minute1 == minute2);
}

// Check if scheduled time is in the future
int isTimeInFuture(int currentHour, int currentMinute, int hour, int minute) {
    if (currentHour < hour || 
        (currentHour == hour && currentMinute < minute)) {
        return 1; // true, future time
    }
    return 0; // false, not future
}

// Execute scheduled device action
void runSchedule(SmartDevice *device, int currentHour, int currentMinute, int action) {
    // Action values: 0 = OFF, 1 = ON
    if (action == 0 && isTimeEqual(currentHour, currentMinute, 22, 0)) {
        turnOffDevice(device);
    } else if (action == 1 && isTimeEqual(currentHour, currentMinute, 7, 0)) {
        turnOnDevice(device);
    }
}