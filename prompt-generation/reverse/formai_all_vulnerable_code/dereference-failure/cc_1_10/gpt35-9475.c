//FormAI DATASET v1.0 Category: Networking ; Style: bold
/*
 * This is a unique networking example program that demonstrates
 * the communication between a server and multiple clients using
 * sockets in C programming language.
 *
 * Author: Chatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

void *handle_client(void *);
void broadcast(char *, int);

int client_count = 0;
int client_sockets[MAX_CLIENTS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char const *argv[])
{
    int server_sock, new_sock, cli_len;
    struct sockaddr_in server, client;

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server attributes
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to the address and port number
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d.\n", PORT);

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    cli_len = sizeof(client);

    while (1)
    {
        // Accept new connection
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t *)&cli_len)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&mutex);

        // Add new client socket to array
        client_sockets[client_count++] = new_sock;

        pthread_mutex_unlock(&mutex);

        // Create and start a new thread to handle client
        pthread_t client_thread;
        int *sock_copy = malloc(sizeof(int));
        *sock_copy = new_sock;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)sock_copy) != 0)
        {
            perror("Client thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *handle_client(void *arg)
{
    int sock = *(int *)arg;
    char buffer[1024] = {0};
    int read_bytes;

    while ((read_bytes = recv(sock, buffer, sizeof(buffer), 0)) > 0)
    {
        // Broadcast message to all clients
        broadcast(buffer, sock);

        memset(buffer, 0, sizeof(buffer));
    }

    pthread_mutex_lock(&mutex);

    // Remove client socket from array
    for (int i = 0; i < client_count; i++)
    {
        if (client_sockets[i] == sock)
        {
            client_sockets[i] = 0;
            break;
        }
    }

    client_count--;

    pthread_mutex_unlock(&mutex);

    // Close socket
    close(sock);
    free(arg);
    pthread_exit(NULL);
}

void broadcast(char *message, int sender_soc)
{
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < client_count; i++)
    {
        // Do not send message to the sender
        if (client_sockets[i] != 0 && client_sockets[i] != sender_soc)
        {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }

    pthread_mutex_unlock(&mutex);
}