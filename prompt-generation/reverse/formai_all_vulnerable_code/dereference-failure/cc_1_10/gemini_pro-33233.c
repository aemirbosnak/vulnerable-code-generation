//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Create a socket
int create_socket(int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Socket structure for server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Accept a client connection
int accept_connection(int sockfd) {
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);

    // Accept the client connection
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    return connfd;
}

// Send data to the client
void send_data(int sockfd, char *data) {
    if (send(sockfd, data, strlen(data), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
}

// Receive data from the client
char *receive_data(int sockfd) {
    char *data = (char *)malloc(1024);
    int n = recv(sockfd, data, 1024, 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    data[n] = '\0';
    return data;
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, connfd;
    char *data;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = create_socket(atoi(argv[1]));

    // Listen for client connections
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a client connection
        connfd = accept_connection(sockfd);

        // Receive data from the client
        data = receive_data(connfd);

        // Process the data
        printf("Received data: %s\n", data);

        // Send data to the client
        send_data(connfd, "Hello from server");

        // Close the client connection
        close(connfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}