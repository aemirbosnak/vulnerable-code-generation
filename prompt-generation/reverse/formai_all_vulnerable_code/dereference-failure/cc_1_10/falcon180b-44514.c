//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int isValidIPv4(char* ip) {
    int i, j, count = 0;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            count++;
        } else if (ip[i] < '0' || ip[i] > '9') {
            return 0;
        }
    }
    return count == 3;
}

int isValidIPv6(char* ip) {
    int i, j, count = 0;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == ':') {
            count++;
        } else if (!isxdigit(ip[i])) {
            return 0;
        }
    }
    return count == 7;
}

unsigned short calculateChecksum(unsigned short* buffer, int size) {
    unsigned short sum = 0;
    for (int i = 0; i < size; i++) {
        sum += buffer[i];
    }
    return (sum >> 16) + (sum & 0xffff);
}

int main() {
    char input[MAX_SIZE];
    printf("Enter an IPv4 or IPv6 address: ");
    fgets(input, MAX_SIZE, stdin);

    char* token = strtok(input, " ");
    if (isValidIPv4(token)) {
        printf("IPv4 address is valid.\n");
        unsigned short checksum = calculateChecksum((unsigned short*)token, strlen(token)/2);
        printf("Checksum: %04x\n", checksum);
    } else if (isValidIPv6(token)) {
        printf("IPv6 address is valid.\n");
        unsigned short checksum = calculateChecksum((unsigned short*)token, strlen(token)/2);
        printf("Checksum: %04x\n", checksum);
    } else {
        printf("Invalid address.\n");
    }

    return 0;
}