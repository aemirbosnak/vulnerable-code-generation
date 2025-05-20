//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT "8080"
#define MAX_CONNECTIONS 5
#define MAX_DATA 1024

void handle_connection(int sockfd) {
    char buf[MAX_DATA];
    int bytes_received;
    char *http_response;
    
    // Receive data from the client
    bytes_received = recv(sockfd, buf, MAX_DATA, 0);
    if (bytes_received == -1) {
        perror("recv");
        return;
    }

    // Parse the HTTP request 
    char *request_line = strtok(buf, "\r\n");
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, " ");
    
    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
        http_response = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
        send(sockfd, http_response, strlen(http_response), 0);
        return;
    }
    // Construct the HTTP response
    char *content = "<html><head><title>My Awesome Web Server</title></head><body><h1>Hello, world!</h1></body></html>";
    char *headers = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n";
    http_response = malloc(strlen(headers) + strlen(content));
    sprintf(http_response, headers, strlen(content));
    strcat(http_response, content);

    // Send the response to the client
    send(sockfd, http_response, strlen(http_response), 0);

    // Close the connection 
    close(sockfd);
}

int main() {
    // Create a socket 
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address and port
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(PORT));
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept connections 
    struct sockaddr_in cliaddr;
    socklen_t clilen;
    while (1) {
        clilen = sizeof(cliaddr);
        int newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);
        if (newsockfd == -1) {
            perror("accept");
            continue;
        }

        // Handle the connection in a separate thread
        pid_t pid = fork();
        if (pid == 0) {
            close(sockfd);
            handle_connection(newsockfd);
            exit(EXIT_SUCCESS);
        } else {
            close(newsockfd);
        }
    }

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}