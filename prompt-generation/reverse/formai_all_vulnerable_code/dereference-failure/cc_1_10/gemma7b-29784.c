//Gemma-7B DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store data about a post-apocalyptic survivor
typedef struct Survivor {
    char name[20];
    int age;
    float health;
    char occupation[20];
    struct Survivor* next;
} Survivor;

// Function to create a new survivor
Survivor* createSurvivor(char* name, int age, float health, char* occupation) {
    Survivor* newSurvivor = (Survivor*)malloc(sizeof(Survivor));
    strcpy(newSurvivor->name, name);
    newSurvivor->age = age;
    newSurvivor->health = health;
    strcpy(newSurvivor->occupation, occupation);
    newSurvivor->next = NULL;
    return newSurvivor;
}

// Function to add a survivor to a linked list
void addSurvivor(Survivor* head, Survivor* newSurvivor) {
    if (head == NULL) {
        head = newSurvivor;
    } else {
        newSurvivor->next = head;
        head = newSurvivor;
    }
}

// Function to find a survivor by name
Survivor* findSurvivorByName(Survivor* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print a list of survivors
void printSurvivors(Survivor* head) {
    while (head) {
        printf("%s, %d, %f, %s\n", head->name, head->age, head->health, head->occupation);
        head = head->next;
    }
}

int main() {
    // Create a linked list of survivors
    Survivor* head = NULL;

    // Add some survivors to the list
    addSurvivor(head, createSurvivor("John Doe", 25, 100.0, "Engineer"));
    addSurvivor(head, createSurvivor("Jane Doe", 30, 90.0, "Doctor"));
    addSurvivor(head, createSurvivor("Bob Smith", 40, 80.0, "Teacher"));

    // Find a survivor by name
    Survivor* survivor = findSurvivorByName(head, "Jane Doe");

    // Print the survivor's information
    if (survivor) {
        printf("%s, %d, %f, %s\n", survivor->name, survivor->age, survivor->health, survivor->occupation);
    } else {
        printf("Survivor not found.\n");
    }

    // Print the list of survivors
    printSurvivors(head);

    return 0;
}