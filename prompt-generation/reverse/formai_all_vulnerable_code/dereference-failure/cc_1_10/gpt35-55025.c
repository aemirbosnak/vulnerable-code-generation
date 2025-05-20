//FormAI DATASET v1.0 Category: Client Server Application ; Style: ephemeral
/*
 * This is a unique C Client Server Application example program
 * that uses ephemeral ports and addresses.
 * The program establishes a TCP connection between client and server,
 * and allows the client to perform file read and write operations on
 * the server's file system.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void handle_error(char *error_message) {
    fprintf(stderr, "Error: %s\nErrno: %d (%s)\n", error_message, errno, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Failed to create socket");
    }

    // Initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(0); // ephemeral port

    // Bind the socket with server address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Failed to bind socket");
    }

    // Get the ephemeral port number allocated by the OS
    struct sockaddr_in temp_addr;
    socklen_t temp_len = sizeof(temp_addr);
    if (getsockname(sockfd, (struct sockaddr *)&temp_addr, &temp_len) < 0) {
        handle_error("Failed to get socket name");
    }
    printf("Server listening at %s:%d\n", inet_ntoa(temp_addr.sin_addr), ntohs(temp_addr.sin_port));

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        handle_error("Error listening");
    }

    while (1) {
        // Accept the connection
        cli_len = sizeof(cli_addr);
        if ((connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len)) < 0) {
            handle_error("Error accepting connection");
        }

        // Read the client request
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        if ((n = read(connfd, buffer, BUFFER_SIZE)) < 0) {
            handle_error("Error reading from client");
        }

        printf("Request received from %s:%d -> %s\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), buffer);

        // Parse the request
        char *filename = strtok(buffer, " ");
        char *mode = strtok(NULL, " ");

        // Open the file
        FILE *fileptr = fopen(filename, mode);
        if (fileptr == NULL) {
            char error_string[BUFFER_SIZE];
            snprintf(error_string, BUFFER_SIZE, "Failed to open %s", filename);
            handle_error(error_string);
        }

        // Process the file operation
        if (strcmp(mode, "r") == 0) {
            // Read operation
            memset(buffer, 0, BUFFER_SIZE);
            while ((n = fread(buffer, 1, BUFFER_SIZE, fileptr)) > 0) {
                if (write(connfd, buffer, n) < 0) {
                    handle_error("Error writing to client");
                }
                memset(buffer, 0, BUFFER_SIZE);
            }
        } else {
            // Write operation
            while ((n = read(connfd, buffer, BUFFER_SIZE)) > 0) {
                fwrite(buffer, 1, n, fileptr);
                memset(buffer, 0, BUFFER_SIZE);
            }
        }

        // Close the file and connection
        fclose(fileptr);
        close(connfd);
    }

    return 0;
}