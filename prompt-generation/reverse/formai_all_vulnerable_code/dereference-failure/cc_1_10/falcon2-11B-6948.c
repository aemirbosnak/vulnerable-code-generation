//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

void* packet_listener(void* arg)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[1024];

    sockfd = *(int*)arg;
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        bzero(buf, sizeof(buf));
        n = read(sockfd, buf, sizeof(buf));
        if (n < 0) {
            perror("read");
            exit(1);
        }

        printf("Received packet: %s\n", buf);
    }

    close(sockfd);
    return NULL;
}

int main(int argc, char** argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    pthread_t thread;
    int ret;

    ret = pthread_create(&thread, NULL, packet_listener, &sockfd);
    if (ret < 0) {
        perror("pthread_create");
        exit(1);
    }

    printf("Listening for packets on port %d\n", atoi(argv[1]));

    while (1) {
        sleep(1);
    }

    pthread_join(thread, NULL);

    close(sockfd);
    return 0;
}