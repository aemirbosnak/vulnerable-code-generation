//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void *handle_client(void *arg)
{
    int sockfd = *(int *)arg;
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    while (1) {
        if (read(sockfd, buffer, sizeof(buffer)) <= 0) {
            break;
        }
        printf("Client: %s", buffer);
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            error("Error writing to socket");
            break;
        }
    }
    close(sockfd);
    free(arg);
    return NULL;
}

int main()
{
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error binding");
    }
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Error accepting");
        }
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = newsockfd;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            error("Error creating thread");
        }
    }
    close(sockfd);
    return 0;
}