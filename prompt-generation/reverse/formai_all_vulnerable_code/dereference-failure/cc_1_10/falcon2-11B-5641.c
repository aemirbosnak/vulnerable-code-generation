//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHT_SWITCHES 10

typedef struct {
    char* name;
    int state;
} LightSwitch;

LightSwitch lightSwitches[MAX_LIGHT_SWITCHES];

void setLightSwitchState(int index, int state) {
    lightSwitches[index].state = state;
}

int getLightSwitchState(int index) {
    return lightSwitches[index].state;
}

int main() {
    int i, j;
    char command[100], switchName[100], switchState[100];
    int switchIndex;

    // Initialize the light switches
    for (i = 0; i < MAX_LIGHT_SWITCHES; i++) {
        strcpy(lightSwitches[i].name, "Light Switch ");
        strcat(lightSwitches[i].name, (i+1));
        strcpy(switchName, lightSwitches[i].name);
        setLightSwitchState(i, 0);
    }

    // Print initial state of all light switches
    printf("Initial state of all light switches:\n");
    for (i = 0; i < MAX_LIGHT_SWITCHES; i++) {
        printf("%s: %s\n", switchName, getLightSwitchState(i) == 1? "On" : "Off");
    }

    // Read command from user
    printf("Enter command:\n");
    fgets(command, sizeof(command), stdin);

    // Process command
    for (i = 0; i < MAX_LIGHT_SWITCHES; i++) {
        if (strcmp(command, "ON") == 0) {
            printf("Turning %s on...\n", switchName);
            setLightSwitchState(i, 1);
            printf("%s: %s\n", switchName, getLightSwitchState(i) == 1? "On" : "Off");
        } else if (strcmp(command, "OFF") == 0) {
            printf("Turning %s off...\n", switchName);
            setLightSwitchState(i, 0);
            printf("%s: %s\n", switchName, getLightSwitchState(i) == 1? "On" : "Off");
        } else if (strcmp(command, "SWITCH") == 0) {
            printf("Enter index of the switch to be switched on or off:\n");
            fgets(switchName, sizeof(switchName), stdin);
            sscanf(switchName, "%d", &switchIndex);
            printf("Switching %s...\n", switchName);
            setLightSwitchState(switchIndex,!getLightSwitchState(switchIndex));
            printf("%s: %s\n", switchName, getLightSwitchState(switchIndex) == 1? "On" : "Off");
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}