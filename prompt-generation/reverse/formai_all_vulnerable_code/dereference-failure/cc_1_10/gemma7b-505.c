//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define MAX_CONN 10
#define MAX_MSG_LEN 256

int main() {
    int sockfd, newsockfd, clientlen, sockopt, i;
    char msg[MAX_MSG_LEN], hostname[MAX_CONN], client_hostname[MAX_CONN];
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the socket to listen
    listen(sockfd, MAX_CONN);

    // Accept connections
    while (1) {
        clientlen = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (int *) &clientlen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Get the client hostname
        gethostname(client_addr.sin_addr.s_addr, client_hostname);

        // Send a welcome message
        strcpy(msg, "Welcome, ");
        strcat(msg, client_hostname);
        send(newsockfd, msg, MAX_MSG_LEN, 0);

        // Receive a message from the client
        recv(newsockfd, msg, MAX_MSG_LEN, 0);

        // Print the message from the client
        printf("Message from %s: %s\n", client_hostname, msg);

        // Close the connection
        close(newsockfd);
    }

    return 0;
}