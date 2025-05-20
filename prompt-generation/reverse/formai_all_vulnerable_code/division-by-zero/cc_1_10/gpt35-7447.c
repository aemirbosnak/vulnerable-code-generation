//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 65536

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind socket to IP and port");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Failed to start listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        // Accept a new incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Receive the client's request
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(new_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Failed to receive data from client");
            exit(EXIT_FAILURE);
        }

        printf("Received request from client:\n%s\n", buffer);

        // Simulate internet speed test by delaying response
        srand(time(NULL));
        int download_speed = rand() % 1000 + 1; // Random download speed between 1-1000 Mbps
        int file_size_mb = 500; // File size to simulate internet speed test

        printf("Running internet speed test...\n");
        sleep(5); // Simulate running internet speed test for 5 seconds

        // Send the response with the calculated download speed
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "Your download speed is %d Mbps. It would take approximately %d seconds to download a %d MB file.", download_speed, (file_size_mb / (download_speed / 8)), file_size_mb);

        if (send(new_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send data to client");
            exit(EXIT_FAILURE);
        }

        printf("Sent response to client:\n%s\n", buffer);

        close(new_socket);
        printf("Connection with client closed\n");
    }

    return 0;
}