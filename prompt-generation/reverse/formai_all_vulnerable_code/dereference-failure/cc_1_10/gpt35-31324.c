//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

struct thread_data {
    int client_socket;
};

void *handle_imap_client(void *arg) {
    char buffer[MAX_BUFFER_SIZE];
    struct thread_data *data = (struct thread_data *)arg;
    int client_socket = data->client_socket;

    // Send the greeting message to the client
    const char *greeting_msg = "* OK IMAP4 Server Ready\r\n";
    send(client_socket, greeting_msg, strlen(greeting_msg), 0);

    // Receive commands from the client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        // Process the received command
        // TODO...

        // Send the response back to the client
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            break;
        }
    }

    // Close the client socket and exit the thread
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t thread;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(143); // IMAP4 port

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and spawn threads to handle them
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept() failed");
            continue;
        }

        // Spawn a new thread to handle the client
        struct thread_data *data = (struct thread_data *)malloc(sizeof(struct thread_data));
        data->client_socket = client_socket;
        if (pthread_create(&thread, NULL, handle_imap_client, (void *)data) != 0) {
            perror("pthread_create() failed");
            free(data);
            close(client_socket);
            continue;
        }

        // Detach the thread to avoid memory leaks
        pthread_detach(thread);
    }

    // Cleanup
    close(server_socket);
    return EXIT_SUCCESS;
}