//Gemma-7B DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Node {
    char name[256];
    struct Node* next;
} Node;

void insertNode(Node** head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Node* head = NULL;

    char cmd[MAX_CMD_LEN];

    printf("Enter command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char* cmdArgs[MAX_CMD_LEN];
    char* token = strtok(cmd, " ");

    int i = 0;
    while (token) {
        cmdArgs[i++] = token;
        token = strtok(NULL, " ");
    }

    if (strcmp(cmdArgs[0], "add") == 0) {
        insertNode(&head, cmdArgs[1]);
        printf("Node added.\n");
    } else if (strcmp(cmdArgs[0], "list") == 0) {
        for (Node* current = head; current; current = current->next) {
            printf("%s\n", current->name);
        }
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}