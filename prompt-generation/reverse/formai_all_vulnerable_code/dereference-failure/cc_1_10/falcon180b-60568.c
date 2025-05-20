//Falcon-180B DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_CONNECTIONS 100
#define MAX_REQUEST_SIZE 4096

struct connection {
    int sock;
    char ip[16];
    int port;
};

void log(const char* message) {
    FILE* logfile = fopen("firewall.log", "a");
    if (logfile) {
        fprintf(logfile, "%s\n", message);
        fclose(logfile);
    }
}

void handle_connection(int sock, struct connection* conn) {
    char request[MAX_REQUEST_SIZE];
    int bytes_received = 0;

    while (1) {
        memset(request, 0, MAX_REQUEST_SIZE);
        bytes_received = recv(sock, request, MAX_REQUEST_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        log(conn->ip);
        log(request);

        send(sock, "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n"), 0);
    }

    close(sock);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CONNECTIONS);

    while (1) {
        struct connection* conn = malloc(sizeof(struct connection));
        memset(conn, 0, sizeof(struct connection));

        int conn_sock = accept(server_sock, NULL, NULL);
        socklen_t addr_len = sizeof(conn->ip);

        getsockname(conn_sock, (struct sockaddr*)&server_addr, &addr_len);
        inet_ntop(AF_INET, &server_addr.sin_addr, conn->ip, sizeof(conn->ip));
        conn->port = ntohs(server_addr.sin_port);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void*)&handle_connection, (void*)conn);
        pthread_detach(thread_id);
    }

    return 0;
}