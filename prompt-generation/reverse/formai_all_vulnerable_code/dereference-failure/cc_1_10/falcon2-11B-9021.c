//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

// Function to establish a TCP connection
int connect_to_server(const char *hostname, int port) {
    struct hostent *server;
    struct sockaddr_in server_addr;

    if ((server = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Failed to create socket\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function to send a request to the server
void send_request(int sockfd, const char *url) {
    char request[512];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url, url);

    int num_bytes_sent = send(sockfd, request, strlen(request), 0);
    if (num_bytes_sent < 0) {
        fprintf(stderr, "Error: Failed to send request\n");
        exit(1);
    }
}

// Function to receive the response from the server
void receive_response(int sockfd, char *buffer, int max_length) {
    char *p = buffer;
    char c;
    int num_bytes_received = 0;

    while (num_bytes_received < max_length && (c = recv(sockfd, &p, 1, 0)) > 0) {
        *p++ = c;
        num_bytes_received++;
    }

    if (num_bytes_received == max_length) {
        fprintf(stderr, "Error: Request timed out\n");
        exit(1);
    }
}

// Function to print the response
void print_response(int sockfd, char *buffer, int length) {
    int i;

    for (i = 0; i < length; i++) {
        if (buffer[i] == '\n') {
            printf("%s\n", buffer + i - 1);
            i++;
        }
        else {
            printf("%c", buffer[i]);
        }
    }
}

// Main function
int main() {
    int sockfd, port, num_bytes_sent, num_bytes_received, length;
    char buffer[1024], url[256], hostname[256];

    printf("Enter the URL: ");
    scanf("%s", url);

    sockfd = connect_to_server("www.example.com", 80);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Failed to establish connection to server\n");
        exit(1);
    }

    send_request(sockfd, url);

    length = sizeof(buffer);
    receive_response(sockfd, buffer, length);
    print_response(sockfd, buffer, length);

    close(sockfd);
    return 0;
}