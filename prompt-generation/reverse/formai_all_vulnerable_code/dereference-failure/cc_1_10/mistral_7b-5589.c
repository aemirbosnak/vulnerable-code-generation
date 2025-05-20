//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUF_SIZE 4096

typedef struct {
    int socket_desc;
    struct sockaddr_in server;
    char recv_buf[MAX_BUF_SIZE];
} Connection;

Connection *init_connection(const char *host, int port) {
    Connection *conn = (Connection *) malloc(sizeof(Connection));
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        free(conn);
        return NULL;
    }

    conn->server.sin_family = AF_INET;
    conn->server.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &conn->server.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        free(conn);
        close(sock);
        return NULL;
    }

    if (connect(sock, (struct sockaddr *) &conn->server, sizeof(conn->server)) < 0) {
        perror("Connection failed");
        free(conn);
        close(sock);
        return NULL;
    }

    conn->socket_desc = sock;
    return conn;
}

void send_request(Connection *conn, const char *request) {
    int len = strlen(request);
    send(conn->socket_desc, request, len, 0);
    printf("Request sent:\n%s\n", request);
}

int receive_response(Connection *conn, char *response, int len) {
    int bytes_received = 0;

    while (bytes_received < len) {
        int bytes = recv(conn->socket_desc, response + bytes_received, len - bytes_received, 0);

        if (bytes <= 0) {
            perror("Error reading from socket");
            close(conn->socket_desc);
            free(conn);
            return -1;
        }

        bytes_received += bytes;
    }

    printf("Response received:\n%s\n", response);
    return bytes_received;
}

void close_connection(Connection *conn) {
    close(conn->socket_desc);
    free(conn);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    Connection *conn = init_connection(argv[1], atoi(argv[2]));

    if (conn == NULL) {
        return 1;
    }

    char request[MAX_BUF_SIZE];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\nUser-Agent: MyHTTPClient/1.0\r\nAccept: */*\r\n\r\n", argv[1]);

    send_request(conn, request);
    char response[MAX_BUF_SIZE];
    int bytes_received = receive_response(conn, response, MAX_BUF_SIZE);

    close_connection(conn);

    return bytes_received > 0 ? 0 : 1;
}