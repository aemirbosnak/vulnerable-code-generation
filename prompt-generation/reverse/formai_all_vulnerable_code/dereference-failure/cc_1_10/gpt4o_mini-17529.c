//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connectionCount;
} Node;

Node* network[MAX_NODES];
int nodeCount = 0;

void addNode(const char* name) {
    if (nodeCount < MAX_NODES) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        strncpy(newNode->name, name, MAX_NAME_LENGTH);
        newNode->connectionCount = 0;
        network[nodeCount++] = newNode;
        printf("Node '%s' added.\n", name);
    } else {
        printf("Node limit reached!\n");
    }
}

void addConnection(const char* name1, const char* name2) {
    Node* node1 = NULL;
    Node* node2 = NULL;

    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(network[i]->name, name1) == 0) {
            node1 = network[i];
        }
        if (strcmp(network[i]->name, name2) == 0) {
            node2 = network[i];
        }
    }

    if (node1 && node2) {
        if (node1->connectionCount < MAX_NODES && node2->connectionCount < MAX_NODES) {
            node1->connections[node1->connectionCount++] = node2;
            node2->connections[node2->connectionCount++] = node1; // bi-directional
            printf("Connection added between '%s' and '%s'.\n", name1, name2);
        } else {
            printf("Connection limit reached for one of the nodes!\n");
        }
    } else {
        printf("One or both nodes not found.\n");
    }
}

void displayNetwork() {
    for (int i = 0; i < nodeCount; i++) {
        Node* node = network[i];
        printf("Node: %s is connected to: ", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. Display Network\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node name: ");
                scanf("%s", name1);
                addNode(name1);
                break;
            case 2:
                printf("Enter first node name: ");
                scanf("%s", name1);
                printf("Enter second node name: ");
                scanf("%s", name2);
                addConnection(name1, name2);
                break;
            case 3:
                displayNetwork();
                break;
            case 4:
                printf("Exiting...\n");
                for (int i = 0; i < nodeCount; i++) {
                    free(network[i]);
                }
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}