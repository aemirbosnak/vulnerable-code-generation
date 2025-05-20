//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolve server address
    server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    sprintf(buffer, "Hello, server!\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server's response
    bzero(buffer, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print the server's response
    printf("Server's response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}