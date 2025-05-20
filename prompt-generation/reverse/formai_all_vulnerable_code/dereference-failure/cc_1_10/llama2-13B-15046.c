//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define INF 1000000

typedef struct node {
    int key;
    struct node* next;
} Node;

void search(Node** head_ref, int key) {
    Node* head = *head_ref;
    Node* current = head;
    Node* previous = NULL;
    int distance = 0;

    while (current != NULL) {
        if (current->key == key) {
            printf("Found key %d at distance %d\n", key, distance);
            return;
        }

        distance++;
        previous = current;
        current = current->next;
    }

    printf("Key %d not found\n", key);
}

int main() {
    Node* head = NULL;

    head = (Node*) malloc(sizeof(Node));
    head->key = 1;
    head->next = NULL;

    head = (Node*) malloc(sizeof(Node));
    head->key = 2;
    head->next = head;

    head = (Node*) malloc(sizeof(Node));
    head->key = 3;
    head->next = head->next;

    search(&head, 2);

    return 0;
}