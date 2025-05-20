//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: lively
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    // Get the server's IP address and port number
    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "gethostbyname: error\n");
        return 1;
    }

    portno = htons(5000);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Send a message to the server
    bzero(buffer, 256);
    strcpy(buffer, "Hello, server!");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive a message from the server
    bzero(buffer, 256);
    if (recv(sockfd, buffer, 256, 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Print the received message
    printf("Server's response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}