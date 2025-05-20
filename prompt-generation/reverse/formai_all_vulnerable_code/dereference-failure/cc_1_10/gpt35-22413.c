//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21 // FTP Port number

// Function to create a socket and connect to the FTP server
int connect_to_ftp_server(char *hostname) {
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd;

    // Get the IP address of the server
    host = gethostbyname(hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server connection settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(server_addr.sin_zero),8);

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to FTP server.\n");

    return sockfd;
}

// Function to login to the FTP server
void login_to_ftp_server(int sockfd, char *username, char *password) {
    char buffer[1024];

    // Wait for greeting message from server
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("Error receiving data from server");
        exit(1);
    }

    printf("%s", buffer);

    // Send the user name to the server
    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending data to server");
        exit(1);
    }

    // Wait for response
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("Error receiving data from server");
        exit(1);
    }

    printf("%s", buffer);

    // Send the password to the server
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending data to server");
        exit(1);
    }

    // Wait for response
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("Error receiving data from server");
        exit(1);
    }

    printf("%s", buffer);

    printf("Logged in to FTP server.\n");
}

// Function to download a file from the FTP server
void download_file(int sockfd, char *filename) {
    FILE *fp;
    char buffer[1024];
    int num_bytes;

    // Open the file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }

    // Send the command to the server to download the file
    sprintf(buffer, "RETR %s\r\n", filename);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending data to server");
        exit(1);
    }

    // Wait for response
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        perror("Error receiving data from server");
        exit(1);
    }

    printf("%s", buffer);

    // Receive the file data and write it to disk
    while ((num_bytes = recv(sockfd, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, num_bytes, fp);
    }

    fclose(fp);

    printf("File downloaded successfully.\n");
}

int main() {
    int sockfd;
    char *hostname = "ftp.example.com"; // Enter the hostname of the FTP server here
    char *username = "myusername"; // Enter your FTP username here
    char *password = "mypassword"; // Enter your FTP password here
    char *filename = "example.txt"; // Enter the filename of the file you want to download here

    // Connect to the FTP server
    sockfd = connect_to_ftp_server(hostname);

    // Login to the FTP server
    login_to_ftp_server(sockfd, username, password);

    // Download the file from the FTP server
    download_file(sockfd, filename);

    // Close the socket
    close(sockfd);

    return 0;
}