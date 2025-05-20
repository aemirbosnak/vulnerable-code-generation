//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void *handle_connection(void *);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, *new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    pthread_t thread;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            fprintf(stderr, "ERROR on accept\n");
            continue;
        }
        new_sockfd = malloc(1);
        *new_sockfd = newsockfd;
        pthread_create(&thread, NULL, handle_connection, (void *) new_sockfd);
    }

    return 0;
}

void *handle_connection(void *sockfd) {
    char buffer[256];
    int n;

    bzero(buffer, 256);
    n = read(*(int *) sockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        close(*(int *) sockfd);
        return NULL;
    }

    if (strncmp(buffer, "GET", 3) != 0) {
        fprintf(stderr, "ERROR invalid request\n");
        close(*(int *) sockfd);
        return NULL;
    }

    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>\n";
    n = write(*(int *) sockfd, response, strlen(response));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
    }

    close(*(int *) sockfd);
    free(sockfd);
    return NULL;
}