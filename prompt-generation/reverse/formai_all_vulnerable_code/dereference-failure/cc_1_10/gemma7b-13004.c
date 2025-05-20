//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_CONN 10

typedef struct Node {
    char name[25];
    struct Node* next;
    int sockfd;
} Node;

int main() {
    int i, j, k, listenfd, connfd;
    struct Node** network = NULL;
    char buf[1024];

    network = (struct Node**)malloc(sizeof(struct Node*) * MAX_CONN);

    for (i = 0; i < MAX_CONN; i++) {
        network[i] = (struct Node*)malloc(sizeof(struct Node));
        network[i]->next = NULL;
        network[i]->sockfd = -1;
    }

    listenfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    bind(listenfd, NULL, 0);

    for (k = 0; k < MAX_CONN; k++) {
        connfd = accept(listenfd, NULL, NULL);
        for (i = 0; i < MAX_CONN; i++) {
            if (network[i]->sockfd == -1) {
                network[i]->sockfd = connfd;
                break;
            }
        }
        printf("Client connected: %s\n", network[i]->name);
        strcpy(network[i]->name, "Client");
        write(network[i]->sockfd, "Welcome to the network!", 24);
    }

    for (i = 0; i < MAX_CONN; i++) {
        free(network[i]);
    }
    free(network);

    return 0;
}