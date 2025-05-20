//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>

#define BUFFER_SIZE 1024 // maximum size of the buffer

// function to create a socket for the proxy server
int createSocket(int port)
{
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in proxy_address;

    if (proxy_socket < 0)
    {
        perror("Could not create proxy socket");
        exit(EXIT_FAILURE);
    }

    printf("Proxy socket created.\n");

    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(port);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Bind successful.\n");

    if (listen(proxy_socket, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening...\n");

    return proxy_socket;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int proxy_socket, client_socket, read_length;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    proxy_socket = createSocket(port);

    printf("Proxy server running on port %d\n", port);

    while (1)
    {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, &client_address_len);

        if (client_socket < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted.\n");

        read_length = read(client_socket, buffer, BUFFER_SIZE);

        if (read_length < 0)
        {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        printf("Request received from client:\n%s\n", buffer);

        /* You can write your own logic here to modify the request
        before forwarding it to the server */

        /* Create a socket to connect to the server */
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of the server
        server_address.sin_port = htons(80); // port number of the server

        /* Connect to the server */
        if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        {
            perror("Connect failed");
            exit(EXIT_FAILURE);
        }

        /* Forward the request to the server */
        if (write(server_socket, buffer, strlen(buffer)) < 0)
        {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        printf("Request forwarded to server.\n");

        /* Receive the response from the server */
        memset(buffer, 0, BUFFER_SIZE);
        read_length = read(server_socket, buffer, BUFFER_SIZE);

        if (read_length < 0)
        {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        printf("Response received from server:\n%s\n", buffer);

        /* You can write your own logic here to modify the response
        before sending it back to the client */

        /* Send the response back to the client */
        if (write(client_socket, buffer, strlen(buffer)) < 0)
        {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        printf("Response sent to client.\n");

        close(client_socket);
        close(server_socket);
    }

    close(proxy_socket);

    return 0;
}