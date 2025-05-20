//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include<stdio.h>
#include<stdlib.h>

typedef struct node {  
    int data;
    struct node *next;
} Node;

typedef struct linkedList {  
    Node *head;
} LinkedList;

LinkedList createLinkedList() {  
    LinkedList list;
    list.head = NULL;
    return list;
}

void addNode(LinkedList *list, int n) {  
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayLinkedList(LinkedList *list) {  
    Node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {  
    LinkedList list = createLinkedList();
    addNode(&list, 5);
    addNode(&list, 10);
    addNode(&list, 20);
    displayLinkedList(&list);
    return 0;
}