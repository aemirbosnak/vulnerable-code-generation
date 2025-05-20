//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Function to create a TCP/IP socket
int create_tcp_socket(int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to accept a new connection
int accept_connection(int sockfd, struct sockaddr_in* client_addr, socklen_t* addr_len) {
    int new_sockfd;

    new_sockfd = accept(sockfd, client_addr, addr_len);
    if (new_sockfd < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    return new_sockfd;
}

// Function to send data to the client
int send_data(int sockfd, char* data, int length) {
    int sent;

    sent = send(sockfd, data, length, 0);
    if (sent < 0) {
        perror("Error sending data");
        exit(EXIT_FAILURE);
    }

    return sent;
}

// Function to receive data from the client
int receive_data(int sockfd, char* data, int length) {
    int received;

    received = recv(sockfd, data, length, 0);
    if (received < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }

    return received;
}

// Function to close a socket
void close_socket(int sockfd) {
    if (close(sockfd) < 0) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }
}

// Main program
int main(int argc, char* argv[]) {
    int sockfd, new_sockfd, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char data[100];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);

    sockfd = create_tcp_socket(port);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        new_sockfd = accept_connection(sockfd, &client_addr, &addr_len);
        if (new_sockfd < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("Connected to client with IP address: %s\n", inet_ntoa(client_addr.sin_addr));

        send_data(new_sockfd, "Hello from server!\n", 18);

        char* input = "Enter your message: ";
        recv(new_sockfd, input, 100, 0);
        printf("Received message: %s\n", input);

        printf("Sending message back to client...\n");
        send_data(new_sockfd, input, 100);

        close_socket(new_sockfd);
    }

    return 0;
}