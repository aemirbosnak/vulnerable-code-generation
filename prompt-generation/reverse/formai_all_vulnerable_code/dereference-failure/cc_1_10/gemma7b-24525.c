//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 256

struct Node {
    char data;
    struct Node* next;
};

typedef struct Node Node;

Node* CreateNode(char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertNode(Node* head, char data) {
    Node* newNode = CreateNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void TraverseNodes(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char secretMessage[MAX_STRING_LENGTH];
    secretMessage[0] = '\0';

    // Create a random number of nodes
    int numNodes = rand() % 10 + 1;

    // Insert nodes into the linked list
    for (int i = 0; i < numNodes; i++) {
        InsertNode(secretMessage, (char)rand() % 26 + 65);
    }

    // Traverse the nodes and print their data
    TraverseNodes(secretMessage);

    return 0;
}