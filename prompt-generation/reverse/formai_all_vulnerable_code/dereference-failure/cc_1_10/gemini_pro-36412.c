//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    // Parse arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <client IP> <client port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *client_ip = argv[1];
    int client_port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Print the client IP and port
    printf("Connected to client at %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from the client
    char buf[MAX_BUF_SIZE];
    int num_bytes_received;

    while ((num_bytes_received = recv(client_sockfd, buf, MAX_BUF_SIZE, 0)) > 0) {
        // Echo the data back to the client
        if (send(client_sockfd, buf, num_bytes_received, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    if (num_bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the client socket
    close(client_sockfd);

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}