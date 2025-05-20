//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node* node) {
    free(node);
}

void deleteList(Node* head) {
    while (head!= NULL) {
        Node* temp = head;
        head = head->next;
        deleteNode(temp);
    }
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void swapNodes(Node* node1, Node* node2) {
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void sortList(Node* head) {
    Node* curr = head;
    Node* next = head->next;
    while (next!= NULL) {
        if (curr->data > next->data) {
            swapNodes(curr, next);
        }
        curr = curr->next;
        next = curr->next;
    }
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        int data = rand() % 100;
        Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next!= NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    printf("Before sorting:\n");
    printList(head);
    sortList(head);
    printf("After sorting:\n");
    printList(head);
    deleteList(head);
    return 0;
}