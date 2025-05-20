//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOSTS 100

struct host_info {
    char *hostname;
    char *ip_address;
};

struct host_info *hosts[MAX_HOSTS];
int num_hosts = 0;

void add_host(char *hostname, char *ip_address) {
    if (num_hosts >= MAX_HOSTS) {
        printf("Error: maximum number of hosts reached\n");
        return;
    }

    hosts[num_hosts] = malloc(sizeof(struct host_info));
    if (hosts[num_hosts] == NULL) {
        printf("Error: could not allocate memory for host\n");
        return;
    }

    hosts[num_hosts]->hostname = strdup(hostname);
    hosts[num_hosts]->ip_address = strdup(ip_address);

    num_hosts++;
}

void print_hosts() {
    for (int i = 0; i < num_hosts; i++) {
        printf("%s: %s\n", hosts[i]->hostname, hosts[i]->ip_address);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname1 hostname2 ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        struct hostent *he = gethostbyname(argv[i]);
        if (he == NULL) {
            printf("Error: could not resolve hostname %s\n", argv[i]);
            continue;
        }

        char *ip_address = inet_ntoa(*(struct in_addr *)he->h_addr_list[0]);
        add_host(argv[i], ip_address);
    }

    print_hosts();

    return EXIT_SUCCESS;
}