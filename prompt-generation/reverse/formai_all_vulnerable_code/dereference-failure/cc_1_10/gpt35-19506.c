//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define NUM_TESTS 5
#define THREAD_COUNT 5

void *ping_server(void *address);

int main(int argc, char *argv[]) {
    char *host;
    int i;
    pthread_t thread_ids[THREAD_COUNT];

    if (argc != 2) {
        fprintf(stderr,"usage: %s hostname\n", argv[0]);
        exit(1);
    }

    host = argv[1];

    for (i=0; i<THREAD_COUNT; i++) {
        pthread_create(&thread_ids[i], NULL, ping_server, (void *) host);
    }

    for (i=0; i<THREAD_COUNT; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    printf("Ping test completed successfully.\n");

    return 0;
}

void *ping_server(void *address) {
    char *host = (char *) address;
    int sockfd, i, err;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_in *h;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((err = getaddrinfo(host, "http", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(1);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", host);
        exit(1);
    }

    h = (struct sockaddr_in *) p->ai_addr;
    printf("Ping test: %s (%s)\n", host, inet_ntoa(h->sin_addr));

    for (i = 1; i <= NUM_TESTS; i++) {
        int status;
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);

        send(sockfd, "PING", 4, 0);
        printf("Ping %d: ", i);

        status = select(sockfd + 1, &fds, NULL, NULL, &tv);

        if (status == -1) {
            perror("select");
        }
        else if (status == 0) {
            printf("Timeout\n");
        }
        else {
            char buffer[256];
            recv(sockfd, buffer, 256, 0);
            printf("Received: %s\n", buffer);
        }

        sleep(1);
    }

    close(sockfd);

    pthread_exit(NULL);
}