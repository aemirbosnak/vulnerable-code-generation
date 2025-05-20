//Gemma-7B DATASET v1.0 Category: System administration ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Node {
    char name[256];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    char cmd[MAX_CMD_LEN];

    printf("Enter a command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    // Tokenize the command
    char* token = strtok(cmd, " ");
    char** args = malloc(10 * sizeof(char*));

    int i = 0;
    while (token) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    // Check if the command is valid
    if (strcmp(args[0], "add") == 0) {
        // Add a new node to the list
        Node* newNode = malloc(sizeof(Node));
        printf("Enter the node name: ");
        scanf("%s", newNode->name);
        newNode->next = head;
        head = newNode;
    } else if (strcmp(args[0], "remove") == 0) {
        // Remove a node from the list
        printf("Enter the node name: ");
        char nodeName[256];
        scanf("%s", nodeName);

        Node* prev = NULL;
        Node* current = head;

        while (current) {
            if (strcmp(current->name, nodeName) == 0) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            printf("Node not found.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    free(args);
    return 0;
}