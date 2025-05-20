//Gemma-7B DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUERY_LENGTH 255

typedef struct Node {
    char name[MAX_QUERY_LENGTH];
    struct Node* next;
} Node;

void insertNode(Node* head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void queryNodes(Node* head, char* query) {
    char* ptr = query;
    char* name;

    while (ptr) {
        name = strtok(ptr, " ");
        ptr = strtok(NULL, " ");

        if (strcmp(name, head->name) == 0) {
            printf("%s ", head->name);
        }

        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insertNode(head, "John Doe");
    insertNode(head, "Jane Doe");
    insertNode(head, "Peter Pan");

    char query[MAX_QUERY_LENGTH] = "Find Jane Doe and Peter Pan";

    queryNodes(head, query);

    printf("\n");

    return 0;
}