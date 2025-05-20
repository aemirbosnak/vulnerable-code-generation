//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node *connections[MAX_NODES];
    int connectionCount;
} Node;

Node *nodes[MAX_NODES];
int nodeCount = 0;

Node* createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->connectionCount = 0;
    return newNode;
}

void addNode(const char *name) {
    if (nodeCount < MAX_NODES) {
        nodes[nodeCount++] = createNode(name);
        printf("Node '%s' added.\n", name);
    } else {
        printf("Maximum number of nodes reached.\n");
    }
}

void connectNodes(const char *name1, const char *name2) {
    Node *node1 = NULL, *node2 = NULL;

    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i]->name, name1) == 0) {
            node1 = nodes[i];
        }
        if (strcmp(nodes[i]->name, name2) == 0) {
            node2 = nodes[i];
        }
    }

    if (node1 && node2) {
        node1->connections[node1->connectionCount++] = node2;
        node2->connections[node2->connectionCount++] = node1;
        printf("Connected '%s' and '%s'.\n", name1, name2);
    } else {
        printf("One or both nodes not found.\n");
    }
}

void displayTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node '%s': ", nodes[i]->name);
        for (int j = 0; j < nodes[i]->connectionCount; j++) {
            printf("%s ", nodes[i]->connections[j]->name);
        }
        printf("\n");
    }
}

Node* findNode(const char *name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i]->name, name) == 0) {
            return nodes[i];
        }
    }
    return NULL;
}

void searchNode(const char *name) {
    Node *node = findNode(name);
    if (node) {
        printf("Node '%s' found with connections: ", node->name);
        for (int j = 0; j < node->connectionCount; j++) {
            printf("%s ", node->connections[j]->name);
        }
        printf("\n");
    } else {
        printf("Node '%s' not found in the network.\n", name);
    }
}

void cleanup() {
    for (int i = 0; i < nodeCount; i++) {
        free(nodes[i]);
    }
}

int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Node\n");
        printf("2. Connect Nodes\n");
        printf("3. Display Topology\n");
        printf("4. Search Node\n");
        printf("5. Exit\n");
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
                connectNodes(name1, name2);
                break;
            case 3:
                displayTopology();
                break;
            case 4:
                printf("Enter node name to search: ");
                scanf("%s", name1);
                searchNode(name1);
                break;
            case 5:
                cleanup();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}