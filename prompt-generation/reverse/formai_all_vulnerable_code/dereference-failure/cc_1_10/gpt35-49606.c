//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <netdb.h>

#define MAX_HOSTS 256

struct host {
    char ip[INET_ADDRSTRLEN];
    char name[NI_MAXHOST];
};

struct host hosts[MAX_HOSTS];
int total_hosts = 0;

void get_ipv4_addresses() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }

            strncpy(hosts[total_hosts].ip, host, INET_ADDRSTRLEN);
            hosts[total_hosts].ip[INET_ADDRSTRLEN-1] = '\0';
            strncpy(hosts[total_hosts].name, ifa->ifa_name, NI_MAXHOST);
            hosts[total_hosts].name[NI_MAXHOST-1] = '\0';
            total_hosts++;
        }
    }

    freeifaddrs(ifaddr);
}

void get_hostnames() {
    struct hostent *he;
    unsigned long i, addr;

    for (i = 0; i < total_hosts; i++) {
        addr = inet_addr(hosts[i].ip);

        if (addr != INADDR_NONE) {
            he = gethostbyaddr((char *) &addr, sizeof(addr), AF_INET);

            if (he != NULL) {
                strncpy(hosts[i].name, he->h_name, NI_MAXHOST);
                hosts[i].name[NI_MAXHOST-1] = '\0';
            }
        }
    }
}

int main(int argc, char **argv) {
    int i;

    get_ipv4_addresses();
    get_hostnames();

    printf("NETWORK TOPOLOGY:\n");

    for (i = 0; i < total_hosts; i++) {
        printf("%s (%s)\n", hosts[i].name, hosts[i].ip);
    }

    exit(EXIT_SUCCESS);
}