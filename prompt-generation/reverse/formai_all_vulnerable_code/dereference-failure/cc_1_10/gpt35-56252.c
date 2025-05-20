//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void send_request(int sockfd, const char* request_header, const char* host);
void receive_response(int sockfd, char* response, int response_size);

void error(const char *str) {
    perror(str);
    exit(1);
}

int connect_to_server(const char* server, int port) {
    // Create a socket for HTTP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not create socket");
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        error("Could not resolve server host");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error("Could not connect to server");
    }

    return sockfd;
}

void send_request(int sockfd, const char* request_header, const char* host) {
    // Send the request to the server
    int len = strlen(request_header);
    int sent = send(sockfd, request_header, len, 0);
    if (sent < 0) {
        error("Could not send request to server");
    }
}

void receive_response(int sockfd, char* response, int response_size) {
    // Receive response from the server
    int received = 0;
    int total_received = 0;
    int remaining = response_size - 1;

    while (total_received < response_size - 1) {
        received = recv(sockfd, response + total_received, remaining, 0);
        if (received < 0) {
            error("Could not receive response from server");
        }
        if (received == 0) {
            break;
        }
        total_received += received;
        remaining -= received;
    }

    response[total_received] = '\0';
}

void get_page(char* response, const char* server, const char* path, int port) {
    // Connect to the server and send a GET request
    int sockfd = connect_to_server(server, port);

    char request_header[MAX_BUFFER_SIZE];
    snprintf(request_header, MAX_BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, server);
    send_request(sockfd, request_header, server);

    // Receive the response from the server
    receive_response(sockfd, response, MAX_BUFFER_SIZE);

    // Close the socket
    close(sockfd);
}

int main() {
    char response[MAX_BUFFER_SIZE];
    char server[50], path[50];

    printf("Enter hostname: ");
    fgets(server, 50, stdin);
    printf("Enter path (e.g. /index.html): ");
    fgets(path, 50, stdin);

    // Remove newline characters from user input
    server[strcspn(server, "\n")] = '\0';
    path[strcspn(path, "\n")] = '\0';

    printf("\nConnecting to server...\n\n");

    get_page(response, server, path, 80);

    printf("\nResponse:\n%s\n", response);

    return 0;
}