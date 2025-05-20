//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ftpclient <ftp_server_address> <username> <password>\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully\n");

    // Set server details
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) != 1) {
        perror("Invalid address format");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    printf("Connected to FTP server\n");

    // Get welcome message from server
    char response[MAX_BUFFER_SIZE];
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Login with username and password
    char command[MAX_BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", argv[2]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    sprintf(command, "PASS %s\r\n", argv[3]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Set transfer mode to binary
    if (send(sockfd, "TYPE I\r\n", 8, 0) == -1) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Download file
    char filename[MAX_BUFFER_SIZE];
    printf("Enter file to download: ");
    scanf("%s", filename);

    sprintf(command, "SIZE %s\r\n", filename);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    char *size_str = strtok(response, " ");
    size_str = strtok(NULL, " ");
    int filesize = atoi(size_str);

    sprintf(command, "RETR %s\r\n", filename);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }

    // Create file to save data
    int fd = open(filename, O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    int total_bytes_read = 0;
    int bytes_read;

    while (total_bytes_read < filesize) {
        bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_read == -1) {
            perror("Error receiving response from server");
            exit(EXIT_FAILURE);
        }
        if (write(fd, buffer, bytes_read) == -1) {
            perror("Error writing file");
            exit(EXIT_FAILURE);
        }
        total_bytes_read += bytes_read;
    }

    close(fd);
    printf("Downloaded file successfully\n");

    // Logout from server
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("Error sending command to server");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response from server");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // Close socket
    close(sockfd);

    return 0;
}