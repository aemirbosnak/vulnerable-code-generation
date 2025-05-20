//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <ctype.h>

#define MAX_IP_LENGTH 16
#define MAX_DEVICE_NAME_LENGTH 64
#define PORT 80

typedef struct device {
    char name[MAX_DEVICE_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
    int port;
    struct device *next;
} Device;

void display_devices(Device *devices);
int is_valid_ip(char *ip);

int main() {
    Device *devices = NULL;

    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        fprintf(stderr, "Error getting interface addresses\n");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;
        if (ifa->ifa_addr->sa_family == AF_INET) {
            // If it is a wireless interface
            if (strstr(ifa->ifa_name, "wlan")) {
                // Get the IP address
                char ip[MAX_IP_LENGTH];
                inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr,
                          ip, sizeof(ip));

                if (is_valid_ip(ip)) {
                    // Check if device is reachable
                    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
                    if (sockfd < 0) {
                        perror("Error creating socket");
                        exit(EXIT_FAILURE);
                    }

                    struct sockaddr_in address;
                    address.sin_family = AF_INET;
                    address.sin_port = htons(PORT);
                    inet_pton(AF_INET, ip, &address.sin_addr);

                    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) == 0) {
                        // Device is reachable, add to list
                        Device *new_device = (Device *)malloc(sizeof(Device));
                        strcpy(new_device->name, "Unknown");
                        strcpy(new_device->ip, ip);
                        new_device->port = PORT;
                        new_device->next = devices;
                        devices = new_device;
                    }

                    close(sockfd);
                }
            }
        }
    }

    freeifaddrs(ifaddr);

    display_devices(devices);

    return 0;
}

void display_devices(Device *devices) {
    printf("Wireless Devices Found:\n");
    printf("=======================\n");
    int i = 1;
    Device *current = devices;
    while (current != NULL) {
        printf("%d) Name: %s\n", i, current->name);
        printf("   IP Address: %s\n", current->ip);
        printf("   Port: %d\n\n", current->port);
        current = current->next;
        i++;
    }
}

int is_valid_ip(char *ip) {
    if (ip == NULL || strlen(ip) < 7 || strlen(ip) > 15) {
        return 0;
    }

    char *num = strtok(ip, ".");
    int n = 0;
    while (num != NULL) {
        n++;
        for (int i = 0; i < strlen(num); i++) {
            if (!isdigit(num[i])) {
                return 0;
            }
        }
        int val = atoi(num);
        if (val < 0 || val > 255) {
            return 0;
        }
        num = strtok(NULL, ".");
    }

    if (n != 4) {
        return 0;
    }

    return 1;
}