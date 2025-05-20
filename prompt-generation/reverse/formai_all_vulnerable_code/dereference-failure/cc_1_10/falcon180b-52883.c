//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *username;
    char *password;
    char *command;

    // Check if command line arguments are provided
    if (argc!= 5) {
        printf("Usage:./ftp_client <server_ip> <username> <password> <command>\n");
        return 1;
    }

    // Assign command line arguments to variables
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Socket creation failed\n");
        return 2;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        return 3;
    }

    printf("Connected to server\n");

    username = argv[2];
    password = argv[3];

    // Send USER command
    send(sockfd, username, strlen(username), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send PASS command
    send(sockfd, password, strlen(password), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Send command
    command = argv[4];
    send(sockfd, command, strlen(command), 0);

    // Receive response
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}