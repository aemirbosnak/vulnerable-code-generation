//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DEVICES 100
#define MAX_IP_LEN 16

struct device {
    char name[50];
    char ip[MAX_IP_LEN];
    int port;
};

int scan_network(char *ip_prefix, struct device **devices) {
    int sockfd, optval;
    struct sockaddr_in addr;
    struct device *d;
    int count = 0;

    for (int i = 1; i < 255; i++) {
        char ip[strlen(ip_prefix) + 4];
        sprintf(ip, "%s.%d", ip_prefix, i);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        optval = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

        memset(&addr, 0, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(80);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) >= 0) {
            d = (struct device *)malloc(sizeof(struct device));

            strncpy(d->ip, ip, MAX_IP_LEN);

            struct hostent *he;
            struct in_addr **addr_list;
            if((he = gethostbyname(ip)) != NULL) {
                addr_list = (struct in_addr **) he->h_addr_list;
                strncpy(d->name, inet_ntoa(*addr_list[0]), 50);
            } else {
                strncpy(d->name, ip, 50);
            }

            d->port = 80;

            devices[count++] = d;
        }

        close(sockfd);
    }

    return count;
}

void print_devices(struct device **devices, int count) {
    for (int i = 0; i < count; i++) {
        printf("Device: %s (%s:%d)\n", devices[i]->name, devices[i]->ip, devices[i]->port);
    }
}

int main() {
    struct device *devices[MAX_DEVICES];
    int count = scan_network("192.168.1", devices);

    printf("Network Topology:\n");
    print_devices(devices, count);

    for (int i = 0; i < count; i++) {
        free(devices[i]);
    }

    return 0;
}