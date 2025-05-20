//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    // Set up the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(argv[1]);
    proxy_addr.sin_port = htons(atoi(argv[2]));

    // Bind the socket
    if (bind(sockfd, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(sockfd, 10) == -1) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy running on %s:%s\n", argv[1], argv[2]);

    while (1) {
        // Accept a new connection
        int client_sockfd;
        struct sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);

        if ((client_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_addr_len)) == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle the client request
        char buffer[MAX_BUFFER_SIZE] = {0};
        int read_bytes = read(client_sockfd, buffer, MAX_BUFFER_SIZE);

        // Parse the request to get the URL
        char* start = strstr(buffer, "://") + 3;
        char* end = strchr(start, ' ');

        char url[end - start + 1];
        strncpy(url, start, end - start);
        url[end - start] = '\0';

        // Open a connection to the web server
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(url);
        server_addr.sin_port = htons(80);

        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (connect(server_sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
            perror("Error connecting to webserver");
            exit(EXIT_FAILURE);
        }

        // Forward the client request to the web server
        write(server_sockfd, buffer, read_bytes);

        // Forward the web server response to the client
        while ((read_bytes = read(server_sockfd, buffer, MAX_BUFFER_SIZE)) > 0) {
            write(client_sockfd, buffer, read_bytes);
        }

        // Close the connection to the web server
        close(server_sockfd);

        // Close the connection to the client
        close(client_sockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}