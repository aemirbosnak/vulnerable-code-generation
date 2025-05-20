//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a knight's armor
struct Knight {
    int armor; // Armor points
    struct Knight *next; // Next knight in the list
};

// Function to create a new knight
struct Knight *createKnight(int armor) {
    struct Knight *newKnight = malloc(sizeof(struct Knight));
    newKnight->armor = armor;
    newKnight->next = NULL;
    return newKnight;
}

// Function to add a knight to the end of the list
void addKnight(struct Knight **head_ref, int armor) {
    struct Knight *newKnight = createKnight(armor);
    newKnight->next = *head_ref;
    *head_ref = newKnight;
}

// Function to remove the first knight from the list
struct Knight *removeFirstKnight(struct Knight **head_ref) {
    struct Knight *firstKnight = *head_ref;
    *head_ref = firstKnight->next;
    free(firstKnight);
    return firstKnight;
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
    addKnight(&head, 10);
    addKnight(&head, 20);
    addKnight(&head, 30);

    // Remove the first knight from the list
    struct Knight *firstKnight = removeFirstKnight(&head);

    // Print all knights in the list
    printKnights(head);

    // Free the remaining knights
    struct Knight *current = head;
    while (current != NULL) {
        struct Knight *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}