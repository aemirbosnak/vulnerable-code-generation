//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_hosts;
    int num_subnets;
    int first_host;
    int last_host;
} subnet_t;

int num_subnets;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char* name, char* mask, int num_hosts) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnet_t* subnet = &subnets[num_subnets];
    strcpy(subnet->name, name);
    strcpy(subnet->mask, mask);
    subnet->num_hosts = num_hosts;
    subnet->num_subnets = 0;
    subnet->first_host = 1;
    subnet->last_host = num_hosts;

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        subnet_t* subnet = &subnets[i];
        printf("%s/%s (%d hosts)\n", subnet->name, subnet->mask, subnet->num_hosts);
    }
}

void calculate_subnets() {
    for (int i = 0; i < num_subnets; i++) {
        subnet_t* subnet = &subnets[i];

        int num_subnet_hosts = subnet->num_hosts / subnet->num_subnets;
        int remainder = subnet->num_hosts % subnet->num_subnets;

        for (int j = 0; j < subnet->num_subnets; j++) {
            subnet_t* subnet_j = &subnets[num_subnets + j];

            int start_host = subnet->first_host + j * num_subnet_hosts;
            int end_host = start_host + num_subnet_hosts - 1;

            if (j < remainder) {
                end_host++;
            }

            strcpy(subnet_j->name, subnet->name);
            strcpy(subnet_j->mask, subnet->mask);
            subnet_j->num_hosts = num_subnet_hosts;
            subnet_j->num_subnets = 0;
            subnet_j->first_host = start_host;
            subnet_j->last_host = end_host;

            num_subnets++;
        }
    }
}

int main() {
    printf("Enter the number of subnets:\n");
    int num_subnets_input;
    scanf("%d", &num_subnets_input);

    if (num_subnets_input < 1 || num_subnets_input > MAX_SUBNETS) {
        printf("Error: Invalid number of subnets.\n");
        return 1;
    }

    num_subnets = num_subnets_input;

    printf("Enter the subnet name and mask (e.g. 192.168.1.0/24):\n");
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    scanf("%s %s", name, mask);

    add_subnet(name, mask, 254);

    calculate_subnets();
    print_subnets();

    return 0;
}