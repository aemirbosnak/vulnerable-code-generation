//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>

#define SA struct sockaddr

#define MAXLINE 1024

int sockfd;

void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("\nCtrl-C received, closing socket and terminating\n");
    close(sockfd);
    exit(0);
}

void usage(char *argv[])
{
    printf("USAGE: %s <hostname> <port>\n", argv[0]);
}

void str_cli(FILE *fp, int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];
    struct timeval tv;

    tv.tv_sec = 5;              // Set the timeout value to 5 seconds
    tv.tv_usec = 0;             // microseconds
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv)) < 0) // Set the socket option for receive timeout
    {
        perror("Error setting socket option");
        exit(1);
    }

    while (fgets(sendline, MAXLINE, fp) != NULL)
    {
        write(sockfd, sendline, strlen(sendline));
        if (read(sockfd, recvline, MAXLINE) == 0)
        {
            printf("str_cli: server terminated prematurely\n");
            exit(1);
        }
        printf("%s", recvline);
    }
}

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;

    if (argc != 3)
    {
        usage(argv);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        perror("Error using inet_pton");
        exit(1);
    }

    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting");
        exit(1);
    }

    signal(SIGINT, sig_handler);    // Set the signal handler for SIGINT (Ctrl-C)

    str_cli(stdin, sockfd);         // Start the client program

    return 0;
}