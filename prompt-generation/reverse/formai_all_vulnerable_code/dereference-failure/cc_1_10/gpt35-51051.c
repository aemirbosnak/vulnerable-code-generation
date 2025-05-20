//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define HTTP_PORT 80

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];

    // Resolve hostname to IP address
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP
    struct addrinfo *result;
    int error = getaddrinfo(hostname, NULL, &hints, &result);
    if (error != 0) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", gai_strerror(error));
        exit(EXIT_FAILURE);
    }

    char ip_str[INET_ADDRSTRLEN];
    struct sockaddr_in *ipv4_addr = (struct sockaddr_in *) result->ai_addr;
    inet_ntop(AF_INET, &(ipv4_addr->sin_addr), ip_str, INET_ADDRSTRLEN);
    printf("Resolved %s to IP address %s\n", hostname, ip_str);

    freeaddrinfo(result);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = ipv4_addr->sin_addr.s_addr;
    server_addr.sin_port = htons(HTTP_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    char *request_data = "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: curl/7.68.0\r\nAccept: */*\r\n\r\n";
    char request[strlen(request_data) + strlen(hostname)];
    sprintf(request, request_data, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        exit(EXIT_FAILURE);
    }

    char response[4096];
    int total_bytes_received = 0;
    int bytes_received;
    while ((bytes_received = recv(sockfd, response + total_bytes_received, sizeof(response) - total_bytes_received, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    if (bytes_received < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    response[total_bytes_received] = '\0';
    printf("Received %d bytes:\n%s", total_bytes_received, response);

    close(sockfd);

    return 0;
}