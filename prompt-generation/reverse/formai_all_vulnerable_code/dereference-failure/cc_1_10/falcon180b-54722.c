//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *metadata;
    int metadata_length;
} Metadata;

void *receive_metadata(void *socket_fd) {
    int client_socket = *(int *) socket_fd;
    char buffer[BUFFER_SIZE];
    Metadata metadata;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        metadata.metadata = strdup(buffer);
        metadata.metadata_length = strlen(metadata.metadata);

        // Do something with the metadata here

        free(metadata.metadata);
    }

    close(client_socket);
    pthread_exit(0);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, receive_metadata, &client_socket);
    }

    close(server_socket);
    return 0;
}