//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Getting the server's IP address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Filling in the server's address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    // Connecting to the server
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected to server\n");

    // Sending data to the server
    printf("Enter a string to send to the server: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Send the message to the server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Write Failed");
        exit(EXIT_FAILURE);
    }

    // Receiving data from the server
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Read Failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", buffer);

    // Closing the socket
    close(sockfd);

    return 0;
}