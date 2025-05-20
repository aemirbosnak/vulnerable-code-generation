//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to convert string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Server function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accepting new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                  (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }

        // Reading data from client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        buffer[valread] = '\0'; // Null terminate the string
        printf("Received: %s", buffer);
        
        // Convert to uppercase
        to_uppercase(buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        printf("Sent: %s", buffer);
        
        // Close the socket after response
        close(new_socket);
    }
}

// Client function
void start_client(const char *msg) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Sending data to the server
    send(sock, msg, strlen(msg), 0);
    printf("Message sent to server: %s\n", msg);

    // Reading response from server
    int valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0'; // Null terminate the string
    printf("Response from server: %s\n", buffer);

    // Close the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc == 2) {
        // If a message is provided, start the client
        start_client(argv[1]);
    } else {
        // Otherwise, start the server
        start_server();
    }

    return 0;
}