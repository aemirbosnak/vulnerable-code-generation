//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int sockfd;
    struct sockaddr_in client_addr;
} client_t;

// Function for handling client communication
void* handle_client(void* arg) {
    client_t* client = (client_t*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client->sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer);
        write(client->sockfd, buffer, bytes_read); // Echo the message back
    }

    close(client->sockfd);
    free(client);
    return NULL;
}

// Main server function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);

    // Accepting client connections in a loop
    while ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) >= 0) {
        printf("New connection accepted\n");
        client_t* client = malloc(sizeof(client_t));
        client->sockfd = new_socket;
        client->client_addr = address;

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void*)client);
        pthread_detach(tid); // Detach the thread for automatic cleanup
    }

    // Closing the server socket
    close(server_fd);
}

// Main function for client
void start_client(const char* server_ip) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    // Configuring server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    char message[BUFFER_SIZE];
    while (1) {
        printf("Enter message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        if (strcmp(message, "exit\n") == 0) break; // Exit command
        send(sock, message, strlen(message), 0); // Send message to server
        int bytes_read = read(sock, message, sizeof(message) - 1); // Read echo back
        if (bytes_read > 0) {
            message[bytes_read] = '\0'; // Null-terminate the string
            printf("Server response: %s", message);
        }
    }

    // Closing the socket and exiting
    close(sock);
}

// Program entry point
int main(int argc, char* argv[]) {
    if (argc == 1) {
        start_server(); // Start as server
    } else if (argc == 2) {
        start_client(argv[1]); // Start as client and connect to server
    } else {
        printf("Usage: %s [server_ip (client mode)]\n", argv[0]);
    }
    return 0;
}