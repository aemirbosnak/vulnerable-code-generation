//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Brave knight struct to represent nodes in the linked list
typedef struct {
    int gold;  // amount of gold collected
    struct brave_knight *next; // pointer to next knight
} brave_knight;

// Function to create a new brave knight
brave_knight* create_knight(int gold) {
    brave_knight* knight = malloc(sizeof(brave_knight));
    knight->gold = gold;
    knight->next = NULL;
    return knight;
}

// Function to add a knight to the front of the list
void add_knight(brave_knight** head_ref, int gold) {
    brave_knight* new_knight = create_knight(gold);
    new_knight->next = *head_ref;
    *head_ref = new_knight;
}

// Function to remove the first knight from the list
void remove_first_knight(brave_knight** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty! No knights to remove.\n");
        return;
    }

    brave_knight* current = *head_ref;
    brave_knight* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
    *head_ref = previous;
}

// Function to traverse the list and print the amount of gold collected
void print_gold(brave_knight* head) {
    if (head == NULL) {
        printf("List is empty! No knights to print.\n");
        return;
    }

    printf("Gold collected so far: %d\n", head->gold);
    print_gold(head->next);
}

int main() {
    brave_knight* head = NULL;

    // Add some knights to the list
    add_knight(&head, 10);
    add_knight(&head, 20);
    add_knight(&head, 30);

    // Remove the first knight from the list
    remove_first_knight(&head);

    // Traverse the list and print the amount of gold collected
    print_gold(head);

    return 0;
}