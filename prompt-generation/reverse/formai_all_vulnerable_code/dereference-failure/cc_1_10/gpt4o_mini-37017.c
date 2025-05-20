//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef enum {
    LIGHT,
    THERMOSTAT,
    DOOR_LOCK,
    CAMERA
} DeviceType;

typedef struct {
    char name[NAME_LENGTH];
    DeviceType type;
    int state; // 0 = off, 1 = on
    int intensity; // For lights
    int temperature; // For thermostats
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char* name, DeviceType type) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, NAME_LENGTH);
        devices[device_count].type = type;
        devices[device_count].state = 0; // Initially off
        devices[device_count].intensity = 0; // Default intensity
        devices[device_count].temperature = 20; // Default temperature
        device_count++;
        printf("Device %s added!\n", name);
    } else {
        printf("Device limit reached.\n");
    }
}

void toggle_device(int index) {
    if (index < device_count) {
        devices[index].state = !devices[index].state;
        printf("%s is now %s.\n", devices[index].name, devices[index].state ? "ON" : "OFF");
    } else {
        printf("Device not found!\n");
    }
}

void set_light_intensity(int index, int intensity) {
    if (index < device_count && devices[index].type == LIGHT) {
        devices[index].intensity = intensity;
        printf("Intensity of %s set to %d%%.\n", devices[index].name, intensity);
    } else {
        printf("Invalid operation!\n");
    }
}

void set_thermostat_temperature(int index, int temperature) {
    if (index < device_count && devices[index].type == THERMOSTAT) {
        devices[index].temperature = temperature;
        printf("Temperature of %s set to %d°C.\n", devices[index].name, temperature);
    } else {
        printf("Invalid operation!\n");
    }
}

void display_devices() {
    printf("\nSmart Home Devices List:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d: %s (Type: %d) - State: %s ", i, devices[i].name, devices[i].type,
               devices[i].state ? "ON" : "OFF");
        if (devices[i].type == LIGHT) {
            printf("Intensity: %d%%\n", devices[i].intensity);
        } else if (devices[i].type == THERMOSTAT) {
            printf("Temperature: %d°C\n", devices[i].temperature);
        } else {
            printf("\n");
        }
    }
}

void automate_lights_based_on_time() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Simple automation: Turn lights on from 6 PM to 6 AM
    int hour = t->tm_hour;
    for (int i = 0; i < device_count; i++) {
        if (devices[i].type == LIGHT) {
            if (hour >= 18 || hour < 6) {
                if (devices[i].state == 0) {
                    toggle_device(i);
                    set_light_intensity(i, 100); // Full brightness
                }
            } else {
                if (devices[i].state == 1) {
                    toggle_device(i);
                    set_light_intensity(i, 0); // Turned off
                }
            }
        }
    }
}

int main() {
    add_device("Living Room Light", LIGHT);
    add_device("Bedroom Light", LIGHT);
    add_device("Main Thermostat", THERMOSTAT);
    add_device("Front Door Lock", DOOR_LOCK);
    add_device("Security Camera", CAMERA);
    
    automate_lights_based_on_time();
    
    display_devices();
    
    // User Commands (Sample)
    toggle_device(0); // Toggle Living Room Light
    set_light_intensity(0, 75); // Dim Living Room Light
    set_thermostat_temperature(2, 22); // Adjust Thermostat
    
    display_devices(); // Display final state of devices
    
    return 0;
}