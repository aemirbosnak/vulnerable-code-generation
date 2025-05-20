//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *serverinfo;
    char *host = argv[1];
    char *port = argv[2];
    char *username = argv[3];
    char *password = argv[4];
    char *filename = argv[5];
    char *mode = argv[6];
    char *command;
    char *buffer = (char *) malloc(MAX_LINE * sizeof(char));
    int n;

    if (argc!= 7) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password> <filename> <mode>\n", argv[0]);
        exit(1);
    }

    if ((serverinfo = getaddrinfo(host, port, NULL, NULL)) == NULL) {
        fprintf(stderr, "getaddrinfo failed\n");
        exit(1);
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket failed\n");
        exit(1);
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect failed\n");
        exit(1);
    }

    fprintf(stdout, "Connected to %s:%s\n", host, port);

    if (strcmp(mode, "download") == 0) {
        command = "RETR ";
    } else if (strcmp(mode, "upload") == 0) {
        command = "STOR ";
    } else {
        fprintf(stderr, "Invalid mode\n");
        exit(1);
    }

    snprintf(buffer, MAX_LINE, "%s%s\r\n", command, filename);
    send(sockfd, buffer, strlen(buffer), 0);

    while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        buffer[n] = '\0';
        fprintf(stdout, "%s", buffer);
    }

    close(sockfd);
    free(buffer);
    return 0;
}