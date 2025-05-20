//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 256
#define MAX_MASK_LENGTH 32
#define MAX_IP_LENGTH 16
#define MAX_SUBNET_NAME_LENGTH 32

typedef struct {
    char ip_address[MAX_IP_LENGTH];
    char subnet_name[MAX_SUBNET_NAME_LENGTH];
    int subnet_size;
    int mask_length;
} Subnet;

Subnet *subnets = NULL;
int num_subnets = 0;

int add_subnet(char *ip_address, char *subnet_name, int subnet_size, int mask_length) {
    Subnet *new_subnet = malloc(sizeof(Subnet));
    strcpy(new_subnet->ip_address, ip_address);
    strcpy(new_subnet->subnet_name, subnet_name);
    new_subnet->subnet_size = subnet_size;
    new_subnet->mask_length = mask_length;
    subnets = realloc(subnets, sizeof(Subnet) * (num_subnets + 1));
    subnets[num_subnets] = *new_subnet;
    num_subnets++;
    return 0;
}

int remove_subnet(int index) {
    if (index < 0 || index >= num_subnets) {
        printf("Invalid subnet index.\n");
        return -1;
    }
    subnets = realloc(subnets, sizeof(Subnet) * (num_subnets - 1));
    memmove(&subnets[index], &subnets[index + 1], sizeof(Subnet) * (num_subnets - index - 1));
    num_subnets--;
    return 0;
}

int print_subnets() {
    for (int i = 0; i < num_subnets; i++) {
        printf("%s/%d (%d hosts)\n", subnets[i].ip_address, subnets[i].mask_length, subnets[i].subnet_size);
    }
    return 0;
}

int main() {
    add_subnet("192.168.0.0", "subnet1", 24, 8);
    add_subnet("192.168.1.0", "subnet2", 28, 10);
    add_subnet("192.168.2.0", "subnet3", 16, 8);
    print_subnets();
    remove_subnet(1);
    print_subnets();
    return 0;
}