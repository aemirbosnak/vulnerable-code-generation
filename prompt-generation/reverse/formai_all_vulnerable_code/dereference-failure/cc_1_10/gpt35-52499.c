//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLINE 1024

typedef struct {
    int sockfd;
    void (*callback)(char *);
    char buffer[MAXLINE];
} message;

void handle_message(char* resp) {
    printf("Response: %s", resp);
}

void connect_to_server(char* server, char* port, void (*callback)(char *)) {
    int sockfd, nbytes, flags;
    struct addrinfo hints, *res;
    char buffer[MAXLINE];
    message* msg;
    msg = (message *)malloc(sizeof(message));

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        return;
    }

    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        perror("socket");
        return;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        return;
    }

    flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    msg->callback = callback;
    msg->sockfd = sockfd;

    sprintf(msg->buffer, "USER username\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    sprintf(msg->buffer, "PASS password\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    sprintf(msg->buffer, "STAT\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    sprintf(msg->buffer, "QUIT\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    sprintf(msg->buffer, "LIST\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    sprintf(msg->buffer, "RETR 1\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    sprintf(msg->buffer, "DELE 1\r\n");
    send(sockfd, msg->buffer, strlen(msg->buffer), 0);

    close(sockfd);
}

int main(int argc, char** argv) {
    connect_to_server("pop3.server.com", "110", &handle_message);
    return 0;
}