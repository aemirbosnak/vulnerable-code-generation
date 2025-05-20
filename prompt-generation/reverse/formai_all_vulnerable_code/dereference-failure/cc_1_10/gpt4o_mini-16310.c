//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: systematic
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

void connect_to_server(int *sockfd, const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("ERROR, no such host\n");
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("ERROR opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }
}

void login(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Read server response
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    // Send USER command
    write(sockfd, username, strlen(username));
    write(sockfd, "\r\n", 2);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    // Send PASS command
    write(sockfd, password, strlen(password));
    write(sockfd, "\r\n", 2);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);
}

void list_files(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Send LIST command
    write(sockfd, "LIST\r\n", 6);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);
}

void quit(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Send QUIT command
    write(sockfd, "QUIT\r\n", 6);
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);
}

void download_file(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *fp;
    int n;

    // Send RETR command
    write(sockfd, "RETR ", 5);
    write(sockfd, filename, strlen(filename));
    write(sockfd, "\r\n", 2);
    
    // Read server response
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    // Open file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("ERROR opening file for writing");
    }

    // Read data from server
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
    printf("Downloaded: %s\n", filename);
}

int main(int argc, char *argv[]) {
    int sockfd;
    const char *hostname, *username, *password;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];

    connect_to_server(&sockfd, hostname);
    login(sockfd, username, password);
    list_files(sockfd);
    download_file(sockfd, "example.txt"); // specify a file on the FTP server
    quit(sockfd);
    
    close(sockfd);
    return 0;
}