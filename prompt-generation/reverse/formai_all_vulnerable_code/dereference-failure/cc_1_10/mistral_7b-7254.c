//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data[50];
    struct Node *next;
} Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void append(Node** head_ref, const char* newData) {
    Node* newNode = createNode(newData);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void displayList(Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* reversedHead = slow->next;
    slow->next = NULL;

    while (reversedHead != NULL) {
        if (head->data[0] != reversedHead->data[0])
            return 0;

        head = head->next;
        reversedHead = reversedHead->next;
    }

    return 1;
}

int main() {
    Node* head = NULL;

    append(&head, "racecar");
    append(&head, "madam");
    append(&head, "hello");
    append(&head, "level");
    append(&head, "deified");

    printf("Linked List: ");
    displayList(head);

    printf("Is Palindrome: %d\n", isPalindrome(head));

    return 0;
}