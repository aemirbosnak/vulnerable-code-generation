//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    char* filename = "example.txt";

    if (argc < 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(1);
    }

    portno = PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    bzero(buffer, 256);

    // Logging into FTP server
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    fprintf(stdout, "%s\n", buffer);
    bzero(buffer, 256);

    fprintf(stdout, "Enter your username: ");
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    fprintf(stdout, "%s\n", buffer);
    bzero(buffer, 256);

    fprintf(stdout, "Enter your password: ");
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    fprintf(stdout, "%s\n", buffer);
    bzero(buffer, 256);

    // Changing to binary mode
    n = write(sockfd, "TYPE I\n", strlen("TYPE I\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    fprintf(stdout, "%s\n", buffer);
    bzero(buffer, 256);

    // Sending request to retrieve file
    n = snprintf(buffer, 256, "RETR %s\n", filename);
    if (n < 0) {
        error("ERROR in snprintf");
    }
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    bzero(buffer, 256);

    // Receiving file data
    FILE* output = fopen(filename, "w");
    char data[256];
    while ((n = read(sockfd, data, 255)) > 0) {
        fwrite(data, sizeof(char), n, output);
        memset(data, 0, 256);
    }
    fclose(output);

    // Quitting FTP session
    n = write(sockfd, "QUIT\n", strlen("QUIT\n"));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    fprintf(stdout, "%s\n", buffer);

    close(sockfd);
    return 0;
}