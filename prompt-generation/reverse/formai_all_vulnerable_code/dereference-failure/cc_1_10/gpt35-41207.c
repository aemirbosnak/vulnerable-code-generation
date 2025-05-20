//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

// Function to display error message & exit
void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    int sock_fd, bytes_read, file_fd;
    struct sockaddr_in serv_addr;

    // Creating socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error creating socket");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Converting IP address(Hostname) from text to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("Error invalid hostname");
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter filename to upload or 'exit' to close connection: ");
        memset(buffer, 0, BUFFER_SIZE);
        scanf("%s", buffer);

        if (strcmp(buffer, "exit") == 0) {
            close(sock_fd);
            printf("Connection closed\n");
            break;
        }

        // Open file to read
        if ((file_fd = open(buffer, O_RDONLY)) < 0) {
            error("Error opening file");
        }

        // Send filename to server
        if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
            error("Error sending filename to server");
        }

        // Receive response from server
        memset(buffer, 0, BUFFER_SIZE);
        if ((bytes_read = recv(sock_fd, buffer, BUFFER_SIZE, 0)) < 0) {
            error("Error receiving response from server");
        }

        if (strcmp(buffer, "Error") == 0) {
            printf("Error uploading file, file already exists!\n");
            close(file_fd);
            continue;
        }

        printf("Uploading file...\n");

        // Read and send file contents
        while ((bytes_read = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
            if (send(sock_fd, buffer, bytes_read, 0) < 0) {
                error("Error sending file contents to server");
            }
        }

        printf("File uploaded successfully!\n");

        // Close file
        close(file_fd);
    }
    return 0;
}