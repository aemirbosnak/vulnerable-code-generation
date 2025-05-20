//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Socket creation failed");
    }

    // Resolve the hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        die("Failed to resolve hostname");
    }

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    return sock;
}

void send_http_request(int sock, const char *hostname) {
    char request[BUFFER_SIZE];

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", hostname);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        die("Failed to send HTTP request");
    }
}

void receive_http_response(int sock) {
    char response[BUFFER_SIZE];
    int received;

    // Receive the server's response
    while ((received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response
    }

    if (received < 0) {
        die("Failed to receive HTTP response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = 80; // Default HTTP port

    // Create a socket and connect to the server
    int sock = create_socket(hostname, port);

    // Send the HTTP GET request
    send_http_request(sock, hostname);

    // Receive and display the response
    receive_http_response(sock);

    // Close the socket
    close(sock);
    return 0;
}