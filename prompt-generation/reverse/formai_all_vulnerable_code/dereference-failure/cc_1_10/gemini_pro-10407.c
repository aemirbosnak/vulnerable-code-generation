//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

typedef struct {
    char *name;
    int state; // 0 = off, 1 = on
} device_t;

device_t devices[] = {
    {"light", 0},
    {"fan", 0},
    {"ac", 0}
};

int num_devices = sizeof(devices) / sizeof(devices[0]);

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;

    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));

        // Receive data from client
        int len = recv(client->sockfd, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            perror("recv");
            break;
        }

        // Parse command
        char *command = strtok(buffer, " ");
        if (command == NULL) {
            continue;
        }

        // Execute command
        if (strcmp(command, "list") == 0) {
            // List all devices
            for (int i = 0; i < num_devices; i++) {
                send(client->sockfd, devices[i].name, strlen(devices[i].name), 0);
                send(client->sockfd, ":", 1, 0);
                send(client->sockfd, devices[i].state ? "on" : "off", 3, 0);
                send(client->sockfd, "\n", 1, 0);
            }
        } else if (strcmp(command, "toggle") == 0) {
            // Toggle a device
            char *device_name = strtok(NULL, " ");
            if (device_name == NULL) {
                continue;
            }

            int device_index = -1;
            for (int i = 0; i < num_devices; i++) {
                if (strcmp(device_name, devices[i].name) == 0) {
                    device_index = i;
                    break;
                }
            }

            if (device_index == -1) {
                send(client->sockfd, "Invalid device name\n", 21, 0);
                continue;
            }

            devices[device_index].state = !devices[device_index].state;
            send(client->sockfd, "OK\n", 3, 0);
        } else {
            // Invalid command
            send(client->sockfd, "Invalid command\n", 16, 0);
        }
    }

    // Close client socket
    close(client->sockfd);
    free(client);

    return NULL;
}

int main() {
    // Create server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Accept incoming connections in a loop
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create client thread
        pthread_t thread;
        client_t *client = malloc(sizeof(client_t));
        client->sockfd = client_sockfd;
        client->addr = client_addr;
        if (pthread_create(&thread, NULL, handle_client, client) != 0) {
            perror("pthread_create");
            close(client_sockfd);
            free(client);
            continue;
        }

        // Detach client thread
        pthread_detach(thread);
    }

    // Close server socket
    close(sockfd);

    return EXIT_SUCCESS;
}