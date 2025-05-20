//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
} Connection;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);

    Connection conn;
    int status;

    memset(&conn.server_addr, 0, sizeof(conn.server_addr));
    conn.server_addr.sin_family = AF_INET;
    conn.server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &conn.server_addr.sin_addr) <= 0) {
        die("Invalid address/ Address not supported");
    }

    conn.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn.sockfd < 0) {
        die("socket");
    }

    status = connect(conn.sockfd, (struct sockaddr *)&conn.server_addr, sizeof(conn.server_addr));
    if (status < 0) {
        die("connect");
    }

    char request[BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, host);
    strcat(request, ":\0"); // Replace "\0" with the actual port number
    strcat(request, "\r\nUser-Agent: My-HTTP-Client/1.0\r\nAccept: */*\r\n\r\n");

    send(conn.sockfd, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(conn.sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(conn.sockfd);

    return EXIT_SUCCESS;
}