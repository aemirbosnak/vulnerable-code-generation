//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

int portno = 8080;
int listenfd, newsockfd, clilen;

void *thread_function(void *arg)
{
    struct sockaddr_in cliaddr;
    int *s = (int *) arg;
    int clilen = sizeof(cliaddr);

    printf("new connection from %s\n", inet_ntoa(cliaddr.sin_addr));
    if(recv(s, &clilen, sizeof(clilen), 0) == -1) {
        perror("recv");
        exit(1);
    }
    char *name = malloc(clilen);
    recv(s, name, clilen, 0);
    printf("received name: %s\n", name);
    free(name);

    char *question = "What is the capital of India?";
    send(s, question, strlen(question), 0);

    char *answer = "New Delhi";
    recv(s, answer, sizeof(answer), 0);
    printf("received answer: %s\n", answer);

    close(s);
    exit(0);
}

int main()
{
    int sockfd, newsockfd, clilen, valread;
    struct sockaddr_in serv_addr, cli_addr;
    char buff[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread;
        int *newfd = (int *) malloc(sizeof(int));
        *newfd = newsockfd;
        if (pthread_create(&thread, NULL, thread_function, newfd) < 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }

        close(newsockfd);
    }

    return 0;
}