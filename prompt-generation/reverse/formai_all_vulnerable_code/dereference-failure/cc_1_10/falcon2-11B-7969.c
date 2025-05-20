//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* insertNodeAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    newNode->prev = NULL;
    if (head!= NULL) {
        head->prev = newNode;
    }
    return newNode;
}

struct Node* insertNodeAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return head;
}

struct Node* insertNodeAtPosition(struct Node* head, int value, int position) {
    if (position == 0) {
        return insertNodeAtBeginning(head, value);
    } else if (position == 1) {
        return insertNodeAtEnd(head, value);
    } else {
        struct Node* current = head;
        int count = 1;
        while (current->next!= NULL && count < position) {
            current = current->next;
            count++;
        }
        struct Node* newNode = createNode(value);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next!= NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        return head;
    }
}

void deleteNodeAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head->next;
        head->next = current->next;
        if (current->next!= NULL) {
            current->next->prev = head;
        }
        free(current);
    }
}

void deleteNodeAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head;
        while (current->next->next!= NULL) {
            current = current->next;
        }
        struct Node* temp = current->next;
        current->next = NULL;
        free(temp);
    }
}

void deleteNodeAtPosition(struct Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteNodeAtBeginning(head);
    } else if (position == 2) {
        deleteNodeAtEnd(head);
    } else {
        struct Node* current = head;
        int count = 1;
        while (current->next!= NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        struct Node* temp = current->next->next;
        current->next->next = temp->next;
        free(temp);
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insertNodeAtBeginning(head, 1);
    head = insertNodeAtBeginning(head, 2);
    head = insertNodeAtBeginning(head, 3);
    head = insertNodeAtEnd(head, 4);
    head = insertNodeAtEnd(head, 5);
    head = insertNodeAtPosition(head, 6, 2);
    head = insertNodeAtPosition(head, 7, 4);
    printf("Initial list: ");
    printList(head);
    printf("\n");
    deleteNodeAtBeginning(head);
    printf("List after deleting the first node: ");
    printList(head);
    printf("\n");
    deleteNodeAtEnd(head);
    printf("List after deleting the last node: ");
    printList(head);
    printf("\n");
    deleteNodeAtPosition(head, 2);
    deleteNodeAtPosition(head, 4);
    printf("List after deleting nodes at positions 2 and 4: ");
    printList(head);
    printf("\n");
    return 0;
}