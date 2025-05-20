//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

// Global variables
int sockfd;
struct sockaddr_in servaddr;

// Thread function to handle client requests
void *handle_client(void *arg) {
    int connfd = *(int *)arg;
    char buffer[1024];
    while (1) {
        // Receive a message from the client
        int n = recv(connfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            // Client has disconnected
            close(connfd);
            break;
        }

        // Process the message
        char *command = strtok(buffer, " ");
        if (strcmp(command, "INDEX") == 0) {
            // Index a document
            char *doc_id = strtok(NULL, " ");
            char *doc_text = strtok(NULL, "\n");
            // TODO: Implement document indexing
            printf("Indexed document %s: %s\n", doc_id, doc_text);
        } else if (strcmp(command, "SEARCH") == 0) {
            // Search for a document
            char *query = strtok(NULL, "\n");
            // TODO: Implement document search
            printf("Search results for query %s:\n", query);
        } else {
            // Invalid command
            printf("Invalid command: %s\n", command);
        }

        // Send a response to the client
        char response[1024];
        // TODO: Implement response generation
        strcpy(response, "OK");
        send(connfd, response, strlen(response), 0);
    }

    return NULL;
}

int main() {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        int connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client request
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &connfd);
        pthread_detach(thread);
    }

    // Close the socket
    close(sockfd);

    return 0;
}