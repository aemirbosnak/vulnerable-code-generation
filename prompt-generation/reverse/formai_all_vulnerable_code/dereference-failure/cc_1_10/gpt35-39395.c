//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define maximum length of buffer that can be passed
#define MAX_BUF_LEN 1024

int main(int argc, char *argv[]) {
    // Check for proper command line arguments
    if (argc != 3) {
        printf("\nUsage: ./proxy <ip_address> <port_number>\n");
        return 1;
    }
    
    // Set up variables for establishing a connection
    int port = atoi(argv[2]);
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_BUF_LEN];
    char *ip = argv[1];

    // Create a socket and check for an error
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("\nError creating socket\n");
        return 1;
    }

    // Set up the server address structure
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("\nError binding socket\n");
        return 1;
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("\nProxy server started.\n");

    while (1) {
        int clilen = sizeof(cliaddr);

        // Accept incoming connections and check for an error
        int newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (newsockfd < 0) {
            printf("\nError accepting incoming connection\n");
            return 1;
        }

        // Create a child process to handle the incoming connection
        int pid = fork();
        if (pid == 0) {
            close(sockfd);

            // Read from the client request
            bzero(buffer, MAX_BUF_LEN);
            read(newsockfd, buffer, MAX_BUF_LEN);
            printf("\nReceived from client: %s\n",buffer);

            // Connect to the requested server and send the client request
            struct sockaddr_in servaddr1;
            int sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
            bzero(&servaddr1, sizeof(servaddr));
            servaddr1.sin_family = AF_INET;
            servaddr1.sin_addr.s_addr = inet_addr(buffer + 4);
            servaddr1.sin_port = htons(80);
            connect(sockfd1, (struct sockaddr *)&servaddr1, sizeof(servaddr1));
            write(sockfd1, buffer, strlen(buffer));

            // Read the response from the requested server and send it to the client
            bzero(buffer, MAX_BUF_LEN);
            while(read(sockfd1, buffer, MAX_BUF_LEN)) {
                write(newsockfd, buffer, strlen(buffer));
                bzero(buffer, MAX_BUF_LEN);
            }

            // Close the sockets and exit the child process
            close(sockfd1);
            close(newsockfd);
            printf("\nClosing client connection.\n");
            exit(0);
        }
        else {
            close(newsockfd);
        }
    }
    return 0;
}