//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void handle_client(int client_fd) {
    char buffer[1024];
    while (1) {
        bzero(buffer, 1024);
        int n = read(client_fd, buffer, 1024);
        if (n == -1) {
            perror("Error reading from client");
            close(client_fd);
            return;
        }
        if (n == 0) {
            close(client_fd);
            return;
        }
        for (int i = 0; i < n; i++) {
            printf("%c", buffer[i]);
        }
        printf("\n");
        for (int i = 0; i < n; i++) {
            send(client_fd, &buffer[i], 1, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s port\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding to socket");
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 5) == -1) {
        perror("Error listening on socket");
        close(server_fd);
        return 1;
    }

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Error accepting connection");
            continue;
        }
        printf("New client connected\n");
        if (fork() == 0) {
            handle_client(client_fd);
            close(client_fd);
            exit(0);
        }
    }

    return 0;
}