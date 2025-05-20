//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// A function to read data from the socket
ssize_t read_socket(int socket, void *buf, size_t len) {
    ssize_t read_size;
    read_size = recv(socket, buf, len, 0);
    return read_size;
}

// A function to write data to the socket
ssize_t write_socket(int socket, const void *buf, size_t len) {
    ssize_t write_size;
    write_size = send(socket, buf, len, 0);
    return write_size;
}

// A function to create a new TCP socket
int create_tcp_socket(int port) {
    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Error in getting localhost IP address");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connecting to the server");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

// A function to process the client request
void process_client_request(int socket_fd, char *buffer, size_t buffer_size) {
    char request_line[256];
    char hostname[256];
    char *host;

    size_t read_size;
    size_t i;

    // Read the request line
    read_size = read_socket(socket_fd, request_line, sizeof(request_line));
    if (read_size <= 0) {
        perror("Error in reading the request line");
        exit(EXIT_FAILURE);
    }

    printf("Request line: %s\n", request_line);

    // Extract the hostname from the request line
    host = strtok(request_line, " ");
    if (host == NULL) {
        perror("Error in extracting hostname");
        exit(EXIT_FAILURE);
    }

    strcpy(hostname, host);

    // Extract the request method and the URL
    host = strtok(NULL, " ");
    if (host == NULL) {
        perror("Error in extracting request method");
        exit(EXIT_FAILURE);
    }

    host = strtok(NULL, " ");
    if (host == NULL) {
        perror("Error in extracting URL");
        exit(EXIT_FAILURE);
    }

    printf("Host: %s\n", host);
    printf("Method: %s\n", host);

    // Build the response line
    snprintf(request_line, sizeof(request_line), "HTTP/1.1 200 OK\r\n");
    snprintf(request_line + strlen(request_line), sizeof(request_line) - strlen(request_line), "Content-Type: text/html\r\n\r\n");

    // Send the response line
    write_socket(socket_fd, request_line, strlen(request_line));

    // Read the entire response from the server
    read_size = read_socket(socket_fd, buffer, buffer_size);
    if (read_size <= 0) {
        perror("Error in reading the response");
        exit(EXIT_FAILURE);
    }

    // Print the response
    printf("Response:\n%s\n", buffer);

    // Close the socket
    close(socket_fd);
}

// The main function
int main(int argc, char **argv) {
    int server_fd;
    int client_fd;
    int port = atoi(argv[1]);
    char buffer[4096];
    size_t buffer_size = sizeof(buffer);

    // Create a new TCP socket
    server_fd = create_tcp_socket(port);
    if (server_fd < 0) {
        perror("Error in creating the server socket");
        exit(EXIT_FAILURE);
    }

    // Accept the client connection
    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("Error in accepting the client connection");
        exit(EXIT_FAILURE);
    }

    // Process the client request
    process_client_request(client_fd, buffer, buffer_size);

    // Close the socket
    close(client_fd);

    // Close the server socket
    close(server_fd);

    return 0;
}