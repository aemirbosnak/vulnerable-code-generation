//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

// Server Function
void server() {
    int sockfd, newsockfd, clilen;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("Error listening");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (newsockfd == -1) {
            perror("Error accepting");
            continue;
        }

        // Read and write data to the client
        while (1) {
            memset(buffer, 0, MAXLINE);
            if (read(newsockfd, buffer, MAXLINE) == -1) {
                perror("Error reading from client");
                break;
            }

            printf("Client: %s\n", buffer);

            memset(buffer, 0, MAXLINE);
            strcpy(buffer, "Server: Hello World!");
            if (write(newsockfd, buffer, strlen(buffer)) == -1) {
                perror("Error writing to client");
                break;
            }
        }

        // Close the client connection
        close(newsockfd);
    }

    // Close the server socket
    close(sockfd);
}

// Client Function
void client(char *ip) {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read and write data to the server
    while (1) {
        memset(buffer, 0, MAXLINE);
        strcpy(buffer, "Client: Hello World!");
        if (write(sockfd, buffer, strlen(buffer)) == -1) {
            perror("Error writing to server");
            break;
        }

        memset(buffer, 0, MAXLINE);
        if (read(sockfd, buffer, MAXLINE) == -1) {
            perror("Error reading from server");
            break;
        }

        printf("Server: %s\n", buffer);
    }

    // Close the client socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [server/client] [server_ip]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        server();
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 3) {
            printf("Usage: %s [server/client] [server_ip]\n", argv[0]);
            return 1;
        }
        client(argv[2]);
    } else {
        printf("Invalid argument. Usage: %s [server/client] [server_ip]\n", argv[0]);
        return 1;
    }

    return 0;
}