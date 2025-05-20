//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <dirent.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USERNAME "anonymous"
#define PASSWORD "user@domain.com"

// Function prototypes
int ftp_connect(const char* hostname);
void ftp_login(int sockfd);
void ftp_list(int sockfd);
void ftp_download(int sockfd, const char *filename);
void ftp_close(int sockfd);

// Main function
int main() {
    char hostname[256];
    int sockfd;

    printf("Welcome to FTP Client!\n");
    printf("Enter the FTP server hostname or IP address: ");
    scanf("%255s", hostname);

    sockfd = ftp_connect(hostname);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to connect to FTP server\n");
        return EXIT_FAILURE;
    }

    ftp_login(sockfd);
    ftp_list(sockfd);

    char filename[256];
    printf("Enter the filename to download: ");
    scanf("%255s", filename);

    ftp_download(sockfd, filename);
    ftp_close(sockfd);

    return EXIT_SUCCESS;
}

// Function to connect to FTP server
int ftp_connect(const char* hostname) {
    struct sockaddr_in server_addr;
    struct hostent* server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", hostname);
        close(sockfd);
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }
    
    return sockfd;
}

// Function to login to FTP server
void ftp_login(int sockfd) {
    char buffer[BUFFER_SIZE];

    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);
    
    // Send USER command
    sprintf(buffer, "USER %s\r\n", USERNAME);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Send PASS command
    sprintf(buffer, "PASS %s\r\n", PASSWORD);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);
}

// Function to list files in the current directory
void ftp_list(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Send PASV command to enter passive mode
    strcpy(buffer, "PASV\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Extract IP address and port for the data connection
    int p1, p2;
    char ip[16];
    sscanf(buffer, "227 Entering Passive Mode (%[^)])-> %d,%d", ip, &p1, &p2);

    int data_port = p1 * 256 + p2;
    int data_sockfd = ftp_connect(ip);
    if (data_sockfd < 0) return;

    // Send LIST command
    strcpy(buffer, "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);

    // Receive file list
    while (read(data_sockfd, buffer, sizeof(buffer) - 1) > 0) {
        printf("%s", buffer);
    }
    close(data_sockfd);
}

// Function to download a file from the FTP server
void ftp_download(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    int file_sockfd;

    // Send PASV command again
    strcpy(buffer, "PASV\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    int p1, p2;
    char ip[16];
    sscanf(buffer, "227 Entering Passive Mode (%[^)])-> %d,%d", ip, &p1, &p2);

    int data_port = p1 * 256 + p2;
    file_sockfd = ftp_connect(ip);
    if (file_sockfd < 0) return;

    // Send RETR command
    sprintf(buffer, "RETR %s\r\n", filename);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    // Open the file for writing
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        close(file_sockfd);
        return;
    }

    // Receive file
    ssize_t n;
    while ((n = read(file_sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }
    
    fclose(fp);
    close(file_sockfd);
    printf("File downloaded: %s\n", filename);
}

// Function to close the connection
void ftp_close(int sockfd) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Server: %s\n", buffer);
    close(sockfd);
}