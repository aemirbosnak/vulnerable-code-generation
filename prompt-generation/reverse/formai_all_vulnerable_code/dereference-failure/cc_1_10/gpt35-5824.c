//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143 // IMAP Port number
#define MAX_BUFFER_SIZE 1024 // Maximum buffer size for reading server response

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    
    // Check if command line arguments are valid
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    // Get server host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    // Set up socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    server_addr.sin_port = htons(IMAP_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        exit(1);
    }

    // Read server welcome message
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from server\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send username to server
    char user_cmd[MAX_BUFFER_SIZE];
    snprintf(user_cmd, sizeof(user_cmd), "1 LOGIN %s\n", argv[2]);
    n = write(sockfd, user_cmd, strlen(user_cmd));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to server\n");
        exit(1);
    }

    // Read server response to username command
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from server\n");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);
    return 0;
}