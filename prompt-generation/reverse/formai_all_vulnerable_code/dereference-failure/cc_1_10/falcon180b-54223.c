//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char *subnet;
    int mask;
    int numHosts;
} Subnet;

void generateSubnets(char *ip, int mask, Subnet *subnets, int numSubnets) {
    int i, j;
    char *subnet;
    for (i = 0; i < numSubnets; i++) {
        subnets[i].subnet = malloc(strlen(ip) + 2);
        strcpy(subnets[i].subnet, ip);
        for (j = strlen(ip) - 1; j >= 0; j--) {
            if (ip[j] == '.') {
                subnets[i].mask = mask;
                subnets[i].numHosts = (32 - mask) / (int)pow(2.0, (double)(strlen(ip) - j - 1));
                break;
            }
        }
        if (j == -1) {
            subnets[i].mask = mask;
            subnets[i].numHosts = 32 - mask;
        }
        sprintf(subnets[i].subnet + j + 1, "%d", (int)pow(2.0, (double)mask) - 1);
        strcat(subnets[i].subnet, ".0");
    }
}

void printSubnets(Subnet *subnets, int numSubnets) {
    int i;
    for (i = 0; i < numSubnets; i++) {
        printf("%s / %d (%d hosts)\n", subnets[i].subnet, subnets[i].mask, subnets[i].numHosts);
    }
}

int main() {
    char ip[16];
    int mask, numSubnets;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter an IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &mask, &mask, &mask, &mask);

    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS);
    scanf("%d", &numSubnets);

    generateSubnets(ip, mask, subnets, numSubnets);
    printSubnets(subnets, numSubnets);

    return 0;
}