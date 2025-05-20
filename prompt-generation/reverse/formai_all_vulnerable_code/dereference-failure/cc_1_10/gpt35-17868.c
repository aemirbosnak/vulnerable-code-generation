//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 1024
#define HOST "pop3.server.com"
#define PORT "110"

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recvline[MAXLINE], buf[MAXLINE];
    struct addrinfo hints, *res;

    // Prepare hints for resolving server's address
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve server's address
    if (getaddrinfo(HOST, PORT, &hints, &res) != 0)
    {
        fprintf(stderr, "Error resolving server's address\n");
        return EXIT_FAILURE;
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error creating socket\n");
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0)
    {
        fprintf(stderr, "Error connecting to server\n");
        freeaddrinfo(res);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Read greeting message from server
    n = read(sockfd, recvline, MAXLINE-1);
    if (n <= 0)
    {
        fprintf(stderr, "Error receiving greeting message\n");
        freeaddrinfo(res);
        close(sockfd);
        return EXIT_FAILURE;
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send username to server
    printf("Username: ");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    sprintf(buf, "USER %s", strtok(buf, "\n"));
    write(sockfd, buf, strlen(buf));
    write(sockfd, "\r\n", 2);

    // Receive response from server
    n = read(sockfd, recvline, MAXLINE-1);
    if (n <= 0)
    {
        fprintf(stderr, "Error receiving username response\n");
        freeaddrinfo(res);
        close(sockfd);
        return EXIT_FAILURE;
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send password to server
    printf("Password: ");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    sprintf(buf, "PASS %s", strtok(buf, "\n"));
    write(sockfd, buf, strlen(buf));
    write(sockfd, "\r\n", 2);

    // Receive response from server
    n = read(sockfd, recvline, MAXLINE-1);
    if (n <= 0)
    {
        fprintf(stderr, "Error receiving password response\n");
        freeaddrinfo(res);
        close(sockfd);
        return EXIT_FAILURE;
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send command to list emails
    sprintf(buf, "LIST");
    write(sockfd, buf, strlen(buf));
    write(sockfd, "\r\n", 2);

    // Receive response from server
    n = read(sockfd, recvline, MAXLINE-1);
    if (n <= 0)
    {
        fprintf(stderr, "Error receiving email list response\n");
        freeaddrinfo(res);
        close(sockfd);
        return EXIT_FAILURE;
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send command to retrieve email
    sprintf(buf, "RETR 1");
    write(sockfd, buf, strlen(buf));
    write(sockfd, "\r\n", 2);

    // Receive response from server
    n = read(sockfd, recvline, MAXLINE-1);
    if (n <= 0)
    {
        fprintf(stderr, "Error receiving email response\n");
        freeaddrinfo(res);
        close(sockfd);
        return EXIT_FAILURE;
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Close connection
    freeaddrinfo(res);
    close(sockfd);

    return EXIT_SUCCESS;
}