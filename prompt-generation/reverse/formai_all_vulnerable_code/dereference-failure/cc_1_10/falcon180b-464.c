//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define BUFF_SIZE 1024
#define MAX_DEVICES 10

struct device {
    char name[BUFF_SIZE];
    char addr[BUFF_SIZE];
    int signal_strength;
    int signal_quality;
};

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}

void get_wifi_info(struct device *devices, int count) {
    FILE *fp;
    char line[BUFF_SIZE];
    char *pch;
    int i = 0;

    fp = popen("iwconfig wlan0", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        return;
    }

    while (fgets(line, BUFF_SIZE, fp)!= NULL) {
        if (i >= count) break;
        pch = strtok(line, " ");
        strcpy(devices[i].name, pch);
        pch = strtok(NULL, " ");
        strcpy(devices[i].addr, pch);
        pch = strtok(NULL, " ");
        devices[i].signal_strength = atoi(pch);
        pch = strtok(NULL, " ");
        devices[i].signal_quality = atoi(pch);
        i++;
    }

    pclose(fp);
}

void display_wifi_info(struct device *devices, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("Device %d:\n", i + 1);
        printf("Name: %s\n", devices[i].name);
        printf("Address: %s\n", devices[i].addr);
        printf("Signal Strength: %d\n", devices[i].signal_strength);
        printf("Signal Quality: %d\n\n", devices[i].signal_quality);
    }
}

void main() {
    struct device devices[MAX_DEVICES];
    int count = 0;
    signal(SIGINT, signal_handler);

    while (count < MAX_DEVICES) {
        get_wifi_info(devices, count);
        count++;
        sleep(5);
    }

    display_wifi_info(devices, count);
}