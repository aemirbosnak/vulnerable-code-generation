//FormAI DATASET v1.0 Category: Client Server Application ; Style: asynchronous
// This is a very basic example of a C client-server application that uses asynchronous I/O.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define PORT 12345
#define MAX_EVENTS 10
#define MAX_BUFFER_SIZE 1024

// Declare the global epoll file descriptor.
int epoll_fd;

// Define our signal handler function, which is used to gracefully shut down the server.
void sigint_handler(int sig) {
    printf("\nShutting down server...\n");
    
    // Close the global epoll file descriptor.
    close(epoll_fd);
    
    // Terminate the program.
    exit(EXIT_SUCCESS);
}

int main(int argc, char** argv) {
    // Declare our server socket file descriptor and our client socket file descriptor.
    int server_fd, client_fd;
    
    // Declare our server address and our client address.
    struct sockaddr_in server_addr, client_addr;
    
    // Declare our epoll event structure and our epoll event array.
    struct epoll_event event, events[MAX_EVENTS];
    
    // Declare our buffer for receiving data.
    char buffer[MAX_BUFFER_SIZE];
    
    // Declare variables for keeping track of the number of bytes read and written.
    ssize_t num_bytes_read, num_bytes_written;
    
    // Set up the server address data structure.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // Create the server socket.
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    // Make the server socket reusable.
    int reuseaddr = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int)) == -1) {
        perror("Error setting server socket to be reusable");
        exit(EXIT_FAILURE);
    }
    
    // Bind the server socket to the server address.
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming client connections.
    if (listen(server_fd, SOMAXCONN) == -1) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    // Set up the epoll instance.
    if ((epoll_fd = epoll_create1(0)) == -1) {
        perror("Error creating epoll instance");
        exit(EXIT_FAILURE);
    }
    
    // Add the server socket file descriptor to the epoll instance.
    event.data.fd = server_fd;
    event.events = EPOLLIN;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
        perror("Error adding server socket to epoll instance");
        exit(EXIT_FAILURE);
    }
    
    // Set up our signal handler to gracefully shut down the server.
    signal(SIGINT, sigint_handler);
    
    // Enter the main event loop.
    while (1) {
        // Wait for incoming events.
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        
        if (num_events == -1) {
            perror("Error waiting for incoming events");
            exit(EXIT_FAILURE);
        }
        
        // Loop over all incoming events.
        for (int i = 0; i < num_events; i++) {
            // Check if this event is an incoming client connection.
            if (events[i].data.fd == server_fd) {
                socklen_t client_addr_len = sizeof(struct sockaddr_in);
                
                // Accept the incoming client connection.
                if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
                    perror("Error accepting incoming client connection");
                    exit(EXIT_FAILURE);
                }
                
                // Set the client socket to be non-blocking.
                int flags = fcntl(client_fd, F_GETFL, 0);
                fcntl(client_fd, F_SETFL, flags | O_NONBLOCK);
                
                // Add the client socket file descriptor to the epoll instance.
                event.data.fd = client_fd;
                event.events = EPOLLIN;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event) == -1) {
                    perror("Error adding client socket to epoll instance");
                    exit(EXIT_FAILURE);
                }
                
                printf("Incoming client connection from %s\n", inet_ntoa(client_addr.sin_addr));
            }
            // Otherwise, this is an existing client connection.
            else {
                // Loop over all incoming messages from the client.
                while ((num_bytes_read = recv(events[i].data.fd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
                    // Echo the message back to the client.
                    num_bytes_written = send(events[i].data.fd, buffer, num_bytes_read, 0);
                    
                    // Check for errors.
                    if (num_bytes_written == -1) {
                        perror("Error echoing message back to client");
                        exit(EXIT_FAILURE);
                    }
                }
                
                // Check if the connection was closed by the client.
                if (num_bytes_read == 0) {
                    printf("Client connection closed\n");
                    
                    // Remove the client socket file descriptor from the epoll instance.
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                    
                    // Close the client socket file descriptor.
                    close(events[i].data.fd);
                }
                
                // Check for other errors.
                if (num_bytes_read == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
                    perror("Error receiving message from client");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    
    // Close the server socket file descriptor.
    close(server_fd);
    
    // Terminate the program.
    exit(EXIT_SUCCESS);
}