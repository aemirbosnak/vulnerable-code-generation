//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    int port;
    char *ip;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port> <message_file>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    char *message_file = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    bcopy(server->h_addr, &server_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(message_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open message file\n");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        n = send(sockfd, line, strlen(line), 0);
        if (n == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);
    close(sockfd);

    return 0;
}