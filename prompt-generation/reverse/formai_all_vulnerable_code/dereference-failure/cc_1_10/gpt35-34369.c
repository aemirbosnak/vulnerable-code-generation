//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    printf("Welcome to the surreal IMAP client!\n");

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
    int bytes_sent, bytes_recv;
    char username[BUFSIZE];
    char password[BUFSIZE];
    char command[BUFSIZE];
    char response[BUFSIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // get server info
    server = gethostbyname("imap.surrealmail.com");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // setup server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(993);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }
    printf("Connected to IMAP server.\n");

    // authenticate with server
    printf("Enter username: ");
    fgets(username, BUFSIZE-1, stdin);
    printf("Enter password: ");
    fgets(password, BUFSIZE-1, stdin);

    sprintf(command, "LOGIN %s %s", username, password);
    bytes_sent = write(sockfd, command, strlen(command));
    bytes_recv = read(sockfd, response, BUFSIZE-1);
    response[bytes_recv] = '\0';

    if (strlen(response) > 0 && response[0] == '+')
    {
        printf("Authenticated with IMAP server.\n");
    }
    else
    {
        printf("Failed to authenticate with IMAP server.\n");
        close(sockfd);
        exit(0);
    }

    // list folders on server
    printf("List of folders on server:\n");
    sprintf(command, "LIST \"\" *");
    bytes_sent = write(sockfd, command, strlen(command));
    bytes_recv = read(sockfd, response, BUFSIZE-1);
    response[bytes_recv] = '\0';
    printf("%s\n", response);

    // select inbox
    sprintf(command, "SELECT INBOX");
    bytes_sent = write(sockfd, command, strlen(command));
    bytes_recv = read(sockfd, response, BUFSIZE-1);
    response[bytes_recv] = '\0';
    printf("Selected INBOX.\n");

    // fetch inbox messages
    sprintf(command, "FETCH 1:* (BODY[HEADER])");
    bytes_sent = write(sockfd, command, strlen(command));
    bytes_recv = read(sockfd, response, BUFSIZE-1);
    response[bytes_recv] = '\0';
    printf("Fetched inbox messages.\n");

    // logout and close connection
    sprintf(command, "LOGOUT");
    bytes_sent = write(sockfd, command, strlen(command));
    bytes_recv = read(sockfd, response, BUFSIZE-1);
    response[bytes_recv] = '\0';
    printf("Logged out of IMAP server.\n");
    close(sockfd);

    return 0;
}