//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for storing the network topology
typedef struct Node {
    char name[100];
    struct Node* next;
} Node;

// Function to create a new node in the topology
Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, 100);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the topology
void addNode(Node** head, char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Function to print the network topology
void printTopology(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%s ", curr->name);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    char input[1000];
    printf("Enter the network topology: ");
    fgets(input, 1000, stdin);

    char* token = strtok(input, ",");
    while (token != NULL) {
        char* trimmed = token;
        while (isspace(*trimmed)) {
            trimmed++;
        }
        int size = strlen(trimmed);
        if (trimmed[size-1] == '\n') {
            trimmed[size-1] = '\0';
        }
        addNode(&head, trimmed);
        token = strtok(NULL, ",");
    }

    printf("The network topology is: ");
    printTopology(head);

    return 0;
}