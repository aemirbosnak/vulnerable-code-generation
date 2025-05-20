//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void subnetCalc(char *ip, char *subnet, char *gateway, char *broadcast) {
    int i, j, k, n;
    char *token;
    char *saveptr;

    n = strlen(ip);
    if (n < 7 || n > 15) {
        printf("Invalid IP address\n");
        exit(1);
    }

    i = 0;
    token = strtok_r(ip, ".", &saveptr);
    while (token!= NULL) {
        if (atoi(token) > 255) {
            printf("Invalid IP address\n");
            exit(1);
        }
        if (++i == 4) {
            printf("Invalid IP address\n");
            exit(1);
        }
        token = strtok_r(NULL, ".", &saveptr);
    }

    if (i!= 4) {
        printf("Invalid IP address\n");
        exit(1);
    }

    strcpy(subnet, ip);
    strcat(subnet, ".0");

    strcpy(gateway, ip);
    strcat(gateway, ".1");

    strcpy(broadcast, ip);
    strcat(broadcast, ".255");
}

int main() {
    char ip[MAX_SIZE];
    char subnet[MAX_SIZE];
    char gateway[MAX_SIZE];
    char broadcast[MAX_SIZE];

    printf("Enter IP address: ");
    fgets(ip, MAX_SIZE, stdin);

    subnetCalc(ip, subnet, gateway, broadcast);

    printf("Subnet: %s\n", subnet);
    printf("Gateway: %s\n", gateway);
    printf("Broadcast: %s\n", broadcast);

    return 0;
}