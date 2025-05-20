//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a survivor
typedef struct Survivor {
    char name[50];
    int age;
    char skills[100];
    struct Survivor *next; // Pointer to the next survivor
} Survivor;

// Function to create a new survivor
Survivor* create_survivor(char* name, int age, char* skills) {
    Survivor* newSurvivor = (Survivor*)malloc(sizeof(Survivor));
    strncpy(newSurvivor->name, name, sizeof(newSurvivor->name));
    newSurvivor->age = age;
    strncpy(newSurvivor->skills, skills, sizeof(newSurvivor->skills));
    newSurvivor->next = NULL;
    return newSurvivor;
}

// Function to append a survivor to the linked list
void append_survivor(Survivor** head_ref, Survivor* newSurvivor) {
    Survivor* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = newSurvivor;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newSurvivor;
}

// Function to display the survivors
void display_survivors(Survivor* survivor) {
    while (survivor != NULL) {
        printf("Survivor Name: %s\n", survivor->name);
        printf("Age: %d\n", survivor->age);
        printf("Skills: %s\n", survivor->skills);
        printf("--------------------------------------------------\n");
        survivor = survivor->next;
    }
}

// Function to free the linked list
void free_survivors(Survivor* survivor) {
    Survivor* temp;
    while (survivor != NULL) {
        temp = survivor;
        survivor = survivor->next;
        free(temp);
    }
}

// Main function
int main() {
    Survivor* survivors = NULL;

    // Creating survivors
    append_survivor(&survivors, create_survivor("Ranger Red", 32, "Archery, Tracking"));
    append_survivor(&survivors, create_survivor("Medic Maria", 28, "First Aid, Herbalism"));
    append_survivor(&survivors, create_survivor("Builder Bob", 45, "Construction, Engineering"));
    append_survivor(&survivors, create_survivor("Scout Sam", 22, "Exploration, Stealth"));

    // Displaying the survivors' information
    printf("Survivor Groups in Post-Apocalyptic Wasteland:\n");
    printf("=====================================\n");
    display_survivors(survivors);

    // Freeing the survivors memory
    free_survivors(survivors);
    return 0;
}