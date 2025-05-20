//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void write_to_file(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("Failed to open file");
    }
    
    int n;
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
}

void ftp_cmd(int sockfd, const char *cmd) {
    char buffer[BUFFER_SIZE];
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

void ftp_login(int sockfd, const char *user, const char *pass) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "USER %s\r\n", user);
    ftp_cmd(sockfd, cmd);
    
    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", pass);
    ftp_cmd(sockfd, cmd);
}

void ftp_retr(int sockfd, const char *filename) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "RETR %s\r\n", filename);
    ftp_cmd(sockfd, cmd);

    int data_sockfd;
    struct sockaddr_in server_addr;

    // Creating a secondary socket for data transfer
    if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Data socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT + 1); // Using the next port for data connection

    // Connect to the data port
    if (connect(data_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Data socket connection failed");
    }

    write_to_file(data_sockfd, filename);

    close(data_sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Read server response
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    
    // Login to FTP server
    ftp_login(sockfd, username, password);

    // Perform FTP RETR command to download a file
    char filename[100];
    printf("Enter filename to download: ");
    scanf("%99s", filename);
    ftp_retr(sockfd, filename);

    close(sockfd);
    return 0;
}