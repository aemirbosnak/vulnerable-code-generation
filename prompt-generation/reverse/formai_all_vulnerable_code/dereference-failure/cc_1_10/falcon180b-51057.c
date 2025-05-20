//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char *error) {
    perror(error);
    exit(EXIT_FAILURE);
}

int main() {
    struct addrinfo hints, *res;
    int sockfd;
    char buffer[BUFFER_SIZE];
    const char *server = "pop.example.com";
    const char *username = "your_username";
    const char *password = "your_password";

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server, "110", &hints, &res)!= 0) {
        die("getaddrinfo");
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        die("connect");
    }

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        die("recv");
    }

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        die("recv");
    }

    printf("Successfully logged in!\n");

    while (1) {
        printf("Enter command (LIST, RETR, DELE, QUIT): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            die("recv");
        }

        printf("%s\n", buffer);

        if (strcmp(buffer, ".") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}