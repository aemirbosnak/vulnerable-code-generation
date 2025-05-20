//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

// FTP Commands
#define USER "USER"
#define PASS "PASS"
#define QUIT "QUIT"
#define LIST "LIST"
#define RETR "RETR"

// Function to handle errors
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to create socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }
    return sockfd;
}

// Function to connect to FTP server
void connect_to_server(int sockfd, const char *ip, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }
}

// Function to send commands to the server
void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

// Function to receive response from the server
void receive_response(int sockfd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("Error receiving response");
    }
    printf("Server: %s\n", buffer);
}

// Main function to run FTP client
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <PORT> <USERNAME>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    const char *username = argv[3];

    int sockfd = create_socket();
    connect_to_server(sockfd, ip, port);

    // Ask for username
    char command[256];
    snprintf(command, sizeof(command), "%s %s\r\n", USER, username);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Ask for password
    printf("Enter password: ");
    char password[64];
    scanf("%63s", password);
    snprintf(command, sizeof(command), "%s %s\r\n", PASS, password);
    send_command(sockfd, command);
    receive_response(sockfd);

    // List files in the current directory
    send_command(sockfd, LIST "\r\n");
    receive_response(sockfd);

    // Retrieve a sample file (sample.txt)
    send_command(sockfd, RETR "sample.txt\r\n");
    receive_response(sockfd);

    // Quit the session
    send_command(sockfd, QUIT "\r\n");
    receive_response(sockfd);

    close(sockfd);
    return 0;
}