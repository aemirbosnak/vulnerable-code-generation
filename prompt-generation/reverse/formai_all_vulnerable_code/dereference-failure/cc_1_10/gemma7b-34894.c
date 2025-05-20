//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINKS 10

typedef struct Node {
    char name[20];
    struct Node **links;
    int numLinks;
} Node;

void drawNetwork(Node *node) {
    int i, j;
    printf("%s: ", node->name);
    for (i = 0; i < node->numLinks; i++) {
        printf("%s ", node->links[i]->name);
    }
    printf("\n");
    for (i = 0; i < node->numLinks; i++) {
        for (j = 0; j < node->links[i]->numLinks; j++) {
            if (node->links[i]->links[j] == node) {
                printf("  %s - %s\n", node->links[i]->name, node->name);
            }
        }
    }
}

int main() {
    Node *nodeA = malloc(sizeof(Node));
    nodeA->name[0] = 'A';
    nodeA->links = malloc(MAX_LINKS * sizeof(Node *));
    nodeA->numLinks = 0;

    Node *nodeB = malloc(sizeof(Node));
    nodeB->name[0] = 'B';
    nodeB->links = malloc(MAX_LINKS * sizeof(Node *));
    nodeB->numLinks = 0;

    Node *nodeC = malloc(sizeof(Node));
    nodeC->name[0] = 'C';
    nodeC->links = malloc(MAX_LINKS * sizeof(Node *));
    nodeC->numLinks = 0;

    Node *nodeD = malloc(sizeof(Node));
    nodeD->name[0] = 'D';
    nodeD->links = malloc(MAX_LINKS * sizeof(Node *));
    nodeD->numLinks = 0;

    nodeA->links[nodeA->numLinks++] = nodeB;
    nodeA->links[nodeA->numLinks++] = nodeC;

    nodeB->links[nodeB->numLinks++] = nodeD;

    nodeC->links[nodeC->numLinks++] = nodeD;

    drawNetwork(nodeA);

    free(nodeA);
    free(nodeB);
    free(nodeC);
    free(nodeD);

    return 0;
}