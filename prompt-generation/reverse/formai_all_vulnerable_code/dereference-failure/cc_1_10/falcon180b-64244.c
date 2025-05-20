//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

// Function prototypes
void die(const char *msg);
int create_socket(int port);
void *thread_func(void *arg);

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int server_socket = create_socket(port);

    if (server_socket == -1) {
        die("Error creating socket");
    }

    printf("Server started on port %d\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);

        if (client_socket == -1) {
            die("Error accepting connection");
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, thread_func, (void *)&client_socket)!= 0) {
            die("Error creating thread");
        }
    }

    return 0;
}

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        die("Error creating socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("Error binding socket");
    }

    if (listen(server_socket, 5) == -1) {
        die("Error listening on socket");
    }

    return server_socket;
}

void *thread_func(void *arg) {
    int client_socket = *((int *)arg);

    char buffer[BUF_SIZE];
    while (1) {
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    return NULL;
}