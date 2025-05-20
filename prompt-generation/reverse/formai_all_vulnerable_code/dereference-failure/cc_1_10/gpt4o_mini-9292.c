//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_ftp(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sockfd;

    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", cmd);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending command");
    }
}

void get_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error("Error receiving response");
    }
    buffer[n] = '\0';
    printf("%s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    get_response(sockfd);
    send_command(sockfd, username);
    get_response(sockfd);
    send_command(sockfd, password);
    get_response(sockfd);
}

int download_file(int sockfd, const char *filename) {
    char file_buffer[BUFFER_SIZE];
    int file_fd, n;

    file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd < 0) {
        error("Error opening file for writing");
    }

    while ((n = recv(sockfd, file_buffer, sizeof(file_buffer), 0)) > 0) {
        write(file_fd, file_buffer, n);
    }

    close(file_fd);
    return n;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = connect_to_ftp(hostname);
    
    // Get and print the welcome message
    get_response(sockfd);

    // Login to FTP server
    send_command(sockfd, "USER");
    login(sockfd, username, password);

    // Get a file from the FTP server
    char *file_to_download = "example.txt"; // The file we want to download
    send_command(sockfd, "RETR example.txt"); // Send retrieval command
    get_response(sockfd); // receive server's response

    // Start the download
    download_file(sockfd, file_to_download);

    // Deck the halls with FTP fun
    printf("File '%s' downloaded successfully from '%s'.\n", file_to_download, hostname);

    close(sockfd);
    return 0;
}