//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <dirent.h>
#include <netdb.h>

#define MAX_DEVICES 100
#define DEVICE_NAME_LENGTH 64

typedef struct {
    char ip_address[INET_ADDRSTRLEN];
    char device_name[DEVICE_NAME_LENGTH];
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char *ip_address, const char *device_name) {
    if (device_count < MAX_DEVICES) {
        strcpy(devices[device_count].ip_address, ip_address);
        strcpy(devices[device_count].device_name, device_name);
        device_count++;
    } else {
        printf("Device list is full!\n");
    }
}

void print_devices() {
    printf("Network Devices Found:\n");
    for (int i = 0; i < device_count; i++) {
        printf("IP: %s | Name: %s\n", devices[i].ip_address, devices[i].device_name);
    }
}

int scan_network(const char *base_ip) {
    char command[128];
    sprintf(command, "fping -a -g %s/24 2>/dev/null", base_ip);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return -1;
    }

    char line[INET_ADDRSTRLEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = 0; // Strip newline
        add_device(line, "Unknown Device"); // Placeholder for device name
    }

    pclose(fp);
    return 0;
}

void get_device_names() {
    for (int i = 0; i < device_count; i++) {
        struct sockaddr_in sa;
        socklen_t sa_len = sizeof(sa);
        int sock = socket(AF_INET, SOCK_DGRAM, 0);

        if (sock < 0) {
            continue;
        }

        if (inet_pton(AF_INET, devices[i].ip_address, &sa.sin_addr) <= 0) {
            close(sock);
            continue;
        }

        getnameinfo((struct sockaddr *)&sa, sa_len, devices[i].device_name, DEVICE_NAME_LENGTH, NULL, 0, 0);
        close(sock);
    }
}

int main() {
    struct ifaddrs *ifaddr, *ifa;
    char host[INET_ADDRSTRLEN];
    char *base_ip = NULL;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return EXIT_FAILURE;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, sizeof(host), NULL, 0, NI_NUMERICHOST) == 0) {
                base_ip = strtok(host, ".");
                base_ip = strtok(NULL, ".");
                base_ip = strtok(NULL, ".");
                base_ip = strtok(NULL, "");
                if (base_ip) {
                    sprintf(host, "%s.%s.%s.0", base_ip, ".0");
                    scan_network(host);
                }
            }
        }
    }

    freeifaddrs(ifaddr);
    get_device_names();
    print_devices();

    return EXIT_SUCCESS;
}