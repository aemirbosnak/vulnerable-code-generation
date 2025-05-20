//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void create_server(void) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accepting a connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            exit(EXIT_FAILURE);
        }

        // Reading message from client
        read(new_socket, buffer, BUFFER_SIZE);
        printf("Message received: %s\n", buffer);
        
        // Sending response back to client
        const char *response = "Hello from server!";
        send(new_socket, response, strlen(response), 0);
        
        // Close the socket
        close(new_socket);
    }

    // Cleanup
    close(server_fd);
}

void create_client(const char *message) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Sending message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);
    
    // Reading response from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);

    // Closing socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message to send to server>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a new process for server
    if (fork() == 0) {
        // Server process
        create_server();
    } else {
        // Delay to ensure server starts first
        sleep(1);
        // Client process
        create_client(argv[1]);
    }

    return EXIT_SUCCESS;
}