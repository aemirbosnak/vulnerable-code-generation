//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_BUFFER 1024

void *handle_connection(void *);

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set address properties
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)))
    {
        pthread_t thread;
        int *new_socket_fd = malloc(sizeof(int));
        *new_socket_fd = client_fd;

        if (pthread_create(&thread, NULL, handle_connection, (void *)new_socket_fd) != 0)
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *handle_connection(void *args)
{
    int socket_fd = *(int *)args;
    char buffer[MAX_BUFFER] = {0};
    int read_bytes;

    // Read data from client
    if ((read_bytes = read(socket_fd, buffer, MAX_BUFFER)) == 0)
    {
        close(socket_fd);
        free(args);
        pthread_exit(NULL);
    }

    // Send data to client
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
    write(socket_fd, response, strlen(response));

    close(socket_fd);
    free(args);
    pthread_exit(NULL);
}