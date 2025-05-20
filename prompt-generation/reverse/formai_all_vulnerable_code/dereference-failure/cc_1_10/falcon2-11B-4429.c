//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define PORT 143

void connect_to_imap_server(const char* hostname, const char* username, const char* password) {
    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in server_addr;

    // Resolve hostname to IP address
    if ((server = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "ERROR: Unknown host\n");
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("ERROR setting socket options");
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bzero((char *) &server_addr.sin_addr, sizeof(server_addr.sin_addr));
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    // Send authentication credentials
    char auth_cmd[BUFFER_SIZE];
    sprintf(auth_cmd, "AUTH LOGIN %s %s", username, password);
    if (write(sockfd, auth_cmd, strlen(auth_cmd)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive authentication response
    char response[BUFFER_SIZE];
    if (read(sockfd, response, BUFFER_SIZE) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Check if authentication failed
    if (strcmp(response, "OK")!= 0) {
        fprintf(stderr, "ERROR: Authentication failed\n");
        exit(1);
    }

    // Send IMAP commands
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "CAPABILITY");
    if (write(sockfd, cmd, strlen(cmd)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive IMAP capabilities
    char capabilities[BUFFER_SIZE];
    if (read(sockfd, capabilities, BUFFER_SIZE) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print IMAP capabilities
    printf("IMAP capabilities: %s\n", capabilities);

    // Close socket
    if (close(sockfd) < 0) {
        perror("ERROR closing socket");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <command>\n", argv[0]);
        exit(1);
    }

    connect_to_imap_server(argv[1], argv[2], argv[3]);

    return 0;
}