//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Check command-line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        exit(1);
    }

    // Convert argument to IPv4/IPv6 address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send command
    printf("FTP Client> ");
    fgets(buffer, sizeof(buffer), stdin);
    if (strncmp(buffer, "quit", 4) == 0) {
        close(sockfd);
        exit(0);
    }

    // Send command
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print response
    printf("Server: %s\n", buffer);

    // Close socket
    close(sockfd);
    return 0;
}