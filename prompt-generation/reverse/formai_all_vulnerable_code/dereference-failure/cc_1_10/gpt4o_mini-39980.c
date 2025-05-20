//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 16
#define MAX_SUBNETS 256

void splitIP(const char *ip_str, int *ip_arr) {
    char *token;
    char ip_copy[MAX_IP_LENGTH];
    strcpy(ip_copy, ip_str);
    
    token = strtok(ip_copy, ".");
    for (int i = 0; i < 4; i++) {
        ip_arr[i] = atoi(token);
        token = strtok(NULL, ".");
    }
}

int validateIP(int *ip_arr) {
    for (int i = 0; i < 4; i++) {
        if (ip_arr[i] < 0 || ip_arr[i] > 255) {
            return 0;
        }
    }
    return 1;
}

void calculateSubnetDetails(int *ip_arr, int subnet_mask) {
    int subnet[4];
    int broadcast[4];
    int first_host[4];
    int last_host[4];

    int wildcard_mask = ~((1 << (32 - subnet_mask)) - 1) & 0xFFFFFFFF;

    subnet[0] = (ip_arr[0] & (wildcard_mask >> 24));
    subnet[1] = (ip_arr[1] & (wildcard_mask >> 16));
    subnet[2] = (ip_arr[2] & (wildcard_mask >> 8));
    subnet[3] = (ip_arr[3] & wildcard_mask);

    broadcast[0] = subnet[0] | (~wildcard_mask >> 24);
    broadcast[1] = subnet[1] | (~wildcard_mask >> 16);
    broadcast[2] = subnet[2] | (~wildcard_mask >> 8);
    broadcast[3] = subnet[3] | ~wildcard_mask;

    first_host[0] = subnet[0];
    first_host[1] = subnet[1];
    first_host[2] = subnet[2];
    first_host[3] = subnet[3] + 1;

    last_host[0] = broadcast[0];
    last_host[1] = broadcast[1];
    last_host[2] = broadcast[2];
    last_host[3] = broadcast[3] - 1;

    printf("\nSubnet Address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("First Host: %d.%d.%d.%d\n", first_host[0], first_host[1], first_host[2], first_host[3]);
    printf("Last Host: %d.%d.%d.%d\n", last_host[0], last_host[1], last_host[2], last_host[3]);
}

int calculateSubnetMask(int subnet_mask) {
    int mask = 0xFFFFFFFF << (32 - subnet_mask);
    return mask;
}

void handleInput(char **ip_str, char **mask_str) {
    printf("Enter IP Address (format: x.x.x.x): ");
    scanf("%s", *ip_str);
    
    printf("Enter Subnet Mask (in CIDR notation, e.g. 24): ");
    scanf("%s", *mask_str);
}

int main() {
    char ip_str[MAX_IP_LENGTH];
    char mask_str[MAX_MASK_LENGTH];
    int ip_arr[4];
    int subnet_mask;

    handleInput(&ip_str, &mask_str);
    subnet_mask = atoi(mask_str);

    splitIP(ip_str, ip_arr);

    if (!validateIP(ip_arr)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask. It should be between 0 and 32.\n");
        return 1;
    }

    calculateSubnetDetails(ip_arr, subnet_mask);

    return 0;
}