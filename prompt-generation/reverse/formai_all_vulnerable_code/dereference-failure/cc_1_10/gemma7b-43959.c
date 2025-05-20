//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char **data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char* data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = malloc(MAX_BUFFER_SIZE);
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    head->next = newNode;
    return newNode;
}

void freeNode(Node* node) {
    free(node->data);
    free(node);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serverSockAddr, clientSockAddr;
    char buffer[MAX_BUFFER_SIZE];
    Node* head = NULL;

    // Listen for incoming connections
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    serverSockAddr.sin_family = AF_INET;
    serverSockAddr.sin_port = htons(8080);
    serverSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr*)&serverSockAddr, sizeof(serverSockAddr));

    // Accept connections
    newsockfd = accept(sockfd, (struct sockaddr*)&clientSockAddr, NULL);

    // Receive data from client
    recv(newsockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Insert data into linked list
    insertAtTail(head, buffer);

    // Send data back to client
    send(newsockfd, buffer, MAX_BUFFER_SIZE, 0);

    // Free resources
    freeNode(head);
    close(newsockfd);
    close(sockfd);

    return 0;
}