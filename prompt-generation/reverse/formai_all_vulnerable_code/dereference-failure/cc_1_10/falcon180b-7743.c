//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host, *username, *password;
    int port;

    // Check if the user provided the correct number of arguments
    if (argc!= 6) {
        printf("Usage:./ftp_client <host> <port> <username> <password>\n");
        return 1;
    }

    // Get the host, port, username, and password from the command line arguments
    host = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send the username and password to the server
    char *message = malloc(strlen(username) + strlen(password) + 3);
    sprintf(message, "USER %s\r\n", username);
    send(sockfd, message, strlen(message), 0);
    free(message);

    message = malloc(strlen(password) + 2);
    sprintf(message, "PASS %s\r\n", password);
    send(sockfd, message, strlen(message), 0);
    free(message);

    // Receive the server response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}