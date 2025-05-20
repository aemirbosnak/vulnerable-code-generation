//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024
#define LOG_FILE "client_interactions.log"

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *greeting = "Welcome to my unique server!\n";
    char *echo = "You said: ";
    FILE *log_file;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        log_file = fopen(LOG_FILE, "a");

        // Accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Greet the client
        send(new_socket, greeting, strlen(greeting), 0);

        // Log the connection
        time_t now;
        char date[20];
        localtime_r(&now, &date);
        fprintf(log_file, "%s - New connection from %s:%d\n", date,
                inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Handle client messages
        while (1) {
            ssize_t read_size;

            // Read message from client
            read_size = recv(new_socket, buffer, BUFFER_SIZE, 0);
            if (read_size <= 0) {
                break;
            }

            // Log the interaction
            fprintf(log_file, "%s - Received: %s", date, buffer);

            // Echo message back to client
            send(new_socket, echo, strlen(echo), 0);
            send(new_socket, buffer, read_size, 0);
        }

        // Close connection and log disconnection
        close(new_socket);
        fclose(log_file);
        fprintf(log_file, "%s - Client disconnected\n", date);
    }

    return 0;
}