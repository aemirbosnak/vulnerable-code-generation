//FormAI DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
/*
 * Post-Apocalyptic C Client-Server Application
 *
 * This program simulates a rudimentary communication system between two remote
 * outposts in a post-apocalyptic wasteland. The server acts as the main hub
 * and manages all incoming and outgoing messages from the client outpost.
 * 
 * Written By: [Your Name]
 * Date: [Current Date]
 */

// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Define constants
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Define function prototypes
void client();
void server();

// Initiate main function
int main(int argc, char *argv[]) {
    pid_t pid;

    if (argc != 2) {
        printf("Usage: %s [client | server]\n", argv[0]);
        return 0;
    }

    // Check if client or server is selected
    if (strcmp(argv[1], "client") == 0) {
        printf("Starting client...\n");
        client(); // Run client function
    } else if (strcmp(argv[1], "server") == 0) {
        printf("Starting server...\n");
        server(); // Run server function
    } else {
        printf("Invalid option. Please use 'client' or 'server'.\n");
        return 0;
    }

    return 0;
}

// Define client function
void client() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        printf("Message sent.\n");
    }

    close(sockfd);
}

// Define server function
void server() {
    int sockfd, connfd;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen;
    char buffer[BUFFER_SIZE];
    pid_t pid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    listen(sockfd, 5);

    while (1) {
        clientAddrLen = sizeof(clientAddr);
        connfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientAddrLen);

        pid = fork();

        if (pid == 0) {
            close(sockfd);

            while (1) {
                int nbytes = recv(connfd, buffer, BUFFER_SIZE, 0);
                if (nbytes == 0) {
                    break;
                }
                printf("Message received: %s\n", buffer);
            }

            close(connfd);
            exit(0);
        }
        else {
            close(connfd);
        }
    }
}