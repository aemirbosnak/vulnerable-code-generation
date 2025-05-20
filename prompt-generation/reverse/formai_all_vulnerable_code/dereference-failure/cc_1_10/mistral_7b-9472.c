//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETMASK_LENGTH 32
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    int netmask_length;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int first_usable_ip;
    unsigned int last_usable_ip;
} SubnetInfo;

void calculate_subnet_info(SubnetInfo* subnet_info, const char* ip, int netmask_length) {
    unsigned int ip_decimal = inet_addr(ip);
    unsigned int subnet_mask = 0xFFFFFFFF << (32 - netmask_length);

    subnet_info->network_address = ip_decimal & subnet_mask;
    subnet_info->broadcast_address = subnet_info->network_address | ~subnet_mask;

    subnet_info->first_usable_ip = subnet_info->network_address + 1;
    subnet_info->last_usable_ip = subnet_info->broadcast_address - 1;

    strcpy(subnet_info->ip, ip);
    subnet_info->netmask_length = netmask_length;
}

void print_subnet_info(const SubnetInfo* subnet_info) {
    printf("Subnet Information:\n");
    printf("IP Address: %s\n", subnet_info->ip);
    printf("Netmask Length: %d\n", subnet_info->netmask_length);
    printf("Network Address: %u.%u.%u.%u\n",
           (unsigned int)((subnet_info->network_address) >> 24),
           (unsigned int)((subnet_info->network_address) >> 16 & 0xFF),
           (unsigned int)((subnet_info->network_address) >> 8 & 0xFF),
           (unsigned int)(subnet_info->network_address & 0xFF));
    printf("Broadcast Address: %u.%u.%u.%u\n",
           (unsigned int)((subnet_info->broadcast_address) >> 24),
           (unsigned int)((subnet_info->broadcast_address) >> 16 & 0xFF),
           (unsigned int)((subnet_info->broadcast_address) >> 8 & 0xFF),
           (unsigned int)(subnet_info->broadcast_address & 0xFF));
    printf("First Usable IP: %u.%u.%u.%u\n",
           (unsigned int)((subnet_info->first_usable_ip) >> 24),
           (unsigned int)((subnet_info->first_usable_ip) >> 16 & 0xFF),
           (unsigned int)((subnet_info->first_usable_ip) >> 8 & 0xFF),
           (unsigned int)(subnet_info->first_usable_ip & 0xFF));
    printf("Last Usable IP: %u.%u.%u.%u\n",
           (unsigned int)((subnet_info->last_usable_ip) >> 24),
           (unsigned int)((subnet_info->last_usable_ip) >> 16 & 0xFF),
           (unsigned int)((subnet_info->last_usable_ip) >> 8 & 0xFF),
           (unsigned int)(subnet_info->last_usable_ip & 0xFF));
}

int main(int argc, char* argv[]) {
    SubnetInfo subnet_info;

    if (argc != 3) {
        printf("Usage: %s <IP Address> <Netmask Length>\n", argv[0]);
        return 1;
    }

    calculate_subnet_info(&subnet_info, argv[1], atoi(argv[2]));
    print_subnet_info(&subnet_info);

    return 0;
}