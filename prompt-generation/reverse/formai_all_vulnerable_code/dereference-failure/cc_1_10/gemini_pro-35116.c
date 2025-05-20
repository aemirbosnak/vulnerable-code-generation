//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
    char buffer[MAX_BUFFER_SIZE];
    int buffer_len;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void handle_connection(connection_t *conn) {
    int nbytes;
    
    // Receive data from the client
    nbytes = recv(conn->fd, conn->buffer, MAX_BUFFER_SIZE - 1, 0);
    if (nbytes < 0) {
        perror("recv");
        close(conn->fd);
        return;
    }
    
    // Terminate the string
    conn->buffer[nbytes] = '\0';
    
    // Check for malicious content
    if (strstr(conn->buffer, "MALICIOUS_CONTENT")) {
        // Log the intrusion attempt
        printf("Intrusion attempt detected from %s:%d\n", inet_ntoa(conn->addr.sin_addr), ntohs(conn->addr.sin_port));
        
        // Close the connection
        close(conn->fd);
        return;
    }
    
    // Send data back to the client
    nbytes = send(conn->fd, conn->buffer, strlen(conn->buffer), 0);
    if (nbytes < 0) {
        perror("send");
        close(conn->fd);
        return;
    }
    
    // Close the connection
    close(conn->fd);
}

int main() {
    int server_fd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    
    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return -1;
    }
    
    // Set the socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return -1;
    }
    
    // Bind the socket to the port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return -1;
    }
    
    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        return -1;
    }
    
    // Accept incoming connections
    while (1) {
        client_addr_len = sizeof(client_addr);
        new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_fd < 0) {
            perror("accept");
            return -1;
        }
        
        // Add the new connection to the list of connections
        connections[num_connections].fd = new_fd;
        connections[num_connections].addr = client_addr;
        connections[num_connections].buffer_len = 0;
        num_connections++;
        
        // Handle the connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_connection, &connections[num_connections - 1]);
    }
    
    // Close the server socket
    close(server_fd);
    
    return 0;
}