//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check command line arguments
    if (argc < 4) {
        printf("Usage: ./ftp <server_address> <server_port> <file_path>\n");
        exit(1);
    }

    // Create socket
    int sockfd;
    struct sockaddr_in serveraddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Set server address and port
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send file path to server
    char filepath[BUFFER_SIZE];
    strcpy(filepath, argv[3]);
    if (write(sockfd, filepath, strlen(filepath)) < 0) {
        perror("Error sending file path to server");
        exit(1);
    }

    // Receive file contents from server
    char buffer[BUFFER_SIZE];
    int filefd = open("received_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (filefd < 0) {
        perror("Error creating received_file");
        exit(1);
    }
    ssize_t n;
    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        if (write(filefd, buffer, n) < 0) {
            perror("Error writing to received_file");
            exit(1);
        }
    }
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Close file descriptor and socket
    close(filefd);
    close(sockfd);

    printf("File transfer complete\n");

    return 0;
}