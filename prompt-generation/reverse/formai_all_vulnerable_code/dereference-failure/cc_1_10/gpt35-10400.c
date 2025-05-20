//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Check the arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }

    // Get the server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Set up the socket
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Connect to the server
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serveraddr.sin_addr.s_addr,
          server->h_length);
    serveraddr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        error("ERROR connecting");
    }

    // Read the welcome message
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send the login command
    char user[BUFFER_SIZE];
    char pass[BUFFER_SIZE];
    printf("Username: ");
    fgets(user, BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(pass, BUFFER_SIZE, stdin);
    sprintf(buffer, "LOGIN %s %s\n", user, pass);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the response to the login command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send the LIST command
    sprintf(buffer, "LIST\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the response to the LIST command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send the SELECT command
    char mailbox[BUFFER_SIZE];
    printf("Select mailbox: ");
    fgets(mailbox, BUFFER_SIZE, stdin);
    sprintf(buffer, "SELECT %s\n", mailbox);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the response to the SELECT command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send the FETCH command
    char seq[BUFFER_SIZE];
    printf("Enter sequence number: ");
    fgets(seq, BUFFER_SIZE, stdin);
    sprintf(buffer, "FETCH %s\n", seq);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the response to the FETCH command
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}