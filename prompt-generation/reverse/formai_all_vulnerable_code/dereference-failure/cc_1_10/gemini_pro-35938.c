//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Constants for request codes and responses
#define GET "GET "
#define HTTP "HTTP/1.1\r\n"
#define HOST "Host: "
#define OK "HTTP/1.1 200 OK\r\n"
#define NOT_FOUND "HTTP/1.1 404 Not Found\r\n"

// Constants for port numbers
#define CLIENT_PORT 5000
#define SERVER_PORT 80

// Structure for client socket
typedef struct client_socket
{
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addr_len;
} client_socket;

// Structure for server socket
typedef struct server_socket
{
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addr_len;
} server_socket;

// Function to create a client socket
client_socket create_client_socket(char *ip_address)
{
    client_socket client;

    // Create a socket
    client.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client.sockfd == -1)
    {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Set client socket address
    client.addr.sin_family = AF_INET;
    client.addr.sin_port = htons(CLIENT_PORT);
    client.addr.sin_addr.s_addr = inet_addr(ip_address);
    client.addr_len = sizeof(client.addr);

    // Connect to the server
    if (connect(client.sockfd, (struct sockaddr *)&client.addr, client.addr_len) == -1)
    {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return client;
}

// Function to create a server socket
server_socket create_server_socket()
{
    server_socket server;

    // Create a socket
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd == -1)
    {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set server socket address
    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(SERVER_PORT);
    server.addr.sin_addr.s_addr = INADDR_ANY;
    server.addr_len = sizeof(server.addr);

    // Bind the socket to the address
    if (bind(server.sockfd, (struct sockaddr *)&server.addr, server.addr_len) == -1)
    {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server.sockfd, 5) == -1)
    {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    return server;
}

// Function to handle client requests
void handle_client_request(client_socket client, server_socket server)
{
    char request[1024];
    char response[1024];

    // Receive the request from the client
    if (recv(client.sockfd, request, sizeof(request), 0) == -1)
    {
        perror("Error receiving request from client");
        exit(EXIT_FAILURE);
    }

    // Parse the request
    char *url = strstr(request, GET) + strlen(GET);
    char *host = strstr(request, HOST) + strlen(HOST);
    *strstr(host, "\r\n") = '\0';

    // Send the request to the server
    if (send(server.sockfd, request, strlen(request), 0) == -1)
    {
        perror("Error sending request to server");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(server.sockfd, response, sizeof(response), 0) == -1)
    {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }

    // Send the response to the client
    if (send(client.sockfd, response, strlen(response), 0) == -1)
    {
        perror("Error sending response to client");
        exit(EXIT_FAILURE);
    }

    // Close the client socket
    close(client.sockfd);
}

// Function to close server socket
void close_server_socket(server_socket server)
{
    close(server.sockfd);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a server socket
    server_socket server = create_server_socket();

    while (1)
    {
        // Accept incoming connections
        client_socket client;
        client.addr_len = sizeof(client.addr);
        client.sockfd = accept(server.sockfd, (struct sockaddr *)&client.addr, &client.addr_len);
        if (client.sockfd == -1)
        {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        // Handle the client request
        handle_client_request(client, server);
    }

    // Close the server socket
    close_server_socket(server);

    return 0;
}