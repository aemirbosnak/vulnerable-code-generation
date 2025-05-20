//FormAI DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define our knight structure
typedef struct knight {
    char* name;
    int strength;
    struct knight* next;
} Knight;

// Function to add a new knight to the list
void enlist(Knight** list, char* name, int strength) {
    // Create a new knight with the provided attributes
    Knight* new_knight = (Knight*)malloc(sizeof(Knight));
    new_knight->name = name;
    new_knight->strength = strength;
    new_knight->next = NULL;

    // If the list is empty, set the new knight as the head
    if (*list == NULL) {
        *list = new_knight;
    }
    // Otherwise, find the end of the list and add the new knight
    else {
        Knight* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_knight;
    }

    printf("%s has joined the kingdom with a strength of %d!\n", name, strength);
}

// Function to remove a knight from the list by their name
void demote(Knight** list, char* name) {
    // If the list is empty, nothing to do
    if (*list == NULL) {
        return;
    }

    Knight* current = *list;
    Knight* previous = NULL;

    // Search for the knight with the provided name
    while (current != NULL && current->name != name) {
        previous = current;
        current = current->next;
    }

    // If we found the knight, remove them from the list and free memory
    if (current != NULL) {
        if (previous == NULL) {
            *list = current->next;
        }
        else {
            previous->next = current->next;
        }

        printf("%s has been demoted from the kingdom...\n", name);
        free(current);
    }
    else {
        printf("Could not find knight %s to demote.\n", name);
    }
}

// Function to display the current state of the kingdom
void display(Knight* list) {
    printf("\nCurrent state of the kingdom:\n\n");

    if (list == NULL) {
        printf("The kingdom is empty!\n");
    }
    else {
        Knight* current = list;
        while (current != NULL) {
            printf("%s - Strength: %d\n", current->name, current->strength);
            current = current->next;
        }
    }

    printf("\n");
}

// Function to merge two kingdoms
void merge(Knight** list1, Knight** list2) {
    // If either list is empty, nothing to do
    if (*list1 == NULL || *list2 == NULL) {
        return;
    }

    // Find the end of list1 and append list2 to it
    Knight* current = *list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *list2;

    printf("Two kingdoms have been merged!\n");
}

// Perform a tournament to determine the strongest knight in the kingdom
void tournament(Knight* list) {
    // If the list is empty, nothing to do
    if (list == NULL) {
        printf("The tournament cannot be held as the kingdom is empty!\n");
        return;
    }

    // Find the strongest knight in the list
    Knight* strongest = list;
    Knight* current = list->next;
    while (current != NULL) {
        if (current->strength > strongest->strength) {
            strongest = current;
        }
        current = current->next;
    }

    printf("A tournament has been held, and %s reigns supreme with a strength of %d!\n", strongest->name, strongest->strength);
}

int main() {
    Knight* knights = NULL;
    enlist(&knights, "Arthur", 100);
    enlist(&knights, "Lancelot", 95);
    enlist(&knights, "Galahad", 85);
    display(knights);

    demote(&knights, "Lancelot");
    demote(&knights, "Robin Hood");
    display(knights);

    Knight* knights2 = NULL;
    enlist(&knights2, "Frodo", 50);
    enlist(&knights2, "Gandalf", 80);
    display(knights2);

    merge(&knights, &knights2);
    display(knights);

    tournament(knights);

    return 0;
}