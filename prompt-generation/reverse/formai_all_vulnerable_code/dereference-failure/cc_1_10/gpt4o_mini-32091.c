//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110 // POP3 port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_server(int *sockfd, const char *hostname) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memmove(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(*sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

void send_command(int sockfd, const char *command) {
    int n;
    // Send command to server
    n = write(sockfd, command, strlen(command));
    if (n < 0)
        error("ERROR writing to socket");
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    // Read response from server
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");
    
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username:password>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *credentials = argv[2];

    // Connect to the email server
    connect_to_server(&sockfd, hostname);

    // Read the server's welcome message
    read_response(sockfd);

    // Send user credentials
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", strtok(credentials, ":"));
    send_command(sockfd, command);
    read_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", strtok(NULL, ":"));
    send_command(sockfd, command);
    read_response(sockfd);

    // List the emails
    send_command(sockfd, "LIST\r\n");
    read_response(sockfd);

    // Retrieving the first email
    send_command(sockfd, "RETR 1\r\n");
    read_response(sockfd);

    // Close connection
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
    
    close(sockfd);
    return 0;
}