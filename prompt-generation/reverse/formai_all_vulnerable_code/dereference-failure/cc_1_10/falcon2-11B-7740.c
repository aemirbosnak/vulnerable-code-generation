//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to create a socket
int create_socket(int domain, int type, int protocol) {
    int sockfd;
    if ((sockfd = socket(domain, type, protocol)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to connect to a server
int connect_to_server(int sockfd, const char* server_addr, int port) {
    if (connect(sockfd, (struct sockaddr*)server_addr, sizeof(struct sockaddr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to send a message to the server
int send_message(int sockfd, const char* message) {
    if (write(sockfd, message, strlen(message)) < 0) {
        perror("Message sending failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to receive a message from the server
int receive_message(int sockfd, char* message, int len) {
    if (read(sockfd, message, len) < 0) {
        perror("Message receiving failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to close a socket
int close_socket(int sockfd) {
    if (close(sockfd) < 0) {
        perror("Socket closing failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_addr> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int domain = AF_INET;
    int type = SOCK_STREAM;
    int protocol = 0;
    int sockfd, connfd;

    // Create a socket
    sockfd = create_socket(domain, type, protocol);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    connfd = connect_to_server(sockfd, argv[1], atoi(argv[2]));
    if (connfd < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char message[100];
    sprintf(message, "USER %s\r\n", argv[1]);
    send_message(connfd, message);

    // Receive a message from the server
    char recv_message[100];
    if (receive_message(connfd, recv_message, sizeof(recv_message)) == -1) {
        perror("Message receiving failed");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close_socket(connfd);
    close_socket(sockfd);

    return 0;
}