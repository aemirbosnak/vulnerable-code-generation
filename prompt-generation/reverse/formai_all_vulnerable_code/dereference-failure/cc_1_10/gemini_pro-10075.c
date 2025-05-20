//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Maximum number of devices
#define MAX_DEVICES 10

// Device types
typedef enum {
    TYPE_LIGHT,
    TYPE_SENSOR,
    TYPE_OTHER
} device_type_t;

// Device states
typedef enum {
    STATE_OFF,
    STATE_ON
} device_state_t;

// Device structure
typedef struct {
    uint32_t id;
    device_type_t type;
    device_state_t state;
    char name[32];
} device_t;

// List of devices
device_t devices[MAX_DEVICES];

// Number of devices
int num_devices = 0;

// Server socket
int server_sock = -1;

// Client sockets
int client_socks[MAX_DEVICES];

// Thread IDs
pthread_t thread_ids[MAX_DEVICES];

// Mutex for accessing the list of devices
pthread_mutex_t devices_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a device to the list of devices
void add_device(device_t *device) {
    pthread_mutex_lock(&devices_mutex);
    devices[num_devices++] = *device;
    pthread_mutex_unlock(&devices_mutex);
}

// Function to get a device by its ID
device_t *get_device_by_id(uint32_t id) {
    pthread_mutex_lock(&devices_mutex);
    for (int i = 0; i < num_devices; i++) {
        if (devices[i].id == id) {
            pthread_mutex_unlock(&devices_mutex);
            return &devices[i];
        }
    }
    pthread_mutex_unlock(&devices_mutex);
    return NULL;
}

// Function to handle a client connection
void *handle_client(void *arg) {
    int client_sock = *(int *)arg;
    free(arg);

    while (true) {
        // Receive a command from the client
        char command[128];
        int n = recv(client_sock, command, sizeof(command), 0);
        if (n <= 0) {
            break;
        }

        // Parse the command
        char *args[3];
        int num_args = sscanf(command, "%s %s %s", args[0], args[1], args[2]);

        // Execute the command
        if (num_args == 3 && strcmp(args[0], "set") == 0) {
            uint32_t id = atoi(args[1]);
            device_state_t state = atoi(args[2]);

            device_t *device = get_device_by_id(id);
            if (device != NULL) {
                device->state = state;

                // Send a response to the client
                char response[128];
                snprintf(response, sizeof(response), "OK");
                send(client_sock, response, strlen(response), 0);
            } else {
                // Send an error response to the client
                char response[128];
                snprintf(response, sizeof(response), "ERROR: Device not found");
                send(client_sock, response, strlen(response), 0);
            }
        } else if (num_args == 2 && strcmp(args[0], "get") == 0) {
            uint32_t id = atoi(args[1]);

            device_t *device = get_device_by_id(id);
            if (device != NULL) {
                // Send a response to the client
                char response[128];
                snprintf(response, sizeof(response), "%d", device->state);
                send(client_sock, response, strlen(response), 0);
            } else {
                // Send an error response to the client
                char response[128];
                snprintf(response, sizeof(response), "ERROR: Device not found");
                send(client_sock, response, strlen(response), 0);
            }
        } else {
            // Send an error response to the client
            char response[128];
            snprintf(response, sizeof(response), "ERROR: Invalid command");
            send(client_sock, response, strlen(response), 0);
        }
    }

    // Close the client socket
    close(client_sock);

    return NULL;
}

int main() {
    // Create a server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the server socket to an address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_DEVICES) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections in a loop
    while (true) {
        // Accept a new connection
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client connection
        int *client_sock_ptr = malloc(sizeof(int));
        *client_sock_ptr = client_sock;
        if (pthread_create(&thread_ids[num_devices], NULL, handle_client, client_sock_ptr) != 0) {
            perror("pthread_create");
            close(client_sock);
            continue;
        }

        // Add the client socket to the list of client sockets
        client_socks[num_devices++] = client_sock;
    }

    // Close the server socket
    close(server_sock);

    return EXIT_SUCCESS;
}