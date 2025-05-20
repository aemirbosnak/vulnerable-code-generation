//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNETS_PER_LINE 5

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    int mask;
} subnet;

subnet *subnets = NULL;
int num_subnets = 0;

void add_subnet(char *name, char *ip, int mask) {
    subnet *new_subnet = (subnet *)malloc(sizeof(subnet));
    strcpy(new_subnet->name, name);
    strcpy(new_subnet->ip, ip);
    new_subnet->mask = mask;
    subnets = (subnet *)realloc(subnets, sizeof(subnet) * (num_subnets + 1));
    subnets[num_subnets++] = *new_subnet;
}

void print_subnets(int per_line) {
    int i, j;
    for (i = 0; i < num_subnets; i += per_line) {
        for (j = i; j < i + per_line && j < num_subnets; j++) {
            printf("%-32s %-15s %d\n", subnets[j].name, subnets[j].ip, subnets[j].mask);
        }
    }
}

int main() {
    char input[MAX_SUBNET_SIZE];
    char *token;
    int mask;

    subnets = (subnet *)malloc(sizeof(subnet));
    num_subnets = 0;

    printf("Enter subnet name (or 'done' to finish): ");
    fgets(input, MAX_SUBNET_SIZE, stdin);

    while (strcmp(input, "done")!= 0) {
        token = strtok(input, " ");
        strcpy(subnets[num_subnets].name, token);

        token = strtok(NULL, " ");
        strcpy(subnets[num_subnets].ip, token);

        token = strtok(NULL, " ");
        mask = atoi(token);
        subnets[num_subnets].mask = mask;

        num_subnets++;

        printf("Enter subnet name (or 'done' to finish): ");
        fgets(input, MAX_SUBNET_SIZE, stdin);
    }

    printf("Subnets:\n");
    print_subnets(MAX_SUBNETS_PER_LINE);

    return 0;
}