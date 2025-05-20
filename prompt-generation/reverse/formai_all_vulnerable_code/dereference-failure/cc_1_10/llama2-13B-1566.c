//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a knight
typedef struct knight {
    int gold; // Gold coins carried by the knight
    struct knight *next; // Next knight in the list
} knight;

// Function to create a new knight
knight *create_knight(int gold) {
    knight *new_knight = (knight *) malloc(sizeof(knight));
    new_knight->gold = gold;
    new_knight->next = NULL;
    return new_knight;
}

// Function to add a knight to the end of a list
void add_knight(knight **head_ref, int gold) {
    knight *new_knight = create_knight(gold);
    new_knight->next = *head_ref;
    *head_ref = new_knight;
}

// Function to remove the first knight from a list
void remove_knight(knight **head_ref) {
    if (*head_ref == NULL) {
        printf("Error: List is empty!\n");
        return;
    }

    knight *current = *head_ref;
    *head_ref = current->next;
    free(current);
}

// Function to traverse the list of knights and print their gold coins
void print_gold(knight *head) {
    while (head != NULL) {
        printf("%d ", head->gold);
        head = head->next;
    }
    printf("\n");
}

int main() {
    knight *head = NULL;

    // Add some knights to the list
    add_knight(&head, 100);
    add_knight(&head, 50);
    add_knight(&head, 200);

    // Remove the first knight from the list
    remove_knight(&head);

    // Traverse the list and print the gold coins
    print_gold(head);

    return 0;
}