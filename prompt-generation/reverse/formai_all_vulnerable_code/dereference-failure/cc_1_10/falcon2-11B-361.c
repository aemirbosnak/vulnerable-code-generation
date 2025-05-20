//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET 16
#define MAX_HOSTS 256
#define MASK_SIZE (32 - MAX_SUBNET)

void subnet_calculator(int subnet, int hosts) {
    int mask[MAX_SUBNET];
    int host[MAX_HOSTS];

    int mask_index = 0;
    int host_index = 0;

    for (int i = 0; i < MASK_SIZE; i++) {
        mask[mask_index++] = 0;
    }

    for (int i = 0; i < MAX_HOSTS; i++) {
        host[host_index++] = 0;
    }

    mask[0] = 1;
    host[0] = 1;

    for (int i = 0; i < MAX_SUBNET; i++) {
        int mask_bit = (1 << i);

        if (subnet & mask_bit) {
            mask[mask_index++] = 1;
            host[host_index++] = 0;
        } else {
            mask[mask_index++] = 0;
            host[host_index++] = (host[host_index - 1] + 1) & 0xff;
        }
    }

    printf("Subnet: %d\n", subnet);
    printf("Hosts: %d\n", hosts);
    printf("Mask: ");
    for (int i = 0; i < MASK_SIZE; i++) {
        printf("%d", mask[i]);
        if (i!= MASK_SIZE - 1) {
            printf(".");
        }
    }
    printf("\n");
    printf("Hosts: ");
    for (int i = 0; i < MAX_HOSTS; i++) {
        printf("%d", host[i]);
        if (i!= MAX_HOSTS - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int subnet;
    int hosts;

    if (argc!= 3) {
        printf("Usage: %s <subnet> <hosts>\n", argv[0]);
        return 1;
    }

    subnet = atoi(argv[1]);
    hosts = atoi(argv[2]);

    subnet_calculator(subnet, hosts);

    return 0;
}