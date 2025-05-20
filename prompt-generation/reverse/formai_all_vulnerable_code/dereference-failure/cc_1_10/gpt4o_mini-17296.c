//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int read_size = read(client_socket, buffer, sizeof(buffer)-1);
    if (read_size < 0) {
        perror("Read failed");
        close(client_socket);
        return NULL;
    }
    buffer[read_size] = '\0';  // Null terminate the received data

    printf("Received request:\n%s\n", buffer);

    // Construct HTTP response
    const char *http_header = "HTTP/1.1 200 OK\r\n"
                              "Content-Type: text/html\r\n"
                              "Connection: close\r\n"
                              "\r\n";
    const char *http_body = "<html><head><title>My Simple Web Server</title></head>"
                            "<body><h1>Hello, World!</h1><p>This is a response from my simple web server!</p></body></html>";

    write(client_socket, http_header, strlen(http_header));
    write(client_socket, http_body, strlen(http_body));

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Listen on all available interfaces
    server_addr.sin_port = htons(PORT);  // Convert port number to network byte order

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Move to the next iteration on failure
        }

        printf("Client connected, handling request...\n");

        // Handle the client request in a new thread
        pthread_t thread_id;
        int *new_sock = malloc(1);
        *new_sock = client_socket; // Pass client socket to thread
        if (pthread_create(&thread_id, NULL, handle_client, (void*)new_sock) != 0) {
            perror("Thread creation failed");
            close(client_socket);
            free(new_sock);
        }
        pthread_detach(thread_id); // Detach thread to clean up when done
    }

    close(server_socket);
    return 0;
}