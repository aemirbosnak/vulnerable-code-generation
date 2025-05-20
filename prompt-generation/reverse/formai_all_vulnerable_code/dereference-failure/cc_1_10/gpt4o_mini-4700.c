//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error connecting to server");

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) 
        error("Error reading from socket");

    printf("%s", buffer);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV");
    read_response(sockfd);

    // Get the data port from the server response
    // For simplicity, we skip parsing the actual data port.
    int data_sockfd = connect_to_server("127.0.0.1"); // Change to appropriate data connection

    send_command(sockfd, "LIST");
    read_response(sockfd);
    // This should also handle data from data_sockfd when implementing

    close(data_sockfd);
}

void download_file(int sockfd, const char *filename) {
    send_command(sockfd, "PASV");
    read_response(sockfd);

    // Again, you would establish a data connection and handle the download
    int data_sockfd = connect_to_server("127.0.0.1"); // Agains use appropriate host/port

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(sockfd, command);
    read_response(sockfd);
    // You would handle receiving the file data over data_sockfd

    close(data_sockfd);
}

void ftp_client(const char *hostname) {
    int sockfd = connect_to_server(hostname);
    read_response(sockfd); // Read server welcome message

    // Example usage: List files and download a file
    list_files(sockfd); // Replace with a filename and interface for user input
    download_file(sockfd, "example.txt"); // Replace with user input

    send_command(sockfd, "QUIT");
    read_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    ftp_client(argv[1]);
    return 0;
}