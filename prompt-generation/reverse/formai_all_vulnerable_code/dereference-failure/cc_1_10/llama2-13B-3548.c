//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 1024
#define PORT_RANGE 1024

struct connection {
    int sock;
    struct sockaddr_in server;
    char buffer[4096];
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server = {
        .sin_family = AF_INET,
        .sin_port = htons(12345),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    while (1) {
        struct connection *conn = malloc(sizeof(struct connection));
        conn->sock = accept(sock, NULL, NULL);
        if (conn->sock < 0) {
            perror("accept failed");
            free(conn);
            continue;
        }

        memset(conn->buffer, 0, sizeof(conn->buffer));

        // Scan the connection
        int port = 0;
        while (port < PORT_RANGE) {
            int bytes_read = recv(conn->sock, conn->buffer, sizeof(conn->buffer), 0);
            if (bytes_read < 0) {
                perror("recv failed");
                break;
            }

            if (strstr(conn->buffer, "Hello, world!") != NULL) {
                port = ntohs(conn->server.sin_port);
                break;
            }

            port++;
        }

        if (port > 0) {
            printf("Connection from %s:%d\n", inet_ntoa(conn->server.sin_addr), port);
        }

        close(conn->sock);
        free(conn);
    }

    close(sock);
    return 0;
}