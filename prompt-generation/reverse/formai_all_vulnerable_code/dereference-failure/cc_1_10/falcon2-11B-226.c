//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Function to receive data from client
void receive_data(int sockfd, char *buffer, int len) {
    int n = recv(sockfd, buffer, len, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    printf("Received data: %s\n", buffer);
}

// Function to send data to client
void send_data(int sockfd, char *buffer, int len) {
    int n = send(sockfd, buffer, len, 0);
    if (n < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    printf("Sent data: %s\n", buffer);
}

// Function to establish a connection with the client
int establish_connection(char *host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    int n = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (n < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char host[256];
    int port = atoi(argv[2]);

    int sockfd = establish_connection(host, port);
    if (sockfd < 0) {
        perror("Failed to establish connection");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int len = sizeof(buffer);

    // Receive data from client
    receive_data(sockfd, buffer, len);

    // Send data to client
    send_data(sockfd, buffer, len);

    close(sockfd);
    return 0;
}