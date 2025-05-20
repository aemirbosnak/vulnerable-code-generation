//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char ip[16];
    char mask[16];
    char net[16];
    char broadcast[16];
    char wildcard[16];
} subnet_t;

subnet_t *create_subnet(char *ip, char *mask) {
    subnet_t *s = malloc(sizeof(subnet_t));
    strcpy(s->ip, ip);
    strcpy(s->mask, mask);
    return s;
}

void delete_subnet(subnet_t *s) {
    free(s);
}

void calculate_subnet(subnet_t *s) {
    uint32_t ip = inet_addr(s->ip);
    uint32_t mask = inet_addr(s->mask);

    strcpy(s->net, inet_ntoa((ip & mask) | ~mask));
    strcpy(s->broadcast, inet_ntoa(ip | ~mask));

    uint32_t wildcard = ~(mask | 0xff000000);
    s->wildcard[0] = 0;

    for (int i = 0; i < 4; i++) {
        uint8_t byte = (wildcard >> (i * 8)) & 0xff;
        if (byte!= 0) {
            sprintf(&(s->wildcard[i * 2]), "%d.%d.%d.%d",
                    (byte >> 4) & 0x0f, (byte >> 2) & 0x0f, (byte >> 0) & 0x0f, 0xff);
        } else {
            strcat(&(s->wildcard[i * 2]), "0.0.0.0");
        }
    }
}

int main() {
    subnet_t *s = create_subnet("192.168.0.1", "255.255.255.0");
    calculate_subnet(s);
    printf("IP: %s\n", s->ip);
    printf("Mask: %s\n", s->mask);
    printf("Net: %s\n", s->net);
    printf("Broadcast: %s\n", s->broadcast);
    printf("Wildcard: %s\n", s->wildcard);

    delete_subnet(s);

    return 0;
}