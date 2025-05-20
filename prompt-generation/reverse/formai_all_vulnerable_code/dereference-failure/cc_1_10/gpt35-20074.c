//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER "imap.example.com"
#define BUF_SIZE 1024

typedef struct {
    char *key;
    char *value;
} header_t;

void display_headers(header_t *headers, int count) {
    printf("Headers:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", headers[i].key, headers[i].value);
    }
}

int main(int argc, char **argv) {
    int sock;
    struct addrinfo hints, *res;
    char buf[BUF_SIZE];
    int bytes_sent, bytes_recv;
    char *username = "username";
    char *password = "password";

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(SERVER, "imap", &hints, &res);
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    connect(sock, res->ai_addr, res->ai_addrlen);

    bytes_recv = recv(sock, buf, sizeof(buf), 0);
    printf("%.*s", bytes_recv, buf);

    bytes_sent = send(sock, "a001 LOGIN username password\r\n", 31, 0);
    printf("Sent: %d bytes\n", bytes_sent);

    bytes_recv = recv(sock, buf, sizeof(buf), 0);
    printf("%.*s", bytes_recv, buf);

    bytes_sent = send(sock, "a002 SELECT INBOX\r\n", 19, 0);
    printf("Sent: %d bytes\n", bytes_sent);

    bytes_recv = recv(sock, buf, sizeof(buf), 0);
    printf("%.*s", bytes_recv, buf);

    bytes_sent = send(sock, "a003 FETCH 1 BODY[HEADER]\r\n", 27, 0);
    printf("Sent: %d bytes\n", bytes_sent);

    bytes_recv = recv(sock, buf, sizeof(buf), 0);
    printf("%.*s", bytes_recv, buf);

    header_t headers[BUF_SIZE];
    int header_count = 0;

    while (bytes_recv > 0) {
        if (strstr(buf, "\r\n\r\n")) {
            char *header = strtok(buf, "\r\n");
            while (header != NULL) {
                if (strstr(header, ":")) {
                    header_t h;
                    h.key = strtok(header, ":");
                    h.value = strtok(NULL, ":");
                    headers[header_count] = h;
                    header_count++;
                }
                header = strtok(NULL, "\r\n");
            }
            break;
        }
        bytes_recv = recv(sock, buf, sizeof(buf), 0);
        printf("%.*s", bytes_recv, buf);
    }

    display_headers(headers, header_count);

    bytes_sent = send(sock, "a004 LOGOUT\r\n", 14, 0);
    printf("Sent: %d bytes\n", bytes_sent);

    bytes_recv = recv(sock, buf, sizeof(buf), 0);
    printf("%.*s", bytes_recv, buf);

    close(sock);

    return 0;
}