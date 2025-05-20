//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: romantic
// Chat Server Example Program
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <poll.h>

// Function to create socket and bind to a port
int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error binding to port");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to accept incoming connections
int accept_connections(int sockfd) {
    int new_socket;
    struct sockaddr_in client_addr;
    int addr_size = sizeof(client_addr);
    int status;
    pid_t pid;

    new_socket = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
    if (new_socket == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    if (new_socket > 0) {
        pid = fork();
        if (pid == 0) {
            close(sockfd);
            dup2(new_socket, 0);
            dup2(new_socket, 1);
            dup2(new_socket, 2);
            close(new_socket);
            execvp("./chat_client", NULL);
            perror("Error executing chat client");
            exit(EXIT_FAILURE);
        } else {
            close(new_socket);
            waitpid(pid, &status, 0);
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, new_socket;
    struct sockaddr_in serv_addr, client_addr;
    int addr_size, port;
    char buffer[1024];

    // Parse command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);

    // Create socket and bind to a port
    sockfd = create_socket(port);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        accept_connections(sockfd);
    }

    return 0;
}