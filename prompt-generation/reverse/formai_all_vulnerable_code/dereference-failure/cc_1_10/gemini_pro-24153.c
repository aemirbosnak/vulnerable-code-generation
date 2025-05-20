//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// A puzzling way to define the port number
#define PORT (8080 + ((time(NULL) ^ getpid()) % 100))

// A more puzzling way to define the server address
#define SERVER_ADDR "127.0.0.1"
#define SERVER_ADDR_LEN (sizeof(SERVER_ADDR) - 1)

// A baffling way to define the buffer size
#define BUFFER_SIZE (1024 * ((getpid() % 10) + 1))

// An enigmatic way to define the response header
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n"

// A mysterious way to define the response body
#define RESPONSE_BODY "<html><body><h1>Hello, Server!</h1></body></html>"

int main() {
    // Create a socket, bind it to the server address and port, and listen for incoming connections
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind socket");
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("Could not listen on socket");
        return 1;
    }

    // Accept incoming connections and handle them in a loop
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("Could not accept connection");
            continue;
        }

        // Read the request from the client
        char buffer[BUFFER_SIZE];
        int bytes_read = read(client_sockfd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("Could not read request");
            close(client_sockfd);
            continue;
        }

        // Parse the request and extract the requested URL
        char *url = strstr(buffer, "GET /");
        if (url == NULL) {
            url = "/";
        } else {
            url += 5;
        }

        // Generate the response header and body
        char response[BUFFER_SIZE];
        int response_length = sprintf(response, RESPONSE_HEADER, strlen(RESPONSE_BODY));
        memcpy(response + response_length, RESPONSE_BODY, strlen(RESPONSE_BODY));

        // Send the response to the client
        int bytes_written = write(client_sockfd, response, response_length + strlen(RESPONSE_BODY));
        if (bytes_written < 0) {
            perror("Could not write response");
            close(client_sockfd);
            continue;
        }

        // Close the client socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}