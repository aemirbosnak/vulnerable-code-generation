//FormAI DATASET v1.0 Category: Simple Web Server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

// Function to send HTTP response
void send_response(int client_fd, const char* response) {
    char header[BUFFER_SIZE];
    sprintf(header, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %lu\r\n\r\n", strlen(response));
    send(client_fd, header, strlen(header), 0);
    send(client_fd, response, strlen(response), 0);
}

// Function to handle incoming HTTP requests
void handle_request(int client_fd) {
    char buffer[BUFFER_SIZE];
    recv(client_fd, buffer, BUFFER_SIZE, 0);

    // Parse the HTTP request to determine the requested resource
    char* method = strtok(buffer, " ");
    char* path = strtok(NULL, " ");
    path++;

    // Open the requested file
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        // The file could not be opened, so send a 404 error
        char* response = "404 Not Found";
        send_response(client_fd, response);
    } else {
        // The file was successfully opened, so read its contents
        struct stat st;
        fstat(fd, &st);
        char* content = malloc(st.st_size);
        read(fd, content, st.st_size);

        // Send the file contents as an HTTP response
        send_response(client_fd, content);
        free(content);
        close(fd);
    }

    // Close the connection
    close(client_fd);
}

int main(int argc, char* argv[]) {
    // Parse command line arguments
    int port = 8080;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    // Set up the server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 10);

    // Wait for incoming connections and handle them
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

        handle_request(client_fd);
    }

    return 0;
}