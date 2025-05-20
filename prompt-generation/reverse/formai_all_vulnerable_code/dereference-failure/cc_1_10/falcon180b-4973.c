//Falcon-180B DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define DELIMITER "\r\n"

struct client {
    int socket;
    char username[20];
    char message[BUFFER_SIZE];
    int message_length;
};

void *handle_client(void *client_socket);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./server <port>\n");
        return -1;
    }

    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        close(server_socket);
        return -1;
    }

    printf("Server started on port %d\n", port);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            close(client_socket);
            continue;
        }

        struct client *new_client = malloc(sizeof(struct client));
        if (new_client == NULL) {
            printf("Error allocating memory for client\n");
            close(client_socket);
            continue;
        }

        new_client->socket = client_socket;
        strcpy(new_client->username, "Unknown");
        new_client->message_length = 0;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) new_client);
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket_ptr) {
    struct client *client = (struct client *) client_socket_ptr;

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (1) {
        bytes_received = recv(client->socket, buffer, BUFFER_SIZE - 1, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client->socket);
            free(client);
            pthread_exit(NULL);
        }

        buffer[bytes_received] = '\0';
        strcat(client->message, buffer);
        client->message_length += bytes_received;

        if (strstr(client->message, DELIMITER)!= NULL) {
            send(client->socket, client->message, client->message_length, 0);
            client->message_length = 0;
        }
    }
}