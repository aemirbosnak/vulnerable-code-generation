//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 20
#define MAX_SUBNET_SIZE 100
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    int size;
} subnet;

void add_subnet(subnet *subnets, int num_subnets, char *ip, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    subnets[num_subnets].ip[0] = '\0';
    strncat(subnets[num_subnets].ip, ip, MAX_IP_SIZE - 1);
    subnets[num_subnets].size = size;

    num_subnets++;
}

void calculate_subnets(subnet *subnets, int num_subnets, int num_hosts) {
    int i, j, k, hosts_per_subnet;

    hosts_per_subnet = num_hosts / num_subnets;

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: ", i + 1);

        for (j = 0; j < subnets[i].size; j++) {
            printf("%d.", (int) subnets[i].ip[j] & 0xff);
        }

        printf("\n");

        for (k = 0; k < hosts_per_subnet - 1; k++) {
            printf("Host %d: ", k + 1);

            for (j = 0; j < subnets[i].size; j++) {
                printf("%d.", (int) subnets[i].ip[j] & 0xff);
            }

            printf("\n");
        }

        if (hosts_per_subnet > 1) {
            printf("Broadcast address: ");

            for (j = 0; j < subnets[i].size; j++) {
                printf("%d. ", (int) subnets[i].ip[j] & 0xff);
            }

            printf("255\n");
        }
    }
}

int main() {
    subnet subnets[MAX_SUBNETS];
    int num_subnets = 0, num_hosts = 0;
    char ip[MAX_IP_SIZE];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    num_hosts = atoi(ip);

    while (num_hosts > 0) {
        int size = num_hosts < 256? num_hosts : 256;

        add_subnet(subnets, num_subnets, ip, size);

        num_hosts -= size;
        num_subnets++;
    }

    calculate_subnets(subnets, num_subnets, num_hosts);

    return 0;
}