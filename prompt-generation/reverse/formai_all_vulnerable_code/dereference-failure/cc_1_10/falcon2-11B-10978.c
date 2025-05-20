//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP 32

int main(int argc, char **argv) {
    char subnet[MAX_IP];
    char ip[MAX_IP];
    int netmask;

    if (argc!= 3) {
        printf("Usage: %s <subnet> <ip>\n", argv[0]);
        exit(1);
    }

    if (strlen(argv[1]) > MAX_IP) {
        printf("Invalid subnet length\n");
        exit(1);
    }

    if (strlen(argv[2]) > MAX_IP) {
        printf("Invalid IP length\n");
        exit(1);
    }

    subnet[0] = argv[1][0];
    subnet[1] = argv[1][1];
    subnet[2] = argv[1][2];
    subnet[3] = argv[1][3];
    subnet[4] = '.';
    subnet[5] = '.';
    subnet[6] = '.';
    subnet[7] = '.';
    subnet[8] = '\0';

    ip[0] = argv[2][0];
    ip[1] = argv[2][1];
    ip[2] = argv[2][2];
    ip[3] = argv[2][3];
    ip[4] = '\0';

    netmask = strtol(argv[2], NULL, 10);

    if (netmask > 32 || netmask < 0) {
        printf("Invalid netmask\n");
        exit(1);
    }

    printf("Subnet: %s\n", subnet);
    printf("IP: %s\n", ip);
    printf("Netmask: %d\n", netmask);

    return 0;
}