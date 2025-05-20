//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

void compress(char* str) {
    Node* head = NULL;
    int i = 0;
    char prevChar = '\0';
    int count = 1;

    for (; str[i] != '\0'; i++) {
        if (prevChar == str[i]) {
            count++;
        } else {
            insertAtTail(&head, prevChar);
            prevChar = str[i];
            count = 1;
        }

        if (head != NULL) {
            printf("%c", head->data);
            if (count > 1) {
                printf("%d", count);
            }
        }
    }

    insertAtTail(&head, prevChar);
    printf("%c", head->data);
    if (count > 1) {
        printf("%d", count);
    }

    printf("\n");
}

int main() {
    char str[] = "aabbbbcccc";
    compress(str);

    return 0;
}