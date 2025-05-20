//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define MAX_LINE_LENGTH 256
#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE_LENGTH];
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return 1;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        return 1;
    }

    printf("Connected to POP3 server\n");

    // Send USER command with username
    write(sockfd, "USER ", strlen("USER "));
    write(sockfd, username, strlen(username));
    printf("Sent USER command\n");

    // Read server response
    read(sockfd, buffer, MAX_LINE_LENGTH);
    printf("Server response: %s\n", buffer);

    // Send PASS command with password
    write(sockfd, "PASS ", strlen("PASS "));
    write(sockfd, password, strlen(password));
    printf("Sent PASS command\n");

    // Read server response
    read(sockfd, buffer, MAX_LINE_LENGTH);
    printf("Server response: %s\n", buffer);

    // Quit the session
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    printf("Sent QUIT command\n");

    // Close the socket
    close(sockfd);
    printf("Disconnected from POP3 server\n");

    return 0;
}