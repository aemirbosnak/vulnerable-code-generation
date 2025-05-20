//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int is_on;
    int brightness; // 0-100
} Appliance;

typedef struct {
    Appliance *appliances;
    int count;
} SmartHome;

void initializeHome(SmartHome *home, int count) {
    home->count = count;
    home->appliances = (Appliance *)malloc(sizeof(Appliance) * count);
    
    for (int i = 0; i < count; i++) {
        sprintf(home->appliances[i].name, "Appliance_%d", i + 1);
        home->appliances[i].is_on = 0; // Off by default
        home->appliances[i].brightness = 0; // Dim by default
    }
}

void turnOnAppliance(SmartHome *home, int index) {
    if (index < 0 || index >= home->count) {
        printf("Error: Invalid appliance index!\n");
        return;
    }
    home->appliances[index].is_on = 1;
    printf("%s is now ON.\n", home->appliances[index].name);
}

void turnOffAppliance(SmartHome *home, int index) {
    if (index < 0 || index >= home->count) {
        printf("Error: Invalid appliance index!\n");
        return;
    }
    home->appliances[index].is_on = 0;
    printf("%s is now OFF.\n", home->appliances[index].name);
}

void setBrightness(SmartHome *home, int index, int brightness) {
    if (index < 0 || index >= home->count) {
        printf("Error: Invalid appliance index!\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Error: Brightness must be between 0 and 100!\n");
        return;
    }
    home->appliances[index].brightness = brightness;
    printf("Brightness of %s set to %d%%.\n", home->appliances[index].name, brightness);
}

void displayAppliances(SmartHome *home) {
    printf("Smart Home Appliances:\n");
    for (int i = 0; i < home->count; i++) {
        printf("[%d] %s - %s, Brightness: %d%%\n", i + 1, 
                home->appliances[i].name, 
                home->appliances[i].is_on ? "ON" : "OFF", 
                home->appliances[i].brightness);
    }
}

void processCommand(SmartHome *home) {
    int choice, index, brightness;
    while (1) {
        printf("\nSmart Home Command Center\n");
        printf("1. Turn On Appliance\n");
        printf("2. Turn Off Appliance\n");
        printf("3. Set Brightness\n");
        printf("4. Display Appliances\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appliance index (1-%d): ", home->count);
                scanf("%d", &index);
                turnOnAppliance(home, index - 1);
                break;
            case 2:
                printf("Enter appliance index (1-%d): ", home->count);
                scanf("%d", &index);
                turnOffAppliance(home, index - 1);
                break;
            case 3:
                printf("Enter appliance index (1-%d): ", home->count);
                scanf("%d", &index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                setBrightness(home, index - 1, brightness);
                break;
            case 4:
                displayAppliances(home);
                break;
            case 5:
                printf("Exiting Smart Home Command Center...\n");
                return;
            default:
                printf("Error: Invalid choice! Please try again.\n");
                break;
        }
    }
}

void freeHome(SmartHome *home) {
    free(home->appliances);
}

int main() {
    SmartHome home;
    initializeHome(&home, 5); // Initialize with 5 appliances
    processCommand(&home);
    freeHome(&home);
    return 0;
}