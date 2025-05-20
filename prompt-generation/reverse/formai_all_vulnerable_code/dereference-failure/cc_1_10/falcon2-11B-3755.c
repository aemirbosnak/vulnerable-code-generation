//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
    } else if (temp == *head) {
        if (temp->next == NULL) {
            free(temp);
            *head = NULL;
        } else {
            *head = temp->next;
            free(temp);
        }
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    printList(head);
    deleteNode(&head, 3);
    printList(head);
    return 0;
}