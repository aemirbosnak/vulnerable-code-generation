//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for various appliance states */
#define ON 1
#define OFF 0
#define MAX_APPLIANCES 10

/* Define a struct to store information about an appliance */
typedef struct appliance {
    char name[50];
    bool status;
    bool hasTimer;
    int timerMinutes;
} Appliance;

/* Define a struct to store information about the home */
typedef struct smartHome {
    Appliance appliances[MAX_APPLIANCES];
    int numAppliances;
    double temperature;
    bool lightsOn;
} SmartHome;

/* Initialize a new SmartHome object with blank values */
SmartHome* initializeSmartHome() {
    SmartHome *smartHome = (SmartHome*)malloc(sizeof(SmartHome));
    for(int i = 0; i < MAX_APPLIANCES; i++) {
        strcpy(smartHome -> appliances[i].name, "");
        smartHome -> appliances[i].status = OFF;
        smartHome -> appliances[i].hasTimer = false;
        smartHome -> appliances[i].timerMinutes = 0;
    }
    smartHome -> numAppliances = 0;
    smartHome -> temperature = 0.0;
    smartHome -> lightsOn = false;
    return smartHome;
}

/* Add an appliance to the SmartHome object */
void addAppliance(SmartHome *smartHome, char *applianceName) {
    if(smartHome -> numAppliances >= MAX_APPLIANCES) {
        printf("Cannot add more appliances. Maximum limit reached.\n");
        return;
    }
    Appliance newAppliance;
    strcpy(newAppliance.name, applianceName);
    newAppliance.status = OFF;
    newAppliance.hasTimer = false;
    newAppliance.timerMinutes = 0;
    smartHome -> appliances[smartHome -> numAppliances++] = newAppliance;
    printf("%s appliance added successfully!\n", applianceName);
}

/* Print the status of all the appliances in the SmartHome object */
void printApplianceStatus(SmartHome *smartHome) {
    printf("Appliance\t\tStatus\t\tTimer\n");
    printf("---------------------------------------\n");
    for(int i = 0; i < smartHome -> numAppliances; i++) {
        printf("%s\t\t", smartHome -> appliances[i].name);
        printf("%s\t\t", smartHome -> appliances[i].status == ON ? "ON" : "OFF");
        if(smartHome -> appliances[i].hasTimer) {
            printf("%d minute(s)\n", smartHome -> appliances[i].timerMinutes);
        } else {
            printf("NO\n");
        }
    }
}

/* Turn on a specified appliance in the SmartHome object */
void turnOnAppliance(SmartHome *smartHome, char *applianceName) {
    for(int i = 0; i < smartHome -> numAppliances; i++) {
        if(strcmp(smartHome -> appliances[i].name, applianceName) == 0) {
            smartHome -> appliances[i].status = ON;
            printf("%s turned ON\n", applianceName);
            return;
        }
    }
    printf("Appliance not found\n");
}

/* Turn off a specified appliance in the SmartHome object */
void turnOffAppliance(SmartHome *smartHome, char *applianceName) {
    for(int i = 0; i < smartHome -> numAppliances; i++) {
        if(strcmp(smartHome -> appliances[i].name, applianceName) == 0) {
            smartHome -> appliances[i].status = OFF;
            printf("%s turned OFF\n", applianceName);
            return;
        }
    }
    printf("Appliance not found\n");
}

/* Set a timer for a specified appliance in the SmartHome object */
void setTimer(SmartHome *smartHome, char *applianceName, int minutes) {
    for(int i = 0; i < smartHome -> numAppliances; i++) {
        if(strcmp(smartHome -> appliances[i].name, applianceName) == 0) {
            smartHome -> appliances[i].hasTimer = true;
            smartHome -> appliances[i].timerMinutes = minutes;
            printf("Timer set for %s for %d minutes\n", applianceName, minutes);
            return;
        }
    }
    printf("Appliance not found\n");
}

/* Main function */
int main() {
    SmartHome *myHome = initializeSmartHome();
    addAppliance(myHome, "Air Conditioner");
    addAppliance(myHome, "Television");
    addAppliance(myHome, "Washing Machine");
    turnOnAppliance(myHome, "Television");
    setTimer(myHome, "Air Conditioner", 30);
    printApplianceStatus(myHome);
    turnOffAppliance(myHome, "Washing Machine");
    printApplianceStatus(myHome);
    return 0;
}