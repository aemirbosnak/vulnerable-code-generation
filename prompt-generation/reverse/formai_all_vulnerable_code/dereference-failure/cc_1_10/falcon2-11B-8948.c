//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[MAX_LINE];

    // Check for proper command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Resolve the hostname into a network address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: hostname not found.\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket");
        exit(1);
    }

    // Set up the server address
    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    bzero((char *) &servaddr.sin_addr.s_addr, sizeof(servaddr.sin_addr));
    servaddr.sin_addr.s_addr = *(unsigned long *) server->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error: connect");
        exit(1);
    }

    // Send the username
    printf("Username: ");
    fgets(buffer, MAX_LINE, stdin);
    if (strlen(buffer) == 0) {
        fprintf(stderr, "Error: no username provided.\n");
        exit(1);
    }

    // Send the password
    printf("Password: ");
    fgets(buffer, MAX_LINE, stdin);
    if (strlen(buffer) == 0) {
        fprintf(stderr, "Error: no password provided.\n");
        exit(1);
    }

    // Send the login command
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server's response
    n = recv(sockfd, buffer, MAX_LINE, 0);
    if (n <= 0) {
        perror("Error: recv");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the quit command
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // Receive the server's response
    n = recv(sockfd, buffer, MAX_LINE, 0);
    if (n <= 0) {
        perror("Error: recv");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}