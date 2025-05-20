//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_DEVICES 100
#define BUFFER_SIZE 1024

typedef struct Device {
    char ip[16];
    char name[50];
    struct Device* next;
} Device;

Device* head = NULL;

void addDevice(char* ip, char* name) {
    Device* newDevice = (Device*)malloc(sizeof(Device));
    strcpy(newDevice->ip, ip);
    strcpy(newDevice->name, name);
    newDevice->next = head;
    head = newDevice;
}

void printTopology() {
    Device* current = head;
    printf("Network Topology:\n");
    while (current != NULL) {
        printf("Device Name: %s, IP Address: %s\n", current->name, current->ip);
        current = current->next;
    }
}

void freeDevices() {
    Device* current = head;
    Device* nextDevice;
    while (current != NULL) {
        nextDevice = current->next;
        free(current);
        current = nextDevice;
    }
    head = NULL;
}

void discoverDevices() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Running a command to simulate device discovery
    snprintf(command, sizeof(command), "nmap -sn 192.168.1.0/24 | grep \"Nmap scan report for\" | awk '{print $5}'");
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Clean up the buffer to remove any trailing newline
        buffer[strcspn(buffer, "\n")] = 0;

        // Simulate device names from IPs (for example purpose)
        char deviceName[50];
        snprintf(deviceName, sizeof(deviceName), "Device_%s", buffer);
        addDevice(buffer, deviceName);
    }
    pclose(fp);
}

int main() {
    printf("Starting Network Topology Mapper...\n");
    
    // Discover devices in the local network
    discoverDevices();
    
    // Print the discovered devices
    printTopology();
    
    // Free allocated memory for devices
    freeDevices();
    
    printf("Topology mapping complete.\n");
    return 0;
}