//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void addNode(Node **head, int data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    srand(time(NULL));
    Node *head = NULL;
    int numNodes, numEdges;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numNodes; i++) {
        addNode(&head, i);
    }

    for (int i = 0; i < numEdges; i++) {
        int from, to;
        printf("Enter the endpoints of edge %d: ", i+1);
        scanf("%d %d", &from, &to);
        Node *fromNode = head;
        while (fromNode->data!= from) {
            fromNode = fromNode->next;
        }
        Node *toNode = head;
        while (toNode->data!= to) {
            toNode = toNode->next;
        }
        fromNode->next = toNode;
    }

    printList(head);

    return 0;
}