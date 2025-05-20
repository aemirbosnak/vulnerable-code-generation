//MISTRAL-7B DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1143
#define BUFFER_SIZE 1024

void imap_login(int connfd, char *username, char *password) {
    char cmd[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(cmd, BUFFER_SIZE, "LOGIN %s %s\r\n", username, password);
    write(connfd, cmd, strlen(cmd));

    ssize_t n = read(connfd, response, BUFFER_SIZE - 1);
    response[n] = '\0';

    if (strstr(response, "OK") == NULL) {
        perror("Failed to login");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "localhost:143", &serv_addr.sin_addr) <= 0) {
        perror("Could not convert IPv4 address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    char *username = malloc(strlen("user") + strlen("@example.com") + 1);
    strcpy(username, "user");
    strcat(username, "@example.com");

    char *password = malloc(strlen("password") + 1);
    strcpy(password, "password");

    imap_login(connfd, username, password);

    free(username);
    free(password);

    close(sockfd);

    return EXIT_SUCCESS;
}