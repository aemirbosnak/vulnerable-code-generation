//GEMINI-pro DATASET v1.0 Category: Networking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Create a TCP socket
int create_tcp_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
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
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listen_socket(int sockfd) {
    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

// Accept a new connection
int accept_connection(int sockfd) {
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&addr, &addr_len);
    if (newsockfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    return newsockfd;
}

// Send data to a socket
int send_data(int sockfd, const char *data, size_t data_len) {
    int sent = send(sockfd, data, data_len, 0);
    if (sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    return sent;
}

// Receive data from a socket
int receive_data(int sockfd, char *buffer, size_t buffer_len) {
    int received = recv(sockfd, buffer, buffer_len, 0);
    if (received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    return received;
}

// Close a socket
void close_socket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    int sockfd = create_tcp_socket();

    // Bind the socket to an address and port
    bind_socket(sockfd, argv[1], atoi(argv[2]));

    // Listen for incoming connections
    listen_socket(sockfd);

    // Accept a new connection
    int newsockfd = accept_connection(sockfd);

    // Send data to the client
    const char *data = "Hello, world!";
    int sent = send_data(newsockfd, data, strlen(data));
    printf("Sent %d bytes of data\n", sent);

    // Receive data from the client
    char buffer[1024];
    int received = receive_data(newsockfd, buffer, sizeof(buffer));
    printf("Received %d bytes of data: %s\n", received, buffer);

    // Close the sockets
    close_socket(newsockfd);
    close_socket(sockfd);

    return EXIT_SUCCESS;
}