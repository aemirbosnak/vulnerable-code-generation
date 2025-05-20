//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024

void *handle_client(void *client_socket)
{
    int sock = *(int *)client_socket;
    free(client_socket);

    char buffer[BUF_SIZE];
    int bytes_received;

    // Communication loop
    while ((bytes_received = recv(sock, buffer, BUF_SIZE, 0)) > 0)
    {
        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("Received from client: %s\n", buffer);

        // Echo back the message
        send(sock, buffer, bytes_received, 0);
        printf("Echoed back to client: %s\n", buffer);
    }

    if (bytes_received == 0) // Client disconnected
    {
        printf("Client disconnected\n");
    }
    else
    {
        perror("recv failed");
    }

    close(sock);
    return NULL;
}

int main()
{
    int server_socket, *new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0)
    {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Main loop to accept clients
    while (1)
    {
        new_client_socket = malloc(sizeof(int));
        if ((*new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0)
        {
            perror("Accept failed");
            free(new_client_socket);
            continue;
        }

        printf("New client connected...\n");

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_client_socket) != 0)
        {
            perror("Could not create thread");
            free(new_client_socket);
        }
        else
        {
            pthread_detach(thread_id); // Detach the thread to reclaim resources when it finishes
        }
    }

    close(server_socket);
    return 0;
}