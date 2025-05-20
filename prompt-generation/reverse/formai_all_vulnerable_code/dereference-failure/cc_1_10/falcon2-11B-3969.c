//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to send a message to the server
void send_message(int sockfd, char* message) {
    int n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("send():");
    }
}

// Function to receive a message from the server
char* receive_message(int sockfd) {
    char buffer[1024];
    int n = recv(sockfd, buffer, 1024, 0);
    if (n < 0) {
        perror("recv():");
    }
    char* message = malloc(n + 1);
    strncpy(message, buffer, n);
    message[n] = '\0';
    return message;
}

// Function to connect to the server
int connect_to_server(char* hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket():");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect():");
        exit(1);
    }
    return sockfd;
}

// Main function
int main(int argc, char* argv[]) {
    char* hostname = argv[1];
    int port = atoi(argv[2]);
    int sockfd = connect_to_server(hostname, port);
    char* message = "hello";
    send_message(sockfd, message);
    char* response = receive_message(sockfd);
    printf("%s\n", response);
    close(sockfd);
    return 0;
}