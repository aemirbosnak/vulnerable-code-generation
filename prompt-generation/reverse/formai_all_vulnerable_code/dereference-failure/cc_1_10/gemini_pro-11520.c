//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>

typedef struct _host {
    char *name;
    char *ip;
    struct _host *next;
} host;

typedef struct _link {
    host *h1;
    host *h2;
    struct _link *next;
} link;

host *hosts = NULL;
link *links = NULL;

void add_host(char *name, char *ip) {
    host *h = malloc(sizeof(host));
    h->name = strdup(name);
    h->ip = strdup(ip);
    h->next = hosts;
    hosts = h;
}

void add_link(host *h1, host *h2) {
    link *l = malloc(sizeof(link));
    l->h1 = h1;
    l->h2 = h2;
    l->next = links;
    links = l;
}

void print_topology() {
    host *h;
    link *l;

    printf("Hosts:\n");
    for (h = hosts; h != NULL; h = h->next) {
        printf("  %s (%s)\n", h->name, h->ip);
    }

    printf("Links:\n");
    for (l = links; l != NULL; l = l->next) {
        printf("  %s - %s\n", l->h1->name, l->h2->name);
    }
}

int main(int argc, char *argv[]) {
    struct ifaddrs *ifaddr, *ifa;
    int s, j;
    char host[NI_MAXHOST];
    char serv[NI_MAXSERV];

    if (getifaddrs(&ifaddr) < 0) {
        perror("getifaddrs");
        return 1;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        if (ifa->ifa_addr->sa_family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICSERV);
            if (s != 0) {
                printf("getnameinfo: %s\n", gai_strerror(s));
            } else {
                add_host(host, inet_ntoa(((struct sockaddr_in *)ifa->ifa_addr)->sin_addr));
            }
        }
    }

    freeifaddrs(ifaddr);

    for (j = 1; j < argc; j++) {
        s = getnameinfo((struct sockaddr *)&argv[j], sizeof(struct sockaddr_in), host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICSERV);
        if (s != 0) {
            printf("getnameinfo: %s\n", gai_strerror(s));
        } else {
            add_host(host, argv[j]);
        }
    }

    print_topology();

    return 0;
}