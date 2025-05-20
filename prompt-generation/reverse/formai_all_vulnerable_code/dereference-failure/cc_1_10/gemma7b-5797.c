//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    system("clear");
    printf("Hey, you! Wanna see a cool C network topology mapper?\n");
    printf("I'm a topologist, ready to map out your dreams...\n");
    printf("Just give me a list of nodes, and I'll create a map that'll make your head spin!\n");
    printf("For example: 3 4 5 6 7\n");
    printf("Enter the nodes:");

    char* nodesStr;
    scanf("%s", nodesStr);

    int numNodes = atoi(nodesStr);
    printf("Number of nodes: %d\n", numNodes);

    // Create an adjacency list to represent the network topology
    int** adjacencyList = (int**)malloc(numNodes * sizeof(int*));
    for (int i = 0; i < numNodes; i++) {
        adjacencyList[i] = (int*)malloc(numNodes * sizeof(int));
    }

    printf("Enter the connections between nodes, using the format 'node1 node2':\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d ", &adjacencyList[i][j]);
        }
    }

    // Draw the network topology
    printf("Here's your network topology:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (adjacencyList[i][j] == 1) {
                printf("%d ----> %d\n", i + 1, j + 1);
            }
        }
    }

    // Free the memory
    for (int i = 0; i < numNodes; i++) {
        free(adjacencyList[i]);
    }
    free(adjacencyList);

    return 0;
}