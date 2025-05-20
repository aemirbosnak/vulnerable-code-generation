//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[MAX_SUBNET_SIZE];
    int mask;
} subnet;

void generate_subnets(char *ip, int mask, subnet subnets[], int *num_subnets) {
    int i, j;
    char *ptr;

    // Initialize the subnets array
    for (i = 0; i < MAX_SUBNETS; i++) {
        subnets[i].ip[0] = '\0';
        subnets[i].mask = -1;
    }

    // Add the original subnet
    strcpy(subnets[0].ip, ip);
    subnets[0].mask = mask;
    (*num_subnets)++;

    // Generate additional subnets
    for (i = 1; i < MAX_SUBNETS; i++) {
        ptr = strchr(ip, '.');
        if (ptr == NULL) break;

        // Increment the last octet
        for (j = 0; j < 3; j++) {
            ptr++;
            if (ptr == NULL || *ptr == '\0') break;
        }

        if (j == 3) {
            // We've reached the end of the subnet, stop generating
            break;
        }

        // Add the new subnet
        strcpy(subnets[i].ip, ip);
        ptr = strchr(subnets[i].ip, '.');
        if (ptr == NULL) break;

        // Increment the last octet
        for (j = 0; j < 3; j++) {
            ptr++;
            if (ptr == NULL || *ptr == '\0') break;
        }

        subnets[i].mask = mask;
        (*num_subnets)++;
    }
}

int main(int argc, char *argv[]) {
    subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    generate_subnets(argv[1], atoi(argv[2]), subnets, &num_subnets);

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s/%d\n", subnets[i].ip, subnets[i].mask);
    }

    return 0;
}