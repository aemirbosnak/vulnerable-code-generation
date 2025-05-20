//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

typedef struct {
    char ip[INET_ADDRSTRLEN];
    char mac[18];
} device_t;

device_t *devices;
int devices_found;

bool check_ip(char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

void scan_network(char *ip_prefix, int num) {
    if (num < 255) {
        char ip[INET_ADDRSTRLEN];
        sprintf(ip, "%s%d", ip_prefix, num);
        if (check_ip(ip)) {
            struct hostent *host = gethostbyaddr(ip, strlen(ip), AF_INET);
            if (host != NULL) {
                char mac[18];
                sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X", 
                        host->h_addr[0], host->h_addr[1], host->h_addr[2], 
                        host->h_addr[3], host->h_addr[4], host->h_addr[5]);
                strncpy(devices[devices_found].ip, ip, INET_ADDRSTRLEN);
                strncpy(devices[devices_found].mac, mac, 18);
                ++devices_found;
            }
        }
        scan_network(ip_prefix, num + 1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <ip_prefix>\n", argv[0]);
        return 1;
    }

    devices = (device_t *)malloc(255 * sizeof(device_t));
    devices_found = 0;

    scan_network(argv[1], 1);

    printf("Found %d devices on the network:\n", devices_found);
    for (int i = 0; i < devices_found; ++i) {
        printf("%s %s\n", devices[i].ip, devices[i].mac);
    }

    free(devices);

    return 0;
}