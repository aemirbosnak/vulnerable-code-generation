//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = (*head);
    *head = newNode;
}

void delete(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    Node* temp;

    while (current!= NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    *head = NULL;
}

void display(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    display(head);

    delete(&head);

    return 0;
}