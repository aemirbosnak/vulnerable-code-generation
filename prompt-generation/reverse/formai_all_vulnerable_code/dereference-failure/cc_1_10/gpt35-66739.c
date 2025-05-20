//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>

#define PORT "80"
#define MAXDATASIZE 100
#define TIMEOUT 2

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int scan_ip(const char *ip)
{
    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;
    char buf[MAXDATASIZE];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(ip, PORT, &hints, &servinfo)) != 0) {
        return 0;
    }

    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0 || setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        if(send(sockfd, "hello", strlen("hello"), 0) == -1) {
            close(sockfd);
            continue;
        }

        if(recv(sockfd, buf, MAXDATASIZE-1, 0) > 0) {
            printf("Found device at IP: %s \n", ip);
            close(sockfd);
            freeaddrinfo(servinfo);
            return 1;
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}

int main()
{
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char ip[INET6_ADDRSTRLEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET || family == AF_INET6) {
            if (getnameinfo(ifa->ifa_addr,
                            (family == AF_INET) ? sizeof(struct sockaddr_in) :
                            sizeof(struct sockaddr_in6),
                            ip, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST) == 0) {
                printf("Scanning on interface: %s\n", ifa->ifa_name);

                char *network_prefix = strtok(ip, ".");
                network_prefix = strcat(network_prefix, ".");
                char *second = strtok(NULL, ".");
                network_prefix = strcat(network_prefix, second);
                network_prefix = strcat(network_prefix, ".");
                char *third = strtok(NULL, ".");
                network_prefix = strcat(network_prefix, third);
                network_prefix = strcat(network_prefix, ".");

                for(int i = 0; i <= 255; i++) {
                    char target_ip[20];
                    sprintf(target_ip, "%s%d", network_prefix, i);
                    scan_ip(target_ip);
                }
            }
        }
    }

    freeifaddrs(ifaddr);
    return 0;
}