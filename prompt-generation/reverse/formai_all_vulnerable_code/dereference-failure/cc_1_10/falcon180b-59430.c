//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

void *thread(void *arg);

int main(int argc, char *argv[]) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    if (argc!= 2) {
        printf("Usage:./server <port>\n");
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", atoi(argv[1]));

    while (1) {
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_create(&thread_id, NULL, thread, (void *)client_fd);
    }

    return 0;
}

void *thread(void *arg) {
    int client_fd = *((int *)arg);
    char buffer[BUF_SIZE];

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(client_fd, buffer, BUF_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected: %d\n", client_fd);
            close(client_fd);
            pthread_exit(NULL);
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);

        send(client_fd, buffer, strlen(buffer), 0);
    }
}