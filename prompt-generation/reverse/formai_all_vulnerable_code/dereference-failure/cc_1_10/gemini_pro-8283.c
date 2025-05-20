//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

typedef struct _host_entry {
    char *hostname;
    char *ipaddr;
    struct _host_entry *next;
} host_entry;

typedef struct _net_map {
    host_entry *hosts;
    int num_hosts;
} net_map;

net_map *new_net_map() {
    net_map *map = malloc(sizeof(net_map));
    map->hosts = NULL;
    map->num_hosts = 0;
    return map;
}

void add_host(net_map *map, char *hostname, char *ipaddr) {
    host_entry *new = malloc(sizeof(host_entry));
    new->hostname = strdup(hostname);
    new->ipaddr = strdup(ipaddr);
    new->next = map->hosts;
    map->hosts = new;
    map->num_hosts++;
}

void print_net_map(net_map *map) {
    host_entry *ptr;
    printf("Network Topology Map\n");
    for (ptr = map->hosts; ptr != NULL; ptr = ptr->next) {
        printf("%s\t%s\n", ptr->hostname, ptr->ipaddr);
    }
}

int main(int argc, char *argv[]) {
    net_map *map = new_net_map();
    struct hostent *hostinfo;
    char **addr_list;
    int i;

    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            hostinfo = gethostbyname(argv[i]);
            if (hostinfo == NULL) {
                fprintf(stderr, "Error: could not resolve hostname %s\n", argv[i]);
                continue;
            }
            addr_list = hostinfo->h_addr_list;
            if (addr_list == NULL) {
                fprintf(stderr, "Error: no IP addresses found for hostname %s\n", argv[i]);
                continue;
            }
            add_host(map, hostinfo->h_name, inet_ntoa(*(struct in_addr *)*addr_list));
        }
    } else {
        printf("Usage: %s <hostname> [<hostname> ...]\n", argv[0]);
    }

    print_net_map(map);

    return 0;
}