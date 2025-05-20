//Gemma-7B DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct FileData {
    char *data;
    int size;
    struct FileData *next;
} FileData;

FileData *insertAtTail(FileData *head, char *data, int size) {
    FileData *newNode = malloc(sizeof(FileData));
    newNode->data = malloc(size);
    newNode->size = size;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printFileData(FileData *head) {
    while (head) {
        printf("Data: %s\n", head->data);
        printf("Size: %d\n", head->size);
        printf("Next: %p\n", head->next);
        printf("\n");
        head = head->next;
    }
}

int main() {
    FileData *head = NULL;

    // Insert data at the tail
    insertAtTail(head, "Hello, world!", 13);
    insertAtTail(head, "This is a file", 16);
    insertAtTail(head, "The quick brown fox jumps over the lazy dog.", 42);

    // Print file data
    printFileData(head);

    return 0;
}