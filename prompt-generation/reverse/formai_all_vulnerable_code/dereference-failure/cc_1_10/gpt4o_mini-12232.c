//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int connectedNodes[MAX_NODES];
    int connectionCount;
} Node;

Node network[MAX_NODES];
int nodeCount = 0;

void addNode(const char* name) {
    if (nodeCount < MAX_NODES) {
        strcpy(network[nodeCount].name, name);
        network[nodeCount].connectionCount = 0;
        nodeCount++;
    } else {
        printf("Maximum node limit reached.\n");
    }
}

void addConnection(const char* from, const char* to) {
    int fromIndex = -1, toIndex = -1;

    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(network[i].name, from) == 0) {
            fromIndex = i;
        }
        if (strcmp(network[i].name, to) == 0) {
            toIndex = i;
        }
    }

    if (fromIndex == -1 || toIndex == -1) {
        printf("Invalid connection: one or both nodes not found.\n");
        return;
    }

    // Prevent duplicate connections
    for (int i = 0; i < network[fromIndex].connectionCount; i++) {
        if (network[fromIndex].connectedNodes[i] == toIndex) {
            printf("Connection already exists.\n");
            return;
        }
    }

    network[fromIndex].connectedNodes[network[fromIndex].connectionCount++] = toIndex;
    network[toIndex].connectedNodes[network[toIndex].connectionCount++] = fromIndex;
    
    printf("Connection added between %s and %s.\n", from, to);
}

void displayTopology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%s connects to: ", network[i].name);
        for (int j = 0; j < network[i].connectionCount; j++) {
            printf("%s ", network[network[i].connectedNodes[j]].name);
        }
        printf("\n");
    }
}

int main() {
    char command[MAX_NAME_LENGTH * 2];
    printf("Welcome to the Retro Network Topology Mapper!\n");
    printf("Commands: ADD NODE [name], ADD CONNECTION [node1] [node2], DISPLAY, EXIT\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        char* token = strtok(command, "\n");

        if (strncmp(token, "ADD NODE ", 9) == 0) {
            addNode(token + 9);
        } else if (strncmp(token, "ADD CONNECTION ", 15) == 0) {
            char* node1 = strtok(token + 15, " ");
            char* node2 = strtok(NULL, " ");
            addConnection(node1, node2);
        } else if (strcmp(token, "DISPLAY") == 0) {
            displayTopology();
        } else if (strcmp(token, "EXIT") == 0) {
            printf("Exiting the Retro Network Topology Mapper. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}