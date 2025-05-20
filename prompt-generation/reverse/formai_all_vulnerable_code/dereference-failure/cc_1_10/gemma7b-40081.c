//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* InsertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void PrintList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    time_t t = time(NULL);
    srand(t);

    char message[MAX_BUFFER_SIZE];
    printf("Enter a message: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);

    Node* head = NULL;
    for (int i = 0; message[i] != '\0'; i++) {
        InsertAtTail(head, message[i]);
    }

    PrintList(head);

    return 0;
}