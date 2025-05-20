//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
} Subnet;

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    char input[1024];
    char *token;
    int i;

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    fgets(input, sizeof(input), stdin);
    num_subnets = atoi(input);

    // Initialize subnets array
    for (i = 0; i < num_subnets; i++) {
        subnets[i].size = 0;
        strcpy(subnets[i].name, "");
    }

    // Get subnet information from user
    printf("Enter subnet information (name size):\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        token = strtok(input, " ");
        strcpy(subnets[atoi(token) - 1].name, token);
        subnets[atoi(token) - 1].size = atoi(strtok(NULL, " "));
    }

    // Calculate subnet sizes
    for (i = 0; i < num_subnets; i++) {
        if (subnets[i].size == 0) {
            printf("Error: Subnet %s has no size.\n", subnets[i].name);
            exit(1);
        }
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %s has %d IP addresses.\n", subnets[i].name, 1 << (32 - subnets[i].size));
    }

    return 0;
}