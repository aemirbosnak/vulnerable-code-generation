//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    int bytes_received;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Get user input
    printf("Enter your command: ");
    fgets(buf, BUF_SIZE, stdin);

    // Send command to server
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response from server
    while ((bytes_received = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        printf("%s", buf);
    }

    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}