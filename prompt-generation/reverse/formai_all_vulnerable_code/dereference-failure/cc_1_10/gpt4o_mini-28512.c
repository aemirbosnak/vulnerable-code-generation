//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 21

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ftp_client(const char *hostname, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        handle_error("Socket creation failed");

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Resolve hostname to IP
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("Connection to the FTP server failed");

    // Read server response
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Send QUIT command to gracefully exit
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    close(sockfd);
    printf("Connection closed.\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    ftp_client(hostname, username, password);

    return EXIT_SUCCESS;
}