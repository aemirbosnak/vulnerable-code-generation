//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %s\n", argv[1]);

    while (1) {
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_socket[i] == 0) {
                continue;
            }

            char buffer[BUFFER_SIZE];
            memset(buffer, 0, BUFFER_SIZE);

            int bytes_received = recv(client_socket[i], buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                close(client_socket[i]);
                client_socket[i] = 0;
            } else {
                printf("Client %d sent message: %s\n", i, buffer);
            }
        }
    }

    return 0;
}