//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>

#define MAX_INTERFACE_NAME_LEN 128
#define MAX_ADDR_STR_LEN 64

/* Function to get the IP address of a network interface */
char *get_interface_ip_address(const char *ifname){
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[MAX_ADDR_STR_LEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if(strcmp(ifa->ifa_name, ifname) == 0){
            family = ifa->ifa_addr->sa_family;

            if (family == AF_INET || family == AF_INET6) {
                s = getnameinfo(ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6),
                                host, MAX_ADDR_STR_LEN, NULL, 0, NI_NUMERICHOST);
                if (s != 0) {
                    printf("getnameinfo() failed: %s\n", gai_strerror(s));
                    exit(EXIT_FAILURE);
                }
                freeifaddrs(ifaddr);
                return strdup(host);
            }
        }
    }

    return NULL;
}

/* Function to perform network topology mapping */
void map_network_topology(){

    struct ifaddrs *ifaddr, *ifa;
    int family, s, i;
    char host[MAX_ADDR_STR_LEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("Network Topology Mapper\n");
    printf("-----------------------\n");

    /* Iterate over all the network interfaces */
    for (ifa = ifaddr, i = 0; ifa != NULL; ifa = ifa->ifa_next, i++) {
        if (ifa->ifa_addr == NULL)
            continue;

        /* Consider IPv4 and IPv6 addresses only */
        family = ifa->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6) {
            printf("\nInterface %d: %s\n", i, ifa->ifa_name);

            /* Get the IP address of the interface */
            s = getnameinfo(ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6),
                            host, MAX_ADDR_STR_LEN, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            printf("IP Address: %s\n", host);
            
            /* Resolve hostnames and print their IP addresses */
            struct hostent *he = gethostbyname(ifa->ifa_name);
            if(he != NULL){
                char **addr_list = he->h_addr_list;
                for(int j = 0; addr_list[j] != NULL; j++){
                    struct in_addr ipv4_addr;
                    memcpy(&ipv4_addr, addr_list[j], sizeof(struct in_addr));
                    printf("Resolved hostname: %s --> IP Address: %s\n", ifa->ifa_name, inet_ntoa(ipv4_addr));
                }
            }
        }
    }

    freeifaddrs(ifaddr);
}

int main(){
    map_network_topology();
    return 0;
}