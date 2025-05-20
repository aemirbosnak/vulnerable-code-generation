//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function declarations
void start_server();
void start_client();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server|client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid option! Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void start_server() {
    int sockfd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(sockfd, 3) < 0) {
        perror("Listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accepting a new connection
        if ((new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        // Read and echo the message
        while (1) {
            memset(buffer, 0, sizeof(buffer)); // Clear buffer
            int valread = read(new_socket, buffer, sizeof(buffer));
            if (valread <= 0) {
                break; // If read failed or client disconnected
            }
            printf("Received: %s", buffer); // Print received message
            send(new_socket, buffer, valread, 0); // Echo back to client
        }
        
        close(new_socket);
        printf("Connection closed\n");
    }

    close(sockfd);
}

void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return;
    }

    // Define server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return;
    }

    // Sending messages to the server
    while (1) {
        printf("Enter message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);
        if (strcmp(message, "exit\n") == 0) {
            break; // Exit if 'exit' is typed
        }
        send(sock, message, strlen(message), 0); // Send message
        int valread = read(sock, buffer, sizeof(buffer)); // Read echo
        if (valread > 0) {
            printf("Echo from server: %s\n", buffer);
        }
    }

    close(sock);
    printf("Client disconnected.\n");
}