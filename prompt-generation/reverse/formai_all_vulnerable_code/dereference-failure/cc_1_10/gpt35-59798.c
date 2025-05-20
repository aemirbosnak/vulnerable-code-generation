//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080
#define MAXLINE 1024
#define MAXFILENAME 256

void syncFiles(int sockfd, char *filename) {
    int file_fd, num_bytes;
    char file_buf[MAXLINE];

    // Open the file to sync
    file_fd = open(filename, O_RDONLY);
    if (file_fd < 0) {
        perror("open");
        return;
    }

    // Read the file content and send it over the socket
    while ((num_bytes = read(file_fd, file_buf, MAXLINE)) > 0) {
        if (send(sockfd, file_buf, num_bytes, 0) < 0) {
            perror("send");
            return;
        }
    }

    // Close the file
    close(file_fd);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char filename[MAXFILENAME];

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./synchronizer <server_ip> <file_path>\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the file name to sync
    strcpy(filename, argv[2]);
    if (send(sockfd, filename, MAXFILENAME, 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Sync the file
    syncFiles(sockfd, filename);

    // Close the socket
    close(sockfd);

    return 0;
}