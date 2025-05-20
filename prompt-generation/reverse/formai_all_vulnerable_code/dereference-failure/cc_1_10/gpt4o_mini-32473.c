//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *client_handler(void *socket_desc) {
    int sock = *(int*)socket_desc;
    free(socket_desc);
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communication loop
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate string

        // Simple command processing
        if (strncmp(buffer, "HELLO", 5) == 0) {
            send(sock, "Hello from server!", 18, 0);
        } else if (strncmp(buffer, "TIME", 4) == 0) {
            time_t now = time(NULL);
            snprintf(buffer, sizeof(buffer), "Current time: %s", ctime(&now));
            send(sock, buffer, strlen(buffer), 0);
        } else if (strncmp(buffer, "BYE", 3) == 0) {
            send(sock, "Goodbye!", 8, 0);
            break;
        } else {
            char *response = "Unknown command!";
            send(sock, response, strlen(response), 0);
        }
    }

    close(sock);
    return 0;
}

int main() {
    int server_fd, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d\n", PORT);

    // Accept clients
    while (1) {
        int *new_socket = malloc(sizeof(int));
        if ((*new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            free(new_socket);
            continue;
        }

        printf("New connection accepted\n");

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void*)new_socket) != 0) {
            perror("Could not create thread");
            free(new_socket);
        } else {
            pthread_detach(thread_id);  // Automatically reclaim resources when done
        }
    }

    // Cleanup
    close(server_fd);
    return 0;
}