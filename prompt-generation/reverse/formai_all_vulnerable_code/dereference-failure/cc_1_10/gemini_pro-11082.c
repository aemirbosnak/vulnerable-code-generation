//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip_address> <port> <email_address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server_ip_address = argv[1];
    int port = atoi(argv[2]);
    char *email_address = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    int n;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the server's IP address
    server = gethostbyname(server_ip_address);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host as %s\n", server_ip_address);
        return EXIT_FAILURE;
    }

    // Fill in the server's address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the email address to the server
    n = write(sockfd, email_address, strlen(email_address));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the server
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Print the response from the server
    buffer[n] = '\0';
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}