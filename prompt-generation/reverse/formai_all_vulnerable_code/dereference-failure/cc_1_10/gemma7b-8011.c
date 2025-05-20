//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STASH_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void stash_init(Node** head) {
    *head = NULL;
}

void stash_add(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

int stash_size(Node* head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

char stash_peek(Node* head) {
    if (head == NULL) {
        return -1;
    } else {
        return head->data;
    }
}

int main() {
    Node* stash = NULL;

    stash_init(&stash);

    // Hide secret message in the stash
    stash_add(&stash, 'H');
    stash_add(&stash, 'I');
    stash_add(&stash, 'S');
    stash_add(&stash, 'T');
    stash_add(&stash, 'O');

    // Extract secret message from the stash
    char secret_message[MAX_STASH_SIZE] = "";
    int i = 0;
    for (Node* current = stash; current; current = current->next) {
        secret_message[i++] = stash_peek(current);
    }

    // Print secret message
    printf("%s\n", secret_message);

    return 0;
}