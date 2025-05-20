//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Node {
    int value;
    char* name;
    struct Node* next;
} Node;

Node* createNode(int value, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->name = strdup(name);
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int value, char* name) {
    Node* newNode = createNode(value, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(Node** head, int value) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current);
            break;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

int findMax(Node* head) {
    Node* current = head;
    int max = current->value;

    while (current != NULL) {
        if (current->value > max) {
            max = current->value;
        }
        current = current->next;
    }

    return max;
}

void printList(Node* head) {
    Node* current = head;

    printf("List: ");
    while (current != NULL) {
        printf("(%s, %d) -> ", current->name, current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    char names[10][20] = { "Apple", "Banana", "Cherry", "Date", "Elderberry", "Fig", "Grape", "Honeydew", "Kiwi", "Lemon" };

    for (int i = 0; i < 10; i++) {
        int randomValue = rand() % 100 + 1;
        append(&head, randomValue, names[i]);
    }

    printList(head);

    int valueToDelete = rand() % 100 + 1;
    delete(&head, valueToDelete);

    printf("Deleted %d from the list.\n", valueToDelete);

    printList(head);

    int maxValue = findMax(head);
    printf("Maximum value in the list is %d.\n", maxValue);

    reverseList(&head);

    printList(head);

    free(head);

    return 0;
}