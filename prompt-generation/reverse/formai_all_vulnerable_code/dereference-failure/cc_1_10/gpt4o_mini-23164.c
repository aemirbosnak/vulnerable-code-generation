//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

// Function to handle the connection to the FTP server
int ftp_connect(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get the server by hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command to the FTP server and receive the response
void ftp_send_command(int sockfd, const char *command, char *response, size_t resp_size) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
  
    // Clear response buffer
    memset(response, 0, resp_size);
    recv(sockfd, response, resp_size - 1, 0);
}

// Function to authenticate to the FTP server
int ftp_login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    ftp_send_command(sockfd, "USER", response, sizeof(response));
    printf("Server: %s", response);

    ftp_send_command(sockfd, username, response, sizeof(response));
    printf("Server: %s", response);

    ftp_send_command(sockfd, "PASS", response, sizeof(response));
    printf("Server: %s", response);

    ftp_send_command(sockfd, password, response, sizeof(response));
    printf("Server: %s", response);

    // Check if login was successful (usually 230 is success)
    if (strncmp(response, "230", 3) == 0) {
        return 1; // Login successful
    }

    return 0; // Login failed
}

// Function to retrieve a file from the FTP server
void ftp_get_file(int sockfd, const char *filename) {
    char response[BUFFER_SIZE];
    ftp_send_command(sockfd, "RETR", response, sizeof(response));
    printf("Server: %s", response);

    ftp_send_command(sockfd, filename, response, sizeof(response));
    printf("Server: %s", response);

    // Open file to save
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    // Transfer data in chunks
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }

    fclose(file);
    printf("File downloaded successfully.\n");
}

// Function to terminate the FTP session
void ftp_quit(int sockfd) {
    char response[BUFFER_SIZE];
    ftp_send_command(sockfd, "QUIT", response, sizeof(response));
    printf("Server: %s", response);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *filename = argv[4];

    // Connect to FTP server
    int sockfd = ftp_connect(hostname, FTP_PORT);
    char response[BUFFER_SIZE];

    // Receive initial server greeting
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response) - 1, 0);
    printf("Server: %s", response);

    // Login to FTP server
    if (ftp_login(sockfd, username, password)) {
        printf("Logged in successfully.\n");
        
        // Retrieve file from FTP server
        ftp_get_file(sockfd, filename);
        
        // Quit the FTP session
        ftp_quit(sockfd);
    } else {
        printf("Login failed.\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return 0;
}