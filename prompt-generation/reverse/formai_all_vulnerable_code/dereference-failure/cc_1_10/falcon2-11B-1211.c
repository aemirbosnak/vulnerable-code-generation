//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

void send_data(int sockfd, char* buffer, int size) {
    int bytes_sent;
    bytes_sent = send(sockfd, buffer, size, 0);
    if (bytes_sent < 0) {
        perror("send():");
        exit(EXIT_FAILURE);
    }
    printf("Sent %d bytes.\n", bytes_sent);
}

void receive_data(int sockfd, char* buffer, int size) {
    int bytes_received;
    bytes_received = recv(sockfd, buffer, size, 0);
    if (bytes_received < 0) {
        perror("recv():");
        exit(EXIT_FAILURE);
    }
    printf("Received %d bytes.\n", bytes_received);
}

void client_loop(int sockfd) {
    char buffer[256];
    int bytes_read;
    while (1) {
        bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_read < 0) {
            perror("recv():");
            exit(EXIT_FAILURE);
        }
        printf("Received: %s\n", buffer);
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
        send_data(sockfd, buffer, strlen(buffer) + 1);
    }
}

int main(int argc, char* argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket():");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect():");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    client_loop(sockfd);

    close(sockfd);

    return 0;
}