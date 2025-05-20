//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_DEVICES 10
#define MAX_BUF_SIZE 1024

typedef struct client {
    int sock;
    struct sockaddr_in addr;
} client_t;

typedef struct device {
    char name[32];
    int type; // 0 - light, 1 - thermostat, 2 - door lock
    int state; // 0 - off, 1 - on, 2 - locked, 3 - unlocked
} device_t;

client_t clients[MAX_CLIENTS];
device_t devices[MAX_DEVICES];
int num_clients = 0;
int num_devices = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t devices_mutex = PTHREAD_MUTEX_INITIALIZER;

void send_message(client_t *client, char *message) {
    int n = send(client->sock, message, strlen(message), 0);
    if (n < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
}

void* client_handler(void *arg) {
    client_t *client = (client_t *)arg;

    char buf[MAX_BUF_SIZE];
    while (1) {
        int n = recv(client->sock, buf, sizeof(buf), 0);
        if (n <= 0) {
            break;
        }

        buf[n] = '\0';
        printf("Received message from client: %s\n", buf);

        // Parse the message
        char *command = strtok(buf, " ");
        char *args = strtok(NULL, " ");

        if (strcmp(command, "list_devices") == 0) {
            // List all devices
            char message[MAX_BUF_SIZE];
            pthread_mutex_lock(&devices_mutex);
            for (int i = 0; i < num_devices; i++) {
                sprintf(message, "%s (%d): %s\n", devices[i].name, devices[i].type, devices[i].state == 0 ? "Off" : "On");
                send_message(client, message);
            }
            pthread_mutex_unlock(&devices_mutex);
        } else if (strcmp(command, "get_device_state") == 0) {
            // Get the state of a device
            char message[MAX_BUF_SIZE];
            int device_id = atoi(args);
            if (device_id < 0 || device_id >= num_devices) {
                send_message(client, "Invalid device ID");
                continue;
            }

            pthread_mutex_lock(&devices_mutex);
            sprintf(message, "%s: %s\n", devices[device_id].name, devices[device_id].state == 0 ? "Off" : "On");
            pthread_mutex_unlock(&devices_mutex);
            send_message(client, message);
        } else if (strcmp(command, "set_device_state") == 0) {
            // Set the state of a device
            char message[MAX_BUF_SIZE];
            int device_id = atoi(args);
            int state = atoi(strtok(NULL, " "));
            if (device_id < 0 || device_id >= num_devices || state < 0 || state > 1) {
                send_message(client, "Invalid device ID or state");
                continue;
            }

            pthread_mutex_lock(&devices_mutex);
            devices[device_id].state = state;
            pthread_mutex_unlock(&devices_mutex);
            send_message(client, "Device state updated");
        } else {
            send_message(client, "Invalid command");
        }
    }

    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sock == client->sock) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(client->sock);
    free(client);

    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full", strlen("Server is full"), 0);
            close(client_sock);
            pthread_mutex_unlock(&clients_mutex);
            continue;
        }

        client_t *client = malloc(sizeof(client_t));
        client->sock = client_sock;
        client->addr = client_addr;
        clients[num_clients++] = *client;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t thread;
        if (pthread_create(&thread, NULL, client_handler, (void *)client) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    close(server_sock);
    return 0;
}