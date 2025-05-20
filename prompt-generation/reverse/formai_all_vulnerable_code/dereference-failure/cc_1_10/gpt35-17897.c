//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024 // maximum buffer size for request and response

void handle_request(int client_fd);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    char buffer[BUFFER_SIZE];

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // set sockaddr_in structure
    memset(&server_address, 0, sizeof(server_address)); 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[1]));
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // bind server socket to IP address and port number
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind error");
        exit(1);
    }

    // listen for incoming connections
    if (listen(server_fd, 0) < 0) {
        perror("listen error");
        exit(1);
    }

    // loop to handle client requests recursively
    while (true) {
        printf("Waiting for client connection...\n");

        // accept incoming client connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length);
        if (client_fd < 0) {
            perror("accept error");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // fork process to handle client request
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            handle_request(client_fd);
            exit(0);
        } else {
            close(client_fd); // close client file descriptor in parent process
        }
    }

    // close server file descriptor
    close(server_fd);
    return 0;
}

void handle_request(int client_fd) {
    char request[BUFFER_SIZE], response[BUFFER_SIZE], resource[BUFFER_SIZE];
    int bytes_read, bytes_written, file_fd;

    // read client request into buffer
    while ((bytes_read = read(client_fd, request, BUFFER_SIZE)) > 0) {
        // null-terminate request string
        request[bytes_read] = '\0';

        // extract file path from request string
        sscanf(request, "GET /%s ", resource);

        // check if file exists on server
        if (access(resource, F_OK) == -1) {
            // file not found, send 404 Not Found response
            sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
        } else {
            // file found, send 200 OK response and content of file
            file_fd = open(resource, O_RDONLY);
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n", lseek(file_fd, 0, SEEK_END));
            lseek(file_fd, 0, SEEK_SET);
            while ((bytes_read = read(file_fd, response + strlen(response), BUFFER_SIZE - strlen(response))) > 0) {
                bytes_written = write(client_fd, response, strlen(response));
                if (bytes_written < 0) {
                    perror("write error");
                    exit(1);
                }
                // clear response buffer
                memset(response, 0, BUFFER_SIZE);
            }
            close(file_fd);
        }

        // write response to client
        bytes_written = write(client_fd, response, strlen(response));
        if (bytes_written < 0) {
            perror("write error");
            exit(1);
        }
        // clear request and response buffers
        memset(request, 0, BUFFER_SIZE);
        memset(response, 0, BUFFER_SIZE);
    }
    // close client file descriptor
    close(client_fd);
}