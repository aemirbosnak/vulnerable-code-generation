//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LINE 1024

int main() {
    // Get the hostname and port number from the user.
    char hostname[100];
    int port;
    printf("Enter the hostname: ");
    scanf("%s", hostname);
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Create a socket for connecting to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Define the server address.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Get the email from the user.
    char email[MAX_LINE];
    printf("Enter the email: ");
    scanf(" %[^\n]", email);

    // Send the email to the server.
    if (send(sockfd, email, strlen(email), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}