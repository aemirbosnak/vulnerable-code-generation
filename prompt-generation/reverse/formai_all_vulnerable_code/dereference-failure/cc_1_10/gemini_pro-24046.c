//GEMINI-pro DATASET v1.0 Category: Networking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUF_SIZE 1024

// Get the IP address of a hostname
char *get_ip_address(char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        exit(1);
    }
    return inet_ntoa(*((struct in_addr *) host->h_addr));
}

// Send an HTTP GET request to a server
void send_http_get_request(int sockfd, char *hostname, char *path) {
    char request[BUF_SIZE];
    snprintf(request, BUF_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    send(sockfd, request, strlen(request), 0);
}

// Receive the HTTP response from a server
int receive_http_response(int sockfd) {
    char buffer[BUF_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        printf("%s", buffer);
    }
    return bytes_received;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname path\n", argv[0]);
        exit(1);
    }

    // Get the IP address of the hostname
    char *ip_address = get_ip_address(argv[1]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send an HTTP GET request to the server
    send_http_get_request(sockfd, argv[1], argv[2]);

    // Receive the HTTP response from the server
    int bytes_received = receive_http_response(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}