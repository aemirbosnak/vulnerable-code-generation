//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#define _CRT_SECURE_NO_WARNINGS
#define MAX_BUFFER_SIZE 4096
#define URL_LENGTH 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>

typedef struct {
    int sock;
    struct sockaddr_in server;
} connection;

void die(char *msg) {
    perror(msg);
    exit(1);
}

void print_usage() {
    printf("Usage: %s <URL>\n", __FILE__);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    connection c;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) die("socket");

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        herror("gethostbyname");
        close(sock);
        die("Invalid URL");
    }

    c.server.sin_family = AF_INET;
    c.server.sin_port = htons(80);
    c.server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&c.server, sizeof(c.server)) < 0) {
        perror("connect");
        close(sock);
        die("Failed to connect to server");
    }

    char request[URL_LENGTH + MAX_BUFFER_SIZE];
    snprintf(request, URL_LENGTH + MAX_BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: HTTP Client\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n", argv[1], argv[1]);

    send(sock, request, strlen(request), 0);

    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(sock, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, bytes_received, 1, stdout);
    }

    close(sock);

    printf("\nHTTP Client: %s\n", argv[1]);
}