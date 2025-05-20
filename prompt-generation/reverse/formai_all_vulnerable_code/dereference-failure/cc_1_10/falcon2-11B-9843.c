//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Struct for HTTP headers
struct http_header {
    char method[16];
    char body_size[16];
};

// Function to parse an HTTP header buffer
struct http_header parse_header(char* buffer) {
    struct http_header hdr;
    strncpy(hdr.method, buffer, sizeof(hdr.method));
    strncpy(hdr.body_size, buffer + sizeof(hdr.method), sizeof(hdr.body_size));
    return hdr;
}

// Function to handle an HTTP response
void handle_response(int sockfd, char* buffer) {
    char* response = malloc(strlen(buffer));
    memcpy(response, buffer, strlen(buffer));
    printf("HTTP/1.1 200 OK\r\n");
    printf("Content-Length: %s\r\n", response);
    printf("\r\n");
    free(response);
}

// Function to create a client socket
int create_client_socket(char* host, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent* server = gethostbyname(host);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr*)server->h_addr);
    int rv = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (rv == -1) {
        perror("connect() failed");
        exit(1);
    }
    return sockfd;
}

// Function to make an HTTP request
void make_request(int sockfd, char* buffer) {
    int n = write(sockfd, buffer, strlen(buffer));
    if (n!= strlen(buffer)) {
        perror("write() failed");
        exit(1);
    }
}

// Function to process requests
void process_request(int client_sockfd, struct http_header* hdr, char* buffer) {
    int server_sockfd = create_client_socket("127.0.0.1", 80);
    if (server_sockfd == -1) {
        perror("socket() failed");
        exit(1);
    }
    char* req = malloc(strlen(buffer) + strlen(hdr->method) + strlen(hdr->body_size) + 4);
    sprintf(req, "%s %s %s\r\n\r\n", hdr->method, hdr->body_size, buffer);
    make_request(server_sockfd, req);
    close(server_sockfd);
    handle_response(client_sockfd, buffer);
}

// Main function
int main(int argc, char* argv[]) {
    int client_sockfd;
    struct hostent* server;
    struct in_addr* in_addr;
    char buffer[2048];
    struct http_header hdr;

    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    in_addr = (struct in_addr*)server->h_addr;
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd == -1) {
        perror("socket() failed");
        exit(1);
    }
    int n = connect(client_sockfd, (struct sockaddr*)&in_addr, sizeof(struct in_addr));
    if (n == -1) {
        perror("connect() failed");
        exit(1);
    }

    hdr = parse_header(buffer);
    process_request(client_sockfd, &hdr, buffer);

    close(client_sockfd);
    return 0;
}