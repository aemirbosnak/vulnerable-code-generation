//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32

typedef struct {
    char *name;
    unsigned char subnet[MAX_SUBNET_SIZE];
    unsigned char mask[MAX_SUBNET_SIZE];
} subnet_t;

void add_subnet(subnet_t *subnets, int count, char *name, char *subnet_str, char *mask_str) {
    if (count >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t *subnet = &subnets[count];
    strcpy(subnet->name, name);

    int i;
    for (i = 0; i < strlen(subnet_str); i++) {
        if (subnet_str[i] == '.') {
            subnet->subnet[i] = atoi(subnet_str);
        } else {
            printf("Error: Invalid subnet format.\n");
            return;
        }
    }

    for (i = 0; i < strlen(mask_str); i++) {
        if (mask_str[i] == '.') {
            subnet->mask[i] = atoi(mask_str);
        } else {
            printf("Error: Invalid mask format.\n");
            return;
        }
    }

    count++;
}

void print_subnets(subnet_t *subnets, int count) {
    printf("Subnets:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("Subnet: ");
        for (int j = 0; j < strlen(subnets[i].subnet); j++) {
            printf("%d.", subnets[i].subnet[j]);
        }
        printf("\n");
        printf("Mask: ");
        for (int j = 0; j < strlen(subnets[i].mask); j++) {
            printf("%d.", subnets[i].mask[j]);
        }
        printf("\n\n");
    }
}

void main() {
    subnet_t subnets[MAX_SUBNETS];
    int count = 0;

    add_subnet(subnets, count, "Subnet 1", "192.168.0.0", "255.255.255.0");
    add_subnet(subnets, count, "Subnet 2", "10.0.0.0", "255.0.0.0");

    print_subnets(subnets, count);
}