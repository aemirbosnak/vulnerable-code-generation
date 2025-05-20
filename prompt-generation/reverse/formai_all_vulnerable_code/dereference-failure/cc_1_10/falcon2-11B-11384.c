//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 993
#define IMAP_MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[IMAP_MAX_BUFFER_SIZE];
    char* hostname = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve hostname to IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Store IP address in serv_addr structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(IMAP_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s\n", hostname);

    // Login
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    write(sockfd, buffer, strlen(buffer));

    // Wait for response
    bzero(buffer, IMAP_MAX_BUFFER_SIZE);
    read(sockfd, buffer, IMAP_MAX_BUFFER_SIZE);
    printf("%s\n", buffer);

    // Logout
    sprintf(buffer, "LOGOUT\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Close socket
    close(sockfd);

    return 0;
}