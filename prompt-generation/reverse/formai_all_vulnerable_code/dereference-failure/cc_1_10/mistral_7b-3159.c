//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char c;
    struct Node* next;
} Node;

Node* createNode(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    newNode->next = NULL;
    return newNode;
}

void addToList(Node** head, char c) {
    Node* newNode = createNode(c);
    newNode->next = *head;
    *head = newNode;
}

int isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node* prev = NULL;
    Node* current = slow->next;
    slow->next = NULL;

    while (current != NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Compare the first and last halves of the list
    Node* first = head;
    while (prev != NULL && first != NULL) {
        if (tolower(first->c) != tolower(prev->c)) {
            return 0;
        }
        first = first->next;
        prev = prev->next;
    }

    return 1;
}

int main() {
    char input[101];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    Node* head = NULL;
    for (int i = 0; i < strlen(input); i++) {
        addToList(&head, input[i]);
    }

    if (isPalindrome(head)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}