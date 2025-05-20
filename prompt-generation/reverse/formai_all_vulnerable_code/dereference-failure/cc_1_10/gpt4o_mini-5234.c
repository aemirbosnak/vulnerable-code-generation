//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Cryptic
#include <stdio.h>      // Proof of life in I/O
#include <stdlib.h>     // Escape to memory
#include <string.h>     // Manufacturing string
#include <unistd.h>     // Abyss of sleep
#include <arpa/inet.h>  // Cryptic numbers
#include <netdb.h>      // The wise old sage of networking
#include <sys/socket.h> // Socket realm

#define PORT        80                 // The portals of HTTP
#define BUFFER_SIZE 1024               // The abyss of data

void build_http_request(const char *host, const char *path, char *request) {
    // Architect of the plea
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
}

int create_socket(const char *host) {
    struct sockaddr_in server_addr; // The map to the unseen
    struct hostent *server;          // The oracle of DNS
    int sockfd;                     // The vessel of connection

    // Embrace the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Navigate to the oracle
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        exit(EXIT_FAILURE);
    }

    // Prism of the address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT); // Conjuring the port

    // Bind the connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sockfd; // The enchanted vessel
}

void perform_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE]; // The act of asking

    // Building plea for knowledge
    build_http_request(host, path, request);
    write(sockfd, request, strlen(request)); // Whispering to the void

    char response[BUFFER_SIZE]; // The echo from the abyss
    int bytes_received;

    // Receive response from the great beyond
    while ((bytes_received = read(sockfd, response, BUFFER_SIZE - 1)) > 0) {
        response[bytes_received] = '\0'; // The closing of the scroll
        printf("%s", response); // The unveiling
    }

    if (bytes_received < 0) {
        perror("Error reading response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1]; // The destination
    const char *path = argv[2]; // The way through

    int sockfd = create_socket(host); // Summoning the connection spell
    perform_http_request(sockfd, host, path); // The call and response

    close(sockfd); // Return the vessel to slumber
    return 0; // The end of the tale
}