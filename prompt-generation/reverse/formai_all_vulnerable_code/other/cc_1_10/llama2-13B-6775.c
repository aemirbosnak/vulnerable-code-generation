//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 256

// Structure to store client information
typedef struct {
    int sock;      // Socket descriptor
    char ip[16];  // Client IP address
    char username[32]; // Client username
} client_t;

// Function to create a new socket
int create_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Function to listen for incoming connections
void listen_for_connections(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    printf("New client connection from IP address %s\n", inet_ntoa(client_addr.sin_addr));
}

// Function to handle incoming messages
void handle_message(int sock, char *message) {
    char *message_ptr = message;
    char username[32];
    int i = 0;

    // Extract the username from the message
    while (*message_ptr != '\0' && i < 32) {
        username[i] = *message_ptr++;
        i++;
    }

    // Send a greeting message to the client
    char greeting[] = "Hello, %s! How can I assist you today?";
    send(sock, greeting, strlen(greeting), 0);

    // Receive a response from the client
    char response[256];
    recv(sock, response, 256, 0);

    // Print the response from the client
    printf("Client response: %s\n", response);
}

// Function to handle incoming disconnects
void handle_disconnect(int sock) {
    printf("Client disconnected\n");
}

int main(void) {
    // Create a new socket
    int sock = create_socket();

    // Listen for incoming connections
    listen_for_connections(sock);

    // Create a thread to handle incoming messages
    pthread_t thread;
    pthread_create(&thread, NULL, handle_message, NULL);

    // Create a thread to handle incoming disconnects
    pthread_t thread2;
    pthread_create(&thread2, NULL, handle_disconnect, NULL);

    // Loop indefinitely to handle incoming connections and messages
    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);

        // Wait for incoming connections or messages
        select(sock + 1, &read_fds, NULL, NULL, NULL);

        // Handle incoming connections and messages
        if (FD_ISSET(sock, &read_fds)) {
            listen_for_connections(sock);
        }

        // Handle incoming disconnects
        if (FD_ISSET(sock, &read_fds)) {
            handle_disconnect(sock);
        }
    }

    return 0;
}