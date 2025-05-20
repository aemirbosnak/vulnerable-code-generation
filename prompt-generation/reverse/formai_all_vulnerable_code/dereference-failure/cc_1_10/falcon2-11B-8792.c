//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <subnet mask> <starting IP> <ending IP>\n", argv[0]);
        return 1;
    }

    char *mask = argv[1];
    char *start_ip = argv[2];
    char *end_ip = argv[3];

    int subnet_mask = strtol(mask, NULL, 10);
    char *start_ip_array = strtok(start_ip, ".");
    char *end_ip_array = strtok(end_ip, ".");

    int start_ip_octets[4];
    int end_ip_octets[4];

    for (int i = 0; i < 4; i++) {
        start_ip_octets[i] = strtol(start_ip_array[i], NULL, 10);
        end_ip_octets[i] = strtol(end_ip_array[i], NULL, 10);
    }

    int subnet_size = 0;
    int subnet_octets[4];
    int ip_count = 0;

    for (int i = 0; i < 4; i++) {
        if (start_ip_octets[i]!= end_ip_octets[i]) {
            subnet_size++;
            subnet_octets[subnet_size - 1] = start_ip_octets[i];
        } else if (start_ip_octets[i] == end_ip_octets[i]) {
            subnet_octets[subnet_size] = end_ip_octets[i];
        }
    }

    int subnet_address = 0;
    for (int i = 0; i < subnet_size; i++) {
        subnet_address = (subnet_address << 8) + subnet_octets[i];
    }

    printf("Subnet mask: %d\n", subnet_mask);
    printf("Start IP: %s\n", start_ip);
    printf("End IP: %s\n", end_ip);
    printf("Subnet size: %d\n", subnet_size);
    printf("Subnet address: %d\n", subnet_address);

    return 0;
}