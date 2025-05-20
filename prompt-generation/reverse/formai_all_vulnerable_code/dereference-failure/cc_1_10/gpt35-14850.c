//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10 
#define BUFFER_SIZE 1024

// Function to parse the client request and extract the destination server and port
void parse_request(char *request, char *host, int *port)
{
    char *ptr = strstr(request, "Host: ");
    ptr = ptr + strlen("Host: ");

    char *end = strstr(ptr, "\r\n");
    int len = end - ptr;

    strncpy(host, ptr, len);
    host[len] = '\0';

    // If the request port is specified in the client request,
    // extract it from the request.
    char *port_start = strchr(host, ':');
    if(port_start != NULL)
    {
        *port_start = '\0';
        port_start++;
        *port = atoi(port_start);
    }
}

int main(int argc, char **argv)
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE], host[100];
    int port = 80;
    int addrlen = sizeof(server_addr);

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to the specified port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connections...\n");

    while (1)
    {
        // Accept incoming connections
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New incoming connection...\n");

        // Receive HTTP request from client
        memset(buffer, 0, BUFFER_SIZE);
        read(client_fd, buffer, BUFFER_SIZE);

        // Parse the request to get the destination server and port
        parse_request(buffer, host, &port);

        printf("Host: %s\n", host);
        printf("Port: %d\n", port);

        // Create socket to communicate with the destination server
        int dest_fd;
        struct sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(port);

        if(inet_pton(AF_INET, host, &dest_addr.sin_addr)<=0)
        {
            printf("\nInvalid address/ Address not supported \n");
            continue;
        }

        if ((dest_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        // Connect to destination server
        if (connect(dest_fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
        {
            perror("Connection failed");
            exit(EXIT_FAILURE);
        }

        printf("Connected to destination server...\n");

        // Forward the client request to the destination server
        if (write(dest_fd, buffer, strlen(buffer)) < 0)
        {
            perror("Write to destination server failed");
            exit(EXIT_FAILURE);
        }

        printf("Client request forwarded to destination server...\n");

        // Forward the destination server response to the client
        memset(buffer, 0, BUFFER_SIZE);
        while(read(dest_fd, buffer, BUFFER_SIZE) > 0)
        {
            if (write(client_fd, buffer, strlen(buffer)) < 0)
            {
                perror("Write to client failed");
                exit(EXIT_FAILURE);
            }
            memset(buffer, 0, BUFFER_SIZE);
        }

        printf("Destination server response forwarded to client...\n");

        // Close the sockets
        close(client_fd);
        close(dest_fd);
    }

    return 0;
}