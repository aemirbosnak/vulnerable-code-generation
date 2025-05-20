//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define READ_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char read_buffer[READ_BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3)
    {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    // send user and password to authenticate
    char user[256];
    char password[256];
    printf("Enter user: ");
    fgets(user, 256, stdin);
    printf("Enter password: ");
    fgets(password, 256, stdin);
    char login[512];
    sprintf(login, "LOGIN %s %s\r\n", user, password);
    write(sockfd, login, strlen(login));
    bzero(read_buffer, READ_BUFFER_SIZE);
    n = read(sockfd, read_buffer, READ_BUFFER_SIZE);
    if (n < 0)
    {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }
    printf("%s", read_buffer);

    // select mailbox inbox
    write(sockfd, "SELECT INBOX\r\n", 15);
    bzero(read_buffer, READ_BUFFER_SIZE);
    n = read(sockfd, read_buffer, READ_BUFFER_SIZE);
    if (n < 0)
    {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }
    printf("%s", read_buffer);

    // search for unseen messages
    write(sockfd, "SEARCH UNSEEN\r\n", 15);
    bzero(read_buffer, READ_BUFFER_SIZE);
    n = read(sockfd, read_buffer, READ_BUFFER_SIZE);
    if (n < 0)
    {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }
    printf("Unseen messages:\n%s", read_buffer);

    close(sockfd);
    return 0;
}