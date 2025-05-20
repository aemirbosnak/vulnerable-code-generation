//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    // Check if the command line arguments are valid
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    // Get the server address and port
    char *server_address = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    printf("Socket created\n");

    // Resolve the server address
    struct hostent *host = gethostbyname(server_address);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", server_address);
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to the server\n");

    // Send a command to the server
    char command[MAX_LINE];
    printf("Enter a command: ");
    fgets(command, MAX_LINE, stdin);

    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive a response from the server
    char response[MAX_LINE];
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response
    printf("Response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}