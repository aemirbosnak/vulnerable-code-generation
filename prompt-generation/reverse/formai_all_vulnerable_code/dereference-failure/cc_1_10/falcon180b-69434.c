//Falcon-180B DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int opt = 1;
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("socket failed: %s\n", strerror(errno));
        return 1;
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("bind failed: %s\n", strerror(errno));
        return 1;
    }

    if (listen(listen_fd, 5) == -1) {
        printf("listen failed: %s\n", strerror(errno));
        return 1;
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (conn_fd == -1) {
            printf("accept failed: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[BUF_SIZE];
        while (1) {
            memset(buffer, 0, BUF_SIZE);
            int bytes_received = recv(conn_fd, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(conn_fd);
                break;
            }

            printf("Received message: %s\n", buffer);

            send(conn_fd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}