//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *handle_client(void *arg);
void shape_shifting_response(char *buffer);

int main() {
    int server_fd, new_socket, *client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
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

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept a new client
        client_socket = malloc(sizeof(int));
        if ((*client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            free(client_socket);
            continue;
        }

        printf("New connection accepted\n");

        // Create a thread for the new client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)client_socket) < 0) {
            perror("Could not create thread");
        }
    }

    // Close server socket (never reached in this infinite loop)
    close(server_fd);
    return 0;
}

void *handle_client(void *arg) {
    int sock = *(int*)arg;
    free(arg);
    char buffer[BUFFER_SIZE];
    int read_value;

    // Communication with the client
    while ((read_value = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_value] = '\0';
        printf("Received message: %s\n", buffer);
        shape_shifting_response(buffer);
        send(sock, buffer, strlen(buffer), 0);
        printf("Response sent: %s\n", buffer);
    }

    if (read_value == 0) {
        printf("Client disconnected\n");
    } else {
        perror("recv failed");
    }
    
    close(sock);
    return NULL;
}

void shape_shifting_response(char *buffer) {
    // Shape-shifting response example
    int length = strlen(buffer);
    for (int i = 0; i < length; i++) {
        // Alternate between upper and lower case
        if (i % 2 == 0) {
            buffer[i] = toupper(buffer[i]);
        } else {
            buffer[i] = tolower(buffer[i]);
        }
    }

    // Add some additional shape-shifting effects
    if (strstr(buffer, "hello") != NULL) {
        strcat(buffer, " - A shape-shifting greeting!");
    } else if (strstr(buffer, "bye") != NULL) {
        strcat(buffer, " - Parting is such sweet sorrow.");
    }
    
    // Adding a playful twist
    strcat(buffer, " ~ You've spoken to a playful server!");
}