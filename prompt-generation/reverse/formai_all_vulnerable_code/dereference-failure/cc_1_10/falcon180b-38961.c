//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 30

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int mask;
} Subnet;

void add_subnet(Subnet *subnets, int num_subnets, char *name, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    int i;
    for (i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            printf("Error: Subnet '%s' already exists.\n", name);
            exit(1);
        }
    }

    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].size = size;
    subnets[num_subnets].mask = (int)pow(2, size) - 1;
    num_subnets++;
}

void print_subnets(Subnet *subnets, int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts)\n", subnets[i].name, subnets[i].size);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char input[MAX_SUBNET_SIZE];
    while (fgets(input, MAX_SUBNET_SIZE, stdin)!= NULL) {
        if (input[0] == '#') {
            continue;
        }

        char *name = strtok(input, " ");
        int size = atoi(strtok(NULL, " "));

        add_subnet(subnets, num_subnets, name, size);
    }

    print_subnets(subnets, num_subnets);

    return 0;
}