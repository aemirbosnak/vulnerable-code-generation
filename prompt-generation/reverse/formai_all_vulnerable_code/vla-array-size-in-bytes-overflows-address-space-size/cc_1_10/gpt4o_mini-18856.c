//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Light structure to represent each light in the home
typedef struct {
    char name[30];
    int isOn;
    int brightness; // 0-100
} Light;

// Function to initialize lights
void initializeLights(Light lights[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of light %d: ", i + 1);
        fgets(lights[i].name, sizeof(lights[i].name), stdin);
        lights[i].name[strcspn(lights[i].name, "\n")] = 0; // Remove newline
        lights[i].isOn = 0; // Initially off
        lights[i].brightness = 0; // Initially dimmed
    }
}

// Function to display light status
void displayStatus(Light lights[], int count) {
    printf("\nLight Status:\n");
    for (int i = 0; i < count; i++) {
        printf("Light: %s, Status: %s, Brightness: %d%%\n", 
                lights[i].name, 
                lights[i].isOn ? "On" : "Off", 
                lights[i].brightness);
    }
}

// Function to turn on a light
void turnOnLight(Light *light) {
    light->isOn = 1;
    light->brightness = 100; // Default brightness when turned on
    printf("%s is now ON at 100%% brightness.\n", light->name);
}

// Function to turn off a light
void turnOffLight(Light *light) {
    light->isOn = 0;
    light->brightness = 0; // Brightness reset when turned off
    printf("%s is now OFF.\n", light->name);
}

// Function to dim a light
void dimLight(Light *light, int level) {
    if (level < 0 || level > 100) {
        printf("Brightness level must be between 0 and 100.\n");
        return;
    }
    light->brightness = level;
    printf("%s is dimmed to %d%%.\n", light->name, level);
}

// Main function
int main() {
    int count = 0;
    printf("Welcome to Smart Home Light Control!\n");
    printf("How many lights do you want to control? ");
    scanf("%d", &count);
    getchar(); // Clear newline from buffer

    Light lights[count];
    initializeLights(lights, count);

    char command[30];
    int lightIndex;
    
    while (1) {
        printf("\nEnter command (status, on <light_num>, off <light_num>, dim <light_num> <level>, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "status") == 0) {
            displayStatus(lights, count);
        } else if (strncmp(command, "on ", 3) == 0) {
            lightIndex = atoi(command + 3) - 1; // Convert to index
            if (lightIndex >= 0 && lightIndex < count) {
                turnOnLight(&lights[lightIndex]);
            } else {
                printf("Invalid light number.\n");
            }
        } else if (strncmp(command, "off ", 4) == 0) {
            lightIndex = atoi(command + 4) - 1; // Convert to index
            if (lightIndex >= 0 && lightIndex < count) {
                turnOffLight(&lights[lightIndex]);
            } else {
                printf("Invalid light number.\n");
            }
        } else if (strncmp(command, "dim ", 4) == 0) {
            char *token = strtok(command + 4, " ");
            lightIndex = atoi(token) - 1; // Convert to index
            token = strtok(NULL, " ");
            int brightnessLevel = atoi(token); // Convert to brightness level

            if (lightIndex >= 0 && lightIndex < count) {
                dimLight(&lights[lightIndex], brightnessLevel);
            } else {
                printf("Invalid light number.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Light Control. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}