//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include<stdio.h>
#include<string.h>

/*Function to turn on/off the light in the living room*/
void control_living_room_light(int stat) {
    if (stat == 1) {
        printf("Living room light turned on\n");
    }
    else {
        printf("Living room light turned off\n");
    }
}

/*Function to turn on/off the light in the bedroom*/
void control_bedroom_light(int stat) {
    if (stat == 1) {
        printf("Bedroom light turned on\n");
    }
    else {
        printf("Bedroom light turned off\n");
    }
}

/*Function to turn on/off the AC in the living room*/
void control_living_room_ac(int stat) {
    if (stat == 1) {
        printf("Living room AC turned on\n");
    }
    else {
        printf("Living room AC turned off\n");
    }
}

/*Function to turn on/off the AC in the bedroom*/
void control_bedroom_ac(int stat) {
    if (stat == 1) {
        printf("Bedroom AC turned on\n");
    }
    else {
        printf("Bedroom AC turned off\n");
    }
}

/*Main program*/
int main() {
    int lr_l = 0; //Living room light status, 0 means off and 1 means on
    int br_l = 0; //Bedroom light status, 0 means off and 1 means on
    int lr_ac = 0; //Living room AC status, 0 means off and 1 means on
    int br_ac = 0; //Bedroom AC status, 0 means off and 1 means on
    char input[50]; //Variable to store the user input
    while (1) { //Infinite loop
        printf("Enter command (e.g. 'living room light on'): ");
        fgets(input, 50, stdin);
        
        /*Parse the user input*/
        char* room = strtok(input, " ");
        char* device = strtok(NULL, " ");
        char* status = strtok(NULL, " ");
        
        /*Check if the user wants to exit*/
        if (strcmp(room, "exit") == 0) {
            break;
        }
        
        /*Decide which device needs to be controlled based on user input*/
        if (strcmp(device, "light") == 0) {
            if (strcmp(room, "living") == 0) {
                if (strcmp(status, "on") == 0) {
                    control_living_room_light(1);
                    lr_l = 1;
                }
                else if (strcmp(status, "off") == 0) {
                    control_living_room_light(0);
                    lr_l = 0;
                }
            }
            else if (strcmp(room, "bedroom") == 0) {
                if (strcmp(status, "on") == 0) {
                    control_bedroom_light(1);
                    br_l = 1;
                }
                else if (strcmp(status, "off") == 0) {
                    control_bedroom_light(0);
                    br_l = 0;
                }
            }
            else {
                printf("Invalid command\n");
            }
        }
        else if (strcmp(device, "AC") == 0) {
            if (strcmp(room, "living") == 0) {
                if (strcmp(status, "on") == 0) {
                    control_living_room_ac(1);
                    lr_ac = 1;
                }
                else if (strcmp(status, "off") == 0) {
                    control_living_room_ac(0);
                    lr_ac = 0;
                }
            }
            else if (strcmp(room, "bedroom") == 0) {
                if (strcmp(status, "on") == 0) {
                    control_bedroom_ac(1);
                    br_ac = 1;
                }
                else if (strcmp(status, "off") == 0) {
                    control_bedroom_ac(0);
                    br_ac = 0;
                }
            }
            else {
                printf("Invalid command\n");
            }
        }
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}