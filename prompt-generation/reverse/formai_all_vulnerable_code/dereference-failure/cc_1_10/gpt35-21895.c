//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int access_imap_server(const char *hostname, const char *username, const char *password)
{
    int sockfd, nbytes;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serveraddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(143);
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("ERROR connecting");
        return -1;
    }

    nbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (nbytes < 0) 
    {
        perror("ERROR reading from socket");
        return -1;
    }

    printf("%s\n", buffer);

    char login_command[MAX_BUFFER_SIZE];
    snprintf(login_command, MAX_BUFFER_SIZE, "a1 LOGIN %s %s\r\n", username, password);
    write(sockfd, login_command, strlen(login_command));

    bzero(buffer, MAX_BUFFER_SIZE);
    nbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (nbytes < 0) 
    {
        perror("ERROR reading from socket");
        return -1;
    }

    printf("%s\n", buffer);

    return sockfd;
}

int fetch_inbox_emails(int sockfd)
{
    char fetch_command[MAX_BUFFER_SIZE];
    snprintf(fetch_command, MAX_BUFFER_SIZE, "a2 EXAMINE INBOX\r\n");
    printf("%s", fetch_command);
    write(sockfd, fetch_command, strlen(fetch_command));
    char buffer[MAX_BUFFER_SIZE];
    bzero(buffer, MAX_BUFFER_SIZE);
    int nbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (nbytes < 0) 
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s\n", buffer);

    char fetch_command2[MAX_BUFFER_SIZE];
    snprintf(fetch_command2, MAX_BUFFER_SIZE, "a3 FETCH 1:* (UID FLAGS BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n");
    printf("%s", fetch_command2);
    write(sockfd, fetch_command2, strlen(fetch_command2));
    bzero(buffer, MAX_BUFFER_SIZE);
    nbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (nbytes < 0) 
    {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s\n", buffer);

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Usage: ./imap_client hostname username password\n");
        return -1;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = access_imap_server(hostname, username, password);
    if (sockfd < 0)
    {
        return -1;
    }

    fetch_inbox_emails(sockfd);

    close(sockfd);

    return 0;
}