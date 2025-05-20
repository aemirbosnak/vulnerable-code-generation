//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 5000
#define MAX_CLIENTS 10

/* Function to handle the client's request */
void *handle_client(void *arg)
{
    int client_socket = *(int*)arg;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    /* Read the input from the client socket */
    read(client_socket, buffer, 1024);

    /* Process the input and send the response */
    char response[1024];
    sprintf(response, "You sent: %s\n", buffer);
    write(client_socket, response, strlen(response));

    /* Close the client socket and exit this thread */
    close(client_socket);
    pthread_exit(NULL);
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    pthread_t threads[MAX_CLIENTS]; /* Array of threads for clients */

    /* Create a socket */
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    /* Set server address values */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    /* Bind the socket to the specified address and port */
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Unable to bind socket to address");
        exit(EXIT_FAILURE);
    }

    /* Listen for incoming connections */
    listen(server_socket, MAX_CLIENTS);

    /* Accept incoming connections and create a thread for each client */
    while (1)
    {
        /* Block until a client connects */
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0)
        {
            perror("Unable to accept client connection");
            exit(EXIT_FAILURE);
        }

        /* Create a new thread to handle the client's request */
        if (pthread_create(&threads[MAX_CLIENTS], NULL, handle_client, &client_socket) < 0)
        {
            perror("Unable to create thread for client");
            exit(EXIT_FAILURE);
        }
    }

    /* Close the server socket */
    close(server_socket);

    return 0;
}