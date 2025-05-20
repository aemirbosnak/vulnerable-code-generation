//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);

        struct timeval timeout = {
            .tv_sec = 1,
            .tv_usec = 0
        };

        select(sock + 1, &read_fds, NULL, NULL, &timeout);

        if (FD_ISSET(sock, &read_fds)) {
            socklen_t client_len = sizeof(struct sockaddr_in);
            int client_sock = accept(sock, (struct sockaddr *)&server_addr, &client_len);
            if (client_sock < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            char buffer[BUFFER_SIZE];
            recv(client_sock, buffer, BUFFER_SIZE, 0);
            printf("Received message from client: %s\n", buffer);

            char *message = "Hello, client!";
            send(client_sock, message, strlen(message), 0);

            close(client_sock);
        }
    }

    close(sock);

    return 0;
}