//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_PENDING_REQUESTS 10
#define MAX_BUFFER 1024

volatile int running = 1;

void handle_signal(int signal) {
    running = 0;
}

int main(int argc, char **argv) {
    int sockfd, connfd;
    struct sockaddr_in server_address, client_address;
    pid_t pid;
    socklen_t client_address_length;
    char buffer[MAX_BUFFER];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));

    // Filling server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket with server address
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening on socket
    if (listen(sockfd, MAX_PENDING_REQUESTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_signal);

    // Accepting incoming connections
    while (running) {
        client_address_length = sizeof(client_address);
        if ((connfd = accept(sockfd, (struct sockaddr *) &client_address, &client_address_length)) < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            close(sockfd);

            // Receiving data from client
            memset(buffer, 0, MAX_BUFFER);
            if (recv(connfd, buffer, MAX_BUFFER, 0) < 0) {
                perror("Receive failed");
                close(connfd);
                exit(EXIT_FAILURE);
            }

            printf("Received data: %s", buffer);

            // Responding to client
            if (send(connfd, "Data received!", strlen("Data received!"), 0) < 0) {
                perror("Send failed");
                close(connfd);
                exit(EXIT_FAILURE);
            }

            close(connfd);
            exit(EXIT_SUCCESS);
        } else {
            close(connfd);
        }
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}