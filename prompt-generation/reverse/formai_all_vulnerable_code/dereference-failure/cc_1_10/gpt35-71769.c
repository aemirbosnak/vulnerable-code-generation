//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to handle errors
void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE] = {0};

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get server hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Receive server greeting
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send login command
    char *user_cmd = "a001 LOGIN imap_username imap_password\r\n";
    n = send(sockfd, user_cmd, strlen(user_cmd), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive server response
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send list command
    char *list_cmd = "a002 LIST \"\" *\r\n";
    n = send(sockfd, list_cmd, strlen(list_cmd), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive server response
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send logout command
    char *logout_cmd = "a003 LOGOUT\r\n";
    n = send(sockfd, logout_cmd, strlen(logout_cmd), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive server response
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}