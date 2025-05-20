//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

// Function to connect to a remote FTP server
int connect_ftp_server(char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command to the FTP server
void send_ftp_command(int sockfd, char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a response from the FTP server
char *receive_ftp_response(int sockfd) {
    char *response = malloc(BUFFER_SIZE);
    int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    response[bytes_received] = '\0';
    return response;
}

// Function to download a file from the FTP server
void download_file(int sockfd, char *filename) {
    // Open a file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Send the RETR command to the server
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "RETR %s\r\n", filename);
    send_ftp_command(sockfd, command);

    // Receive the file from the server
    char buffer[BUFFER_SIZE];
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    // Close the file
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Connect to the FTP server
    int sockfd = connect_ftp_server(argv[1]);

    // Send the USER command to the server
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "USER anonymous\r\n");
    send_ftp_command(sockfd, command);

    // Receive the response from the server
    char *response = receive_ftp_response(sockfd);
    printf("%s", response);

    // Send the PASS command to the server
    snprintf(command, BUFFER_SIZE, "PASS anonymous@example.com\r\n");
    send_ftp_command(sockfd, command);

    // Receive the response from the server
    response = receive_ftp_response(sockfd);
    printf("%s", response);

    // Send the TYPE command to the server
    snprintf(command, BUFFER_SIZE, "TYPE I\r\n");
    send_ftp_command(sockfd, command);

    // Receive the response from the server
    response = receive_ftp_response(sockfd);
    printf("%s", response);

    // Download the file from the server
    download_file(sockfd, argv[2]);

    // Close the connection to the FTP server
    close(sockfd);

    return 0;
}