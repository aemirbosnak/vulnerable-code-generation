//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_DEVICES 50

typedef struct {
    char ip[INET_ADDRSTRLEN];
    char name[1024];
} Device;

void get_device_details(struct ifaddrs *ifaddr, Device *device) {
    struct sockaddr_in *addr = (struct sockaddr_in *) ifaddr->ifa_addr;
    inet_ntop(AF_INET, &addr->sin_addr, device->ip, INET_ADDRSTRLEN);
    strncpy(device->name, ifaddr->ifa_name, 1024);
}

void scan_network(Device *devices, int *count) {
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) < 0) {
        fprintf(stderr, "Error getting network interface information.\n");
        exit(1);
    }
    *count = 0;
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET) {
            continue;
        }
        if (*count >= MAX_DEVICES) {
            break;
        }
        get_device_details(ifa, &devices[*count]);
        (*count)++;
    }
    freeifaddrs(ifaddr);
}

void print_network_details(Device *devices, int count) {
    printf("Network Topology\n");
    printf("================\n");
    int i, j;
    for (i = 0; i < count; i++) {
        printf("%s (%s)\n", devices[i].name, devices[i].ip);
        for (j = 0; j < count; j++) {
            if (i == j) {
                continue;
            }
            struct addrinfo hints, *res;
            memset((void *) &hints, 0, sizeof(hints));
            hints.ai_family = AF_INET;
            hints.ai_socktype = SOCK_STREAM;
            int status = getaddrinfo(devices[j].ip, "22", &hints, &res);
            if (status != 0) {
                printf("\t%s not reachable from %s\n", devices[j].ip, devices[i].ip);
            } else {
                printf("\t%s is reachable from %s\n", devices[j].ip, devices[i].ip);
                freeaddrinfo(res);
            }
        }
    }
}

int main() {
    Device devices[MAX_DEVICES];
    int count;
    scan_network(devices, &count);
    print_network_details(devices, count);
    return 0;
}