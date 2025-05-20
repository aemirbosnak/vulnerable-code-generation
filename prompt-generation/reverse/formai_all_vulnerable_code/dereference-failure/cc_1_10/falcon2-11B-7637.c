//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertNode(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    Node* prev = NULL;

    if (position == 0) {
        *head = newNode;
    } else {
        for (int i = 0; i < position - 1; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = newNode;
        newNode->next = temp;
    }
}

void deleteNode(Node** head, int position) {
    Node* temp = *head;
    Node* prev = NULL;

    if (position == 0) {
        *head = temp->next;
    } else {
        for (int i = 0; i < position - 1; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }

    free(temp);
}

int search(Node* head, int value) {
    Node* temp = head;

    while (temp!= NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

void sort(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp!= NULL && temp->next!= NULL) {
        Node* second = temp->next;

        while (second->next!= NULL) {
            second = second->next;
        }

        if (temp->data > second->data) {
            Node* temp1 = temp->data;
            temp->data = second->data;
            second->data = temp1;

            prev = temp;
            temp = temp->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void reverse(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp!= NULL && temp->next!= NULL) {
        Node* second = temp->next;

        while (second->next!= NULL) {
            second = second->next;
        }

        if (temp->data > second->data) {
            Node* temp1 = temp->data;
            temp->data = second->data;
            second->data = temp1;

            prev = temp;
            temp = temp->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void print(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void execute(Node* head, int operation) {
    switch (operation) {
        case 1:
            insertNode(&head, 10, 1);
            insertNode(&head, 20, 2);
            insertNode(&head, 30, 3);
            insertNode(&head, 40, 4);
            insertNode(&head, 50, 5);

            printf("Sorted Linked List: ");
            sort(&head);
            print(head);
            break;
        case 2:
            deleteNode(&head, 1);
            deleteNode(&head, 3);
            deleteNode(&head, 5);
            deleteNode(&head, 4);

            printf("Reversed Linked List: ");
            reverse(&head);
            print(head);
            break;
        case 3:
            printf("Value found at index %d\n", search(head, 30));
            break;
        case 4:
            printf("Sorted Linked List: ");
            sort(&head);
            print(head);
            break;
    }
}

int main() {
    Node* head = NULL;
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        insertNode(&head, rand() % 100, rand() % 10);
    }

    printf("Original Linked List: ");
    print(head);

    int operation;
    printf("Enter operation (1-4): ");
    scanf("%d", &operation);

    execute(head, operation);

    return 0;
}