//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connect_to_server(const char *server, int port, int *sockfd) {
    struct hostent *host;
    struct sockaddr_in server_addr;

    if ((host = gethostbyname(server)) == NULL) {
        handle_error("gethostbyname");
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        handle_error("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        handle_error("send");
    }
}

void receive_response(int sockfd, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0) {
        handle_error("recv");
    }
    printf("Server: %s", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <POP3 Server> <Username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *username = argv[2];

    connect_to_server(server, PORT, &sockfd);
    receive_response(sockfd, buffer);

    char command[BUFFER_SIZE];

    snprintf(command, BUFFER_SIZE, "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd, buffer);

    snprintf(command, BUFFER_SIZE, "PASS your_password_here\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, buffer);

    snprintf(command, BUFFER_SIZE, "List\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, buffer);

    snprintf(command, BUFFER_SIZE, "STAT\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, buffer);

    snprintf(command, BUFFER_SIZE, "RETR 1\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, buffer);

    snprintf(command, BUFFER_SIZE, "QUIT\r\n");
    send_command(sockfd, command);
    receive_response(sockfd, buffer);

    close(sockfd);
    return EXIT_SUCCESS;
}