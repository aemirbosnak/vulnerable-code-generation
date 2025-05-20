//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
} connection_t;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

connection_t *create_connection(const char *host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct hostent *he = gethostbyname(host);
    if (!he) die("gethostbyname");

    connection_t *conn = malloc(sizeof(connection_t));
    if (!conn) die("malloc");

    memset(&(conn->addr), 0, sizeof(struct sockaddr_in));
    conn->addr.sin_family = AF_INET;
    conn->addr.sin_port = htons(port);
    memcpy(&(conn->addr.sin_addr), he->h_addr, he->h_length);

    if (connect(sockfd, (struct sockaddr *)&(conn->addr), sizeof(struct sockaddr_in)) < 0)
        die("connect");

    conn->fd = sockfd;
    return conn;
}

void send_request(connection_t *conn, const char *request) {
    send(conn->fd, request, strlen(request), 0);
}

void read_response(connection_t *conn, char *buffer, int size) {
    ssize_t bytes_received = recv(conn->fd, buffer, size, MSG_WAITALL);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    } else if (bytes_received < 0) {
        perror("recv");
    }
}

int main() {
    const char *host = "www.google.com";
    int port = 80;

    connection_t *conn = create_connection(host, port);

    char request[BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: MySimpleClient/1.0\r\nAccept: */*\r\n\r\n";
    snprintf(request + strlen(request), BUFFER_SIZE - strlen(request), "%s:", host);

    send_request(conn, request);

    char buffer[BUFFER_SIZE];
    read_response(conn, buffer, BUFFER_SIZE);

    close(conn->fd);
    free(conn);

    return 0;
}