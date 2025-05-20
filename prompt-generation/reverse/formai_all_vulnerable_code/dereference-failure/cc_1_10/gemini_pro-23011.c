//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of clients
#define MAX_CLIENTS 100

// Define the maximum size of the message buffer
#define MAX_BUFFER_SIZE 1024

// Define the number of threads for the server
#define NUM_THREADS 10

// Create a structure to store the client information
typedef struct client_info {
    int socket;
    struct sockaddr_in address;
    char* username;
    char* password;
} client_info_t;

// Create a structure to store the server information
typedef struct server_info {
    int socket;
    struct sockaddr_in address;
    int num_clients;
    client_info_t* clients[MAX_CLIENTS];
} server_info_t;

// Create a structure to store the thread information
typedef struct thread_info {
    server_info_t* server;
    int id;
} thread_info_t;

// Create a function to handle the client connections
void* handle_client(void* arg) {
    // Get the thread information
    thread_info_t* thread_info = (thread_info_t*)arg;

    // Get the server information
    server_info_t* server = thread_info->server;

    // Get the client information
    client_info_t* client = server->clients[thread_info->id];

    // Receive the message from the client
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = recv(client->socket, buffer, MAX_BUFFER_SIZE, 0);

    // Check if the client has disconnected
    if (bytes_received <= 0) {
        printf("Client %s has disconnected\n", client->username);
        close(client->socket);
        server->num_clients--;
        return NULL;
    }

    // Parse the message from the client
    char* message = strtok(buffer, " ");
    char* payload = strtok(NULL, " ");

    // Check the message type
    if (strcmp(message, "AUTH") == 0) {
        // Check the username and password
        if (strcmp(payload, "admin:password") == 0) {
            // Send a success message to the client
            char* success_message = "AUTH OK";
            send(client->socket, success_message, strlen(success_message), 0);
        } else {
            // Send a failure message to the client
            char* failure_message = "AUTH FAIL";
            send(client->socket, failure_message, strlen(failure_message), 0);
        }
    } else if (strcmp(message, "DATA") == 0) {
        // Process the data from the client
        printf("Data received from client %s: %s\n", client->username, payload);
    } else {
        // Send an error message to the client
        char* error_message = "ERROR";
        send(client->socket, error_message, strlen(error_message), 0);
    }

    // Close the client socket
    close(client->socket);

    // Return NULL to exit the thread
    return NULL;
}

// Create a function to start the server
void start_server() {
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the server socket was created successfully
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the address
    int bind_result = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Check if the server socket was bound successfully
    if (bind_result == -1) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for incoming connections
    int listen_result = listen(server_socket, MAX_CLIENTS);

    // Check if the server socket is listening successfully
    if (listen_result == -1) {
        perror("Error listening on server socket");
        exit(1);
    }

    // Create a server information structure
    server_info_t server;
    server.socket = server_socket;
    server.address = server_address;
    server.num_clients = 0;

    // Create a thread pool
    pthread_t threads[NUM_THREADS];

    // Start the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_info_t* thread_info = malloc(sizeof(thread_info_t));
        thread_info->server = &server;
        thread_info->id = i;
        pthread_create(&threads[i], NULL, handle_client, thread_info);
    }

    // Accept incoming connections
    while (1) {
        // Accept a connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);

        // Check if the client socket was created successfully
        if (client_socket == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Create a client information structure
        client_info_t* client = malloc(sizeof(client_info_t));
        client->socket = client_socket;
        client->address = client_address;
        client->username = NULL;
        client->password = NULL;

        // Add the client to the server
        server.clients[server.num_clients] = client;
        server.num_clients++;

        // Print a message to the console
        printf("Client %s has connected\n", inet_ntoa(client_address.sin_addr));
    }

    // Close the server socket
    close(server_socket);
}

// Create a function to start the client
void start_client() {
    // Create a client socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the client socket was created successfully
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(1);
    }

    // Set the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to the server
    int connect_result = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Check if the client socket connected successfully
    if (connect_result == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    // Get the username and password from the user
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Send the username and password to the server
    char message[MAX_BUFFER_SIZE];
    sprintf(message, "AUTH %s:%s", username, password);
    send(client_socket, message, strlen(message), 0);

    // Receive the response from the server
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

    // Check if the client received a response from the server
    if (bytes_received <= 0) {
        perror("Error receiving response from server");
        exit(1);
    }

    // Print the response from the server
    printf("Response from server: %s\n", buffer);

    // Close the client socket
    close(client_socket);
}

int main() {
    // Start the server
    start_server();

    // Start the client
    start_client();

    return 0;
}