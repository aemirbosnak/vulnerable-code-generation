//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct baggage_tag {
    char name[20];
    int weight;
    struct baggage_tag* next;
} baggage_tag;

baggage_tag* insert_baggage(baggage_tag* head, char* name, int weight) {
    baggage_tag* new_node = (baggage_tag*)malloc(sizeof(baggage_tag));
    strcpy(new_node->name, name);
    new_node->weight = weight;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void handle_baggage(baggage_tag* head) {
    printf("The baggage handling area is abuzz with activity...\n");
    printf("Here is a list of passengers' belongings:**\n");

    baggage_tag* current = head;
    while (current) {
        printf("Name: %s, Weight: %d kg\n", current->name, current->weight);
        current = current->next;
    }

    printf("Please select a passenger's baggage:**\n");
    char* name = malloc(20);
    scanf("%s", name);

    current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            printf("Ah, you have found your baggage! Please collect it from the carousel.\n");
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Sorry, your baggage could not be found.\n");
    }
}

int main() {
    baggage_tag* head = NULL;

    insert_baggage(head, "John Doe", 20);
    insert_baggage(head, "Jane Doe", 15);
    insert_baggage(head, "Peter Pan", 25);

    handle_baggage(head);

    return 0;
}