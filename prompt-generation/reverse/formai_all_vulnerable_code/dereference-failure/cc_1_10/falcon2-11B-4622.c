//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node *create_node(int value) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int main() {
    node *first = create_node(1);
    node *second = create_node(2);
    node *third = create_node(3);

    first->next = second;
    second->next = third;

    node *current = first;
    int turns = 0;

    printf("Welcome to the Memory Game!\n");
    printf("Turns: %d\n", turns);
    printf("First Card: %d\n", first->value);
    printf("Second Card: %d\n", second->value);
    printf("Third Card: %d\n", third->value);
    printf("-----------------------------\n");

    while (current!= NULL) {
        if (turns % 2 == 0) {
            printf("Turn: %d\n", turns);
            printf("Card: %d\n", current->value);
            printf("-----------------------------\n");
        } else {
            printf("Turn: %d\n", turns);
            printf("Card: %d\n", current->value);
            printf("Card: %d\n", current->next->value);
            printf("-----------------------------\n");
        }
        current = current->next;
        turns++;
    }

    return 0;
}