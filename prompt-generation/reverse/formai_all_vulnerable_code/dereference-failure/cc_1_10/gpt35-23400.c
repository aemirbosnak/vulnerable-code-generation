//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the default HTTP port
#define HTTP_PORT 80

// Define the maximum number of connections to maintain
#define MAX_CONNECTIONS 10

// Define the size of the buffer to use for reading and writing
#define BUFFER_SIZE 4096

// Define the proxy server IP and port
#define PROXY_SERVER_IP "127.0.0.1"
#define PROXY_SERVER_PORT 8888

// Define the default timeout in seconds
#define TIMEOUT 30

// Define a struct to hold information about each client connection
struct client_connection {
    int client_fd;
    int server_fd;
    char *request_buf;
    char *response_buf;
    size_t request_len;
    size_t response_len;
};

int create_server_socket(int port);
int accept_client_connection(int server_fd);
int connect_to_server(char *hostname, int port);
void close_client_connection(struct client_connection *conn);
void proxy_client_request(struct client_connection *conn);
void proxy_server_response(struct client_connection *conn);

int main(int argc, char* argv[]) {
    // Create the server socket
    int server_fd = create_server_socket(PROXY_SERVER_PORT);
    
    // Loop indefinitely, accepting client connections and proxying requests
    while (1) {
        // Accept a client connection
        int client_fd = accept_client_connection(server_fd);
        if (client_fd < 0) {
            continue;
        }
        
        // Create a new client connection struct
        struct client_connection *conn = malloc(sizeof(struct client_connection));
        if (conn == NULL) {
            close(client_fd);
            continue;
        }
        memset(conn, 0, sizeof(struct client_connection));
        
        // Set the client file descriptor
        conn->client_fd = client_fd;
        
        // Set the request buffer
        conn->request_buf = malloc(BUFFER_SIZE);
        if (conn->request_buf == NULL) {
            close_client_connection(conn);
            continue;
        }
        
        // Set the response buffer
        conn->response_buf = malloc(BUFFER_SIZE);
        if (conn->response_buf == NULL) {
            close_client_connection(conn);
            continue;
        }

        // Call the function to proxy client requests
        proxy_client_request(conn);
    }
    
    // Close the server socket
    close(server_fd);
    
    return 0;
}

int create_server_socket(int port) {
    // Create the server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    
    // Create the server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error creating server socket: %s\n", strerror(errno));
        exit(1);
    }
    
    // Bind the server socket to the server address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding server socket: %s\n", strerror(errno));
        exit(1);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        printf("Error listening on server socket: %s\n", strerror(errno));
        exit(1);
    }
    
    printf("Proxy server listening on port %d...\n", port);
    
    return server_fd;
}

int accept_client_connection(int server_fd) {
    // Accept the next client connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
    
    if (client_fd < 0) {
        printf("Error accepting client connection: %s\n", strerror(errno));
        return -1;
    }
    
    printf("Accepted new client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
    return client_fd;
}

int connect_to_server(char *hostname, int port) {
    // Create the server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);
    
    // Create the server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error creating server socket: %s\n", strerror(errno));
        exit(1);
    }
    
    // Connect to the server
    if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }
    
    return server_fd;
}

void close_client_connection(struct client_connection *conn) {
    // Close the client and server file descriptors
    close(conn->client_fd);
    if (conn->server_fd > 0) {
        close(conn->server_fd);
    }
    
    // Free the request and response buffers
    if (conn->request_buf != NULL) {
        free(conn->request_buf);
    }
    if (conn->response_buf != NULL) {
        free(conn->response_buf);
    }
    
    // Free the connection struct
    free(conn);
}

void proxy_client_request(struct client_connection *conn) {
    // Set the timeout for the client socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(conn->client_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Read the client request into the buffer
    ssize_t bytes_read = recv(conn->client_fd, conn->request_buf, BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        printf("Error reading request from client: %s\n", strerror(errno));
        close_client_connection(conn);
        return;
    }
    if (bytes_read == 0) {
        printf("Client disconnected\n");
        close_client_connection(conn);
        return;
    }
    
    // Update the length of the request buffer
    conn->request_len = bytes_read;
    
    // Parse the client request to determine the server host and port
    char *request_str = conn->request_buf;
    char *hostname_start = strstr(request_str, "Host: ") + strlen("Host: ");
    char *hostname_end = strstr(hostname_start, "\r\n");
    char hostname[256];
    strncpy(hostname, hostname_start, hostname_end - hostname_start);
    hostname[hostname_end - hostname_start] = '\0';
    char *port_start = strstr(hostname_start, ":");
    int port = HTTP_PORT;
    if (port_start != NULL) {
        port = atoi(port_start + 1);
    }
    
    printf("Proxying request to %s:%d\n", hostname, port);
    
    // Connect to the server
    conn->server_fd = connect_to_server(hostname, port);
    
    // Forward the request to the server
    if (send(conn->server_fd, conn->request_buf, conn->request_len, 0) < 0) {
        printf("Error forwarding request to server: %s\n", strerror(errno));
        close_client_connection(conn);
        return;
    }
    
    // Call the function to proxy the server response
    proxy_server_response(conn);
}

void proxy_server_response(struct client_connection *conn) {
    // Set the timeout for the server socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(conn->server_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    
    // Read the server response into the buffer
    ssize_t bytes_read = recv(conn->server_fd, conn->response_buf, BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        printf("Error reading response from server: %s\n", strerror(errno));
        close_client_connection(conn);
        return;
    }
    if (bytes_read == 0) {
        printf("Server disconnected\n");
        close_client_connection(conn);
        return;
    }
    
    // Update the length of the response buffer
    conn->response_len = bytes_read;
    
    // Forward the server response to the client
    if (send(conn->client_fd, conn->response_buf, conn->response_len, 0) < 0) {
        printf("Error forwarding response to client: %s\n", strerror(errno));
        close_client_connection(conn);
        return;
    }
    
    // Loop back to the function to proxy the next client request
    proxy_client_request(conn);
}