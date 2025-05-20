//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];

    // Check arguments
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    // Get server by hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(0);
    }

    // Set server information
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(0);
    }

    // Read response from server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(0);
    }

    // Print the response
    printf("%s", buffer);

    // Send IMAP command
    char* command = "a01 LOGIN user@example.com password\n";
    n = write(sockfd, command, strlen(command));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    // Read response from server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(0);
    }

    // Print the response
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}