//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long long INT64;

void print_binary(INT64 num, int len) {
    char* str = malloc(len + 1);
    int i;

    for (i = len - 1; i >= 0; i--) {
        str[i] = (num % 2) + '0';
        num /= 2;
    }
    str[len] = '\0';

    printf("%s", str);

    free(str);
}

void calculate_subnet(char* ip_addr, char* subnet_mask, char* cidr, char* host_min, char* host_max, char* broadcast) {
    INT64 ip, mask, cidr_val, host_min_val, host_max_val, broadcast_val;
    int i, num_bits, num_hosts;

    // Convert IP address to integer
    ip = 0;
    for (i = 0; i < 4; i++) {
        int octet = atoi(strtok(ip_addr, "."));
        ip |= (octet << (24 - i * 8));
    }

    // Convert subnet mask to integer
    mask = 0;
    for (i = 0; i < 4; i++) {
        int octet = atoi(strtok(subnet_mask, "."));
        mask |= (octet << (24 - i * 8));
    }

    // Calculate CIDR value
    cidr_val = 0;
    for (i = 32; i >= 0; i--) {
        if (mask & (1LL << i)) {
            cidr_val++;
        } else {
            break;
        }
    }

    // Calculate host min and max values
    host_min_val = ip & mask;
    host_max_val = host_min_val | ~mask;

    // Calculate broadcast value
    broadcast_val = host_max_val | 1;

    // Convert host min and max values to IP addresses
    sprintf(host_min, "%d.%d.%d.%d", (host_min_val >> 24) & 0xFF, (host_min_val >> 16) & 0xFF, (host_min_val >> 8) & 0xFF, host_min_val & 0xFF);
    sprintf(host_max, "%d.%d.%d.%d", (host_max_val >> 24) & 0xFF, (host_max_val >> 16) & 0xFF, (host_max_val >> 8) & 0xFF, host_max_val & 0xFF);

    // Convert broadcast value to IP address
    sprintf(broadcast, "%d.%d.%d.%d", (broadcast_val >> 24) & 0xFF, (broadcast_val >> 16) & 0xFF, (broadcast_val >> 8) & 0xFF, broadcast_val & 0xFF);

    // Calculate number of hosts
    num_hosts = pow(2, 32 - cidr_val) - 2;

    // Print results
    printf("IP Address: %s\n", ip_addr);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("CIDR Value: %d\n", cidr_val);
    printf("Host Min: %s\n", host_min);
    printf("Host Max: %s\n", host_max);
    printf("Broadcast: %s\n", broadcast);
    printf("Number of Hosts: %d\n", num_hosts);
}

int main() {
    char ip_addr[16], subnet_mask[16], cidr[4], host_min[16], host_max[16], broadcast[16];

    printf("Enter IP address: ");
    scanf("%s", ip_addr);

    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    calculate_subnet(ip_addr, subnet_mask, cidr, host_min, host_max, broadcast);

    return 0;
}