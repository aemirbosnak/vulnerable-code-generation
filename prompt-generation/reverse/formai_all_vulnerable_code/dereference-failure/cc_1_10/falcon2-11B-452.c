//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888); // Replace with your desired port number
    server = gethostbyname("localhost"); // Replace with your server address
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char message[] = "Hello, server!";
    n = send(sockfd, message, sizeof(message), 0);
    if (n < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive a response from the server
    bzero(message, sizeof(message));
    n = recv(sockfd, message, sizeof(message), 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Received: %s\n", message);

    // Close the socket
    close(sockfd);

    return 0;
}