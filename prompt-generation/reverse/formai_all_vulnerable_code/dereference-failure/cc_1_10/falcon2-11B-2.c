//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertNodeAtPosition(struct Node* head, int data, int position){
    if (position == 0) {
        struct Node* newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    int count = 0;
    while (current->next!= NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void printList(struct Node* head){
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* deleteNode(struct Node* head, int position){
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    int count = 0;
    while (current->next!= NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

struct Node* deleteNodeAtPosition(struct Node* head, int position){
    if (position == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    int count = 0;
    while (current->next!= NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    struct Node* temp = current->next;
    struct Node* temp2 = current->next;
    current->next = temp2->next;
    free(temp);
    free(temp2);
    return head;
}

struct Node* reverseList(struct Node* head){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct Node* removeDuplicates(struct Node* head){
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current!= NULL) {
        struct Node* next = current->next;
        while (next!= NULL && current->data == next->data) {
            next = next->next;
        }
        if (prev == NULL) {
            head = current;
        }
        else {
            prev->next = current;
        }
        prev = current;
        current = next;
    }
    return head;
}

int main(){
    struct Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 4);
    insertNode(head, 4);
    insertNode(head, 4);
    insertNode(head, 4);
    insertNode(head, 4);
    printList(head);
    printf("\n");
    deleteNodeAtPosition(head, 4);
    deleteNodeAtPosition(head, 2);
    printList(head);
    printf("\n");
    reverseList(head);
    printList(head);
    printf("\n");
    removeDuplicates(head);
    printList(head);
    printf("\n");
    return 0;
}