//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT "80"

struct sockaddr_in server;
int sockfd;
char buffer[BUF_SIZE];

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    char *ip;
    struct hostent *host;
    char *ptr;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 0;
    }

    ip = argv[1];
    host = gethostbyname(ip);

    if (host == NULL) {
        printf("Invalid IP address\n");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("Error creating socket");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Error connecting to server");
    }

    printf("Connected to %s\n", ip);

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        i = recv(sockfd, buffer, BUF_SIZE, 0);

        if (i <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}