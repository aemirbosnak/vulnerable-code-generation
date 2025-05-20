//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *user;
    char *pass;

    // Check if arguments are provided
    if (argc < 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send username
    user = argv[2];
    strcat(user, "\r\n");
    write(sockfd, user, strlen(user));

    // Send password
    pass = argv[3];
    strcat(pass, "\r\n");
    write(sockfd, pass, strlen(pass));

    // Read server response
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n <= 0) {
        printf("Error reading server response\n");
        exit(1);
    }

    // Print server response
    printf("Server response:\n%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}