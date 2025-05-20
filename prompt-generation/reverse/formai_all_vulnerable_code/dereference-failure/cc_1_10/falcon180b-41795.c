//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

typedef struct {
    int subnet_number;
    char subnet_mask[16];
} Subnet;

int num_subnets;
Subnet subnets[MAX_SUBNETS];

void add_subnet(int subnet_number, char *subnet_mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    subnets[num_subnets].subnet_number = subnet_number;
    strcpy(subnets[num_subnets].subnet_mask, subnet_mask);

    num_subnets++;
}

int main() {
    char input_line[100];
    char *token;
    int subnet_number, subnet_mask_int;
    char subnet_mask_str[16];

    printf("Enter the number of subnets (1-100): ");
    fgets(input_line, sizeof(input_line), stdin);
    num_subnets = atoi(input_line);

    if (num_subnets < 1 || num_subnets > MAX_SUBNETS) {
        printf("Error: Invalid number of subnets.\n");
        exit(1);
    }

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the subnet number and mask for subnet %d:\n", i+1);
        fgets(input_line, sizeof(input_line), stdin);
        token = strtok(input_line, " ");
        subnet_number = atoi(token);

        token = strtok(NULL, " ");
        strcpy(subnet_mask_str, token);

        subnet_mask_int = atoi(subnet_mask_str);
        if (subnet_mask_int < 1 || subnet_mask_int > 32) {
            printf("Error: Invalid subnet mask.\n");
            exit(1);
        }

        add_subnet(subnet_number, subnet_mask_str);
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", subnets[i].subnet_number, subnets[i].subnet_mask);
    }

    return 0;
}