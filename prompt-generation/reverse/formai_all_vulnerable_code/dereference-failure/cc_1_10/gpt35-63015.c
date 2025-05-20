//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_IP_SIZE 16
#define MAX_DEVICES 100

typedef struct {
    char ip[MAX_IP_SIZE];
    int num_ports;
    char **connected_ips;
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char *ip) {
    strcpy(devices[num_devices].ip, ip);
    devices[num_devices].num_ports = 0;
    devices[num_devices].connected_ips = (char **)malloc(sizeof(char *) * MAX_DEVICES);
    num_devices++;
}

void add_connection(Device *device, char *connected_ip) {
    device->connected_ips[device->num_ports] = (char *)malloc(sizeof(char) * MAX_IP_SIZE);
    strcpy(device->connected_ips[device->num_ports], connected_ip);
    device->num_ports++;
}

bool is_device_already_added(char *ip) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].ip, ip) == 0) {
            return true;
        }
    }
    return false;
}

void parse_connections(char *line) {
    char *ip = strtok(line, " ");
    if (!is_device_already_added(ip)) {
        add_device(ip);
    }
    Device *device = NULL;
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].ip, ip) == 0) {
            device = &devices[i];
            break;
        }
    }
    char *connected_ip = strtok(NULL, " ");
    while (connected_ip != NULL) {
        if (!is_device_already_added(connected_ip)) {
            add_device(connected_ip);
        }
        add_connection(device, connected_ip);
        connected_ip = strtok(NULL, " ");
    }
}

void print_topology() {
    printf("Network Topology:\n");
    for (int i = 0; i < num_devices; i++) {
        Device device = devices[i];
        printf("IP: %s\n", device.ip);
        printf("Number of Ports: %d\n", device.num_ports);
        printf("Connected IPs:\n");
        for (int j = 0; j < device.num_ports; j++) {
            printf("\t%s\n", device.connected_ips[j]);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        parse_connections(line);
    }
    fclose(fp);
    print_topology();
    for (int i = 0; i < num_devices; i++) {
        free(devices[i].connected_ips);
    }
    return 0;
}