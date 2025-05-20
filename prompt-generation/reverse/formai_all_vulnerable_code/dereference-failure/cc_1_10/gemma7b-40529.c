//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CONN 10

typedef struct Node {
    char name[255];
    struct Node* next;
    int sockfd;
    int online;
} Node;

Node* head = NULL;

void addNode(char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->sockfd = -1;
    newNode->online = 0;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
}

void mapTopology() {
    printf("The Galactic Grid:\n");

    Node* current = head;
    while (current) {
        printf("%s ", current->name);

        if (current->next) {
            printf("-> ");
        }
    }

    printf("\n");
}

int main() {
    addNode("C-137");
    addNode("M-12");
    addNode("Z-42");
    addNode("R-5");

    mapTopology();

    return 0;
}