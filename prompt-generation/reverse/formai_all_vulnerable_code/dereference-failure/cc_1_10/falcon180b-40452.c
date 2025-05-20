//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <time.h>

int main() {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[NI_MAXSERV];
    int num_hosts = 0;
    int num_hosts_up = 0;
    int num_hosts_down = 0;
    int max_attempts = 5;
    int attempts = 0;
    int this_attempt = 0;
    time_t start_time;
    time_t end_time;
    double total_time;
    start_time = time(NULL);
    printf("Starting ping test...\n");
    if (getaddrinfo("www.google.com", "http", &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            continue;
        }
        if (getsockopt(sock, SOL_SOCKET, SO_ERROR, (char *)&rv, (socklen_t)sizeof(rv)) == -1) {
            close(sock);
            perror("getsockopt");
            continue;
        }
        if (rv == 0) {
            num_hosts_up++;
            printf("Host is up: %s\n", s);
        } else {
            num_hosts_down++;
            printf("Host is down: %s\n", s);
        }
        close(sock);
    }
    end_time = time(NULL);
    total_time = difftime(end_time, start_time);
    printf("Total time taken for the ping test: %.2lf seconds\n", total_time);
    printf("Number of hosts up: %d\n", num_hosts_up);
    printf("Number of hosts down: %d\n", num_hosts_down);
    return 0;
}