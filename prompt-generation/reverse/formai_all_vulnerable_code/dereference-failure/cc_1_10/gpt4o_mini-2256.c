//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_ftp_server(const char *hostname, int port, int *sockfd) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Resolve the server address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Create socket
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set the server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(*sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Successfully connected to FTP server: %s:%d\n", hostname, port);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent command: %s", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    // Read the server response
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("ERROR receiving from socket");
    }
    printf("Server response: %s\n", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Send USER command
    sprintf(command, "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Send PASS command
    sprintf(command, "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    char command[BUFFER_SIZE];

    // Send LIST command
    sprintf(command, "PASV\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    // For this example, we simulate an accept connection where the data is sent
    printf("Simulate file listing...\n");
    sprintf(command, "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
}

void close_ftp_connection(int sockfd) {
    close(sockfd);
    printf("Connection closed.\n");
}

int main(int argc, char *argv[]) {
    int sockfd;
    const char *hostname = "ftp.dlptest.com"; // Example FTP server
    const char *username = "dlpuser";         // Test username
    const char *password = "rNrKYTX9g7z3RgJRmxWuGHbeu";

    if (argc > 1) {
        hostname = argv[1];
    }

    connect_to_ftp_server(hostname, 21, &sockfd); // Connect to FTP server
    receive_response(sockfd);

    ftp_login(sockfd, username, password);  // Log in to FTP server
    list_files(sockfd);                     // List files on server

    close_ftp_connection(sockfd);           // Close the connection

    return 0;
}