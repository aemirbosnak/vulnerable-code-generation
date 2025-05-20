//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024
#define BUFFER_STEP_SIZE 512

void handle_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int open_socket(char *host, char *port) {
    struct addrinfo hints, *res, *p;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res) < 0)
        handle_error("getaddrinfo");

    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd < 0)
            continue;

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == 0)
            break;

        close(sockfd);
    }

    freeaddrinfo(res);

    if (p == NULL)
        handle_error("open_socket");

    return sockfd;
}

void send_message(int sockfd, char *message) {
    ssize_t bytes_sent = 0;
    size_t message_size = strlen(message);
    while (bytes_sent < message_size) {
        bytes_sent += send(sockfd, message + bytes_sent, message_size - bytes_sent, 0);
    }
}

void receive_message(int sockfd, char **buffer, int *buffer_size) {
    ssize_t bytes_received;
    int total_bytes_received = 0;

    do {
        if (total_bytes_received + BUFFER_STEP_SIZE > *buffer_size) {
            *buffer_size += BUFFER_STEP_SIZE;
            *buffer = realloc(*buffer, *buffer_size);
        }
        bytes_received = recv(sockfd, *buffer + total_bytes_received, BUFFER_STEP_SIZE, 0);
        total_bytes_received += bytes_received;
    } while (bytes_received == BUFFER_STEP_SIZE);

    if (bytes_received < 0) {
        handle_error("receive_message");
    }

    (*buffer)[total_bytes_received] = '\0';
}

int main(int argc, char *argv[]) {
    char *host = "imap.example.com";
    char *port = "993";
    char *username = "example";
    char *password = "password";

    int sockfd = open_socket(host, port);
    char *buffer = malloc(sizeof(char) * MAX_BUFFER_SIZE);
    int buffer_size = MAX_BUFFER_SIZE;

    receive_message(sockfd, &buffer, &buffer_size);
    printf("%s\n", buffer);

    char message[MAX_BUFFER_SIZE];
    sprintf(message, "a001 LOGIN %s %s\r\n", username, password);
    send_message(sockfd, message);
    receive_message(sockfd, &buffer, &buffer_size);
    printf("%s\n", buffer);

    sprintf(message, "a001 SELECT INBOX\r\n");
    send_message(sockfd, message);
    receive_message(sockfd, &buffer, &buffer_size);
    printf("%s\n", buffer);

    close(sockfd);
    free(buffer);
    return 0;
}