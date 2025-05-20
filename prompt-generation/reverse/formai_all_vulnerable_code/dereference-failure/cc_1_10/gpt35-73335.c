//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {

    // Declare variables
    int sockfd, n;
    char recvline[MAXLINE + 1], user[MAXLINE + 1], pass[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *he;

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pop server>\n", argv[0]);
        exit(1);
    }

    // Get hostname
    if ((he=gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Set server address and port number
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Receive welcome message
    if ((n = read(sockfd, recvline, MAXLINE)) < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send USER command
    printf("Username: ");
    fgets(user, MAXLINE, stdin);
    user[strlen(user) - 1] = '\0';
    snprintf(recvline, MAXLINE, "USER %s\r\n", user);
    write(sockfd, recvline, strlen(recvline));

    // Receive +OK response
    if ((n = read(sockfd, recvline, MAXLINE)) < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send PASS command
    printf("Password: ");
    fgets(pass, MAXLINE, stdin);
    pass[strlen(pass) - 1] = '\0';
    snprintf(recvline, MAXLINE, "PASS %s\r\n", pass);
    write(sockfd, recvline, strlen(recvline));

    // Receive +OK response
    if ((n = read(sockfd, recvline, MAXLINE)) < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send LIST command
    snprintf(recvline, MAXLINE, "LIST\r\n");
    write(sockfd, recvline, strlen(recvline));

    // Receive message list
    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    // Close socket
    close(sockfd);

    return 0;
}