//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Initialize the server address structure
    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    portno = htons(atoi(argv[1]));
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[2]);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    sprintf(buffer, "Hello, server!\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Error: Failed to send message to server\n");
        exit(EXIT_FAILURE);
    }

    // Receive a response from the server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        fprintf(stderr, "Error: Failed to receive response from server\n");
        exit(EXIT_FAILURE);
    }

    // Print the response
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}