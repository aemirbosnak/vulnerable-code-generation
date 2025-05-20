//FormAI DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define PORT_NUMBER 8080
#define MAX_BUFFER_SIZE 1024

void *handle_client(void *client_socket_ptr)
{
    int client_socket = *(int*) client_socket_ptr;
    char buffer[MAX_BUFFER_SIZE];

    while(1)
    {   
        memset(buffer, 0, MAX_BUFFER_SIZE);

        if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) <= 0)
        {
            close(client_socket);
            pthread_exit(NULL);
        }

        printf("Client says: %s\n", buffer);

        if(send(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0)
        {
            perror("Error sending message to client");
            pthread_exit(NULL);
        }
    }
}

int main(int argc, char const *argv[])
{
    int server_socket;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(server_address);

    // create socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // bind socket to port
    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if(listen(server_socket, 5) < 0) // 5 is number of connections to be queued
    {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    while(1)
    {
        int new_socket;

        if((new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0)
        {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        pthread_t client_thread;
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = new_socket;

        if(pthread_create(&client_thread, NULL, handle_client, (void*)client_socket_ptr) < 0)
        {
            perror("Error creating thread for client");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}