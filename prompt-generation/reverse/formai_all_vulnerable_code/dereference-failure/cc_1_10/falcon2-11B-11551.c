//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} node;

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    node* head = NULL;

    for (int i = 1; i <= n; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    printf("Original sequence of disks:\n");
    node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    node* source = head;
    node* destination = NULL;
    node* auxiliary = NULL;

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            node* temp = source->next;
            source->next = auxiliary;
            auxiliary->next = temp;
            destination = source;
            source = temp;
        } else {
            node* temp = source->next;
            source->next = auxiliary;
            auxiliary->next = destination;
            destination = source;
            source = temp;
        }
    }

    printf("\nFinal sequence of disks:\n");
    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}