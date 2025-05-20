//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertNodeAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    int count = 0;

    while(temp!= NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) {
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;

    while(temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);

    printList(head);

    return 0;
}