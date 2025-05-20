//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int client_fd;

void handle_signal(int signal) {
    close(client_fd);
    printf("\nConnection closed.\n");
    exit(0);
}

void handle_data(void *data, int len) {
    write(client_fd, data, len);
}

int main(int argc, char const *argv[]) {
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int opt = 1;

    // Create socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Set socket to non-blocking
    if (fcntl(client_fd, F_SETFL, O_NONBLOCK) < 0) {
        perror("Can't set socket to non-blocking");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    memset(&server, '0', sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_fd, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Connected to server!\n");
    } else if (errno != EINPROGRESS) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    // Wait for connection to succeed or fail
    fd_set set;
    FD_ZERO(&set);          /* clear the set */
    FD_SET(client_fd, &set);/* add our file descriptor to the set */
    struct timeval timeout = {10, 0}; /* timeout after 10 seconds */
    if (select(client_fd+1, NULL, &set, NULL, &timeout) == 1) {
        int val;
        socklen_t len = sizeof(val);
        getsockopt(client_fd, SOL_SOCKET, SO_ERROR, &val, &len);
        if (val != 0) {
            perror("Connection error");
            exit(EXIT_FAILURE);
        } else {
            printf("Connected to server!\n");
        }
    } else {
        perror("Connection timeout");
        exit(EXIT_FAILURE);
    }
    
    // Set up signal handler
    signal(SIGINT, handle_signal);

    // Wait for input
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // Read user input
        printf("Enter a string to send to the server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';

        // Write input to server
        handle_data(buffer, strlen(buffer));

        // Read response from server
        int rc = read(client_fd, buffer, BUFFER_SIZE);

        // Handle response
        if (rc < 0) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                perror("Read error");
                exit(EXIT_FAILURE);
            }
        } else if (rc > 0) {
            printf("Server response: %s\n", buffer);
        }
    }

    return 0;
}