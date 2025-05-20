//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a knight's armor
struct Knight {
    int armor;   // Armor points (0-100)
    struct Knight *next; // Next knight in the list
};

// Function to add a new knight to the list
void addKnight(struct Knight **head_ref, int armor) {
    struct Knight *new_knight = malloc(sizeof(struct Knight));
    new_knight->armor = armor;
    new_knight->next = *head_ref;
    *head_ref = new_knight;
}

// Function to remove a knight from the list
void removeKnight(struct Knight **head_ref, int armor) {
    struct Knight *current = *head_ref;
    struct Knight *prev = NULL;

    while (current != NULL) {
        if (current->armor == armor) {
            if (prev == NULL) {
                *head_ref = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print all knights in the list
void printKnights(struct Knight *head) {
    while (head != NULL) {
        printf("%d ", head->armor);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Knight *head = NULL;

    // Add some knights to the list
    addKnight(&head, 20);
    addKnight(&head, 30);
    addKnight(&head, 40);
    addKnight(&head, 50);

    // Remove a knight from the list
    removeKnight(&head, 30);

    // Print all knights in the list
    printKnights(head);

    return 0;
}