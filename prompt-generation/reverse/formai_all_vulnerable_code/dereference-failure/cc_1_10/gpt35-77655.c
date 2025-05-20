//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_LENGTH 4096

// Function to create a HTTP request and send it to the server
void send_http_request(int socket_fd, const char *host_name, const char *uri) {
    char request_buffer[MAX_BUFFER_LENGTH];
    snprintf(request_buffer, MAX_BUFFER_LENGTH, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", uri, host_name);
    send(socket_fd, request_buffer, strlen(request_buffer), 0);
}

// Function to read the response from the server
int read_response(int socket_fd, char *buffer, int buffer_length) {
    int num_bytes_received = 0;
    int num_bytes_total = 0;

    do {
        num_bytes_received = recv(socket_fd, buffer + num_bytes_total, buffer_length - num_bytes_total, 0);

        if(num_bytes_received < 0) {
            perror("Error receiving data from server");
            return -1;
        }

        num_bytes_total += num_bytes_received;

    } while(num_bytes_received > 0);

    return num_bytes_total;
}

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: %s <hostname> <uri>\n", argv[0]);
        return -1;
    }

    const char *host_name = argv[1];
    const char *uri = argv[2];

    // Get the IP address of the host
    struct hostent *server_info = gethostbyname(host_name);

    if(server_info == NULL) {
        printf("Error: Could not resolve server address\n");
        return -1;
    }

    // Create a TCP socket to communicate with the server
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(socket_fd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the server address and port number
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *(struct in_addr *)server_info->h_addr;
    server_address.sin_port = htons(80);

    // Connect to the server
    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    // Send the HTTP request
    send_http_request(socket_fd, host_name, uri);

    // Read the response from the server
    char response_buffer[MAX_BUFFER_LENGTH];
    int num_bytes_received = read_response(socket_fd, response_buffer, MAX_BUFFER_LENGTH);

    if(num_bytes_received < 0) {
        printf("Error: Could not read response from server\n");
        return -1;
    }

    // Print the response from the server
    response_buffer[num_bytes_received] = '\0';
    printf("%s", response_buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}