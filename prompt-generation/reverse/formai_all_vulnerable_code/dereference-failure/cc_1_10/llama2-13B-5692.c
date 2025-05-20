//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_CONNS 1024
#define PORT 8080

struct conn {
    int sock;
    struct sockaddr_in client_addr;
    char client_ip[16];
    int len;
};

int main() {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, MAX_CONNS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        struct conn *conn = malloc(sizeof(struct conn));
        conn->sock = accept(listen_sock, NULL, NULL);
        if (conn->sock < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        socklen_t client_len = sizeof(struct sockaddr_in);
        getpeername(conn->sock, (struct sockaddr *)&conn->client_addr, &client_len);
        inet_ntop(AF_INET, &conn->client_addr.sin_addr, conn->client_ip, sizeof(conn->client_ip));

        printf("Connection from %s:%d\n", conn->client_ip, ntohs(conn->client_addr.sin_port));

        // Do something with the connection...

        free(conn);
    }

    close(listen_sock);
    return 0;
}