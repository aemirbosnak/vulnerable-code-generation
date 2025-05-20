//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 21
#define MAX_BUFFER_SIZE 1024

// Function to display error messages
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to get the IP address of a hostname
char *get_ip_address(char *hostname) {
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        error("gethostbyname() failed");
    }
    return inet_ntoa(*((struct in_addr *)host->h_addr));
}

// Function to establish a connection to an FTP server
int connect_to_ftp_server(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket() failed");
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("connect() failed");
    }

    return sockfd;
}

// Function to send a command to an FTP server
void send_command(int sockfd, char *command) {
    // Send the command to the server
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("send() failed");
    }
}

// Function to receive a response from an FTP server
char *receive_response(int sockfd) {
    char *response = malloc(MAX_BUFFER_SIZE);
    memset(response, 0, MAX_BUFFER_SIZE);

    // Receive the response from the server
    if (recv(sockfd, response, MAX_BUFFER_SIZE, 0) < 0) {
        error("recv() failed");
    }

    return response;
}

// Function to list the files in a directory on an FTP server
void list_files(int sockfd) {
    // Send the LIST command to the server
    send_command(sockfd, "LIST\r\n");

    // Receive the response from the server
    char *response = receive_response(sockfd);

    // Print the response to the console
    printf("%s", response);
}

// Function to download a file from an FTP server
void download_file(int sockfd, char *filename) {
    // Send the RETR command to the server
    char command[MAX_BUFFER_SIZE];
    sprintf(command, "RETR %s\r\n", filename);
    send_command(sockfd, command);

    // Receive the response from the server
    char *response = receive_response(sockfd);

    // Open a file to write the downloaded data to
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("fopen() failed");
    }

    // Receive the file data from the server
    char buffer[MAX_BUFFER_SIZE];
    while (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    // Close the file
    fclose(fp);
}

// Function to upload a file to an FTP server
void upload_file(int sockfd, char *filename) {
    // Send the STOR command to the server
    char command[MAX_BUFFER_SIZE];
    sprintf(command, "STOR %s\r\n", filename);
    send_command(sockfd, command);

    // Receive the response from the server
    char *response = receive_response(sockfd);

    // Open the file to read the data from
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        error("fopen() failed");
    }

    // Send the file data to the server
    char buffer[MAX_BUFFER_SIZE];
    while (fread(buffer, 1, MAX_BUFFER_SIZE, fp) > 0) {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    // Close the file
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and port from the command line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Get the IP address of the hostname
    char *ip_address = get_ip_address(hostname);

    // Connect to the FTP server
    int sockfd = connect_to_ftp_server(ip_address, port);

    // Receive the welcome message from the server
    char *response = receive_response(sockfd);

    // Print the welcome message to the console
    printf("%s", response);

    // List the files in the current directory on the FTP server
    list_files(sockfd);

    // Download a file from the FTP server
    download_file(sockfd, "file.txt");

    // Upload a file to the FTP server
    upload_file(sockfd, "file.txt");

    // Close the connection to the FTP server
    close(sockfd);

    return 0;
}