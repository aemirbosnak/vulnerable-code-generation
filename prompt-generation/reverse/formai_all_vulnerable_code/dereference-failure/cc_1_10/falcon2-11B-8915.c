//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ip[16];
    int mask;
    int first_usable_ip;
    int num_usable_ips;
    char gateway[16];
} Subnet;

Subnet* create_subnet(char* ip, int mask) {
    Subnet* subnet = (Subnet*)malloc(sizeof(Subnet));
    strcpy(subnet->ip, ip);
    subnet->mask = mask;
    subnet->first_usable_ip = 0;
    subnet->num_usable_ips = 0;
    subnet->gateway[0] = 0;
    return subnet;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip> <mask>\n", argv[0]);
        exit(1);
    }
    char* ip = argv[1];
    int mask = atoi(argv[2]);
    Subnet* subnet = create_subnet(ip, mask);
    int num_subnets = 0;
    while (subnet->first_usable_ip < 256) {
        int ip_index = subnet->first_usable_ip;
        int ip_octets[4];
        for (int i = 0; i < 4; i++) {
            ip_octets[i] = subnet->ip[ip_index + i] - '0';
        }
        int subnet_mask = 0;
        for (int i = 0; i < 4; i++) {
            subnet_mask |= (1 << (3 - i));
        }
        int subnet_ip[4];
        for (int i = 0; i < 4; i++) {
            subnet_ip[i] = ip_octets[i] & subnet_mask;
        }
        int subnet_gateway = subnet->ip[0] & subnet_mask;
        strcpy(subnet->gateway, ip);
        strcat(subnet->gateway, ".0");
        for (int i = 1; i < 4; i++) {
            strcat(subnet->gateway, ".");
            strcat(subnet->gateway, (ip + i)[0] & subnet_mask + '0');
        }
        subnet->first_usable_ip += 1;
        num_subnets++;
    }
    printf("Subnet: %s\n", subnet->ip);
    printf("Mask: %d\n", subnet->mask);
    printf("Gateway: %s\n", subnet->gateway);
    printf("First usable IP: %d\n", subnet->first_usable_ip);
    printf("Num usable IPs: %d\n", subnet->num_usable_ips);
    printf("Num subnets: %d\n", num_subnets);
    return 0;
}