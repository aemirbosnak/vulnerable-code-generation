//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 4096

int main() {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(errno);
    }

    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(errno);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(errno);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(conn_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                if (bytes_received == 0)
                    printf("Client disconnected\n");
                else
                    perror("recv");

                close(conn_fd);
                break;
            }

            printf("Received: %s", buffer);

            send(conn_fd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}