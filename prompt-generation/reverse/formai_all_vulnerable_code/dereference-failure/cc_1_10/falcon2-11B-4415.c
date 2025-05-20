//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int listen_fd, client_fd;
    int port = atoi(argv[1]);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        exit(1);
    }

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[256];
        while (1) {
            int bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
            if (bytes_read < 0) {
                perror("recv");
                close(client_fd);
                break;
            }

            buffer[bytes_read] = '\0';
            printf("Received message: %s\n", buffer);
            send(client_fd, "Hello, World!", 13, 0);
        }
        close(client_fd);
    }

    close(listen_fd);
    return 0;
}