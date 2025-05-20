//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 21
#define FILE_NAME_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Get the server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set up server address struct
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
}

void read_response(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    bzero(buffer, MAX_BUFFER_SIZE);
    int n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[MAX_BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    read_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    char command[MAX_BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    read_response(sockfd);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("ERROR opening file");
    }
    
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;
    
    // Read data from FTP server
    while ((bytes_read = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, bytes_read, fp);
    }
    fclose(fp);
    printf("File %s downloaded successfully.\n", filename);
}

void list_files(int sockfd) {
    char command[MAX_BUFFER_SIZE];
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    read_response(sockfd);

    // Simulate receiving file list
    // In reality, you need to parse the PASV response to set data connection
    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to FTP server
    int sockfd = connect_to_server(hostname);
    read_response(sockfd);

    // Login to the FTP server
    login(sockfd, username, password);

    // List files in the directory
    list_files(sockfd);

    // Download a file (hardcoded for example, could be made dynamic)
    download_file(sockfd, "example.txt");

    // Close the connection
    close(sockfd);
    return 0;
}