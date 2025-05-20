//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in listen_addr, client_addr;
    int client_addr_size;
    char buffer[BUFFER_SIZE];
    pid_t child_pid;

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &listen_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Listening on port %d...\n", atoi(argv[1]));

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        child_pid = fork();
        if (child_pid == -1) {
            printf("Error forking process: %s\n", strerror(errno));
            close(client_socket);
            continue;
        } else if (child_pid == 0) {
            close(listen_socket);
            dup2(client_socket, 0);
            dup2(client_socket, 1);
            execlp("curl", "curl", "-v", NULL);
            exit(1);
        } else {
            close(client_socket);
        }
    }

    return 0;
}