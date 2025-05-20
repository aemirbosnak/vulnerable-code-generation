//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_info {
    int socket;
    char name[100];
};

static int server_socket = -1;
static struct client_info clients[MAX_CLIENTS];
static pthread_mutex_t client_lock = PTHREAD_MUTEX_INITIALIZER;

static void broadcast_message(char *message);
static void *client_thread(void *arg);
static void handle_client(int socket);
static void handle_input();

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return 1;
    }

    printf("Server listening on port %d\n", port);

    pthread_t input_thread;
    pthread_create(&input_thread, NULL, (void *(*)(void *))handle_input, NULL);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        pthread_mutex_lock(&client_lock);

        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == -1) {
                clients[i].socket = client_socket;
                strcpy(clients[i].name, inet_ntoa(client_address.sin_addr));
                break;
            }
        }

        pthread_mutex_unlock(&client_lock);

        if (i == MAX_CLIENTS) {
            close(client_socket);
            printf("Too many clients, rejecting connection from %s\n", inet_ntoa(client_address.sin_addr));
            continue;
        }

        pthread_t client_thread;
        pthread_create(&client_thread, NULL, (void *(*)(void *))client_thread, &clients[i]);
    }

    close(server_socket);
    return 0;
}

static void broadcast_message(char *message) {
    pthread_mutex_lock(&client_lock);

    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket != -1) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }

    pthread_mutex_unlock(&client_lock);
}

static void *client_thread(void *arg) {
    struct client_info *client = (struct client_info *)arg;

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
        int bytes_received = recv(client->socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("recv");
            break;
        } else if (bytes_received == 0) {
            printf("%s has left the chat\n", client->name);
            break;
        }

        buffer[bytes_received] = '\0';

        char message[BUFFER_SIZE];
        memset(message, 0, sizeof(message));
        sprintf(message, "%s: %s", client->name, buffer);

        broadcast_message(message);
    }

    pthread_mutex_lock(&client_lock);

    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == client->socket) {
            clients[i].socket = -1;
            break;
        }
    }

    pthread_mutex_unlock(&client_lock);

    close(client->socket);
    return NULL;
}

static void handle_client(int socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
        int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("recv");
            break;
        } else if (bytes_received == 0) {
            printf("Client has left the chat\n");
            break;
        }

        buffer[bytes_received] = '\0';

        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "/quit") == 0) {
            printf("Client has requested to quit\n");
            break;
        }
    }

    close(socket);
}

static void handle_input() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
        fgets(buffer, BUFFER_SIZE - 1, stdin);

        buffer[strlen(buffer) - 1] = '\0';

        if (strcmp(buffer, "/quit") == 0) {
            printf("Quitting server\n");
            break;
        } else {
            char message[BUFFER_SIZE];
            memset(message, 0, sizeof(message));
            sprintf(message, "Server: %s", buffer);

            broadcast_message(message);
        }
    }
}