//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int integer_data;
    float decimal_data;
    char character_data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Create a few nodes
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->integer_data = 10;
    node1->decimal_data = 20.5f;
    node1->character_data = 'a';
    node1->next = NULL;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->integer_data = 20;
    node2->decimal_data = 30.2f;
    node2->character_data = 'b';
    node2->next = NULL;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->integer_data = 30;
    node3->decimal_data = 40.1f;
    node3->character_data = 'c';
    node3->next = NULL;

    // Link the nodes together
    if (head == NULL) {
        head = node1;
        tail = node1;
    } else {
        tail->next = node2;
        tail = node2;
    }

    tail->next = node3;
    tail = node3;

    // Print the data of each node
    while (head) {
        printf("Integer data: %d\n", head->integer_data);
        printf("Decimal data: %.2f\n", head->decimal_data);
        printf("Character data: %c\n", head->character_data);
        printf("\n");

        head = head->next;
    }

    return 0;
}