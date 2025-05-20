//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the server's IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    server_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a command to the server
    char command[1024];
    printf("Enter a command: ");
    scanf("%s", command);
    if (strcmp(command, "QUIT") == 0) {
        close(sockfd);
        return 0;
    }
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Print the server's response
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}