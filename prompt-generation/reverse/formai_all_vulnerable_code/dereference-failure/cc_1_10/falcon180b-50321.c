//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <net/if.h>

#define BUF_SIZE 1024
#define MAX_DEVICES 10

struct device {
    char name[IF_NAMESIZE];
    char mac[18];
    char ip[16];
    int is_wireless;
};

void print_devices(struct device devices[], int count) {
    printf("Wireless devices found:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", devices[i].name);
        printf("MAC: %s\n", devices[i].mac);
        printf("IP: %s\n", devices[i].ip);
        printf("Is wireless: %d\n\n", devices[i].is_wireless);
    }
}

int get_wireless_devices(struct device devices[], int max_devices) {
    int count = 0;
    FILE *fp;
    char line[BUF_SIZE];
    char *token;

    fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/net/wireless\n");
        return -1;
    }

    while (fgets(line, BUF_SIZE, fp)!= NULL) {
        token = strtok(line, ":");
        strcpy(devices[count].name, token);

        token = strtok(NULL, ":");
        strcpy(devices[count].mac, token);

        token = strtok(NULL, ":");
        strcpy(devices[count].ip, token);

        devices[count].is_wireless = 1;
        count++;

        if (count >= max_devices) {
            break;
        }
    }

    fclose(fp);
    return count;
}

int main() {
    struct device devices[MAX_DEVICES];
    int count;

    count = get_wireless_devices(devices, MAX_DEVICES);
    if (count > 0) {
        print_devices(devices, count);
    } else {
        printf("No wireless devices found.\n");
    }

    return 0;
}