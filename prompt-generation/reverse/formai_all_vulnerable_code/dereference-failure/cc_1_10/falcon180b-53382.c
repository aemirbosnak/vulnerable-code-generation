//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(LinkedList* list, int data) {
    Node* prev = NULL;
    Node* curr = list->head;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node not found\n");
    } else if (curr == list->head) {
        list->head = curr->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void printList(LinkedList* list) {
    Node* curr = list->head;
    printf("Linked List: ");

    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main() {
    LinkedList* list = createLinkedList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);

    printList(list);

    deleteNode(list, 2);

    printList(list);

    return 0;
}