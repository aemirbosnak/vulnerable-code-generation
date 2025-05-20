//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_SIZE 100

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void generateRandomString(char *str) {
    int i;
    srand(time(NULL));

    for (i = 0; i < STR_SIZE && str[i] != '\0'; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[i] = '\0';
}

Node *createNode(char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error: could not allocate node\n");
        exit(EXIT_FAILURE);
    }

    newNode->str = (char *)malloc(sizeof(STR_SIZE) * sizeof(char));

    if (newNode->str == NULL) {
        printf("Memory error: could not allocate string\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->str, str);
    newNode->next = NULL;

    return newNode;
}

void insertNode(Node *newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

void printList() {
    Node *temp = head;

    while (temp != NULL) {
        printf("%s -> ", temp->str);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeMemory(Node *node) {
    if (node != NULL) {
        free(node->str);
        free(node);
    }
}

int main() {
    int i;
    char str[STR_SIZE];
    Node *newNode;

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        generateRandomString(str);
        newNode = createNode(str);
        insertNode(newNode);
    }

    printList();

    Node *temp = head;

    while (temp != NULL) {
        Node *next = temp->next;
        freeMemory(temp);
        temp = next;
    }

    return 0;
}