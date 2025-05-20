//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5

typedef struct Node {
    struct Node* next;
    char data;
} Node;

Node* head = NULL;

void addToTail(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

int main() {

    char buffer[BUFFER_SIZE];

    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = '\0';
    }

    FILE* file = fopen("file.txt", "r");

    if (file == NULL) {
        return 1;
    }

    char data;

    while ((data = fgetc(file)) != EOF) {
        addToTail(data);
    }

    fclose(file);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%c ", buffer[i]);
    }

    printf("\n");

    return 0;
}