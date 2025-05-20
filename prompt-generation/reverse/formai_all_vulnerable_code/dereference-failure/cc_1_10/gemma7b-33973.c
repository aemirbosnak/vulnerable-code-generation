//Gemma-7B DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about survivors
typedef struct Survivor {
    char name[20];
    int age;
    float health;
    struct Survivor* next;
} Survivor;

// Function to insert a survivor into the linked list
void insertSurvivor(Survivor* head, char* name, int age, float health) {
    Survivor* newSurvivor = (Survivor*)malloc(sizeof(Survivor));
    strcpy(newSurvivor->name, name);
    newSurvivor->age = age;
    newSurvivor->health = health;
    newSurvivor->next = NULL;

    if (head == NULL) {
        head = newSurvivor;
    } else {
        Survivor* currentSurvivor = head;
        while (currentSurvivor->next) {
            currentSurvivor = currentSurvivor->next;
        }
        currentSurvivor->next = newSurvivor;
    }
}

// Function to search for a survivor by name
Survivor* searchSurvivorByName(Survivor* head, char* name) {
    Survivor* currentSurvivor = head;
    while (currentSurvivor) {
        if (strcmp(currentSurvivor->name, name) == 0) {
            return currentSurvivor;
        }
        currentSurvivor = currentSurvivor->next;
    }
    return NULL;
}

// Function to print the survivors
void printSurvivors(Survivor* head) {
    Survivor* currentSurvivor = head;
    while (currentSurvivor) {
        printf("%s, %d, %.2f\n", currentSurvivor->name, currentSurvivor->age, currentSurvivor->health);
        currentSurvivor = currentSurvivor->next;
    }
}

int main() {
    // Create a linked list of survivors
    Survivor* head = NULL;

    // Insert some survivors
    insertSurvivor(head, "John Doe", 25, 100.0);
    insertSurvivor(head, "Jane Doe", 30, 90.0);
    insertSurvivor(head, "Bob Smith", 40, 80.0);
    insertSurvivor(head, "Alice White", 20, 70.0);

    // Search for a survivor by name
    Survivor* survivor = searchSurvivorByName(head, "Bob Smith");

    // Print the survivor
    if (survivor) {
        printf("Name: %s\n", survivor->name);
        printf("Age: %d\n", survivor->age);
        printf("Health: %.2f\n", survivor->health);
    } else {
        printf("Survivor not found.\n");
    }

    // Print all survivors
    printSurvivors(head);

    return 0;
}