//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
} client_t;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("socket creation error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("bind error");
    }

    if (listen(sockfd, 5) < 0) {
        die("listen error");
    }

    return sockfd;
}

int main(int argc, char **argv) {
    client_t client;
    int sockfd;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    char request[MAX_BUFFER_SIZE];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (!server) {
        herror("gethostbyname error");
        exit(EXIT_FAILURE);
    }

    sockfd = create_socket(atoi(argv[2]));

    client.server_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);
    client.server_addr.sin_family = AF_INET;
    client.server_addr.sin_port = htons(atoi(argv[2]));

    snprintf(request, sizeof(request),
             "GET /HTTP_REQUEST_HERE HTTP/1.1\r\n"
             "Host: %s:%s\r\n"
             "User-Agent: Ada-Lovelace-HTTP-Client\r\n"
             "Accept: */*\r\n"
             "Connection: keep-alive\r\n\r\n", argv[1], argv[2]);

    connect(client.sockfd, (struct sockaddr *)&client.server_addr, sizeof(client.server_addr));

    write(client.sockfd, request, strlen(request));

    while ((n = recv(client.sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        printf("%s", buffer);
    }

    close(client.sockfd);

    return EXIT_SUCCESS;
}