//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 4
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME_LENGTH 64

typedef struct {
    char name[MAX_SUBNET_NAME_LENGTH];
    char subnet_str[MAX_SUBNET_SIZE];
    int num_hosts;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Name: %s\n", subnet->name);
    printf("Subnet: %s\n", subnet->subnet_str);
    printf("Number of Hosts: %d\n\n", subnet->num_hosts);
}

void print_subnets(Subnet subnets[], int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    while (num_subnets < MAX_SUBNETS) {
        printf("Enter the name of the subnet (or type 'done' to finish): ");
        scanf("%s", subnets[num_subnets].name);

        if (strcmp(subnets[num_subnets].name, "done") == 0) {
            break;
        }

        printf("Enter the subnet in CIDR notation (e.g. 192.168.0.0/24): ");
        scanf("%s", subnets[num_subnets].subnet_str);

        int prefix_len = atoi(strchr(subnets[num_subnets].subnet_str, '/') + 1);
        subnets[num_subnets].num_hosts = (int) pow(2, (32 - prefix_len));

        num_subnets++;
    }

    print_subnets(subnets, num_subnets);

    return 0;
}