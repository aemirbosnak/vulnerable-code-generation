//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void get_response(int sock, char *response) {
    if (recv(sock, response, BUFFER_SIZE - 1, 0) < 0) {
        error("recv failed");
    }
    response[BUFFER_SIZE - 1] = '\0'; // Null terminate the string
}

void ftp_command(int sock, const char *cmd, char *response) {
    send(sock, cmd, strlen(cmd), 0);
    get_response(sock, response);
    printf("Response: %s\n", response);
}

void list_files(int sock) {
    char response[BUFFER_SIZE];
    ftp_command(sock, "PASV\r\n", response); // Enter passive mode
    ftp_command(sock, "LIST\r\n", response); // List files
}

void download_file(int sock, const char *filename) {
    char response[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];

    // Send PASV command, enter passive mode to receive data
    ftp_command(sock, "PASV\r\n", response);

    // Prepare the RETR command for downloading the file
    snprintf(cmd, sizeof(cmd), "RETR %s\r\n", filename);
    ftp_command(sock, cmd, response);
    
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("File cannot be opened for writing");
    }

    // Here, you would receive the file data and write it to the file.
    // For simplicity, we will skip actual data transfer part here.
    printf("Downloading file: %s\n", filename);
    
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const int port = atoi(argv[2]);

    // Prepare connection
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the FTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to the server");
    }

    // Receive the welcome message
    char response[BUFFER_SIZE];
    get_response(sock, response);
    printf("Welcome: %s\n", response);

    // Login
    ftp_command(sock, "USER anonymous\r\n", response);
    ftp_command(sock, "PASS guest@example.com\r\n", response);

    // List files
    list_files(sock);

    // Download a specific file (for testing, we assume "example.txt" exists)
    download_file(sock, "example.txt");

    // Exit the session
    ftp_command(sock, "QUIT\r\n", response);
    
    // Close the socket
    close(sock);
    printf("Disconnected successfully. Goodbye!\n");

    return 0;
}