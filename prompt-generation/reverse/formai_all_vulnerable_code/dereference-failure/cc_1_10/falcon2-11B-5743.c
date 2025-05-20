//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <string.h>

#define PORT 8080

// Function to handle incoming requests
void start_proxy(int port) {
    // Create socket to listen for incoming connections
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Error binding socket to port\n");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    int client_fd;
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    client_fd = accept(sockfd, (struct sockaddr *)&client, &client_len);
    if (client_fd < 0) {
        fprintf(stderr, "Error accepting connection\n");
        exit(EXIT_FAILURE);
    }

    // Spawn a new process for each connection
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error forking process\n");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Close the parent socket
        close(sockfd);

        // Handle the proxy server logic for this connection
        char buffer[1024];
        int read_size = recv(client_fd, buffer, sizeof(buffer), 0);
        if (read_size < 0) {
            fprintf(stderr, "Error reading from client\n");
            exit(EXIT_FAILURE);
        }
        buffer[read_size] = '\0';
        printf("Client request: %s\n", buffer);

        // Connect to the server
        int server_fd;
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0) {
            fprintf(stderr, "Error creating socket for server\n");
            exit(EXIT_FAILURE);
        }
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(8080);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            fprintf(stderr, "Error connecting to server\n");
            exit(EXIT_FAILURE);
        }

        // Forward the client request to the server
        int send_size = send(server_fd, buffer, read_size, 0);
        if (send_size < 0) {
            fprintf(stderr, "Error sending to server\n");
            exit(EXIT_FAILURE);
        }

        // Read the server response
        char server_response[1024];
        read_size = recv(server_fd, server_response, sizeof(server_response), 0);
        if (read_size < 0) {
            fprintf(stderr, "Error reading from server\n");
            exit(EXIT_FAILURE);
        }
        server_response[read_size] = '\0';
        printf("Server response: %s\n", server_response);

        // Send the server response back to the client
        send_size = send(client_fd, server_response, read_size, 0);
        if (send_size < 0) {
            fprintf(stderr, "Error sending to client\n");
            exit(EXIT_FAILURE);
        }

        // Close the client socket
        close(client_fd);
        exit(EXIT_SUCCESS);
    }

    // Close the parent socket
    close(sockfd);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
    int port = PORT;
    static struct option long_options[] = {
        {"port", required_argument, NULL, 'p'},
        {NULL, 0, NULL, 0}
    };
    int option_index = 0;
    while (1) {
        int c = getopt_long(argc, argv, "p:", long_options, &option_index);
        if (c == -1) {
            break;
        }
        switch (c) {
            case 'p':
                port = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -p <port>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    start_proxy(port);

    return 0;
}