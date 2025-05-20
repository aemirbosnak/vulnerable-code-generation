//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 256

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *message;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);
    
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Simulate temperature reading
        srand(time(0));
        float temperature = (rand() % 3000) / 100.0; // between 0.0 and 30.0
        snprintf(buffer, BUFFER_SIZE, "Current Temperature: %.2f°C", temperature);

        send(new_socket, buffer, strlen(buffer), 0);
        printf("Temperature sent: %s\n", buffer);
        close(new_socket);
    }
}

void start_client() {
    struct sockaddr_in address;
    int sock = 0;
    char buffer[BUFFER_SIZE] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Connection Failed \n");
        return;
    }

    // Send request for temperature data
    send(sock, "Get Temperature", strlen("Get Temperature"), 0);
    printf("Request for temperature sent.\n");

    // Receive the temperature from the server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("Temperature data received from server: %s\n", buffer);
    
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        sleep(1);  // Ensure server starts before client
        start_client();
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'server' or 'client'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}