//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// HTTP request methods
#define GET "GET"
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"

// HTTP status codes
#define OK 200
#define NOT_FOUND 404
#define INTERNAL_SERVER_ERROR 500

// Maximum buffer size
#define MAX_BUFFER_SIZE 1024

// Function to create a socket
int create_socket(int port, char *ip_address) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send an HTTP request
void send_request(int sockfd, char *method, char *path, char *body) {
    char request[MAX_BUFFER_SIZE];

    // Format the request
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %ld\r\n\r\n%s", method, path, "example.com", strlen(body), body);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }
}

// Function to receive an HTTP response
char *receive_response(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    char *response = NULL;
    int bytes_received = 0;

    // Receive the response
    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        // Reallocate the response buffer
        response = realloc(response, strlen(response) + bytes_received + 1);

        // Append the received data to the response
        strcat(response, buffer);
    }

    if (bytes_received < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    return response;
}

// Function to parse the HTTP response
int parse_response(char *response) {
    char *status_line;
    int status_code;

    // Get the status line
    status_line = strtok(response, "\r\n");

    // Get the status code
    status_code = atoi(strtok(status_line, " "));

    return status_code;
}

// Function to print the HTTP response
void print_response(char *response) {
    printf("%s\n", response);
}

// Main function
int main(int argc, char **argv) {
    int sockfd;
    char *response;
    int status_code;

    // Create a socket
    sockfd = create_socket(80, "127.0.0.1");

    // Send an HTTP request
    send_request(sockfd, GET, "/", NULL);

    // Receive an HTTP response
    response = receive_response(sockfd);

    // Parse the HTTP response
    status_code = parse_response(response);

    // Print the HTTP response
    print_response(response);

    // Close the socket
    close(sockfd);

    return 0;
}