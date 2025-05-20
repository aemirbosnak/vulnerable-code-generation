//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUFFER_SIZE 1024

void draw_banner() {
    printf("========================================\n");
    printf("   Hark! The HTTP Client of Yore!    \n");
    printf("========================================\n");
}

void create_http_request(const char* host, const char* path, char* request_buffer) {
    sprintf(request_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
}

int establish_connection(const char* host) {
    struct hostent* server;
    struct sockaddr_in server_addr;

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Alas! No such host found.\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Oh no! Failed to create a socket.\n");
        exit(EXIT_FAILURE);
    }

    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "By my sword! Unable to connect to the server.\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void fetch_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    
    printf("Awaiting the response from the noble server...\n");
    while ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[n] = '\0';  
        printf("%s", buffer); 
    }
    if (n < 0) {
        fprintf(stderr, "The heavens weep! Failed to receive data.\n");
    }
}

int main(int argc, char* argv[]) {
    draw_banner();

    if (argc != 3) {
        fprintf(stderr, "Woe unto thee! Usage: ./http_client <host> <path>\n");
        exit(EXIT_FAILURE);
    }

    const char* host = argv[1];
    const char* path = argv[2];

    char request_buffer[BUFFER_SIZE];

    int sockfd = establish_connection(host);
    create_http_request(host, path, request_buffer);
    
    printf("Sending forth the request to the server...\n");
    int sent = send(sockfd, request_buffer, strlen(request_buffer), 0);
    
    if (sent < 0) {
        fprintf(stderr, "A curse upon this socket! Failed to send request.\n");
        exit(EXIT_FAILURE);
    }

    fetch_http_response(sockfd);

    close(sockfd);
    printf("The quest is complete! Reap the fruit of knowledge.\n");
    return 0;
}