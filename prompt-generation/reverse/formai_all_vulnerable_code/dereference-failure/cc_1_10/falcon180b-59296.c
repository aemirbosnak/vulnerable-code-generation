//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUBNETS 10

typedef struct {
    char ip[16];
    int mask;
} subnet;

void print_subnet(subnet subnet) {
    printf("IP: %s\n", subnet.ip);
    printf("Mask: %d\n", subnet.mask);
}

int main() {
    subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;
    char input[16];
    char *token;

    // Prompt user for IP address
    printf("Enter IP address: ");
    scanf("%s", input);

    // Parse IP address into subnet
    token = strtok(input, ".");
    subnets[num_subnets].ip[0] = atoi(token);
    num_subnets++;

    while ((token = strtok(NULL, "."))!= NULL) {
        subnets[num_subnets].ip[num_subnets - 1] = atoi(token);
        num_subnets++;
    }

    // Calculate subnet mask
    int mask = 32;
    int i = 0;
    while (i < num_subnets) {
        if (subnets[i].ip[i] == 0) {
            mask--;
        }
        i++;
    }

    // Calculate subnet IP addresses
    for (i = 0; i < num_subnets; i++) {
        subnets[i].mask = mask;
        printf("Subnet %d:\n", i + 1);
        print_subnet(subnets[i]);
    }

    return 0;
}