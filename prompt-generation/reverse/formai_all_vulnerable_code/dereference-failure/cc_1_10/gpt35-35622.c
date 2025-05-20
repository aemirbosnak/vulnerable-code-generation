//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_HOSTS 1000
#define MAX_IP_LEN 16

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *hostname = argv[1];
    char ip_str[MAX_IP_LEN];
    struct hostent *host;
    struct in_addr **addr_list;
    int i, j, sockfd, ret;
    struct sockaddr_in sa;
    socklen_t len = sizeof(sa);
    char buf[MAX_IP_LEN + 1];
    int hosts[MAX_HOSTS], num_hosts = 1;

    /* Resolve hostname to IP */
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    addr_list = (struct in_addr **) host->h_addr_list;
    if (addr_list == NULL) {
        perror("host->h_addr_list");
        exit(EXIT_FAILURE);
    }
    for (i = 0; addr_list[i] != NULL; i++) {
        printf("IP address %d: %s\n", i + 1, inet_ntoa(*addr_list[i]));
        if (num_hosts >= MAX_HOSTS) {
            fprintf(stderr, "Error: too many hosts to scan\n");
            exit(EXIT_FAILURE);
        }
        hosts[num_hosts++] = * (int *) addr_list[i];
    }

    /* Scan hosts and output results */
    for (i = 1; i < num_hosts; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = hosts[i];
        sa.sin_port = htons(80);
        ret = connect(sockfd, (struct sockaddr *) &sa, len);
        if (ret == -1) {
            perror("connect");
            printf("Host %s is down\n", inet_ntoa(sa.sin_addr));
        } else {
            ret = getnameinfo((struct sockaddr *) &sa, len, buf, sizeof(buf), NULL, 0, NI_NAMEREQD);
            if (ret != 0) {
                fprintf(stderr, "Error: %s\n", gai_strerror(ret));
                exit(EXIT_FAILURE);
            }
            printf("Host %s is up (reverse DNS: %s)\n", inet_ntoa(sa.sin_addr), buf);
        }
        close(sockfd);
    }

    return 0;
}