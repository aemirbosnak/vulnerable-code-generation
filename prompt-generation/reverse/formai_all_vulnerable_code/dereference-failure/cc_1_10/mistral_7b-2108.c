//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_SIZE 256
#define FILE_EXT ".txt"

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

Node *head = NULL;

void createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList() {
    Node *current = head;
    printf("\nCheerful C Graph Representation Program:\n");
    printf("-----------------------------------------\n");

    while (current != NULL) {
        printf("| %s |\n", current->data);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int i;
    char data[MAX_SIZE];

    for (i = 0; i < 10; i++) {
        sprintf(data, "Node %d", i + 1);
        createNode(data);
    }

    printList();

    return 0;
}

// Randomly create 10 nodes and add them to the linked list
// Display the cheerful C Graph Representation Program