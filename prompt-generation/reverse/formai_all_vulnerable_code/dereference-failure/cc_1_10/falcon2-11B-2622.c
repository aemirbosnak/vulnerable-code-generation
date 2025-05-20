//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to establish a TCP connection with the server
int establish_connection(char* server_ip, int server_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function to send a HTTP request to the server
void send_request(int sockfd, char* request) {
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Error sending request");
    }
}

// Function to receive and print the HTTP response from the server
void receive_response(int sockfd) {
    char buffer[1024];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Error receiving response");
    }

    printf("HTTP Response: %s\n", buffer);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <client_ip> <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    char* client_ip = argv[1];
    char* server_ip = argv[2];
    int server_port = atoi(argv[3]);

    // Establish a TCP connection with the server
    int sockfd = establish_connection(server_ip, server_port);
    if (sockfd < 0) {
        return 1;
    }

    // Send the HTTP request
    char request[] = "GET / HTTP/1.1\r\nHost: ";
    request[strlen(request) - 1] = '\r';
    request[strlen(request) - 2] = '\n';
    request[strlen(request) - 3] = '\0';
    strcat(request, server_ip);
    send_request(sockfd, request);

    // Receive and print the HTTP response
    receive_response(sockfd);

    close(sockfd);
    return 0;
}