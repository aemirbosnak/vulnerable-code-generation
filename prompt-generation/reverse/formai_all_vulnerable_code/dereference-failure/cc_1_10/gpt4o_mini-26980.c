//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 1024

// Function to handle errors gracefully
void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to start the server
void startServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handleError("Socket creation failed");
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        handleError("Set socket options failed");
    }

    // Prepare the sockaddr_in structure
    address.sin_family = AF_INET;         
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);        

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handleError("Bind failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        handleError("Listen failed");
    }

    // Accept an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
        (socklen_t*)&addrlen)) < 0) {
        handleError("Accept failed");
    }

    // Communication with the client
    while (1) {
        int valread = read(new_socket, buffer, MAX_BUFFER);
        if (valread <= 0) {
            printf("Connection closed by client.\n");
            break; // Exit if read fails or client disconnects
        }
        
        printf("Received: %s\n", buffer);
        send(new_socket, buffer, valread, 0); // Echo back the message
        memset(buffer, 0, sizeof(buffer)); // Clear out the buffer for the next message
    }

    // Close the sockets
    close(new_socket);
    close(server_fd);
    printf("Server shut down.\n");
}

// Function to start the client
void startClient(const char *server_ip) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client!";
    char buffer[MAX_BUFFER] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Socket creation error");
    }

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        handleError("Invalid address / Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handleError("Connection failed");
    }

    // Send and receive messages in a loop
    while (1) {
        send(sock, message, strlen(message), 0);
        printf("Message sent: %s\n", message);
        
        // Read the echoed message from the server
        int valread = read(sock, buffer, MAX_BUFFER);
        if (valread <= 0) {
            printf("Server closed the connection.\n");
            break;
        }
        
        printf("Echo from server: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer for the next received message
        sleep(2); // Sleep for a short time before sending another message
    }

    // Close the socket
    close(sock);
    printf("Client closed.\n");
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Choose to run server or client based on command line argument
    if (strcmp(argv[1], "server") == 0) {
        printf("Starting server...\n");
        startServer();
    } else if (strcmp(argv[1], "client") == 0) {
        printf("Starting client...\n");
        startClient("127.0.0.1"); // Connect to localhost
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}