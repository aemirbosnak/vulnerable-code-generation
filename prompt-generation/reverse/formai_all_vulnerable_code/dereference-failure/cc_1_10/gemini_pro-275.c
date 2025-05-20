//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define MAX_LIGHTS 100
#define BUFFER_SIZE 1024

struct light {
    int id;
    char name[32];
    int state;
};

struct light lights[MAX_LIGHTS];
int num_lights = 0;

struct client {
    int socket;
    struct sockaddr_in address;
    int id;
};

struct client clients[MAX_CONNECTIONS];
int num_clients = 0;

pthread_mutex_t lock;

void send_lights(int socket) {
    char buffer[BUFFER_SIZE];
    int i;

    pthread_mutex_lock(&lock);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "lights %d", num_lights);
    send(socket, buffer, strlen(buffer), 0);

    for (i = 0; i < num_lights; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "%d %s %d", lights[i].id, lights[i].name, lights[i].state);
        send(socket, buffer, strlen(buffer), 0);
    }

    pthread_mutex_unlock(&lock);
}

void handle_client(void *arg) {
    struct client *client = (struct client *)arg;
    char buffer[BUFFER_SIZE];
    int i;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        recv(client->socket, buffer, BUFFER_SIZE, 0);

        if (strcmp(buffer, "get lights") == 0) {
            send_lights(client->socket);
        } else if (strncmp(buffer, "set light ", 10) == 0) {
            int id, state;
            char name[32];

            sscanf(buffer, "set light %d %s %d", &id, name, &state);

            pthread_mutex_lock(&lock);

            for (i = 0; i < num_lights; i++) {
                if (lights[i].id == id) {
                    strcpy(lights[i].name, name);
                    lights[i].state = state;
                    break;
                }
            }

            if (i == num_lights) {
                struct light light;

                light.id = id;
                strcpy(light.name, name);
                light.state = state;
                lights[num_lights++] = light;
            }

            pthread_mutex_unlock(&lock);

            send_lights(client->socket);
        } else if (strcmp(buffer, "quit") == 0) {
            close(client->socket);
            pthread_mutex_lock(&lock);
            num_clients--;
            pthread_mutex_unlock(&lock);
            break;
        }
    }
}

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    pthread_t tid;

    pthread_mutex_init(&lock, NULL);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        pthread_mutex_lock(&lock);

        if (num_clients < MAX_CONNECTIONS) {
            struct client client;
            client.socket = client_socket;
            client.address = client_address;
            client.id = num_clients++;
            clients[num_clients - 1] = client;
            pthread_create(&tid, NULL, handle_client, (void *)&client);
        } else {
            close(client_socket);
        }

        pthread_mutex_unlock(&lock);
    }

    close(server_socket);

    return 0;
}