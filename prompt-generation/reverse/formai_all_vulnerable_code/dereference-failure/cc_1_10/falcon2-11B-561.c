//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct sockaddr_in *create_sockaddr_in(const char *hostname, int port)
{
    struct sockaddr_in *addr = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = inet_addr(hostname);
    return addr;
}

void *scan_network(void *arg)
{
    struct addrinfo hints, *res;
    char port[16];
    int sockfd, rc;
    int i;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rc = getaddrinfo(NULL, "0", &hints, &res);
    if (rc) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
        return NULL;
    }

    for (i = 0; res!= NULL && i < 100; i++) {
        memset(port, 0, sizeof port);
        sprintf(port, "%d", rand() % 65535);
        struct sockaddr_in *addr = create_sockaddr_in(res->ai_canonname, atoi(port));
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sockfd < 0) {
            continue;
        }
        rc = connect(sockfd, addr, sizeof(*addr));
        if (rc == -1) {
            continue;
        }
        printf("Connected to %s on port %d\n", res->ai_canonname, atoi(port));
        close(sockfd);
        freeaddrinfo(res);
        break;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread;
    struct addrinfo hints, *res;
    int rc;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rc = getaddrinfo(NULL, "0", &hints, &res);
    if (rc) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
        return 1;
    }

    for (; res!= NULL; res = res->ai_next) {
        pthread_create(&thread, NULL, scan_network, (void*)res);
        pthread_join(thread, NULL);
    }

    freeaddrinfo(res);

    return 0;
}