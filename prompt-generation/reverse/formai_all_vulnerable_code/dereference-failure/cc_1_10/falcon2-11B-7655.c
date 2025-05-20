//Falcon2-11B DATASET v1.0 Category: Networking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd, valread, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolve server name
    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Store the server's address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    printf("Sending data to the server...\n");
    n = write(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", 53);
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Read data from the server
    printf("Receiving data from the server...\n");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    valread = read(sockfd, &serv_addr, sizeof(serv_addr));
    if (valread < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    printf("Server address: %s\n", inet_ntoa(serv_addr.sin_addr));
    printf("Server port: %d\n", ntohs(serv_addr.sin_port));

    // Close the socket
    close(sockfd);

    return 0;
}