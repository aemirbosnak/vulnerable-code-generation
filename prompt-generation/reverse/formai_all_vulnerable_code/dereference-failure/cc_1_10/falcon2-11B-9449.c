//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    // Declare variables
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Assign address to server
    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Fill in the rest of the structure with the server's IP address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21); // Standard FTP port number

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send command to the server
    n = sprintf(buffer, "USER anonymous\r\n");
    write(sockfd, buffer, n);
    n = sprintf(buffer, "PASS anonymous@\r\n");
    write(sockfd, buffer, n);

    // Send FTP commands
    n = sprintf(buffer, "LIST\r\n");
    write(sockfd, buffer, n);
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}