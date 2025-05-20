//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 10
#define LIGHT_NAME_LENGTH 20

typedef enum {
    OFF,
    ON
} LightState;

typedef struct {
    char name[LIGHT_NAME_LENGTH];
    LightState state;
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int lightCount = 0;

void initializeLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, LIGHT_NAME_LENGTH, "Light %d", i + 1);
        lights[i].state = OFF;
    }
    lightCount = MAX_LIGHTS;
}

void printLightStatus() {
    printf("\n--- Smart Home Light Status ---\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].state == ON ? "ON" : "OFF");
    }
    printf("-------------------------------\n");
}

void toggleLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].state = lights[index].state == ON ? OFF : ON;
        printf("%s is now %s.\n", lights[index].name, lights[index].state == ON ? "ON" : "OFF");
    } else {
        printf("Invalid light index: %d\n", index);
    }
}

void turnOnLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].state = ON;
        printf("%s is now ON.\n", lights[index].name);
    } else {
        printf("Invalid light index: %d\n", index);
    }
}

void turnOffLight(int index) {
    if (index >= 0 && index < lightCount) {
        lights[index].state = OFF;
        printf("%s is now OFF.\n", lights[index].name);
    } else {
        printf("Invalid light index: %d\n", index);
    }
}

void scheduleLights(int hour, int minute, int durationMinutes) {
    printf("Scheduling lights...\n");
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    tm->tm_hour = hour;
    tm->tm_min = minute;
    tm->tm_sec = 0;

    time_t scheduledTime = mktime(tm);
    printf("Lights will turn ON at %02d:%02d and remain ON for %d minutes.\n", hour, minute, durationMinutes);

    turnOnLight(0); // Turn on first light as an example; you can change this logic
    sleep(durationMinutes * 60); // Sleep for the duration
    turnOffLight(0); // Turn it off after duration
}

int main() {
    int choice, lightIndex;
    initializeLights();

    while (1) {
        printf("\n--- Smart Home Light Control ---\n");
        printf("1. Print light status\n");
        printf("2. Toggle light\n");
        printf("3. Turn on light\n");
        printf("4. Turn off light\n");
        printf("5. Schedule light\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printLightStatus();
                break;
            case 2:
                printf("Enter light index to toggle (0 to %d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                toggleLight(lightIndex);
                break;
            case 3:
                printf("Enter light index to turn ON (0 to %d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                turnOnLight(lightIndex);
                break;
            case 4:
                printf("Enter light index to turn OFF (0 to %d): ", lightCount - 1);
                scanf("%d", &lightIndex);
                turnOffLight(lightIndex);
                break;
            case 5:
                {
                    int hour, minute, duration;
                    printf("Enter hour (0-23): ");
                    scanf("%d", &hour);
                    printf("Enter minute (0-59): ");
                    scanf("%d", &minute);
                    printf("Enter duration in minutes: ");
                    scanf("%d", &duration);
                    scheduleLights(hour, minute, duration);
                    break;
                }
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}