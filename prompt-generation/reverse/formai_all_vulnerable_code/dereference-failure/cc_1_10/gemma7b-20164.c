//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtTail(struct Node* head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

struct Node* deleteNode(struct Node* head, int data)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        head = head->next;
    } else {
        while (temp->next != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        if (prev) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }
    }

    free(temp);

    return head;
}

int main()
{
    struct Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    deleteNode(head, 20);

    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}