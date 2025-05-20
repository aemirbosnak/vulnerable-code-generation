//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 8192 /* max text line length */

/* Function signatures */
void error(char *msg);
int open_clientfd(char *host, int port);
void quit(int fd);

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    char user[80], password[80], email[80];
    char command[1024], response[1024];
    char *p, *q;
    struct sockaddr_in serveraddr;
    struct hostent *hp;
    int port = atoi(argv[2]);

    /* Check command line arguments */
    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }

    /* Open a connection to the server */
    sockfd = open_clientfd(argv[1], port);

    /* Read greeting message from server */
    n = read(sockfd, recvline, MAXLINE);
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Send user command and get response */
    printf("Enter user name: ");
    fflush(stdout);
    fgets(user, 80, stdin);
    user[strlen(user) - 1] = '\0'; /* Remove newline character */
    sprintf(command, "a001 LOGIN %s ", user);
    write(sockfd, command, strlen(command));
    n = read(sockfd, response, 1024);
    response[n] = '\0';
    printf("%s\n", response);

    /* Send password command and get response */
    printf("Enter password: ");
    fflush(stdout);
    fgets(password, 80, stdin);
    password[strlen(password) - 1] = '\0'; /* Remove newline character */
    sprintf(command, "a002 PASSWORD %s ", password);
    write(sockfd, command, strlen(command));
    n = read(sockfd, response, 1024);
    response[n] = '\0';
    printf("%s\n", response);

    /* Send list command and get response */
    sprintf(command, "a003 LIST \"\" *");
    write(sockfd, command, strlen(command));
    n = read(sockfd, response, 1024);
    response[n] = '\0';
    printf("%s\n", response);

    /* Send logout command */
    quit(sockfd);

    exit(0);
}

/*
 * error - wrapper for perror
 */
void error(char *msg)
{
    perror(msg);
    exit(0);
}

/*
 * open_clientfd - open connection to server at <hostname, port>
 *  and return a socket descriptor ready for reading and writing.
 *
 *  If the connection fails, terminate the process.
 */
int open_clientfd(char *hostname, int port)
{
    int clientfd;
    struct hostent *hp;
    struct sockaddr_in serveraddr;

    /* Create a socket */
    if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;

    /* Fill in the server's IP address and port */
    if ((hp = gethostbyname(hostname)) == NULL)
        return -2;
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)hp->h_addr_list[0],
            (char *)&serveraddr.sin_addr.s_addr, hp->h_length);
    serveraddr.sin_port = htons(port);

    /* Establish a connection with the server */
    if (connect(clientfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
        return -1;

    return clientfd;
}

/*
 * quit - send logout command and close socket
 */
void quit(int fd)
{
    char command[1024], response[1024];
    int n;

    /* Send logout command and get response */
    sprintf(command, "a004 LOGOUT");
    write(fd, command, strlen(command));
    n = read(fd, response, 1024);
    response[n] = '\0';
    printf("%s\n", response);

    /* Close the socket */
    close(fd);
}