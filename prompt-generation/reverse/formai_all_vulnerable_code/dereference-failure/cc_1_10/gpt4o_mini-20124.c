//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024
#define MAX_FILENAME_LENGTH 256

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *hostname) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/Address not supported");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0); // FTP uses CRLF ending
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        error("Error receiving response");
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    printf("%s", buffer);
}

void login_to_ftp(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(sockfd, command);
    receive_response(sockfd);

    FILE *file = fopen(filename, "wb");
    if (!file) {
        error("Error opening file for writing");
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }

    if (bytes_received < 0) {
        error("Error receiving file data");
    }

    fclose(file);
    printf("Downloaded file: %s\n", filename);
}

void close_connection(int sockfd) {
    close(sockfd);
    printf("Connection closed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket();
    connect_to_server(sockfd, hostname);
    receive_response(sockfd);

    login_to_ftp(sockfd, username, password);

    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the filename to download: ");
    if (fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = 0; // Remove newline character
    } else {
        error("Failed to read filename");
    }

    download_file(sockfd, filename);
    close_connection(sockfd);

    return 0;
}