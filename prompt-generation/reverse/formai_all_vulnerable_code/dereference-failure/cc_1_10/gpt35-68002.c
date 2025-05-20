//FormAI DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_SIZE 2048

int main(int argc, char *argv[]) {
    int port = 8080;
    char *root_dir = "/"; // Root directory for serving files
    int fd, connfd, n, open_file;
    char buffer[MAX_SIZE];
    struct sockaddr_in address;
    struct stat file_stat;

    memset(buffer, 0, MAX_SIZE);
    memset(&address, 0, sizeof(address));

    // Check if port is specified
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    // Check if root directory is specified
    if (argc > 2) {
        root_dir = argv[2];
    }

    // Create socket
    fd = socket(AF_INET, SOCK_STREAM, 0);

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(fd, (struct sockaddr *) &address, sizeof(address));

    // Listen for connections
    listen(fd, 5);
    printf("Listening on port %d...\n", port);

    while (1) {
        // Accept incoming connection
        connfd = accept(fd, (struct sockaddr *) NULL, NULL);

        // Read request from socket
        n = read(connfd, buffer, MAX_SIZE);

        // Extract filename from request
        char *filename = strtok(&buffer[4], " ");

        // Check if file exists
        if (stat(filename, &file_stat) < 0) {
            printf("File not found: %s\n", filename);
            close(connfd);
            continue;
        }

        // Check if file is a regular file
        if (!S_ISREG(file_stat.st_mode)) {
            printf("Not a regular file: %s\n", filename);
            close(connfd);
            continue;
        }

        // Open file
        open_file = open(filename, O_RDONLY);

        // Write response headers
        char response_headers[MAX_SIZE];
        sprintf(response_headers, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", file_stat.st_size);
        write(connfd, response_headers, strlen(response_headers));

        // Serve file
        while ((n = read(open_file, buffer, MAX_SIZE)) > 0) {
            write(connfd, buffer, n);
        }

        // Close file and connection
        close(open_file);
        close(connfd);
    }

    return 0;
}