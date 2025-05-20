//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char *ip;
    char *mask;
    char *subnet;
} Subnet;

void generate_ip(char *ip, int i, int j) {
    sprintf(ip, "%d.%d.%d.%d", i, j, i + (j / 256), j % 256);
}

void generate_subnet(char *subnet, int i, int j) {
    sprintf(subnet, "%d.%d.%d.%d/%d", i, j, i + (j / 256), j % 256, 32 - log2(256 - j % 256));
}

int main() {
    int num_subnets, i, j;
    Subnet *subnets;
    char input[32];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    subnets = malloc(num_subnets * sizeof(Subnet));

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the IP address for subnet #%d: ", i + 1);
        scanf("%s", input);

        subnets[i].ip = strdup(input);
        generate_subnet(subnets[i].subnet, atoi(input), 0);

        printf("Enter the subnet mask: ");
        scanf("%s", input);

        subnets[i].mask = strdup(input);
        generate_ip(subnets[i].ip, atoi(input), 0);
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet #%d:\n", i + 1);
        printf("IP Address: %s\n", subnets[i].ip);
        printf("Subnet Mask: %s\n", subnets[i].mask);
        printf("Subnet IP Address: %s\n", subnets[i].subnet);
        printf("\n");
    }

    for (i = 0; i < num_subnets; i++) {
        free(subnets[i].ip);
        free(subnets[i].mask);
        free(subnets[i].subnet);
    }

    free(subnets);

    return 0;
}