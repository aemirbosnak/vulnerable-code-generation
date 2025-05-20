//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
} client_info_t;

void *handle_client(void *arg);
void execute_command(int client_socket, char *command);
void send_response(int client_socket, const char *response);
void receive_command(int client_socket, char *command);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    pthread_t thread_id;
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("FTP Server is running on port %d\n", SERVER_PORT);

    // Accept clients in a loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

        client_info_t *client_info = malloc(sizeof(client_info_t));
        client_info->client_socket = client_socket;
        client_info->client_address = client_address;

        // Create a thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, client_info) != 0) {
            perror("Could not create thread");
            free(client_info);
            close(client_socket);
        } else {
            pthread_detach(thread_id); // Automatically free the thread resources
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    client_info_t *client_info = (client_info_t *)arg;
    int client_socket = client_info->client_socket;
    char command[BUFFER_SIZE];

    send_response(client_socket, "220FTP Server Ready.\r\n");

    // Handle client commands
    while (1) {
        receive_command(client_socket, command);
        if (strcmp(command, "QUIT") == 0) {
            send_response(client_socket, "221 Bye.\r\n");
            break;
        }
        execute_command(client_socket, command);
    }

    close(client_socket);
    free(client_info);
    printf("Client disconnected.\n");
    return NULL;
}

void execute_command(int client_socket, char *command) {
    // Simple command execution (for demonstration)
    if (strncmp(command, "USER", 4) == 0) {
        send_response(client_socket, "331 User name okay, need password.\r\n");
    } else if (strncmp(command, "PASS", 4) == 0) {
        send_response(client_socket, "230 User logged in, proceed.\r\n");
    } else if (strcmp(command, "PWD") == 0) {
        send_response(client_socket, "257 \"/\" is the current directory.\r\n");
    } else {
        send_response(client_socket, "500 Unknown command.\r\n");
    }
}

void send_response(int client_socket, const char *response) {
    send(client_socket, response, strlen(response), 0);
}

void receive_command(int client_socket, char *command) {
    ssize_t bytes_received = recv(client_socket, command, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        command[bytes_received] = '\0'; // Null-terminate the string
        // Remove newline characters
        command[strcspn(command, "\r\n")] = 0;
    }
}