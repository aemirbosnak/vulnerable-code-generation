//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFSIZE 4096

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buff[BUFFSIZE];
    char *host, *file;
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    file = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        error("Error converting host to address");
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        error("Error connecting to server");
    }

    len = sizeof(cliaddr);
    if (getsockname(sockfd, (struct sockaddr *)&cliaddr, &len) < 0) {
        error("Error getting client address");
    }

    printf("Client IP: %s, Port: %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    // FTP commands
    strcpy(buff, "USER anonymous\r\n");
    if (send(sockfd, buff, strlen(buff), 0) < 0) {
        error("Error sending USER command");
    }
    if (recv(sockfd, buff, BUFFSIZE, 0) < 0) {
        error("Error receiving response from server");
    }
    printf("Server response: %s", buff);

    strcpy(buff, "PASS guest@example.com\r\n");
    if (send(sockfd, buff, strlen(buff), 0) < 0) {
        error("Error sending PASS command");
    }
    if (recv(sockfd, buff, BUFFSIZE, 0) < 0) {
        error("Error receiving response from server");
    }
    printf("Server response: %s", buff);

    strcpy(buff, "TYPE I\r\n");
    if (send(sockfd, buff, strlen(buff), 0) < 0) {
        error("Error sending TYPE command");
    }
    if (recv(sockfd, buff, BUFFSIZE, 0) < 0) {
        error("Error receiving response from server");
    }
    printf("Server response: %s", buff);

    strcpy(buff, "RETR ");
    strcat(buff, file);
    strcat(buff, "\r\n");
    if (send(sockfd, buff, strlen(buff), 0) < 0) {
        error("Error sending RETR command");
    }
    if (recv(sockfd, buff, BUFFSIZE, 0) < 0) {
        error("Error receiving response from server");
    }
    printf("Server response: %s", buff);

    // Receive file
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        error("Error opening file");
    }

    while ((n = recv(sockfd, buff, BUFFSIZE, 0)) > 0) {
        fwrite(buff, 1, n, fp);
    }
    if (n < 0) {
        error("Error receiving file");
    }

    fclose(fp);
    printf("File received successfully\n");

    // Close connection
    close(sockfd);

    return 0;
}