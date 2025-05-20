//FormAI DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10

void *client_handler(void *);
int read_from_client(int, char *);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t threads[MAX_CLIENTS];
    int thread_count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: socket creation failed.");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if ((bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr))) < 0) {
        perror("Error: socket binding failed.");
        exit(1);
    }

    if ((listen(server_socket, MAX_CLIENTS)) < 0) {
        perror("Error: listening failed.");
        exit(1);
    }

    printf("Chat server is listening on port %d...\n", port);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len)) < 0) {
            perror("Error: client connection failed.");
            exit(1);
        }

        if (thread_count < MAX_CLIENTS) {
            pthread_create(&threads[thread_count], NULL, client_handler, (void *) &client_socket);
            thread_count++;
            printf("Client connected. %d clients currently connected.\n", thread_count);
        } else {
            printf("Max number of clients reached. Rejecting client connection.\n");
            close(client_socket);
        }
    }

    return 0;
}

void *client_handler(void *client_socket_ptr) {
    int client_socket = *(int *) client_socket_ptr;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    while (read_from_client(client_socket, buffer) > 0) {
        printf("[%d]", client_socket);
        printf(" %s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    close(client_socket);
}

int read_from_client(int client_socket, char *buffer) {
    int n = read(client_socket, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error: reading from client failed.");
        exit(1);
    }
    return n;
}