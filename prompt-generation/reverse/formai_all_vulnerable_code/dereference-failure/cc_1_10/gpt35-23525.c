//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

// Function to display error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR: Failed to open socket.");

    // Get server address and port number
    server = gethostbyname("pop.gmail.com");
    portno = 995;

    // Initialize server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR: Failed to connect to server.");

    // Receive server greeting
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR: Failed to read from socket.");
    printf("%s", buffer);

    // Send username and password
    char *username = "USERNAME_HERE";
    char *password = "PASSWORD_HERE";
    char login[BUFFER_SIZE];
    sprintf(login, "USER %s\r\n", username);
    n = write(sockfd, login, strlen(login));
    if (n < 0)
        error("ERROR: Failed to write to socket.");
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR: Failed to read from socket.");
    printf("%s", buffer);
    char pass[BUFFER_SIZE];
    sprintf(pass, "PASS %s\r\n", password);
    n = write(sockfd, pass, strlen(pass));
    if (n < 0)
        error("ERROR: Failed to write to socket.");
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR: Failed to read from socket.");
    printf("%s", buffer);

    // Send retrieve command for all emails
    n = write(sockfd, "RETR 1-100\r\n", strlen("RETR 1-100\r\n"));
    if (n < 0)
        error("ERROR: Failed to write to socket.");

    // Read and print each email
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE-1);
        if (n < 0)
            error("ERROR: Failed to read from socket.");
        if (strstr(buffer, "-ERR")) {
            printf("%s", buffer);
            break;
        } else {
            printf("%s", buffer);
        }
    }

    // Close socket and exit program
    close(sockfd);
    return 0;
}