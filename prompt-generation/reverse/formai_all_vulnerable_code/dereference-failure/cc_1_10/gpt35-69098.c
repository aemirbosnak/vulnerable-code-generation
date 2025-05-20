//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char address[20], mask[20], *token;
    int p1, p2, p3, p4, m1, m2, m3, m4, m_bits, i, net_id[4], n_hosts = 0;

    printf("Enter IP address: ");
    fgets(address, 20, stdin);
    printf("Enter subnet mask: ");
    fgets(mask, 20, stdin);

    token = strtok(address, ".");
    p1 = atoi(token);
    token = strtok(NULL, ".");
    p2 = atoi(token);
    token = strtok(NULL, ".");
    p3 = atoi(token);
    token = strtok(NULL, ".");
    p4 = atoi(token);

    token = strtok(mask, ".");
    m1 = atoi(token);
    token = strtok(NULL, ".");
    m2 = atoi(token);
    token = strtok(NULL, ".");
    m3 = atoi(token);
    token = strtok(NULL, ".");
    m4 = atoi(token);

    m_bits = m1 * 256 * 256 * 256 + m2 * 256 * 256 + m3 * 256 + m4;

    for(i = 0; i < 32; i++) {
        if((1 << i) & m_bits) {
            net_id[i/8] |= (1 << (7 - (i % 8)));
        }
    }

    printf("Network ID: %d.%d.%d.%d\n", net_id[0], net_id[1], net_id[2], net_id[3]);

    for(i = 0; i < 32; i++) {
        if(!((1 << i) & m_bits)) {
            n_hosts |= (1 << (31 - i));
        }
    }

    n_hosts--;

    printf("Number of hosts: %d\n", n_hosts);
    return 0;
}