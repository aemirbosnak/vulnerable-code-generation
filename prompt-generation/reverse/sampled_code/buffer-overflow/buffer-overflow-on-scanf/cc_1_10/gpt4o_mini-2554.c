//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_PLAYERS 5

typedef struct {
    char type[20]; // Type of component (Resistor, Capacitor, or Voltage Source)
    double value;  // Value of component (Resistance in Ohms, Capacitance in Farads)
} Component;

typedef struct {
    Component components[MAX_COMPONENTS];
    int count;
    char playerName[50];
} Circuit;

void addComponent(Circuit *circuit) {
    if (circuit->count >= MAX_COMPONENTS) {
        printf("Circuit is full! Cannot add more components.\n");
        return;
    }

    printf("Enter component type (Resistor/Capacitor/Voltage): ");
    scanf("%s", circuit->components[circuit->count].type);
    
    printf("Enter component value: ");
    scanf("%lf", &circuit->components[circuit->count].value);
    
    circuit->count++;
    printf("Component added by %s!\n", circuit->playerName);
}

void calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "Resistor") == 0) {
            totalResistance += circuit->components[i].value;
        }
    }
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
}

void calculateTotalCapacitance(Circuit *circuit) {
    double totalCapacitance = 0.0;
    for (int i = 0; i < circuit->count; i++) {
        if (strcmp(circuit->components[i].type, "Capacitor") == 0) {
            totalCapacitance += circuit->components[i].value;
        }
    }
    printf("Total Capacitance: %.2f Farads\n", totalCapacitance);
}

void showCircuit(Circuit *circuit) {
    printf("Circuit components added by %s:\n", circuit->playerName);
    for (int i = 0; i < circuit->count; i++) {
        printf("%d: %s - %.2f\n", i + 1, circuit->components[i].type, circuit->components[i].value);
    }
}

int main() {
    Circuit circuits[MAX_PLAYERS];
    int playerCount = 0;
    char playerName[50];
    
    printf("Welcome to the Multiplayer Circuit Simulator!\n");
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", circuits[i].playerName);
        circuits[i].count = 0;
    }

    int turn = 0;
    while (1) {
        printf("\n%s's turn!\n", circuits[turn].playerName);
        printf("1. Add a component\n2. Show circuit\n3. Calculate Total Resistance\n4. Calculate Total Capacitance\n5. Next player's turn\n0. Quit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addComponent(&circuits[turn]);
                break;
            case 2:
                showCircuit(&circuits[turn]);
                break;
            case 3:
                calculateTotalResistance(&circuits[turn]);
                break;
            case 4:
                calculateTotalCapacitance(&circuits[turn]);
                break;
            case 5:
                turn = (turn + 1) % playerCount;
                break;
            case 0:
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}