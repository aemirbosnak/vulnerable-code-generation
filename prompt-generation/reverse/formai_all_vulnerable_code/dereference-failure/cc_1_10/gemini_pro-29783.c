//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define MAX_BUFFER_SIZE 1024

// Function to establish a control connection with the FTP server
int establish_control_connection(char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return -1;
    }

    // Resolve the hostname
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        return -1;
    }

    // Set up the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return -1;
    }

    return sockfd;
}

// Function to send a command to the FTP server
int send_command(int sockfd, char *command) {
    int n;

    // Send the command
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        fprintf(stderr, "Error sending command\n");
        return -1;
    }

    return 0;
}

// Function to receive a response from the FTP server
int receive_response(int sockfd, char *buffer) {
    int n;

    // Receive the response
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (n < 0) {
        fprintf(stderr, "Error receiving response\n");
        return -1;
    }

    // Terminate the response string
    buffer[n] = '\0';

    return 0;
}

// Function to login to the FTP server
int login(int sockfd, char *username, char *password) {
    char buffer[MAX_BUFFER_SIZE];

    // Send the USER command
    send_command(sockfd, "USER ");
    send_command(sockfd, username);
    send_command(sockfd, "\r\n");

    // Receive the response
    receive_response(sockfd, buffer);

    // Check if the login was successful
    if (strncmp(buffer, "230", 3) != 0) {
        fprintf(stderr, "Login failed\n");
        return -1;
    }

    // Send the PASS command
    send_command(sockfd, "PASS ");
    send_command(sockfd, password);
    send_command(sockfd, "\r\n");

    // Receive the response
    receive_response(sockfd, buffer);

    // Check if the login was successful
    if (strncmp(buffer, "230", 3) != 0) {
        fprintf(stderr, "Login failed\n");
        return -1;
    }

    return 0;
}

// Function to retrieve a file from the FTP server
int retrieve_file(int sockfd, char *filename) {
    char buffer[MAX_BUFFER_SIZE];
    FILE *fp;

    // Send the RETR command
    send_command(sockfd, "RETR ");
    send_command(sockfd, filename);
    send_command(sockfd, "\r\n");

    // Receive the response
    receive_response(sockfd, buffer);

    // Check if the file transfer was successful
    if (strncmp(buffer, "150", 3) != 0) {
        fprintf(stderr, "File transfer failed\n");
        return -1;
    }

    // Open the file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    // Receive the file data
    while (1) {
        int n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (n <= 0) {
            break;
        }
        fwrite(buffer, 1, n, fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to close the connection with the FTP server
void close_connection(int sockfd) {
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd;

    // Check if the correct number of arguments were provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    // Get the host, username, and password from the command line arguments
    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Establish a control connection with the FTP server
    sockfd = establish_control_connection(host, FTP_PORT);
    if (sockfd < 0) {
        return 1;
    }

    // Login to the FTP server
    if (login(sockfd, username, password) < 0) {
        close_connection(sockfd);
        return 1;
    }

    // Retrieve a file from the FTP server
    if (retrieve_file(sockfd, "test.txt") < 0) {
        close_connection(sockfd);
        return 1;
    }

    // Close the connection with the FTP server
    close_connection(sockfd);

    return 0;
}