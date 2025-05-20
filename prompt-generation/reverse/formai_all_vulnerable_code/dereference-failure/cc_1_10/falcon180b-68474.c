//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 20
#define MAX_SUBNET_SIZE 100

typedef struct {
    char *name;
    int num_hosts;
    int subnet_size;
    int *hosts;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Subnet name: %s\n", subnet->name);
    printf("Number of hosts: %d\n", subnet->num_hosts);
    printf("Subnet size: %d\n", subnet->subnet_size);
    printf("Hosts: ");
    for (int i = 0; i < subnet->num_hosts; i++) {
        printf("%d ", subnet->hosts[i]);
    }
    printf("\n");
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    int num_hosts;
    int subnet_size;
    char subnet_name[MAX_SUBNETS][20];
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnet_name[i]);
        printf("Enter the number of hosts in subnet %s: ", subnet_name[i]);
        scanf("%d", &num_hosts);
        subnets[i].name = strdup(subnet_name[i]);
        subnets[i].num_hosts = num_hosts;
        subnets[i].subnet_size = num_hosts;
        subnets[i].hosts = malloc(num_hosts * sizeof(int));
        for (int j = 0; j < num_hosts; j++) {
            subnets[i].hosts[j] = j+1;
        }
    }

    printf("\nSubnets:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}