//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/my_socket"
#define BUFFER_SIZE 100

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Infinite loop to handle multiple messages from the client
    while (1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
        
        // Receive message from the client
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        
        if (bytes_received <= 0) {
            perror("Client disconnected or error receiving");
            break;
        }
        
        // Process the received message
        printf("Server received: %s\n", buffer);
        
        // If message is "exit", close the connection
        if (strcmp(buffer, "exit") == 0) {
            printf("Client has requested to exit. Closing connection.\n");
            break;
        }
        
        // Echo back the received message
        send(client_socket, buffer, bytes_received, 0);
    }
    close(client_socket);
}

void start_server() {
    int server_socket, client_socket;
    struct sockaddr_un server_addr, client_addr;
    socklen_t client_len;

    // Create socket
    server_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);
    
    // Bind the socket to the path
    unlink(SOCKET_PATH); // Remove any existing socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Failed to listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on %s...\n", SOCKET_PATH);

    // Accept clients in an infinite loop
    while (1) {
        client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1) {
            perror("Failed to accept client");
            continue;
        }
        printf("Client connected!\n");
        
        handle_client(client_socket); // Handle client messages
    }

    // Clean up
    close(server_socket);
    unlink(SOCKET_PATH);
}

void start_client() {
    int client_socket;
    struct sockaddr_un server_addr;
    char buffer[BUFFER_SIZE];

    // Create the socket
    client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server! Send messages (type 'exit' to quit):\n");

    // Continuous loop to send messages to the server
    while (1) {
        // Get user input
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Send the message to the server
        send(client_socket, buffer, strlen(buffer), 0);

        // If message is "exit", close the connection
        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting client...\n");
            break;
        }
        
        // Receive echo response from the server
        char response[BUFFER_SIZE];
        recv(client_socket, response, sizeof(response), 0);
        printf("Server echoed: %s\n", response);
    }

    // Clean up
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [server|client]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server(); // Start the server
    } else if (strcmp(argv[1], "client") == 0) {
        start_client(); // Start the client
    } else {
        fprintf(stderr, "Unknown option. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}