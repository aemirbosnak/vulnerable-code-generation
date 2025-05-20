//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct device {
    char* name;
    char* ip_address;
    struct device* next_device;
} Device;

Device* create_device(char* name, char* ip_address) {
    Device* new_device = (Device*) malloc(sizeof(Device));
    new_device->name = strdup(name);
    new_device->ip_address = strdup(ip_address);
    new_device->next_device = NULL;
    return new_device;
}

void add_device(Device** devices, char* name, char* ip_address) {
    Device* new_device = create_device(name, ip_address);
    if (*devices == NULL) {
        *devices = new_device;
    } else {
        Device* current_device = *devices;
        while (current_device->next_device != NULL) {
            current_device = current_device->next_device;
        }
        current_device->next_device = new_device;
    }
}

void print_devices(Device* devices) {
    if (devices == NULL) {
        printf("No devices found.\n");
    } else {
        Device* current_device = devices;
        while (current_device != NULL) {
            printf("Device: %s, IP Address: %s\n", current_device->name, current_device->ip_address);
            current_device = current_device->next_device;
        }
    }
}

int main() {
    Device* devices = NULL;
    add_device(&devices, "Router 1", "192.168.0.1");
    add_device(&devices, "Switch 1", "192.168.0.2");
    add_device(&devices, "Switch 2", "192.168.0.3");
    add_device(&devices, "PC 1", "192.168.0.4");
    add_device(&devices, "PC 2", "192.168.0.5");
    add_device(&devices, "Server 1", "192.168.0.6");
    add_device(&devices, "Server 2", "192.168.0.7");
    add_device(&devices, "Printer 1", "192.168.0.8");
    add_device(&devices, "Printer 2", "192.168.0.9");
    
    printf("Peaceful Networks Network Topology:\n");
    printf("-----------------------------------\n");
    printf("Router 1 -------- Switch 1 ------ PC 1\n");
    printf("                  |             |---- PC 2\n");
    printf("                  |             |---- Server 1\n");
    printf("                  |             |---- Server 2\n");
    printf("                  |             |---- Printer 1\n");
    printf("                  |             |---- Printer 2\n");
    printf("                  |\n");
    printf("                  -------- Switch 2\n");
    
    printf("\nDetected Devices:\n");
    printf("-----------------\n");
    print_devices(devices);
    
    return 0;
}