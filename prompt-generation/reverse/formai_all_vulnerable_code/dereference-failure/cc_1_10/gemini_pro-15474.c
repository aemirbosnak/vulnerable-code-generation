//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 100
#define MAX_MESSAGE_LENGTH 1024

struct client {
    int socket;
    char name[MAX_MESSAGE_LENGTH];
    struct client *next;
};

struct client *clients = NULL;

void add_client(int socket, char *name) {
    struct client *new_client = malloc(sizeof(struct client));
    new_client->socket = socket;
    strcpy(new_client->name, name);
    new_client->next = clients;
    clients = new_client;
}

void remove_client(int socket) {
    struct client *prev = NULL;
    struct client *curr = clients;
    while (curr != NULL) {
        if (curr->socket == socket) {
            if (prev == NULL) {
                clients = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void broadcast_message(char *message, int sender_socket) {
    struct client *curr = clients;
    while (curr != NULL) {
        if (curr->socket != sender_socket) {
            send(curr->socket, message, strlen(message), 0);
        }
        curr = curr->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        close(server_socket);
        return 1;
    }

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);

    while (1) {
        fd_set temp_fds = read_fds;
        if (select(FD_SETSIZE, &temp_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            break;
        }

        if (FD_ISSET(server_socket, &temp_fds)) {
            int client_socket = accept(server_socket, NULL, NULL);
            if (client_socket == -1) {
                perror("accept");
            } else {
                char name[MAX_MESSAGE_LENGTH];
                if (recv(client_socket, name, sizeof(name), 0) == -1) {
                    perror("recv");
                    close(client_socket);
                } else {
                    add_client(client_socket, name);
                    printf("New client connected with name %s\n", name);
                    broadcast_message(name, client_socket);
                }
            }
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &temp_fds) && i != server_socket) {
                char message[MAX_MESSAGE_LENGTH];
                if (recv(i, message, sizeof(message), 0) == -1) {
                    perror("recv");
                    remove_client(i);
                } else {
                    if (strcmp(message, "/quit") == 0) {
                        remove_client(i);
                    } else {
                        broadcast_message(message, i);
                    }
                }
            }
        }
    }

    close(server_socket);
    return 0;
}