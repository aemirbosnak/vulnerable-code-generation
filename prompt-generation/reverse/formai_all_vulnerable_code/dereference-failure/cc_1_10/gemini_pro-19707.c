//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to establish a connection with the FTP server
int connect_to_server(char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command to the FTP server
void send_command(int sockfd, char *command) {
    // Send the command
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    char buffer[BUFFER_SIZE];
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Check if the response is an error
    if (buffer[0] == '5') {
        fprintf(stderr, "Error: %s", buffer);
        exit(EXIT_FAILURE);
    }

    // Print the response from the server
    printf("%s", buffer);
}

// Function to retrieve a file from the FTP server
int retrieve_file(int sockfd, char *filename) {
    // Open a file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Send the RETR command to the server
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "RETR %s", filename);
    send_command(sockfd, command);

    // Receive the file from the server
    char buffer[BUFFER_SIZE];
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        fwrite(buffer, 1, BUFFER_SIZE, fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Connect to the FTP server
    int sockfd = connect_to_server(argv[1], atoi(argv[2]));

    // Send the USER command to the server
    send_command(sockfd, "USER anonymous\r\n");

    // Send the PASS command to the server
    send_command(sockfd, "PASS anonymous@\r\n");

    // Send the CWD command to the server
    send_command(sockfd, "CWD /pub/\r\n");

    // Send the LIST command to the server
    send_command(sockfd, "LIST\r\n");

    // Retrieve a file from the FTP server
    retrieve_file(sockfd, "index.html");

    // Close the connection to the FTP server
    close(sockfd);

    return 0;
}