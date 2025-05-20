//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[32];
    int size;
} Subnet;

int main() {
    int numSubnets;
    Subnet subnets[MAX_SUBNETS];
    char input[1024];
    char *token;
    int i, j, k;

    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    for (i = 0; i < numSubnets; i++) {
        printf("Enter the name and size of subnet %d (format: name size): ", i + 1);
        scanf("%s", input);

        token = strtok(input, " ");
        strcpy(subnets[i].name, token);

        token = strtok(NULL, " ");
        subnets[i].size = atoi(token);
    }

    printf("\nSubnet Calculator Results:\n");
    printf("-----------------------------\n");

    for (i = 0; i < numSubnets; i++) {
        printf("Subnet %d: %s\n", i + 1, subnets[i].name);

        for (j = 1; j <= subnets[i].size; j++) {
            for (k = 0; k < MAX_SUBNET_SIZE - strlen(subnets[i].name) - 3; k++) {
                printf(" ");
            }

            printf("%d.%d.%d.%d\n", (i + 1) * 10 + j, 1, 1, j);
        }

        printf("\n");
    }

    return 0;
}