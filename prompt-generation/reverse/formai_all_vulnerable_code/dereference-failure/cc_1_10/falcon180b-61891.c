//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    char *username = "your_username";
    char *password = "your_password";
    char *command = "STAT\r\n";

    if (argc!= 3) {
        printf("Usage:./program <server_address> <port>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server %s on port %d\n", argv[1], atoi(argv[2]));

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (strncmp(buffer, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (strncmp(buffer, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);

    printf("Server response: %s", buffer);

    close(sockfd);

    return 0;
}