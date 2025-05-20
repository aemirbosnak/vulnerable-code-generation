//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <pthread.h>

#define BUFSIZE 4096

int sockfd;
struct sockaddr_in servaddr;

void *send_thread(void *arg) {
    char *buf = (char *)arg;
    while (1) {
        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        sleep(1);
    }
}

void *recv_thread(void *arg) {
    char *buf = (char *)arg;
    while (1) {
        recvfrom(sockfd, buf, BUFSIZE, 0, NULL, NULL);
        printf("%s", buf);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    pthread_t send_tid, recv_tid;
    pthread_create(&send_tid, NULL, send_thread, "Hello world!\n");
    pthread_create(&recv_tid, NULL, recv_thread, "");

    pthread_join(send_tid, NULL);
    pthread_join(recv_tid, NULL);

    close(sockfd);
    return 0;
}