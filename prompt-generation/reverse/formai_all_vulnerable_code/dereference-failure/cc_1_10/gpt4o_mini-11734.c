//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to perform DNS resolution
char *resolve_hostname(const char *hostname) {
    struct hostent *host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        perror("gethostbyname");
        return NULL;
    }
    return inet_ntoa(*(struct in_addr *)host_entry->h_addr_list[0]);
}

// Function to create a socket connection
int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    char *ip_address = resolve_hostname(hostname);
    if (ip_address == NULL) {
        close(sockfd);
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function to send an HTTP request
void send_http_request(int sockfd, const char *hostname) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", hostname);

    send(sockfd, request, strlen(request), 0);
}

// Function to read the response from the server
void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null terminate the buffer
        printf("%s", buffer); // Print the response to stdout
    }
    
    if (bytes_received < 0) {
        perror("recv failed");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sockfd = create_socket(hostname, port);
    if (sockfd < 0) {
        exit(EXIT_FAILURE);
    }

    send_http_request(sockfd, hostname);
    read_response(sockfd);

    close(sockfd);
    return 0;
}