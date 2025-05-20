//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    // create a linked list
    node *head = NULL;
    node *current = NULL;

    // generate random numbers for the linked list
    int nums[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        nums[i] = (rand() % 100) + 1;
    }

    // add nodes to the linked list
    for (int i = 0; i < 10; i++) {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = nums[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }

    // print the linked list
    node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // free memory
    while (head!= NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}