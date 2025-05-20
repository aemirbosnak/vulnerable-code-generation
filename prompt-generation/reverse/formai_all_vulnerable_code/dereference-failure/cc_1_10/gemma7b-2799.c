//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int calculateDistance(Node* node1, Node* node2) {
    int distance = abs(node1->data - node2->data);
    return distance;
}

int main() {

    // Create a linked list
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    // Print the list
    printList(head);

    // Calculate the distances between each pair of nodes
    for (Node* node1 = head; node1; node1) {
        for (Node* node2 = head; node2; node2) {
            if (node1 != node2) {
                int distance = calculateDistance(node1, node2);
                printf("Distance between %d and %d is %d\n", node1->data, node2->data, distance);
            }
        }
    }

    return 0;
}