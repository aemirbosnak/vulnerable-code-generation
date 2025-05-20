//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants for FTP protocol
#define FTP_PORT 21
#define BUFFER_SIZE 1024

// Function declarations
void error(const char *msg);
int connect_to_ftp_server(const char *hostname);
void login_to_ftp(int sockfd, const char *username, const char *password);
void list_files(int sockfd);
void quit_ftp(int sockfd);

int main(int argc, char *argv[]) {
    // Ensure correct usage
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Visionary initialization message
    printf("Welcome to the FTP Client of Tomorrow!\n");
    printf("Connecting to remote server %s...\n", hostname);

    // Connecting to the FTP server
    int sockfd = connect_to_ftp_server(hostname);
    
    // Logging in to the FTP server
    login_to_ftp(sockfd, username, password);
    
    // Listing files in the current directory
    list_files(sockfd);
    
    // Quitting the FTP session
    quit_ftp(sockfd);
    
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_ftp_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Getting server info
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(FTP_PORT);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    // Receiving server greeting
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer); // Print the server response

    return sockfd;
}

void login_to_ftp(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    // Sending USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer); // Print server response

    // Sending PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer); // Print server response
}

void list_files(int sockfd) {
    char buffer[BUFFER_SIZE];
    
    // Sending LIST command
    snprintf(buffer, sizeof(buffer), "PASV\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer); // Print server response

    // Here you must open a data connection for file listing.
    // Pseudo-code representation for data connection logic.
    // Assume we now retrieve data connection address and port...

    // Sending LIST command to get the directory listing
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer); // Print directory listing
}

void quit_ftp(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Sending QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer); // Print server response
    
    // Closing the socket
    close(sockfd);
    printf("Disconnected from the server. Thank you for using the FTP Client of Tomorrow!\n");
}