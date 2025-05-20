//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>


void scan_network(char *subnet);


int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        printf("Usage: %s <subnet>\n", argv[0]);
        return 1;
    }

    char *subnet = argv[1];
    scan_network(subnet);

    return 0;
}

void scan_network(char *subnet) {

    struct ifaddrs *addrs, *tmp;
    struct sockaddr_in *pAddr;
    char *ip;
    int sock, opt;
    struct hostent *server;
    struct timeval tv;
    fd_set readfds;
    socklen_t len;
    int ret;
    char buffer[1024];

    if (getifaddrs(&addrs) == -1) {
        fprintf(stderr, "getifaddrs() failed. %s\n", strerror(errno));
        return;
    }

    tmp = addrs;
    while (tmp) {
        if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_INET) {
            pAddr = (struct sockaddr_in*)tmp->ifa_addr;
            ip = inet_ntoa(pAddr->sin_addr);
            if (strstr(ip, subnet) == ip) {
                printf("%s:\n", tmp->ifa_name);
                for (int i = 1; i < 255; i++) {
                    char target[1024];
                    sprintf(target, "%s.%d", ip, i);
                    server = gethostbyname(target);
                    if (server == NULL) {
                        continue;
                    }

                    sock = socket(AF_INET, SOCK_STREAM, 0);
                    if (sock < 0) {
                        fprintf(stderr, "socket() failed. %s\n", strerror(errno));
                        continue;
                    }

                    opt = 1;
                    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
                    setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(opt));

                    struct sockaddr_in addr;
                    memset(&addr, 0, sizeof(addr));
                    addr.sin_family = AF_INET;
                    addr.sin_addr.s_addr = *(unsigned long*)server->h_addr;
                    addr.sin_port = htons(80);
                    len = sizeof(addr);

                    // Set socket timeout to 1 second
                    tv.tv_sec = 1;
                    tv.tv_usec = 0;
                    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

                    ret = connect(sock, (struct sockaddr*)&addr, len);
                    if (ret < 0 && errno == EINPROGRESS) {

                        FD_ZERO(&readfds);
                        FD_SET(sock, &readfds);

                        // Wait 1 second for socket to connect
                        tv.tv_sec = 1;
                        tv.tv_usec = 0;

                        if ((ret = select(sock+1, NULL, &readfds, NULL, &tv)) > 0) {
                            int error = 0;
                            socklen_t optlen = sizeof(error);

                            getsockopt(sock, SOL_SOCKET, SO_ERROR, &error, &optlen);
                            if (error == 0) {
                                printf("\t%s is up\n", target);
                            }
                        }
                    }

                    close(sock);
                }
            }
        }
        tmp = tmp->ifa_next;
    }

    freeifaddrs(addrs);
}