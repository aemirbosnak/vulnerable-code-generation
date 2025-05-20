//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFSIZE 256

// Function prototypes
void *server(void *arg);
void *client(void *arg);
int receive_message(int socket);
void send_message(int socket, char *message);
void print_usage(char *progname);
void handle_client(int socket, char *message);

// Global variables
pthread_t server_thread;
pthread_t client_thread;

int main(int argc, char **argv) {
    // Check for correct usage
    if (argc!= 2) {
        print_usage(argv[0]);
        exit(1);
    }

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating server socket: %s\n", strerror(errno));
        exit(1);
    }

    // Create server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    // Create server thread
    pthread_create(&server_thread, NULL, server, NULL);

    // Create client thread
    pthread_create(&client_thread, NULL, client, NULL);

    // Wait for server thread to finish
    pthread_join(server_thread, NULL);

    // Close socket
    close(server_socket);

    return 0;
}

// Server function
void *server(void *arg) {
    int server_socket = (int)arg;

    // Accept incoming connections
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        // Create client thread
        pthread_create(&client_thread, NULL, client, (void *)client_socket);
    }

    return NULL;
}

// Client function
void *client(void *arg) {
    int client_socket = (int)arg;

    // Receive message from server
    char message[BUFSIZE];
    int message_length = receive_message(client_socket);
    if (message_length == -1) {
        fprintf(stderr, "Error receiving message: %s\n", strerror(errno));
        exit(1);
    }

    // Handle message
    handle_client(client_socket, message);

    // Close socket
    close(client_socket);

    return NULL;
}

// Receive message from server
int receive_message(int socket) {
    int bytes_received = 0;
    char message[BUFSIZE];

    // Read message from socket
    while (bytes_received < BUFSIZE) {
        int n = read(socket, &message[bytes_received], BUFSIZE - bytes_received);
        if (n == -1) {
            fprintf(stderr, "Error reading message: %s\n", strerror(errno));
            exit(1);
        }

        bytes_received += n;
    }

    return bytes_received;
}

// Send message to server
void send_message(int socket, char *message) {
    int bytes_sent = 0;
    while (bytes_sent < strlen(message)) {
        int n = write(socket, message + bytes_sent, strlen(message) - bytes_sent);
        if (n == -1) {
            fprintf(stderr, "Error writing message: %s\n", strerror(errno));
            exit(1);
        }

        bytes_sent += n;
    }
}

// Handle client command
void handle_client(int socket, char *message) {
    // Split message into command and arguments
    char *command = strtok(message, " ");
    char *arguments = strtok(NULL, " ");

    // Check for valid command
    if (strcmp(command, "on") == 0) {
        // Turn on light
        send_message(socket, "Light turned on.");
    } else if (strcmp(command, "off") == 0) {
        // Turn off light
        send_message(socket, "Light turned off.");
    } else if (strcmp(command, "up") == 0) {
        // Increase temperature
        send_message(socket, "Temperature increased.");
    } else if (strcmp(command, "down") == 0) {
        // Decrease temperature
        send_message(socket, "Temperature decreased.");
    } else if (strcmp(command, "lock") == 0) {
        // Lock door
        send_message(socket, "Door locked.");
    } else if (strcmp(command, "unlock") == 0) {
        // Unlock door
        send_message(socket, "Door unlocked.");
    } else {
        // Invalid command
        send_message(socket, "Invalid command.");
    }
}

// Print usage message
void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s <port>\n", progname);
    exit(1);
}