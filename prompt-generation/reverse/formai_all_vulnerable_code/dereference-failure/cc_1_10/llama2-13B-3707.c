//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure for a medieval knight
struct knight {
    int armor;  // Armor points
    int health; // Health points
    struct knight *next; // Next knight in the list
};

// Function to create a new knight
struct knight *create_knight(int armor, int health) {
    struct knight *new_knight = (struct knight *) malloc(sizeof(struct knight));
    new_knight->armor = armor;
    new_knight->health = health;
    new_knight->next = NULL;
    return new_knight;
}

// Function to add a knight to the beginning of the list
void add_knight(struct knight **head_ref, int armor, int health) {
    struct knight *new_knight = create_knight(armor, health);
    new_knight->next = *head_ref;
    *head_ref = new_knight;
}

// Function to remove the first knight from the list
void remove_first_knight(struct knight **head_ref) {
    if (*head_ref != NULL) {
        struct knight *current = *head_ref;
        *head_ref = current->next;
        free(current);
    }
}

// Function to traverse the list and print the armor and health of each knight
void print_knights(struct knight *head) {
    while (head != NULL) {
        printf("Knight #%d: Armor %d, Health %d\n", head->next == NULL ? 1 : 2, head->armor, head->health);
        head = head->next;
    }
}

int main() {
    struct knight *head = NULL;

    // Add some knights to the list
    add_knight(&head, 5, 100);
    add_knight(&head, 10, 50);
    add_knight(&head, 15, 20);

    // Remove the first knight from the list
    remove_first_knight(&head);

    // Traverse the list and print the armor and health of each knight
    print_knights(head);

    return 0;
}