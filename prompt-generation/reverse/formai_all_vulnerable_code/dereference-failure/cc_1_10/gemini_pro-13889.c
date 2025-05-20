//GEMINI-pro DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Define the maximum buffer size
#define MAX_BUFFER_SIZE 1024

// Define the port number
#define PORT "3490"  // Non-standard port for demonstration purposes

// Get the address info for the given hostname and port
struct addrinfo *get_address_info(const char *hostname, const char *port) {
    struct addrinfo hints, *result;

    // Initialize the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;  // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;  // TCP socket
    hints.ai_flags = AI_PASSIVE;  // For binding to a socket

    // Get the address info
    int status = getaddrinfo(hostname, port, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    return result;
}

// Create a socket and bind it to the given address
int create_and_bind_socket(struct addrinfo *address_info) {
    // Create the socket
    int sockfd = socket(address_info->ai_family, address_info->ai_socktype, address_info->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the address
    int bind_status = bind(sockfd, address_info->ai_addr, address_info->ai_addrlen);
    if (bind_status == -1) {
        perror("bind");
        exit(1);
    }

    // Return the socket file descriptor
    return sockfd;
}

// Listen for incoming connections on the given socket
void listen_for_connections(int sockfd) {
    // Listen for incoming connections
    int listen_status = listen(sockfd, 5);  // Queue up to 5 incoming connections
    if (listen_status == -1) {
        perror("listen");
        exit(1);
    }

    printf("Listening for incoming connections on port %s...\n", PORT);
}

// Accept an incoming connection on the given socket
int accept_connection(int sockfd) {
    // Accept an incoming connection
    struct sockaddr_storage client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
        perror("accept");
        exit(1);
    }

    // Get the client's IP address and port
    char client_ip[INET6_ADDRSTRLEN];
    int port;
    if (client_addr.ss_family == AF_INET) {
        struct sockaddr_in *client_addr_ipv4 = (struct sockaddr_in *)&client_addr;
        inet_ntop(AF_INET, &client_addr_ipv4->sin_addr, client_ip, INET6_ADDRSTRLEN);
        port = ntohs(client_addr_ipv4->sin_port);
    } else if (client_addr.ss_family == AF_INET6) {
        struct sockaddr_in6 *client_addr_ipv6 = (struct sockaddr_in6 *)&client_addr;
        inet_ntop(AF_INET6, &client_addr_ipv6->sin6_addr, client_ip, INET6_ADDRSTRLEN);
        port = ntohs(client_addr_ipv6->sin6_port);
    }

    // Print the client's IP address and port
    printf("Connection accepted from %s:%d\n", client_ip, port);

    // Return the client socket file descriptor
    return client_sockfd;
}

// Receive data from the given socket
int receive_data(int sockfd, char *buffer, int buffer_size) {
    // Receive data from the socket
    int recv_status = recv(sockfd, buffer, buffer_size, 0);
    if (recv_status == -1) {
        perror("recv");
        exit(1);
    }

    // Return the number of bytes received
    return recv_status;
}

// Send data to the given socket
int send_data(int sockfd, const char *data, int data_len) {
    // Send data to the socket
    int send_status = send(sockfd, data, data_len, 0);
    if (send_status == -1) {
        perror("send");
        exit(1);
    }

    // Return the number of bytes sent
    return send_status;
}

// Close the given socket
void close_socket(int sockfd) {
    // Close the socket
    int close_status = close(sockfd);
    if (close_status == -1) {
        perror("close");
        exit(1);
    }
}

// Free the address info
void free_address_info(struct addrinfo *address_info) {
    // Free the address info
    freeaddrinfo(address_info);
}

// Main function
int main(int argc, char *argv[]) {
    // Get the address info for the given hostname and port
    struct addrinfo *address_info = get_address_info(NULL, PORT);

    // Create a socket and bind it to the given address
    int sockfd = create_and_bind_socket(address_info);

    // Listen for incoming connections on the given socket
    listen_for_connections(sockfd);

    // Accept an incoming connection on the given socket
    int client_sockfd = accept_connection(sockfd);

    // Receive data from the client
    char buffer[MAX_BUFFER_SIZE];
    int recv_status = receive_data(client_sockfd, buffer, MAX_BUFFER_SIZE);

    // Print the received data
    printf("Received data: %s\n", buffer);

    // Send data to the client
    const char *response = "Hello from the server!";
    int send_status = send_data(client_sockfd, response, strlen(response));

    // Close the client socket
    close_socket(client_sockfd);

    // Close the server socket
    close_socket(sockfd);

    // Free the address info
    free_address_info(address_info);

    return 0;
}