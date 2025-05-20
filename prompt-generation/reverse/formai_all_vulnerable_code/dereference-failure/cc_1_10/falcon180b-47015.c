//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 10
#define MAX_IP_LENGTH 15
#define MAX_MASK_LENGTH 15

typedef struct {
    char ip_address[MAX_IP_LENGTH];
    char subnet_mask[MAX_MASK_LENGTH];
    int num_subnets;
    char **subnet_ips;
} SubnetCalculator;

void calculate_subnets(SubnetCalculator *sc) {
    int i, j, k;
    char *token;
    char ip_address[MAX_IP_LENGTH];
    char subnet_mask[MAX_MASK_LENGTH];
    int num_subnets = sc->num_subnets;
    char **subnet_ips = sc->subnet_ips;

    strcpy(ip_address, sc->ip_address);
    strcpy(subnet_mask, sc->subnet_mask);

    for (i = 0; i < num_subnets; i++) {
        subnet_ips[i] = malloc(sizeof(char) * MAX_IP_LENGTH);
        sprintf(subnet_ips[i], "%s.%d", ip_address, i + 1);
    }
}

int main() {
    SubnetCalculator sc;
    char input[MAX_IP_LENGTH];
    char *token;
    int num_subnets;

    printf("Enter the IP address: ");
    fgets(input, MAX_IP_LENGTH, stdin);

    token = strtok(input, ".");
    strcpy(sc.ip_address, token);

    token = strtok(NULL, ".");
    sc.num_subnets = atoi(token);

    sc.subnet_mask[0] = '1';
    sc.subnet_mask[1] = '1';
    sc.subnet_mask[2] = '1';
    sc.subnet_mask[3] = '0';

    calculate_subnets(&sc);

    printf("Subnet IP addresses:\n");
    for (num_subnets = 0; num_subnets < sc.num_subnets; num_subnets++) {
        printf("%s\n", sc.subnet_ips[num_subnets]);
    }

    return 0;
}