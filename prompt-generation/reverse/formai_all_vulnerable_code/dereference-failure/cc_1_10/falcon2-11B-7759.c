//Falcon2-11B DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Resolve the server address
    struct hostent *server;
    struct sockaddr_in server_addr;
    server = gethostbyname("localhost");
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    // Send data to the server
    char message[100];
    bzero(message, sizeof(message));
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive data from the server
    char response[100];
    bzero(response, sizeof(response));
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("receive failed");
        exit(1);
    }
    printf("Received: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}