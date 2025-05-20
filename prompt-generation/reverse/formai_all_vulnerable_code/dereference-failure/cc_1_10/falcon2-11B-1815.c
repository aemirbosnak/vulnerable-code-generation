//Falcon2-11B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

// Function to send a message to a remote server
void send_message(int sockfd, const char *message) {
    int n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }
}

// Function to receive a message from a remote server
int receive_message(int sockfd, char *message, int max_length) {
    int n = recv(sockfd, message, max_length, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(1);
    }
    return n;
}

// Function to establish a TCP connection with a remote server
int connect_to_server(const char *server_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_address);

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    return sockfd;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    const char *server_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = connect_to_server(server_address, port);
    if (sockfd < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    char message[256];
    printf("Enter a message to send to the server: ");
    fgets(message, sizeof(message), stdin);

    send_message(sockfd, message);

    char received_message[256];
    int n = receive_message(sockfd, received_message, sizeof(received_message));
    if (n <= 0) {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received message from server: %s\n", received_message);

    close(sockfd);
    return 0;
}