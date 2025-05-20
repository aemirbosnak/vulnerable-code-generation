//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <netdb.h>
#include <fcntl.h>

#define FTP_PORT 21
#define MAX_HOSTNAME 256
#define MAX_USERNAME 64
#define MAX_PASSWORD 64
#define ERROR -1
#define SUCCESS 0
#define MAX_DATA 1024

// Function to establish a TCP connection with the FTP server
int establishConnection(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == ERROR) {
        perror("Error creating socket");
        return ERROR;
    }

    // Set the server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("Error converting hostname to IP address");
        close(sockfd);
        return ERROR;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return ERROR;
    }

    return sockfd;
}

// Function to send a command to the FTP server
int sendCommand(int sockfd, const char *command) {
    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error sending command to server");
        return ERROR;
    }

    // Receive the response from the server
    char response[MAX_DATA];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Error receiving response from server");
        return ERROR;
    }

    // Check the response code
    if (response[0] != '2') {
        printf("Error: %s", response);
        return ERROR;
    }

    return SUCCESS;
}

// Function to receive a file from the FTP server
int receiveFile(int sockfd, const char *filename) {
    // Open the file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return ERROR;
    }

    // Receive the file data from the server
    char buffer[MAX_DATA];
    int bytesReceived;
    while ((bytesReceived = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytesReceived, fp);
    }

    // Close the file
    fclose(fp);

    return SUCCESS;
}

int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 4) {
        printf("Usage: %s hostname filename username password\n", argv[0]);
        return ERROR;
    }

    // Establish a connection with the FTP server
    int sockfd = establishConnection(argv[1], FTP_PORT);
    if (sockfd == ERROR) {
        return ERROR;
    }

    // Send the username and password to the server
    if (sendCommand(sockfd, "USER ") == ERROR) {
        close(sockfd);
        return ERROR;
    }
    if (sendCommand(sockfd, argv[3]) == ERROR) {
        close(sockfd);
        return ERROR;
    }
    if (sendCommand(sockfd, "PASS ") == ERROR) {
        close(sockfd);
        return ERROR;
    }
    if (sendCommand(sockfd, argv[4]) == ERROR) {
        close(sockfd);
        return ERROR;
    }

    // Send the RETR command to the server to retrieve the file
    if (sendCommand(sockfd, "RETR ") == ERROR) {
        close(sockfd);
        return ERROR;
    }
    if (sendCommand(sockfd, argv[2]) == ERROR) {
        close(sockfd);
        return ERROR;
    }

    // Receive the file from the server
    if (receiveFile(sockfd, argv[2]) == ERROR) {
        close(sockfd);
        return ERROR;
    }

    // Close the connection with the FTP server
    close(sockfd);

    return SUCCESS;
}