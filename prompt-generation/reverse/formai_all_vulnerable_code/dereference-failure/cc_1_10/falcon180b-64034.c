//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

// Function prototypes
void *handle_client(void *socket_desc);
int create_socket(int port);

int main(int argc, char **argv) {
    int opt = 1;
    int listener = 0;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    listener = create_socket(8080);

    puts("HTTP Proxy is listening on port 8080...");

    // Accept incoming connections and handle them in separate threads
    while (1) {
        socklen_t client_size = sizeof(address);
        int client = accept(listener, (struct sockaddr *)&address, &client_size);

        if (client < 0) {
            perror("accept");
        } else {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)client);
        }
    }

    return 0;
}

// Function to handle each client connection
void *handle_client(void *socket_desc) {
    int sock = *(int *) socket_desc;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        send(sock, buffer, bytes_received, 0);
    }

    close(sock);
    return NULL;
}

// Function to create socket
int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}