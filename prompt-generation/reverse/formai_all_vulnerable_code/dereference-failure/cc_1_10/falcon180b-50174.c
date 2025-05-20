//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void *port_scanner(void *arg) {
    int sockfd, port;
    struct sockaddr_in server_addr;
    char *ip_address = (char *) arg;

    for (port = PORT_RANGE_MIN; port <= PORT_RANGE_MAX; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip_address);

        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open on %s\n", port, ip_address);
            close(sockfd);
        } else {
            printf("Port %d is closed on %s\n", port, ip_address);
            close(sockfd);
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Thread Count>\n");
        exit(1);
    }

    int num_threads = atoi(argv[2]);
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid thread count\n");
        exit(1);
    }

    pthread_t threads[num_threads];
    char *ip_address = argv[1];

    int rc;
    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, port_scanner, (void *) ip_address);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}