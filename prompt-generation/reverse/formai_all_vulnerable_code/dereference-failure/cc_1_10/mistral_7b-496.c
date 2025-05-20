//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Element: %s\n", slow->data);
}

bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* start = head;
    Node* end = slow;

    while (end != NULL && start != NULL) {
        if (strcmp(start->data, end->data) != 0) {
            return false;
        }
        start = start->next;
        end = end->next;
    }

    return true;
}

int main() {
    Node* head = NULL;

    push(&head, "apple");
    push(&head, "banana");
    push(&head, "cherry");
    push(&head, "orange");
    push(&head, "grape");

    printf("Original List: ");
    displayList(head);

    printf("\nReversed List: ");
    reverseList(&head);
    displayList(head);

    printf("\nMiddle Element: ");
    findMiddle(head);

    printf("\nIs Palindrome: %d\n", isPalindrome(head));

    return 0;
}