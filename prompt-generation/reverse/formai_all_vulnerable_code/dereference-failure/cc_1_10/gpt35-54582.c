//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>
#include <inttypes.h>

#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

typedef struct {
    uint32_t network_address;
    uint32_t subnet_mask;
    uint32_t broadcast_address;
    uint32_t first_host_address;
    uint32_t last_host_address;
    uint32_t total_hosts;
} subnet_info_t;

typedef struct {
    int client_fd;
    struct sockaddr_in client_address;
} client_info_t;

static subnet_info_t subnet_info;
static char recv_buffer[BUFFER_SIZE];
static char send_buffer[BUFFER_SIZE];
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int server_socket = -1;
static int client_socket = -1;
static bool is_server_running = true;
static pthread_t client_thread;

void print_subnet_info() {
    char first_host_address_str[INET_ADDRSTRLEN];
    char last_host_address_str[INET_ADDRSTRLEN];
    char broadcast_address_str[INET_ADDRSTRLEN];
    char network_address_str[INET_ADDRSTRLEN];
    char subnet_mask_str[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &subnet_info.first_host_address, first_host_address_str,
            sizeof(first_host_address_str));
    inet_ntop(AF_INET, &subnet_info.last_host_address, last_host_address_str,
            sizeof(last_host_address_str));
    inet_ntop(AF_INET, &subnet_info.broadcast_address, broadcast_address_str,
            sizeof(broadcast_address_str));
    inet_ntop(AF_INET, &subnet_info.network_address, network_address_str,
            sizeof(network_address_str));
    inet_ntop(AF_INET, &subnet_info.subnet_mask, subnet_mask_str,
            sizeof(subnet_mask_str));

    printf("Network Address: %s\nSubnet Mask: %s\nBroadcast Address: %s\n"
           "First Host Address: %s\nLast Host Address: %s\nTotal Hosts: %u\n",
           network_address_str, subnet_mask_str, broadcast_address_str,
           first_host_address_str, last_host_address_str, subnet_info.total_hosts);
}

void calculate_subnet_info(uint32_t ip_address, uint32_t subnet_mask) {
    subnet_info.network_address = (ip_address & subnet_mask);
    subnet_info.subnet_mask = subnet_mask;
    subnet_info.broadcast_address = (subnet_info.network_address | (~subnet_info.subnet_mask));

    subnet_info.first_host_address = (subnet_info.network_address + 1);
    subnet_info.last_host_address = (subnet_info.broadcast_address - 1);

    // Calculate the number of possible hosts on the subnet
    subnet_info.total_hosts = (~subnet_mask) - 1;

    print_subnet_info();
}

void handle_client_request(int client_fd, struct sockaddr_in client_address) {
    // Receive the IP and subnet mask from the client
    ssize_t bytes_received = recv(client_fd, recv_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive data from client");
        return;
    }

    // Parse the received data
    char *ip_str = strtok(recv_buffer, "/");
    char *subnet_mask_str = strtok(NULL, "/");
    if (ip_str == NULL || subnet_mask_str == NULL) {
        printf("Invalid data received from client: %s\n", recv_buffer);
        return;
    }

    uint32_t ip_address;
    if (inet_pton(AF_INET, ip_str, &ip_address) == -1) {
        perror("Failed to convert IP address");
        return;
    }

    uint32_t subnet_mask;
    if (inet_pton(AF_INET, subnet_mask_str, &subnet_mask) == -1) {
        perror("Failed to convert subnet mask");
        return;
    }

    calculate_subnet_info(ip_address, subnet_mask);

    // Send the subnet info back to the client
    memset(send_buffer, 0, sizeof(send_buffer));
    snprintf(send_buffer, BUFFER_SIZE, "Network Address: %u\nSubnet Mask: %u\n"
             "Broadcast Address: %u\nFirst Host Address: %u\n"
             "Last Host Address: %u\nTotal Hosts: %u\n", subnet_info.network_address,
             subnet_info.subnet_mask, subnet_info.broadcast_address,
             subnet_info.first_host_address, subnet_info.last_host_address,
             subnet_info.total_hosts);
    ssize_t bytes_sent = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (bytes_sent == -1) {
        perror("Failed to send data to client");
        return;
    }

    printf("Sent data to client:\n%s\n", send_buffer);

    // Flush the standard output stream
    fflush(stdout);
}

void *handle_client(void *arg) {
    client_info_t *client_info = (client_info_t *)arg;

    handle_client_request(client_info->client_fd, client_info->client_address);

    // Close the client socket
    close(client_info->client_fd);

    // Free the dynamically allocated memory
    free(client_info);

    return NULL;
}

void run_server(const char *bind_address, int port) {
    // Create a new server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set the SO_REUSEADDR socket option to allow the socket to be restarted
    int value = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)) == -1) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the given address and port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }

    // Set the socket to listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on %s:%d\n",
           bind_address == NULL ? "0.0.0.0" : bind_address, port);

    // Handle incoming client connections
    while (is_server_running) {
        // Accept the next connection request from the queue
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);

        if (client_socket == -1) {
            if (errno == EINTR || errno == EAGAIN) {
                // A signal was received or the socket is non-blocking, try again
                continue;
            }

            perror("Failed to accept incoming connection");
            break;
        }

        // Disable blocking on the client socket
        if (fcntl(client_socket, F_SETFL, O_NONBLOCK) == -1) {
            perror("Failed to set client socket to non-blocking");
            break;
        }

        printf("Accepted incoming connection from %s:%d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create a new thread to handle the client request
        client_info_t *client_info = (client_info_t *)malloc(sizeof(client_info_t));
        client_info->client_fd = client_socket;
        client_info->client_address = client_address;

        pthread_create(&client_thread, NULL, handle_client, (void *)client_info);
    }

    // Clean up
    close(server_socket);
    server_socket = -1;
}

void stop_server() {
    // Stop accepting new client connections
    is_server_running = false;

    // Close the main socket to interrupt any pending accept() calls
    if (server_socket != -1) {
        close(server_socket);
    }

    // Close the client socket to interrupt any pending send() or recv() calls
    if (client_socket != -1) {
        close(client_socket);
    }

    // Wait for the client thread to exit
    pthread_join(client_thread, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *bind_address = NULL;
    int port = atoi(argv[1]);

    run_server(bind_address, port);

    stop_server();

    return 0;
}