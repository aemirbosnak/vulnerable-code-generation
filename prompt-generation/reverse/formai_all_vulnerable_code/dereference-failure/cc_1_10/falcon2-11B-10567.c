//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>

#define PORT 21
#define MAX_FILE_SIZE 1024 * 1024

void* connect_to_ftp(void* arg) {
    // Connect to FTP server
    int sockfd = *(int*)arg;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error connecting to FTP server");
        exit(1);
    }
    printf("Connected to FTP server\n");

    // Login to FTP server
    char* username = "username";
    char* password = "password";
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);
    if (recv(sockfd, password, strlen(password), 0) < 0) {
        perror("Error sending username and password to FTP server");
        exit(1);
    }
    printf("Logged in to FTP server\n");

    // Change directory to "/home"
    char* dir = "/home";
    send(sockfd, dir, strlen(dir), 0);
    send(sockfd, "\r\n", 2, 0);
    if (recv(sockfd, dir, strlen(dir), 0) < 0) {
        perror("Error sending directory to FTP server");
        exit(1);
    }
    printf("Changed directory to '/home'\n");

    // Upload a file
    char* filename = "file.txt";
    char* data = "Hello, world!";
    int file_size = strlen(data);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "STOR ", 4, 0);
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);
    if (recv(sockfd, &file_size, sizeof(int), 0) < 0) {
        perror("Error receiving file size from FTP server");
        exit(1);
    }
    if (file_size!= strlen(data)) {
        perror("Error sending file data to FTP server");
        exit(1);
    }
    int bytes_sent = send(sockfd, data, file_size, 0);
    if (bytes_sent < 0) {
        perror("Error sending file data to FTP server");
        exit(1);
    }
    printf("File uploaded successfully\n");

    // Download a file
    char* download_filename = "downloaded.txt";
    int download_file_size = 1024;
    FILE* download_file = fopen(download_filename, "wb");
    if (download_file == NULL) {
        perror("Error opening download file");
        exit(1);
    }
    send(sockfd, "RETR ", 5, 0);
    send(sockfd, download_filename, strlen(download_filename), 0);
    send(sockfd, "\r\n", 2, 0);
    if (recv(sockfd, &download_file_size, sizeof(int), 0) < 0) {
        perror("Error receiving download file size from FTP server");
        exit(1);
    }
    int bytes_received = 0;
    while (bytes_received < download_file_size) {
        int n = recv(sockfd, (char*)download_file, download_file_size, 0);
        if (n < 0) {
            perror("Error receiving download file data from FTP server");
            exit(1);
        }
        bytes_received += n;
    }
    fclose(download_file);
    printf("File downloaded successfully\n");

    // Disconnect from FTP server
    send(sockfd, "QUIT", 4, 0);
    printf("Disconnected from FTP server\n");
    close(sockfd);
    return NULL;
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        exit(1);
    }
    if (listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }
    printf("Listening on port %d\n", PORT);
    while (1) {
        int client_fd = accept(sockfd, NULL, NULL);
        if (client_fd < 0) {
            perror("Error accepting client");
            exit(1);
        }
        pthread_t thread;
        pthread_create(&thread, NULL, connect_to_ftp, (void*)&client_fd);
        pthread_detach(thread);
    }
    return 0;
}