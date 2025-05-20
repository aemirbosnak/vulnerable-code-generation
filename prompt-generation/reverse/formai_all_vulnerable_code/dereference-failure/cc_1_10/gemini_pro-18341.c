//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int addr;
    unsigned int mask;
    unsigned int net;
    unsigned int bcast;
    unsigned int hostmin;
    unsigned int hostmax;
    unsigned int numhosts;
    char *cidr;
} subnet;

void calculate_subnet(subnet *s, char *cidr)
{
    unsigned int i, bits, mask, addr;

    s->cidr = strdup(cidr);

    // Parse the CIDR notation
    bits = atoi(strchr(cidr, '/') + 1);

    // Create the subnet mask
    mask = 0;
    for (i = 0; i < bits; i++)
    {
        mask |= (1 << (31 - i));
    }

    // Calculate the network address
    addr = inet_addr(strtok(cidr, "/"));
    s->addr = addr & mask;

    // Calculate the broadcast address
    s->bcast = s->addr | ~mask;

    // Calculate the first and last host addresses
    s->hostmin = s->addr + 1;
    s->hostmax = s->bcast - 1;

    // Calculate the number of hosts
    s->numhosts = pow(2, 32 - bits) - 2;
}

int main(int argc, char **argv)
{
    subnet s;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <CIDR notation>\n", argv[0]);
        exit(1);
    }

    calculate_subnet(&s, argv[1]);

    printf("Subnet Calculator\n");
    printf("-----------------\n");
    printf("CIDR notation: %s\n", s.cidr);
    printf("Network address: %s\n", inet_ntoa(s.addr));
    printf("Broadcast address: %s\n", inet_ntoa(s.bcast));
    printf("First host address: %s\n", inet_ntoa(s.hostmin));
    printf("Last host address: %s\n", inet_ntoa(s.hostmax));
    printf("Number of hosts: %u\n", s.numhosts);

    return 0;
}