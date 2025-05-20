//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100

typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    srand(time(NULL)); // Seed the random number generator

    Node* head = NULL;
    Node* tail = NULL;

    int n = 0;
    int value = rand() % 100; // Random value between 0 and 99
    int counter = 0;

    while (value <= 0 || value > MAX_NODES) {
        value = rand() % 100;
    }

    while (counter < value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = rand() % 100;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        counter++;
    }

    printf("Node count: %d\n", counter);

    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}