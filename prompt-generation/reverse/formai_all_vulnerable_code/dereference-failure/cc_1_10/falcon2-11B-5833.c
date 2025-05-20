//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_NETMASK_LEN 8

typedef struct {
    char ip[MAX_IP_LEN];
    char netmask[MAX_NETMASK_LEN];
} IpNetmask;

void print_usage() {
    printf("Usage:./subnet_calc <ip> <netmask>\n");
    printf("Example:./subnet_calc 192.168.0.1 255.255.255.0\n");
}

int is_valid_ip(const char* ip) {
    int len = strlen(ip);
    if (len!= 4 && len!= 6) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (ip[i] < '0' || ip[i] > '9') {
            return 0;
        }
    }

    return 1;
}

int is_valid_netmask(const char* netmask) {
    int len = strlen(netmask);
    if (len!= 8) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        if (netmask[i] < '0' || netmask[i] > '1') {
            return 0;
        }
    }

    return 1;
}

void parse_ip_netmask(IpNetmask* ip_netmask, const char* input) {
    char* ip = strtok(input, " ");
    char* netmask = strtok(NULL, " ");

    if (ip == NULL || netmask == NULL) {
        printf("Invalid input format.\n");
        return;
    }

    ip_netmask->ip[0] = ip[0];
    ip_netmask->ip[1] = ip[1];
    ip_netmask->ip[2] = ip[2];
    ip_netmask->ip[3] = ip[3];

    ip_netmask->netmask[0] = netmask[0];
    ip_netmask->netmask[1] = netmask[1];
    ip_netmask->netmask[2] = netmask[2];
    ip_netmask->netmask[3] = netmask[3];
    ip_netmask->netmask[4] = netmask[4];
    ip_netmask->netmask[5] = netmask[5];
    ip_netmask->netmask[6] = netmask[6];
    ip_netmask->netmask[7] = netmask[7];
}

void get_subnet_info(IpNetmask* ip_netmask, unsigned char* subnet, int* subnet_mask) {
    *subnet_mask = 0;
    int i;

    for (i = 0; i < 8; i++) {
        if (ip_netmask->netmask[i] == '1') {
            *subnet_mask |= (1 << (7 - i));
        }
    }

    *subnet = 0;
    for (i = 0; i < 4; i++) {
        *subnet |= (ip_netmask->ip[i] << (24 - (8 * i)));
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    IpNetmask ip_netmask;
    parse_ip_netmask(&ip_netmask, argv[1]);

    if (!is_valid_ip(ip_netmask.ip)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    if (!is_valid_netmask(ip_netmask.netmask)) {
        printf("Invalid netmask.\n");
        return 1;
    }

    unsigned char subnet[4];
    int subnet_mask;
    get_subnet_info(&ip_netmask, subnet, &subnet_mask);

    printf("Subnet: %s\n", inet_ntoa(subnet));
    printf("Subnet mask: %d\n", subnet_mask);

    return 0;
}