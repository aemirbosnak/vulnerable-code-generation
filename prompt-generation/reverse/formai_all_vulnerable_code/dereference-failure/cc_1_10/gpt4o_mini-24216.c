//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to establish a connection to the FTP server
int connectToFtpServer(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    return sockfd;
}

// Function to send commands and receive responses from the FTP server
void sendCommand(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);  // Sending CRLF to terminate the command
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);  // Read the response
    printf("%s", buffer);  // Display the server's response
}

void ftpLogin(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    sprintf(command, "USER %s", username);
    sendCommand(sockfd, command);
    sprintf(command, "PASS %s", password);
    sendCommand(sockfd, command);
}

void listFiles(int sockfd) {
    sendCommand(sockfd, "PASV");

    // Now we should establish a data connection in passive mode
    // Extract the port using a regex or simple parsing from the response is necessary
    // But for this example, we will keep it simple:
    
    printf("Listing files...\n");
    sendCommand(sockfd, "LIST");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    printf("Starting FTP Client...\n");

    // Connect to the FTP server
    int sockfd = connectToFtpServer(hostname);
    printf("Connected to %s\n", hostname);

    // Reading the server greeting
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE - 1);
    printf("%s", buffer);

    // Login to the server
    ftpLogin(sockfd, username, password);

    // List files from the server
    listFiles(sockfd);
    
    // Clean up and close the connection
    close(sockfd);
    printf("Connection closed. Goodbye!\n");

    return 0;
}