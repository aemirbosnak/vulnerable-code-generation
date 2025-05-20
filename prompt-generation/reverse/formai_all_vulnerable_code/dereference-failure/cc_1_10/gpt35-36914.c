//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_REQUEST_SIZE 2048
#define MAX_RESPONSE_SIZE 4096

// Structure to hold the client and server sockets
typedef struct {
    int client_sock;
    int server_sock;
} connection_t;

// Forward declaration of our proxy functionality
void *proxy_handler(void *);

int main(int argc, char *argv[]) {
    // Validate the command line arguments
    if (argc < 2) {
        printf("Usage: %s <listening port>\n", argv[0]);
        return 1;
    }

    // Parse the listening port from the command line
    int listening_port = atoi(argv[1]);

    // Create the listening socket
    int listening_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_sock == -1) {
        perror("Failed to create listening socket");
        return 1;
    }

    // Bind the listening socket to the listening port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(listening_port);

    int bind_result = bind(listening_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result == -1) {
        perror("Failed to bind to listening port");
        return 1;
    }

    // Listen for incoming connections
    int listen_result = listen(listening_sock, 10);
    if (listen_result == -1) {
        perror("Failed to listen for connections");
        return 1;
    }

    printf("Proxy server listening on port %d\n", listening_port);

    // Loop forever to handle incoming connections
    while (1) {
        // Create a connection_t struct to hold the client and server sockets
        connection_t *connection = (connection_t *)malloc(sizeof(connection_t));

        // Accept an incoming client connection
        connection->client_sock = accept(listening_sock, NULL, NULL);
        if (connection->client_sock == -1) {
            perror("Failed to accept client connection");
            free(connection);
            continue;
        }

        // Create a new thread to handle the client connection
        pthread_t client_thread;
        int create_result = pthread_create(&client_thread, NULL, proxy_handler, (void *)connection);
        if (create_result == -1) {
            perror("Failed to create client connection handler thread");
            close(connection->client_sock);
            free(connection);
            continue;
        }

        printf("Started client connection handler thread\n");
    }
}

void *proxy_handler(void *arg) {
    // Convert the argument to a connection_t struct
    connection_t *connection = (connection_t *)arg;

    // Allocate buffers for the HTTP request and response
    char request_buffer[MAX_REQUEST_SIZE];
    memset(request_buffer, 0, MAX_REQUEST_SIZE);
    char response_buffer[MAX_RESPONSE_SIZE];
    memset(response_buffer, 0, MAX_RESPONSE_SIZE);

    // Read the client's request into the request buffer
    int request_size = recv(connection->client_sock, request_buffer, MAX_REQUEST_SIZE, 0);
    if (request_size == -1) {
        perror("Failed to read client request");
        close(connection->client_sock);
        free(connection);
        return NULL;
    }

    // Parse the HTTP method and the requested URL from the request buffer
    char method[16];
    char url[256];
    sscanf(request_buffer, "%s %s", method, url);

    // Print the incoming request
    printf("Incoming request: %s %s\n", method, url);

    // Parse the hostname and the port number from the requested URL
    char *protocol = strtok(url, "://");
    char *hostname = strtok(NULL, ":");
    char *port_str = strtok(NULL, "/");
    int port = atoi(port_str);

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Failed to resolve hostname: %s\n", hostname);
        close(connection->client_sock);
        free(connection);
        return NULL;
    }

    // Create a new socket to connect to the server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create server socket");
        close(connection->client_sock);
        free(connection);
        return NULL;
    }

    // Connect the server socket to the server's IP address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    server_addr.sin_port = htons(port);

    int connect_result = connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_result == -1) {
        perror("Failed to connect to server");
        close(connection->client_sock);
        close(server_sock);
        free(connection);
        return NULL;
    }

    // Write the client's request to the server socket
    int write_result = write(server_sock, request_buffer, request_size);
    if (write_result == -1) {
        perror("Failed to write request to server");
        close(connection->client_sock);
        close(server_sock);
        free(connection);
        return NULL;
    }

    // Read the server's response into the response buffer
    int response_size = recv(server_sock, response_buffer, MAX_RESPONSE_SIZE, 0);
    if (response_size == -1) {
        perror("Failed to read server response");
        close(connection->client_sock);
        close(server_sock);
        free(connection);
        return NULL;
    }

    // Write the server's response to the client socket
    write_result = write(connection->client_sock, response_buffer, response_size);
    if (write_result == -1) {
        perror("Failed to write response to client");
        close(connection->client_sock);
        close(server_sock);
        free(connection);
        return NULL;
    }

    printf("Finished handling request\n");

    // Clean up the sockets and connection struct
    close(connection->client_sock);
    close(server_sock);
    free(connection);

    return NULL;
}