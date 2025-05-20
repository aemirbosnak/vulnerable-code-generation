//FormAI DATASET v1.0 Category: Client Server Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, port;
    socklen_t clientlen;
    struct sockaddr_in serveraddr, clientaddr;
    char buffer[BUFFER_SIZE];
    char *welcome_msg = "Welcome to the immersive C Client Server Application!\n";
    
    // check for correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);
    
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket!");
    }
    
    // bind socket to port
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        error("Error binding socket to port!");
    }
    
    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        error("Error listening for incoming connections!");
    }
    printf("Server is listening for incoming connections on port %d...\n", port);
    
    while (1) {
        // accept incoming connection
        clientlen = sizeof(clientaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (newsockfd < 0) {
            error("Error accepting incoming connection!");
        }
        
        // welcome the client
        if (write(newsockfd, welcome_msg, strlen(welcome_msg)) < 0) {
            error("Error writing welcome message to client!");
        }
        
        // communicate with client
        while (1) {
            bzero(buffer, BUFFER_SIZE);
            if (read(newsockfd, buffer, BUFFER_SIZE) < 0) {
                error("Error reading from client!");
            }
            if (strcmp(buffer, "quit\n") == 0) {
                printf("Client has disconnected.\n");
                break;
            }
            printf("Client: %s", buffer);
            printf("Server: ");
            bzero(buffer, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE, stdin);
            if (write(newsockfd, buffer, strlen(buffer)) < 0) {
                error("Error writing to client!");
            }
        }
        
        // close connection with client
        close(newsockfd);
    }
    
    return 0;
}