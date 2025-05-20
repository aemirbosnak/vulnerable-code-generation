//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <signal.h>

#define BUF_SIZE 1024
#define MAX_CONNECTIONS 5
#define DEFAULT_SERVER_PORT 8080
#define DEFAULT_SERVER_ADDR "127.0.0.1"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server-address> <server-port>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int sockfd;
    if ((sockfd = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol)) == -1)
        error("ERROR opening socket");

    if (getaddrinfo(argv[1], argv[2], &hints, &servinfo) == -1)
        error("ERROR resolving server address");

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
            error("ERROR opening socket");

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL)
        error("ERROR connecting to server");

    if (listen(sockfd, MAX_CONNECTIONS) == -1)
        error("ERROR listening on socket");

    while (1) {
        struct sockaddr_in clientaddr;
        socklen_t clientlen = sizeof(clientaddr);

        int newfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (newfd == -1)
            error("ERROR accepting connection");

        printf("Connected to client: %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

        // Simulate network quality of service by introducing delays
        for (int i = 0; i < 10; i++) {
            struct timeval start, end;
            gettimeofday(&start, NULL);

            send(newfd, "Hello, client!", strlen("Hello, client!") + 1, 0);
            if (recv(newfd, "World!", sizeof("World!"), 0) == -1)
                error("ERROR receiving from client");

            gettimeofday(&end, NULL);
            printf("Delay: %ld.%06ld ms\n", (end.tv_sec - start.tv_sec) * 1000, (end.tv_usec - start.tv_usec) / 1000);
        }

        close(newfd);
    }

    return 0;
}