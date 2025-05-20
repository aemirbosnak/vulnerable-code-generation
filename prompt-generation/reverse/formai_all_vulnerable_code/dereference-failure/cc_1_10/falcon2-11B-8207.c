//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Create a socket
int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Get the IP address of the server
void get_ip_address(struct sockaddr_in *server_addr, char *ip_address) {
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr->sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}

// Set the IP address of the server
void set_ip_address(struct sockaddr_in *server_addr, char *ip_address) {
    if (inet_pton(AF_INET, ip_address, &server_addr->sin_addr) <= 0) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}

// Bind the socket to the server address
void bind_socket(int sockfd, struct sockaddr_in *server_addr) {
    if (bind(sockfd, server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listen_for_connections(int sockfd, int backlog) {
    if (listen(sockfd, backlog) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

// Accept a connection from a client
int accept_connection(int sockfd, struct sockaddr_in *client_addr, socklen_t *client_addr_len) {
    int newsockfd;
    if ((newsockfd = accept(sockfd, client_addr, client_addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return newsockfd;
}

// Send a message to a client
void send_message(int sockfd, char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from a client
char *receive_message(int sockfd) {
    char *msg = NULL;
    int len;
    if ((len = recv(sockfd, msg, 1024, 0)) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    msg = realloc(msg, len + 1);
    msg[len] = '\0';
    return msg;
}

// Close a socket
void close_socket(int sockfd) {
    if (close(sockfd) < 0) {
        perror("close failed");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    // Create a socket
    int sockfd = create_socket();

    // Get the IP address of the server
    struct sockaddr_in server_addr;
    get_ip_address(&server_addr, "127.0.0.1");

    // Set the IP address of the server
    set_ip_address(&server_addr, "0.0.0.0");

    // Bind the socket to the server address
    bind_socket(sockfd, &server_addr);

    // Listen for incoming connections
    int backlog = 5;
    listen_for_connections(sockfd, backlog);

    // Accept a connection from a client
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(struct sockaddr_in);
    int newsockfd = accept_connection(sockfd, &client_addr, &client_addr_len);

    // Send a message to the client
    char msg[] = "Welcome to the C Chat Server!";
    send_message(newsockfd, msg);

    // Receive a message from the client
    char *msg_from_client = receive_message(newsockfd);

    // Close the socket
    close_socket(newsockfd);

    printf("Message from client: %s\n", msg_from_client);

    return 0;
}