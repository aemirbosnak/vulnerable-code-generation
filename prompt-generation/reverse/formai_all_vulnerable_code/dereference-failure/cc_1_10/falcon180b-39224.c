//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d added to the list\n", data);
}

void deleteNode(int data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d deleted from the list\n", data);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found in the list\n", data);
}

void searchNode(int data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("%d found in the list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the list\n", data);
}

void printList() {
    Node *temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    printList();
    searchNode(4);
    deleteNode(3);
    printList();
    return 0;
}