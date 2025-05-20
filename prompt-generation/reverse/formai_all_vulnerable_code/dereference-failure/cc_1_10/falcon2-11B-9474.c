//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, valread, valwrite;
    struct sockaddr_in server;
    struct hostent *serverHost;
    char buffer[BUF_SIZE];
    char *fileName;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fileName = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    serverHost = gethostbyname("example.com");
    if (serverHost == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *)serverHost->h_addr, (char *)&server.sin_addr.s_addr, serverHost->h_length);
    server.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    if (send(sockfd, fileName, strlen(fileName), 0) < 0) {
        perror("Error sending file name");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    valread = recv(sockfd, buffer, BUF_SIZE, 0);
    if (valread < 0) {
        perror("Error receiving response");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sockfd);
    exit(0);
}