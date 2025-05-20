//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Function declarations */
Node *createList(int *arr, int size);
int length(Node *head);
void display(Node *head);
Node *insertAtHead(Node *head, int value);
Node *insertAtTail(Node *head, int value);
Node *insertAtIndex(Node *head, int value, int index);
Node *deleteAtHead(Node *head);
Node *deleteAtIndex(Node *head, int index);
void searchValue(Node *head, int value);
bool detectLoop(Node *head);

int main() {
    int arr[] = {5, 3, 1, 7, 9};
    Node *head = createList(arr, 5);

    printf("Initial linked list:\n");
    display(head);

    /* Testing insertion operations */
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 4);
    head = insertAtIndex(head, 6, 3);

    printf("\nAfter inserting elements:\n");
    display(head);

    /* Testing deletion operations */
    head = deleteAtHead(head);
    head = deleteAtIndex(head, 3);

    printf("\nAfter deleting elements:\n");
    display(head);

    /* Testing searching operation */
    searchValue(head, 5);
    searchValue(head, 2);

    /* Testing loop detection operation */
    printf("\nIs there a loop in the linked list: %d\n", detectLoop(head));

    /* Creating a loop for testing */
    head->next->next->next->next->next = head->next;

    printf("\nIs there a loop in the linked list: %d\n", detectLoop(head));
}

/* Function definitions */

/* Create a linked list from an array */
Node *createList(int *arr, int size) {
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < size; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

/* Get the length of the linked list */
int length(Node *head) {
    int count = 0;
    Node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

/* Display the linked list */
void display(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

/* Insert a node at the beginning of the linked list */
Node *insertAtHead(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;

    return newNode;
}

/* Insert a node at the end of the linked list */
Node *insertAtTail(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;

    return head;
}

/* Insert a node at a specific index */
Node *insertAtIndex(Node *head, int value, int index) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *prev = head;
    int i;
    for (i = 0; i < index - 1; i++) {
        if (prev->next == NULL) {
            printf("Index out of range\n");
            return head;
        }

        prev = prev->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;

    return head;
}

/* Delete the first node of the linked list */
Node *deleteAtHead(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

/* Delete a node at a specific index */
Node *deleteAtIndex(Node *head, int index) {
    if (head == NULL) {
        return NULL;
    }

    if (index == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    Node *prev = head;
    int i;
    for (i = 0; i < index - 1; i++) {
        if (prev->next == NULL) {
            printf("Index out of range\n");
            return head;
        }

        prev = prev->next;
    }

    Node *temp = prev->next;
    prev->next = prev->next->next;
    free(temp);

    return head;
}

/* Search for a value in the linked list */
void searchValue(Node *head, int value) {
    Node *current = head;
    bool found = false;

    while (current != NULL) {
        if (current->data == value) {
            found = true;
            break;
        }

        current = current->next;
    }

    if (found) {
        printf("\n%d found in the linked list\n", value);
    } else {
        printf("\n%d not found in the linked list\n", value);
    }
}

/* Detect if there is a loop in the linked list */
bool detectLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}