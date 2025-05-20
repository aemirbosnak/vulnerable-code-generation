//FormAI DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

void *client_handler(void *arg);

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    unsigned short server_port;
    unsigned int client_length;

    if (argc != 2)
    {
        printf("Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    server_port = atoi(argv[1]);

    // Create a new socket
    server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0)
    {
        printf("Error creating server socket\n");
        exit(1);
    }

    // Construct server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(server_port);

    // Bind to local address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Error binding server socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0)
    {
        printf("Error listening on server socket\n");
        exit(1);
    }

    while (1)
    {
        // Wait for client connection
        client_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length);
        if (client_socket < 0)
        {
            printf("Error accepting client connection\n");
            continue;
        }

        // Create a new thread to handle client request
        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, (void *)&client_socket) != 0)
        {
            printf("Error creating client thread\n");
            continue;
        }
    }

    return 0;
}

void *client_handler(void *arg)
{
    int client_socket = *((int *)arg);
    char buffer[1024];
    int recv_msg_size;

    // Receive and print client message
    recv_msg_size = recv(client_socket, buffer, 1024, 0);
    printf("Received message from client: %s", buffer);

    // Send response to client
    char *response = "Got your message!";
    if (send(client_socket, response, strlen(response), 0) != strlen(response))
    {
        printf("Error sending response to client\n");
    }

    // Close client socket
    close(client_socket);

    // Exit thread
    pthread_exit(NULL);
}