//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

// Create a socket
int create_socket(int domain, int type, int protocol) {
    int sockfd = socket(domain, type, protocol);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }
    return sockfd;
}

// Bind a socket to an address
int bind_socket(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int ret = bind(sockfd, addr, addrlen);
    if (ret == -1) {
        perror("bind");
        return -1;
    }
    return 0;
}

// Listen for incoming connections on a socket
int listen_socket(int sockfd, int backlog) {
    int ret = listen(sockfd, backlog);
    if (ret == -1) {
        perror("listen");
        return -1;
    }
    return 0;
}

// Accept a connection on a socket
int accept_connection(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int newsockfd = accept(sockfd, addr, addrlen);
    if (newsockfd == -1) {
        perror("accept");
        return -1;
    }
    return newsockfd;
}

// Send data on a socket
int send_data(int sockfd, const void *buf, size_t buflen, int flags) {
    int ret = send(sockfd, buf, buflen, flags);
    if (ret == -1) {
        perror("send");
        return -1;
    }
    return ret;
}

// Receive data on a socket
int recv_data(int sockfd, void *buf, size_t buflen, int flags) {
    int ret = recv(sockfd, buf, buflen, flags);
    if (ret == -1) {
        perror("recv");
        return -1;
    }
    return ret;
}

// Close a socket
int close_socket(int sockfd) {
    int ret = close(sockfd);
    if (ret == -1) {
        perror("close");
        return -1;
    }
    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <message>\n", argv[0]);
        return -1;
    }

    // Get the port number from the command line
    int port = atoi(argv[1]);

    // Get the message to send from the command line
    char *message = argv[2];

    // Create a new socket
    int sockfd = create_socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    // Set the socket options
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind_socket(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return -1;
    }

    // Listen for incoming connections
    if (listen_socket(sockfd, 5) == -1) {
        return -1;
    }

    // Accept a new connection
    struct sockaddr_in client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    int newsockfd = accept_connection(sockfd, (struct sockaddr *)&client_addr, &client_addrlen);
    if (newsockfd == -1) {
        return -1;
    }

    // Send the message to the client
    if (send_data(newsockfd, message, strlen(message), 0) == -1) {
        return -1;
    }

    // Receive a message from the client
    char buf[1024];
    int ret = recv_data(newsockfd, buf, sizeof(buf), 0);
    if (ret == -1) {
        return -1;
    }

    // Print the message from the client
    printf("Received message: %s\n", buf);

    // Close the new socket
    if (close_socket(newsockfd) == -1) {
        return -1;
    }

    // Close the original socket
    if (close_socket(sockfd) == -1) {
        return -1;
    }

    return 0;
}