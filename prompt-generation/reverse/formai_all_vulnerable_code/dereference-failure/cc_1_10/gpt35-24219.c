//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024

/* This function takes an IP address and a port number as input and tries to establish connection with the
   specified server. It returns a socket descriptor that can be used to exchange data with the server */
int connect_to_server(char* server_ip, int port) {
    struct sockaddr_in server_addr;

    // create a socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Error occurred while creating the socket");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Error while setting server address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", server_ip, port);
    return sock_fd;
}

/* This function sends a message to a connected server */
void send_message(int sock_fd, char* message) {
    size_t message_len = strlen(message);
    if (send(sock_fd, message, message_len, 0) < 0) {
        perror("Error occurred while sending the message to server");
    } else {
        printf("Message sent: %s", message);
    }
}

/* This function receives a message from a connected server */
char* receive_message(int sock_fd) {
    char* buffer = (char*)malloc(sizeof(char)*MAX_PACKET_SIZE);
    int bytes_received = recv(sock_fd, buffer, MAX_PACKET_SIZE-1, 0);
    if (bytes_received <= 0) {
        perror("Error occurred while receiving the message from server");
    } else {
        buffer[bytes_received] = '\0';
        printf("Message received: %s", buffer);
    }
    return buffer;
}

/* This function closes the connection with the server */
void close_connection(int sock_fd) {
    if (close(sock_fd) < 0) {
        perror("Error occurred while closing the connection");
    } else {
        printf("Connection closed successfully\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s server_ip port_number\n", argv[0]);
        return 0;
    }
    char* server_ip = argv[1];
    int port = atoi(argv[2]);

    // connect to server
    int sock_fd = connect_to_server(server_ip, port);

    // send and receive messages
    send_message(sock_fd, "Hello, server!\n");
    char* response = receive_message(sock_fd);
    free(response);

    // close connection
    close_connection(sock_fd);

    return 0;
}