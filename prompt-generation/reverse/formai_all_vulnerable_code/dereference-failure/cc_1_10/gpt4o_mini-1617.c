//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int brightness; // 0 to 100
    int isOn; // 1 for ON, 0 for OFF
    struct tm schedule; // Schedule for ON/OFF
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void addLight(const char *name) {
    if (lightCount < MAX_LIGHTS) {
        strcpy(lights[lightCount].name, name);
        lights[lightCount].brightness = 0;
        lights[lightCount].isOn = 0;
        lightCount++;
        printf("Light '%s' added!\n", name);
    } else {
        printf("Cannot add more lights, maximum limit reached.\n");
    }
}

void toggleLight(const char *name) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].isOn = !lights[i].isOn;
            printf("Light '%s' is now %s!\n", name, lights[i].isOn ? "ON" : "OFF");
            return;
        }
    }
    printf("Light '%s' not found!\n", name);
}

void setBrightness(const char *name, int brightness) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (brightness >= 0 && brightness <= 100) {
                lights[i].brightness = brightness;
                printf("Brightness of '%s' set to %d%%\n", name, brightness);
            } else {
                printf("Invalid brightness value! Must be between 0 and 100.\n");
            }
            return;
        }
    }
    printf("Light '%s' not found!\n", name);
}

void displayStatus() {
    printf("\n--- Light Status ---\n");
    for (int i = 0; i < lightCount; i++) {
        printf("Light Name: %s\n", lights[i].name);
        printf("Status: %s\n", lights[i].isOn ? "ON" : "OFF");
        printf("Brightness: %d%%\n", lights[i].brightness);
        printf("----------------------\n");
    }
}

void scheduleLight(const char *name, int hour, int minute, int isOn) {
    for (int i = 0; i < lightCount; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].schedule.tm_hour = hour;
            lights[i].schedule.tm_min = minute;
            lights[i].isOn = isOn;
            printf("%s scheduled for %02d:%02d\n", name, hour, minute);
            return;
        }
    }
    printf("Light '%s' not found!\n", name);
}

void checkSchedules() {
    time_t now = time(0);
    struct tm *currentTime = localtime(&now);

    for (int i = 0; i < lightCount; i++) {
        if (lights[i].schedule.tm_hour == currentTime->tm_hour && 
            lights[i].schedule.tm_min == currentTime->tm_min) {
            lights[i].isOn = !lights[i].isOn; // Toggle light status
            printf("Scheduled action triggered for '%s': %s\n", lights[i].name, lights[i].isOn ? "ON" : "OFF");
        }
    }
}

int main() {
    addLight("Living Room");
    addLight("Bedroom");
    addLight("Kitchen");

    setBrightness("Living Room", 75);
    toggleLight("Bedroom");
    setBrightness("Kitchen", 50);

    scheduleLight("Living Room", 20, 0, 1); // Schedule ON at 20:00
    scheduleLight("Bedroom", 21, 0, 1);     // Schedule ON at 21:00

    while (1) {
        checkSchedules();
        displayStatus();
        sleep(60); // Check every minute
    }

    return 0;
}