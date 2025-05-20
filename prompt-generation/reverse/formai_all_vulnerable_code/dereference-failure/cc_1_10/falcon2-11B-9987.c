//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portnum;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send a message
    char buffer[256];
    sprintf(buffer, "Hello, world! This is a message from the C Port Scanner.");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending data");
        exit(1);
    }

    // Receive a response
    char response[256];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }
    printf("Received response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}