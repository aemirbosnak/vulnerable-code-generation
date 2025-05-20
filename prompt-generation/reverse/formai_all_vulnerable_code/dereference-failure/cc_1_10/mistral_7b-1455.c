//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addToList(Node** head, char data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int isPalindrome(Node* head, int length) {
    if (length <= 0) {
        return 1;
    }
    if (length == 1) {
        return head->data == head->next->data;
    }
    return head->data == head->next->data && isPalindrome(head->next->next, length - 2);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    char str[101];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; i < strlen(str); i++) {
        addToList(&head, str[i]);
    }

    int result = isPalindrome(head, strlen(str));

    printList(head);

    printf("The given string is %spalindrome%s.\n", result ? "" : "not ", result ? "" : "not ");

    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        temp->next = NULL;
        free(temp);
        temp = next;
    }

    return 0;
}