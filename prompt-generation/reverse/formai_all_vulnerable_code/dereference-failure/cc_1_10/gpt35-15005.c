//FormAI DATASET v1.0 Category: Chat server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

struct client_t {
    pthread_t thread_id;
    int socket_fd;
    struct sockaddr_in address;
    char username[20];
};

struct client_t *clients[10];
int num_clients = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_ptr) {
    struct client_t *client = client_ptr;
    char buffer[1024];
    char message[1048];

    while (1) {
        int read_val = read(client->socket_fd, buffer, 1024);

        if (read_val == 0) {
            printf("%s has disconnected\n", client->username);
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i] == client) {
                    for (int j = i; j < num_clients - 1; j++) {
                        clients[j] = clients[j + 1];
                    }
                    num_clients--;
                    break;
                }
            }
            pthread_mutex_unlock(&mutex);
            close(client->socket_fd);
            pthread_exit(NULL);
        } else if (read_val > 0) {
            buffer[read_val] = '\0';
            sprintf(message, "%s: %s", client->username, buffer);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i] != client) {
                    write(clients[i]->socket_fd, message, strlen(message));
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 3);

    printf("Listening on port %d\n", PORT);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

        printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        char username[20];
        read(new_socket, username, 20);

        printf("%s has joined the chat\n", username);

        struct client_t *client = malloc(sizeof(struct client_t));
        client->socket_fd = new_socket;
        client->address = address;
        strncpy(client->username, username, 20);

        pthread_mutex_lock(&mutex);
        clients[num_clients] = client;
        num_clients++;
        pthread_mutex_unlock(&mutex);

        pthread_create(&client->thread_id, NULL, handle_client, client);
    }

    return 0;
}