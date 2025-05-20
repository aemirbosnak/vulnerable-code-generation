//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("Received: %s", buffer);
}

int main(int argc, char *argv[]) {
    char *hostname, *username, *password, *remote_file;
    int sockfd, port;
    struct sockaddr_in server_addr;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <remote_file>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];
    remote_file = argv[4];

    port = FTP_PORT;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // Set up server address structure
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) error("ERROR, no such host");

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Read welcome message
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("Received: %s", buffer);

    // User login
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);

    // Set passive mode
    send_command(sockfd, "PASV\r\n");

    // Determine the data port
    int p1, p2, data_port;
    sscanf(buffer, "%*s %*s %*s %*s %d,%d", &p1, &p2);
    data_port = p1 * 256 + p2;

    // Connect to data port
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_port = htons(data_port);
    if (connect(data_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting to data port");

    // Retrieve file
    snprintf(command, sizeof(command), "RETR %s\r\n", remote_file);
    send_command(sockfd, command);

    // Receive file data and save to local file
    FILE *fp = fopen(remote_file, "wb");
    if (fp == NULL) error("ERROR opening file");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int n = recv(data_sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (n <= 0) break; // End of file
        fwrite(buffer, 1, n, fp);
    }
    
    printf("File downloaded successfully\n");

    fclose(fp);
    close(data_sockfd);
    close(sockfd);
    
    return 0;
}