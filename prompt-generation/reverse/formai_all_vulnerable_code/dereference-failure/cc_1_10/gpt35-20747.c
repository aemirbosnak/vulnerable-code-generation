//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: genious
// A genius-style HTTP client example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to create a HTTP request message
char *create_http_request(char *host, char *path) {
    char *request = (char *) malloc(sizeof(char) * 500);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)\r\nAccept: */*\r\nConnection: close\r\n\r\n", path, host);
    return request;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("USAGE: %s [HOSTNAME] [PATH]\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *path = argv[2];

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        return 1;
    }

    // Specify server details
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    int res = inet_pton(AF_INET, host, &server_addr.sin_addr);
    if (res == -1) {
        perror("Failed to set server address");
        return 1;
    }

    // Connect to the server
    int conn_res = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (conn_res == -1) {
        perror("Failed to connect to server");
        return 1;
    }

    // Create HTTP request
    char *http_request = create_http_request(host, path);

    // Send HTTP request to server
    int bytes_sent = send(sockfd, http_request, strlen(http_request), 0);

    // Receive server response
    char response[1024];
    int bytes_received = 0;
    int total_bytes_received = 0;
    while ((bytes_received = recv(sockfd, response + total_bytes_received, 1024, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    // Print server response
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}