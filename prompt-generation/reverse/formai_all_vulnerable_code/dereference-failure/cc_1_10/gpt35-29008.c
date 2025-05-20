//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAXLINE 1024

int sockfd;
pthread_mutex_t lock;

void *recv_thread(void *arg)
{
    char recvline[MAXLINE];
    int n;

    while (1)
    {
        n = recv(sockfd, recvline, MAXLINE, 0);
        if (n <= 0)
        {
            close(sockfd);
            exit(1);
        }

        recvline[n] = '\0';
        printf("%s", recvline);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    struct sockaddr_in servaddr;
    char user[MAXLINE], pass[MAXLINE];

    if (argc != 3)
    {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket error");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect error");
        return 1;
    }

    printf("Connected to IMAP server\n");

    memset(user, 0, MAXLINE);
    printf("Username: ");
    fgets(user, MAXLINE, stdin);

    memset(pass, 0, MAXLINE);
    printf("Password: ");
    fgets(pass, MAXLINE, stdin);

    snprintf(user, MAXLINE, "LOGIN %s %s\n", user, pass);
    send(sockfd, user, strlen(user), 0);

    pthread_t tid;
    pthread_create(&tid, NULL, recv_thread, NULL);

    char command[MAXLINE];
    while (fgets(command, MAXLINE, stdin) != NULL)
    {
        pthread_mutex_lock(&lock);
        send(sockfd, command, strlen(command), 0);
        pthread_mutex_unlock(&lock);
    }

    return 0;
}