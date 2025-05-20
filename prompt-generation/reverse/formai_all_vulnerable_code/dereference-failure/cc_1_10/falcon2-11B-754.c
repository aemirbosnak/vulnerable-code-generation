//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_SIZE 1024

void print_usage() {
    printf("Usage:./popprogram <hostname> <port> <username> <password>\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        print_usage();
    }

    char hostname[MAX_SIZE];
    char port[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    char response[MAX_SIZE];

    strcpy(hostname, argv[1]);
    strcpy(port, argv[2]);
    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    int sockfd, numBytes;
    struct sockaddr_in serveraddr;
    int opt = 1;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(port));

    if (inet_aton(hostname, &serveraddr.sin_addr) < 0) {
        perror("inet_aton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(int)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    char cmd[MAX_SIZE] = "USER ";
    strcat(cmd, username);
    strcat(cmd, " ");
    strcat(cmd, password);

    if (write(sockfd, cmd, strlen(cmd)) < 0) {
        perror("write");
        exit(1);
    }

    if (read(sockfd, response, MAX_SIZE) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", response);

    close(sockfd);

    return 0;
}