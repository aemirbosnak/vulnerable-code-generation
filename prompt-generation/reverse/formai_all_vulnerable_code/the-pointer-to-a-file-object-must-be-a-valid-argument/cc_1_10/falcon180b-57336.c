//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_DEVICES 10
#define BUFFER_SIZE 1024

struct device {
    char name[64];
    char address[64];
    char vendor[64];
};

void print_devices() {
    int count = 0;
    struct device devices[MAX_DEVICES];

    FILE *fp = popen("iwlist wlan0 scan", "r");
    char line[BUFFER_SIZE];

    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (count >= MAX_DEVICES) {
            break;
        }

        if (strstr(line, "Address: ")!= NULL) {
            strcpy(devices[count].address, line + 10);
        } else if (strstr(line, "ESSID:\"")!= NULL) {
            strcpy(devices[count].name, line + 8);
        } else if (strstr(line, "Vendor: ")!= NULL) {
            strcpy(devices[count].vendor, line + 9);
        }

        count++;
    }

    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", devices[i].name);
        printf("Address: %s\n", devices[i].address);
        printf("Vendor: %s\n\n", devices[i].vendor);
    }
}

int main() {
    print_devices();

    return 0;
}