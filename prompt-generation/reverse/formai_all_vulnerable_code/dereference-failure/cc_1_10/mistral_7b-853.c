//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char data[MAX_LEN];
    struct Node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    char input[MAX_LEN];

    printf("Enter the data for linked list (Enter 'exit' to quit):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        insertAtEnd(&head, input);
    }

    displayList(head);

    return 0;
}