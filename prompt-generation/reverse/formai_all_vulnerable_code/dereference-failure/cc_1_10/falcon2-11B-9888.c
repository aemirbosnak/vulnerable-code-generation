//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP 255 // Maximum length of IP address
#define MAX_SUBNET 32 // Maximum length of subnet mask
#define MAX_PREFIX 8 // Maximum length of prefix

struct ip_address {
    char ip[MAX_IP]; // IP address in string format
    int netmask[MAX_SUBNET]; // Subnet mask in binary format
    int prefix; // Prefix length
};

struct ip_address calculate_subnet(char *ip, char *netmask) {
    struct ip_address ip_addr;
    int i, j, k;

    memset(ip_addr.ip, 0, MAX_IP);
    memset(ip_addr.netmask, 0, MAX_SUBNET);
    memset(ip_addr.prefix, 0, MAX_PREFIX);

    for (i = 0; i < MAX_IP; i++) {
        if (i == 0 || i == 3 || i == 6 || i == 7 || i == 8 || i == 9)
            ip_addr.ip[i] = ip[i];
    }

    for (i = 0; i < MAX_SUBNET; i++) {
        if (i == 0 || i == 3 || i == 6 || i == 7 || i == 8 || i == 9)
            ip_addr.netmask[i] = netmask[i];
    }

    ip_addr.prefix = ip_addr.ip[7] - ip_addr.netmask[7] + 1;

    return ip_addr;
}

void print_ip_address(struct ip_address ip) {
    int i;

    for (i = 0; i < ip.prefix; i++) {
        printf("%d.%d.%d.%d", ip.ip[0], ip.ip[1], ip.ip[2], ip.ip[3]);
    }
}

int main() {
    char ip[] = "192.168.1.1";
    char netmask[] = "255.255.255.0";
    struct ip_address ip_addr = calculate_subnet(ip, netmask);
    print_ip_address(ip_addr);
    return 0;
}