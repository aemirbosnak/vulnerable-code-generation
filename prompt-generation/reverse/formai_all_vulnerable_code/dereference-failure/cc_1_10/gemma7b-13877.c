//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 10

typedef struct baggage {
    char name[50];
    int weight;
    struct baggage* next;
} baggage;

void add_baggage(baggage** head, char* name, int weight) {
    baggage* new_baggage = malloc(sizeof(baggage));
    strcpy(new_baggage->name, name);
    new_baggage->weight = weight;
    new_baggage->next = NULL;

    if (*head == NULL) {
        *head = new_baggage;
    } else {
        ((*head)->next = new_baggage);
        *head = new_baggage;
    }
}

void handle_bags(baggage* head) {
    printf("Welcome to the Great Hall of Baggage Handling!\n");
    printf("----------------------------------------\n");
    printf("List of baggage:**\n");

    while (head) {
        printf("Name: %s, Weight: %d\n", head->name, head->weight);
        head = head->next;
    }

    printf("Please select a baggage to be retrieved:");
    char name[50];
    scanf("%s", name);

    baggage* current_baggage = head;

    while (current_baggage) {
        if (strcmp(current_baggage->name, name) == 0) {
            printf("Baggage retrieved: %s, Weight: %d\n", current_baggage->name, current_baggage->weight);
            break;
        }
        current_baggage = current_baggage->next;
    }

    if (current_baggage == NULL) {
        printf("No baggage found with that name.\n");
    }
}

int main() {
    baggage* head = NULL;
    add_baggage(&head, "Anya's Bag", 20);
    add_baggage(&head, "Bob's Backpack", 30);
    add_baggage(&head, "Charlie's Chest", 40);
    add_baggage(&head, "Diana's Drum", 50);

    handle_bags(head);

    return 0;
}