//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 16
#define MAX_HOSTS 256

struct interface {
    char *name;
    unsigned int ip;
    unsigned int mask;
    struct interface *next;
};

struct host {
    char *name;
    unsigned int ip;
    struct host *next;
};

struct link {
    struct host *host1;
    struct host *host2;
    struct link *next;
};

struct network {
    struct interface *interfaces;
    struct host *hosts;
    struct link *links;
};

void print_error(char *msg) {
    perror(msg);
    exit(1);
}

void print_interface(struct interface *iface) {
    printf("%s: %s/%d\n", iface->name, inet_ntoa(*(struct in_addr *)&iface->ip), iface->mask);
}

void print_host(struct host *host) {
    printf("%s: %s\n", host->name, inet_ntoa(*(struct in_addr *)&host->ip));
}

void print_link(struct link *link) {
    printf("%s -> %s\n", link->host1->name, link->host2->name);
}

void print_network(struct network *network) {
    struct interface *iface;
    struct host *host;
    struct link *link;

    printf("Interfaces:\n");
    for (iface = network->interfaces; iface != NULL; iface = iface->next) {
        print_interface(iface);
    }

    printf("\nHosts:\n");
    for (host = network->hosts; host != NULL; host = host->next) {
        print_host(host);
    }

    printf("\nLinks:\n");
    for (link = network->links; link != NULL; link = link->next) {
        print_link(link);
    }
}

void free_network(struct network *network) {
    struct interface *iface, *next_iface;
    struct host *host, *next_host;
    struct link *link, *next_link;

    for (iface = network->interfaces; iface != NULL; iface = next_iface) {
        next_iface = iface->next;
        free(iface->name);
        free(iface);
    }

    for (host = network->hosts; host != NULL; host = next_host) {
        next_host = host->next;
        free(host->name);
        free(host);
    }

    for (link = network->links; link != NULL; link = next_link) {
        next_link = link->next;
        free(link);
    }

    free(network);
}

struct network *discover_network() {
    struct network *network;
    struct ifaddrs *ifaddrs, *ifa;
    struct hostent *hostent;
    struct sockaddr_in *sa;
    struct interface *iface;
    struct host *host;
    struct link *link;
    int sockfd;

    network = malloc(sizeof(struct network));
    if (network == NULL) {
        print_error("malloc");
    }

    network->interfaces = NULL;
    network->hosts = NULL;
    network->links = NULL;

    if (getifaddrs(&ifaddrs) == -1) {
        print_error("getifaddrs");
    }

    for (ifa = ifaddrs; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET) {
            continue;
        }

        iface = malloc(sizeof(struct interface));
        if (iface == NULL) {
            print_error("malloc");
        }

        iface->name = strdup(ifa->ifa_name);
        if (iface->name == NULL) {
            print_error("strdup");
        }

        sa = (struct sockaddr_in *)ifa->ifa_addr;
        iface->ip = sa->sin_addr.s_addr;

        sa = (struct sockaddr_in *)ifa->ifa_netmask;
        iface->mask = sa->sin_addr.s_addr;

        iface->next = network->interfaces;
        network->interfaces = iface;
    }

    freeifaddrs(ifaddrs);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        print_error("socket");
    }

    for (iface = network->interfaces; iface != NULL; iface = iface->next) {
        struct ifreq ifr;

        strcpy(ifr.ifr_name, iface->name);

        if (ioctl(sockfd, SIOCGIFBRDADDR, &ifr) == -1) {
            print_error("ioctl");
        }

        sa = (struct sockaddr_in *)&ifr.ifr_broadaddr;
        hostent = gethostbyaddr((const char *)&sa->sin_addr, sizeof(sa->sin_addr), AF_INET);
        if (hostent == NULL) {
            print_error("gethostbyaddr");
        }

        host = malloc(sizeof(struct host));
        if (host == NULL) {
            print_error("malloc");
        }

        host->name = strdup(hostent->h_name);
        if (host->name == NULL) {
            print_error("strdup");
        }

        host->ip = sa->sin_addr.s_addr;

        host->next = network->hosts;
        network->hosts = host;
    }

    close(sockfd);

    for (iface = network->interfaces; iface != NULL; iface = iface->next) {
        for (host = network->hosts; host != NULL; host = host->next) {
            if (host->ip & iface->mask == iface->ip & iface->mask) {
                link = malloc(sizeof(struct link));
                if (link == NULL) {
                    print_error("malloc");
                }

                link->host1 = iface;
                link->host2 = host;

                link->next = network->links;
                network->links = link;
            }
        }
    }

    return network;
}

int main(int argc, char *argv[]) {
    struct network *network;

    network = discover_network();

    print_network(network);

    free_network(network);

    return 0;
}