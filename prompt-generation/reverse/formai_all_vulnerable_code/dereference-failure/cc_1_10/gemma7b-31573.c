//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define SERVER_PORT 8080
#define MAX_CLIENT_CONN 10

struct node {
    int data;
    struct node* next;
};

int main() {
    int sockfd, clientfd;
    struct node* head = NULL;
    char buffer[1024];
    int i, j;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Listen for clients
    listen(sockfd, MAX_CLIENT_CONN);

    // Accept a client connection
    clientfd = accept(sockfd, NULL, NULL);

    // Receive data from the client
    recv(clientfd, buffer, 1024, 0);

    // Parse the data received from the client
    for (i = 0; buffer[i] != '\0'; i++) {
        int data = buffer[i] - '0';
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Send data back to the client
    send(clientfd, "Data received", 13, 0);

    // Close the client connection
    close(clientfd);

    // Print the linked list
    for (i = 0; head; i++) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}