//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char buffer[BUFFER_SIZE];
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    // Login to server
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        perror("recv failed");
        exit(1);
    }
    printf("Login response: %s\n", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        perror("recv failed");
        exit(1);
    }
    printf("Password response: %s\n", buffer);

    // Send command to server
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        perror("recv failed");
        exit(1);
    }

    // Output server response
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}