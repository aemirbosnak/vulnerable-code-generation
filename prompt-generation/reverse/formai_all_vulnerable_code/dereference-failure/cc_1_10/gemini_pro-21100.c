//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Define the maximum length of the message
#define MAX_MSG_LEN 1024

// Create a socket
int create_socket() {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Bind the socket to an address and port
void bind_socket(int sockfd, const char *ip, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listen_socket(int sockfd) {
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (newsockfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    return newsockfd;
}

// Send a message to a client
void send_message(int sockfd, const char *msg) {
    int len = strlen(msg);
    if (send(sockfd, msg, len, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from a client
char *receive_message(int sockfd) {
    char *msg = malloc(MAX_MSG_LEN);
    int len = recv(sockfd, msg, MAX_MSG_LEN, 0);
    if (len == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    msg[len] = '\0';
    return msg;
}

// Close a socket
void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address and port from the command line
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = create_socket();

    // Bind the socket to an address and port
    bind_socket(sockfd, ip, port);

    // Listen for incoming connections
    listen_socket(sockfd);

    // Accept an incoming connection
    int newsockfd = accept_connection(sockfd);

    // Send a message to the client
    send_message(newsockfd, "Hello from the server!\n");

    // Receive a message from the client
    char *msg = receive_message(newsockfd);
    printf("Received message from client: %s\n", msg);

    // Close the socket
    close_socket(newsockfd);
    close_socket(sockfd);

    // Free the allocated memory
    free(msg);

    return 0;
}