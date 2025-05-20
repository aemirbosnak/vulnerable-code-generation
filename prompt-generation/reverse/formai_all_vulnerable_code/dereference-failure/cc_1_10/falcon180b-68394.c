//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int size;
    int mask;
};

void parse_subnet(char *subnet_str, struct subnet *subnet) {
    char *ptr = strchr(subnet_str, '/');
    if (ptr == NULL) {
        subnet->size = 0;
        subnet->mask = 0;
    } else {
        *ptr = '\0';
        subnet->size = atoi(subnet_str);
        subnet->mask = (1 << subnet->size) - 1;
        if (subnet->size > 32) {
            printf("Error: subnet size must be 32 or less\n");
            exit(1);
        }
    }
    strcpy(subnet->name, subnet_str);
}

void print_subnet(struct subnet *subnet) {
    printf("%s/%d (%d hosts)\n", subnet->name, subnet->size, (1 << subnet->size) - 1);
}

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    struct subnet subnets[MAX_SUBNETS];

    if (argc < 2) {
        printf("Usage: %s <subnet1> [<subnet2>...]\n", argv[0]);
        return 1;
    }

    while (num_subnets < MAX_SUBNETS && argc > 1) {
        parse_subnet(argv[1], &subnets[num_subnets]);
        num_subnets++;
        argc--;
        argv++;
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}