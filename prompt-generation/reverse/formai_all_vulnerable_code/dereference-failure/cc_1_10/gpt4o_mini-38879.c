//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function for the Romeo's server to receive messages
void romeoServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Romeo's heart is broken: Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Romeo's heart falters: Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Define the type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Alas! Romeo's love may be lost: Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Oh, cruel fate! Listening failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Romeo awaits his dear Juliet...\n");
    
    // Accept the connection from Juliet
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("A tragic misstep: Accept failed");
        exit(EXIT_FAILURE);
    }
    
    // Receive messages from Juliet
    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread < 0) {
            perror("Oh, woe! Reading from Juliet's love failed");
            break;
        }
        printf("Juliet says: %s\n", buffer);
    }
    
    close(new_socket);
    close(server_fd);
}

// Function for Juliet's client to send messages
void julietClient() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "O Romeo, Romeo! Wherefore art thou?";
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nConnection to the heart was lost: Socket creation error");
        return;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nA tragedy! Invalid address: Address not supported");
        return;
    }
    
    // Connect to the Romeo's server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nAlas! The connection faltered, Romeo!");
        return;
    }

    // Send messages to Romeo
    while (1) {
        printf("Enter your message for Romeo (type 'exit' to leave): ");
        char buffer[BUFFER_SIZE];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        
        if (strcmp(buffer, "exit") == 0) {
            printf("Goodnight, dear Romeo!\n");
            break;
        }
        
        send(sock, buffer, strlen(buffer), 0);
    }

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <role: server/client>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        romeoServer();
    } else if (strcmp(argv[1], "client") == 0) {
        julietClient();
    } else {
        fprintf(stderr, "Invalid role specified. Use 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return 0;
}