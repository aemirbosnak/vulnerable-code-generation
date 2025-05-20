//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold planet information
typedef struct Planet {
    char name[50];
    float distanceFromSun; // in million km
    int numMoons;
    struct Planet* next;
} Planet;

// Function prototypes
Planet* createPlanet(char name[], float distance, int moons);
void addPlanet(Planet** head, char name[], float distance, int moons);
void displayPlanets(Planet* head);
void visualizePlanets(Planet* head);
void freePlanets(Planet* head);
void showMenu();

int main() {
    // Head of the linked list
    Planet* head = NULL;

    // Sample planets to add
    addPlanet(&head, "Mercury", 57.91, 0);
    addPlanet(&head, "Venus", 108.21, 0);
    addPlanet(&head, "Earth", 149.60, 1);
    addPlanet(&head, "Mars", 227.94, 2);
    addPlanet(&head, "Jupiter", 778.57, 79);
    addPlanet(&head, "Saturn", 1433.5, 83);
    addPlanet(&head, "Uranus", 2872.5, 27);
    addPlanet(&head, "Neptune", 4495.1, 14);

    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayPlanets(head);
                break;
            case 2:
                visualizePlanets(head);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    // Free allocated memory
    freePlanets(head);

    return 0;
}

// Function to create a new planet
Planet* createPlanet(char name[], float distance, int moons) {
    Planet* newPlanet = (Planet*)malloc(sizeof(Planet));
    strcpy(newPlanet->name, name);
    newPlanet->distanceFromSun = distance;
    newPlanet->numMoons = moons;
    newPlanet->next = NULL;
    return newPlanet;
}

// Function to add a planet to the linked list
void addPlanet(Planet** head, char name[], float distance, int moons) {
    Planet* newPlanet = createPlanet(name, distance, moons);
    newPlanet->next = *head;
    *head = newPlanet;
}

// Function to display the planets
void displayPlanets(Planet* head) {
    Planet* current = head;
    printf("\n*** Planets in the Solar System ***\n");
    while (current != NULL) {
        printf("Planet: %s | Distance from Sun: %.2f million km | Moons: %d\n", 
               current->name, current->distanceFromSun, current->numMoons);
        current = current->next;
    }
    printf("************************************\n");
}

// Function to visualize planets in a futuristic style
void visualizePlanets(Planet* head) {
    printf("\n--- Planet Visualization ---\n");
    Planet* current = head;
    while (current != NULL) {
        printf("🚀 %s orbiting at a distance of %.2f million km with %d moon(s)\n", 
               current->name, current->distanceFromSun, current->numMoons);
        current = current->next;
    }
    printf("------------------------------\n");
}

// Function to free allocated memory for planets
void freePlanets(Planet* head) {
    Planet* current = head;
    Planet* nextPlanet;

    while (current != NULL) {
        nextPlanet = current->next;
        free(current);
        current = nextPlanet;
    }
}

// Function to show program menu
void showMenu() {
    printf("\n*** Solar System Explorer ***\n");
    printf("1. Display Planets\n");
    printf("2. Visualize Planets\n");
    printf("3. Exit\n");
}