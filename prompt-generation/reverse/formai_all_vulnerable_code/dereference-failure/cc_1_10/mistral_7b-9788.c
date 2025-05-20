//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define ALPHABET_SIZE 26

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    int length;
} Message;

typedef struct node {
    Message data;
    struct node *next;
} Node;

Node *head = NULL;

int entropy(char *str, int length) {
    int freq[ALPHABET_SIZE] = {0};
    int i, sum = 0;

    for (i = 0; i < length; i++)
        freq[str[i] - 'A']++;

    for (i = 0; i < ALPHABET_SIZE; i++)
        sum += freq[i] * log2(freq[i] + 1);

    return -sum / length;
}

void allocateMessage(Message *msg) {
    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        head->data = *msg;
        head->next = NULL;
    } else {
        Node *current = head;
        while (current->next != NULL)
            current = current->next;

        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = *msg;
        newNode->next = NULL;
        current->next = newNode;
    }
}

void freeList() {
    Node *current = head;
    while (head != NULL) {
        head = head->next;
        free(current);
        current = head;
    }
}

int main() {
    Message msg;
    char str[MAX_MESSAGE_LENGTH];
    int i, length;

    printf("Enter a message: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    length = strlen(str);

    msg.length = length;
    strncpy(msg.message, str, length + 1);

    allocateMessage(&msg);

    printf("Message allocated with entropy: %.2f\n", entropy(msg.message, msg.length));

    freeList();

    return 0;
}