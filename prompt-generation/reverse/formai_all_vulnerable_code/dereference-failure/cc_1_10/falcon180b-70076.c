//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define MAX_BACKLOG 10
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        die("socket");
    }

    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        die("setsockopt");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("bind");
    }

    if (listen(listen_fd, MAX_BACKLOG) == -1) {
        die("listen");
    }

    printf("Server listening on port %s\n", argv[1]);

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            if (errno == ECONNABORTED) {
                printf("Connection aborted\n");
            } else if (errno!= EINTR) {
                die("accept");
            }
        } else {
            char buffer[BUFFER_SIZE];
            int bytes_received = 0;

            while ((bytes_received = recv(conn_fd, buffer, BUFFER_SIZE, 0)) > 0) {
                buffer[bytes_received] = '\0';
                printf("Received: %s\n", buffer);
            }

            if (bytes_received == 0) {
                printf("Client disconnected\n");
            } else {
                printf("Connection closed by client\n");
            }

            close(conn_fd);
        }
    }

    return 0;
}