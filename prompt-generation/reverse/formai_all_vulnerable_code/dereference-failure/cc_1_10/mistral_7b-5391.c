//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

void addStringToList(Node **head, char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    newNode->str = strdup(str);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%s -> ", current->str);
        current = current->next;
    }

    printf("NULL\n");
}

void freeList(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
}

int main(int argc, char *argv[]) {
    Node *stringList = NULL;

    for (int i = 1; i < argc; ++i) {
        addStringToList(&stringList, argv[i]);
    }

    printList(stringList);
    freeList(stringList);

    return 0;
}