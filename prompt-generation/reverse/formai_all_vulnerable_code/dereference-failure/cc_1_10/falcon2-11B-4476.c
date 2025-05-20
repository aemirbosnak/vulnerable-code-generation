//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char* ftp_command;
    char* ftp_response;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.example.com"); // Replace with your FTP server address
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21); // Standard FTP port

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    ftp_command = "USER anonymous\r\n";
    n = write(sockfd, ftp_command, strlen(ftp_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    ftp_command = "PASS anonymous@\r\n";
    n = write(sockfd, ftp_command, strlen(ftp_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    ftp_command = "PWD\r\n";
    n = write(sockfd, ftp_command, strlen(ftp_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("Current working directory: %s\n", buffer);

    // Close the socket and exit
    close(sockfd);
    exit(EXIT_SUCCESS);
}