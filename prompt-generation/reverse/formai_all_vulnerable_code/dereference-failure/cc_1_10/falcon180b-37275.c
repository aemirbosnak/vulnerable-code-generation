//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char *name;
    char *subnet;
    int size;
} Subnet;

void add_subnet(Subnet *subnets, int num_subnets, char *name, char *subnet, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Too many subnets.\n");
        return;
    }

    for (int i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            printf("Error: Subnet '%s' already exists.\n", name);
            return;
        }
    }

    subnets[num_subnets].name = strdup(name);
    subnets[num_subnets].subnet = strdup(subnet);
    subnets[num_subnets].size = size;
    num_subnets++;
}

void delete_subnet(Subnet *subnets, int num_subnets, char *name) {
    for (int i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            free(subnets[i].name);
            free(subnets[i].subnet);
            for (int j = i; j < num_subnets - 1; j++) {
                subnets[j] = subnets[j + 1];
            }
            num_subnets--;
            return;
        }
    }

    printf("Error: Subnet '%s' not found.\n", name);
}

void list_subnets(Subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts)\n", subnets[i].name, (int)pow(2, (double)subnets[i].size * 8) - 2);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    add_subnet(subnets, num_subnets, "192.168.0.0/24", "192.168.0.0", 24);
    add_subnet(subnets, num_subnets, "192.168.1.0/24", "192.168.1.0", 24);
    list_subnets(subnets, num_subnets);

    delete_subnet(subnets, num_subnets, "192.168.0.0/24");
    list_subnets(subnets, num_subnets);

    return 0;
}