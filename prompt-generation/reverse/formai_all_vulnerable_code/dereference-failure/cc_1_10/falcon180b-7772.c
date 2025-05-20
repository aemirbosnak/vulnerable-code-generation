//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

void die(const char* msg) {
    perror(msg);
    exit(1);
}

int connect_to_host(const char* host, int port) {
    struct addrinfo hints;
    struct addrinfo* result;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, NULL, &hints, &result)!= 0) {
        die("getaddrinfo");
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        die("connect");
    }

    return sockfd;
}

void send_command(int sockfd, const char* cmd) {
    char buffer[MAX_LINE_LENGTH];
    snprintf(buffer, MAX_LINE_LENGTH, "%s\r\n", cmd);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        die("send");
    }
}

char* receive_response(int sockfd) {
    char buffer[MAX_LINE_LENGTH];
    char* response = NULL;
    ssize_t bytes_received;

    bytes_received = recv(sockfd, buffer, MAX_LINE_LENGTH, 0);

    if (bytes_received == 0) {
        die("recv");
    }

    response = malloc(bytes_received + 1);
    if (response == NULL) {
        die("malloc");
    }

    memcpy(response, buffer, bytes_received);
    response[bytes_received] = '\0';

    return response;
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <command>\n", argv[0]);
        return 1;
    }

    const char* host = argv[1];
    int port = atoi(argv[2]);
    const char* cmd = argv[3];

    int sockfd = connect_to_host(host, port);

    send_command(sockfd, cmd);

    char* response = receive_response(sockfd);

    printf("Response: %s\n", response);

    close(sockfd);

    return 0;
}