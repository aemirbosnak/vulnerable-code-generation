//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main() {
    int sockfd, bytes_received = 0, bytes_sent = 0;
    char buffer[BUFFER_SIZE];
    struct addrinfo *server_info;
    struct sockaddr *server_addr;
    int server_addr_size;

    printf("Initializing...\n");

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error initializing socket!\n");
        return 1;
    }

    printf("Resolving server address...\n");

    // Resolve server address
    if (getaddrinfo(SERVER_IP, "http", &server_info, NULL)!= 0) {
        printf("Error resolving server address!\n");
        return 1;
    }

    server_addr = server_info->ai_addr;
    server_addr_size = server_info->ai_addrlen;

    printf("Connecting to server...\n");

    // Connect to server
    if (connect(sockfd, server_addr, server_addr_size) == -1) {
        printf("Error connecting to server!\n");
        return 1;
    }

    printf("Connected to server!\n");

    char *request = "GET /speedtest.php HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n";

    bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent == -1) {
        printf("Error sending request!\n");
        return 1;
    }

    printf("Request sent successfully!\n");

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving response!\n");
        return 1;
    }

    printf("Response received successfully!\n");

    close(sockfd);

    return 0;
}