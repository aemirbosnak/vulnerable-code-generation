//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define PORT_NUM 65535
#define MAX_THREADS 100

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int close(int fd);
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
void *scan_ports(void *arg);

int main(int argc, char **argv) {
    if(argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return -1;
    }

    char *ip = argv[1];
    struct in_addr in;

    if(inet_pton(AF_INET, ip, &in) <= 0) {
        printf("Invalid IP Address\n");
        return -1;
    }

    printf("Scanning %s...\n", ip);

    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    for(int i = 0; i < PORT_NUM; i++) {
        pthread_create(&threads[num_threads], NULL, scan_ports, (void *)i);
        num_threads++;
    }

    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *scan_ports(void *arg) {
    int port = *(int *)arg;

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sockfd);
    } else {
        printf("Port %d is closed\n", port);
        close(sockfd);
    }

    return NULL;
}