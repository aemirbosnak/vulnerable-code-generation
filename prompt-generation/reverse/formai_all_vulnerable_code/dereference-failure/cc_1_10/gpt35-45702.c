//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// This program is a network topology mapper that is going to map a big and crazy network with different nodes and links

typedef struct node {
    char name[20];
    int id;
    int numOfLinks;
    struct link *links;
} Node;

typedef struct link {
    int id;
    int weight;
    Node *node1;
    Node *node2;
} Link;

Node *createNode(char name[], int id) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->id = id;
    newNode->numOfLinks = 0;
    newNode->links = NULL;
    return newNode;
}

Link *createLink(int id, int weight, Node *node1, Node *node2) {
    Link *newLink = (Link *) malloc(sizeof(Link));
    newLink->id = id;
    newLink->weight = weight;
    newLink->node1 = node1;
    newLink->node2 = node2;
    return newLink;
}

void addLink(Node* node, Link* link) {
    node->numOfLinks++;
    node->links = (Link *) realloc(node->links, node->numOfLinks*sizeof(Link));
    node->links[node->numOfLinks-1] = *link;
}

void printNetworkStatus(Node nodes[], int numOfNodes) {
    printf("Network status:\n");
    for (int i = 0; i < numOfNodes; i++) {
        printf("\nNode %s (id: %d) has %d links:\n", nodes[i].name, nodes[i].id, nodes[i].numOfLinks);
        for (int j = 0; j < nodes[i].numOfLinks; j++) {
            printf("Link %d with weight %d connects node %s and node %s\n", nodes[i].links[j].id, nodes[i].links[j].weight, nodes[i].name, nodes[i].links[j].node1->name);
        }
    }
}

int main() {

    Node nodeA = *createNode("A", 1);
    Node nodeB = *createNode("B", 2);
    Node nodeC = *createNode("C", 3);
    Node nodeD = *createNode("D", 4);

    Link link1 = *createLink(1, 10, &nodeA, &nodeB);
    Link link2 = *createLink(2, 20, &nodeB, &nodeC);
    Link link3 = *createLink(3, 30, &nodeC, &nodeD);
    Link link4 = *createLink(4, 50, &nodeD, &nodeA);

    addLink(&nodeA, &link1);
    addLink(&nodeB, &link2);
    addLink(&nodeC, &link3);
    addLink(&nodeD, &link4);

    Node nodes[] = {nodeA, nodeB, nodeC, nodeD};

    int numOfNodes = sizeof(nodes)/sizeof(Node);

    printNetworkStatus(nodes, numOfNodes);

    return 0;
}