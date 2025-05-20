//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <net/if.h>

#define BUFFER_SIZE 1024
#define MAX_INTERFACES 16

struct wireless_network {
    char ssid[32];
    char bssid[18];
    int channel;
    int signal_strength;
};

struct interface {
    char name[IFNAMSIZ];
    char ip_address[INET_ADDRSTRLEN];
    char netmask[INET_ADDRSTRLEN];
    char broadcast_address[INET_ADDRSTRLEN];
};

int parse_wireless_networks(char *buffer, struct wireless_network *networks, int max_networks) {
    int num_networks = 0;
    char *line = strtok(buffer, "\n");
    while (line != NULL && num_networks < max_networks) {
        struct wireless_network network;
        if (sscanf(line, "%32[^,], %18[^,], %d, %d", network.ssid, network.bssid, &network.channel, &network.signal_strength) == 4) {
            networks[num_networks++] = network;
        }
        line = strtok(NULL, "\n");
    }
    return num_networks;
}

int get_wireless_networks(char *interface, struct wireless_network *networks, int max_networks) {
    FILE *pipe;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    snprintf(command, BUFFER_SIZE, "sudo iwlist %s scanning", interface);
    if ((pipe = popen(command, "r")) == NULL) {
        fprintf(stderr, "Error opening pipe for command: %s\n", command);
        return -1;
    }
    fgets(buffer, BUFFER_SIZE, pipe); // skip first line
    fgets(buffer, BUFFER_SIZE, pipe); // skip second line
    fgets(buffer, BUFFER_SIZE, pipe); // skip third line
    int num_networks = parse_wireless_networks(buffer, networks, max_networks);
    pclose(pipe);
    return num_networks;
}

bool get_interface_details(char *interface, struct interface *details) {
    struct ifaddrs *ifa_list;
    if (getifaddrs(&ifa_list) == -1) {
        fprintf(stderr, "getifaddrs returned error: %s\n", strerror(errno));
        return false;
    }
    for (struct ifaddrs *ifa = ifa_list; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET && strcmp(ifa->ifa_name, interface) == 0) {
            struct sockaddr_in *addr = (struct sockaddr_in*) ifa->ifa_addr;
            struct sockaddr_in *netmask = (struct sockaddr_in*) ifa->ifa_netmask;
            struct sockaddr_in *broadcast = (struct sockaddr_in*) ifa->ifa_ifu.ifu_broadaddr;
            inet_ntop(AF_INET, &addr->sin_addr, details->ip_address, INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &netmask->sin_addr, details->netmask, INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &broadcast->sin_addr, details->broadcast_address, INET_ADDRSTRLEN);
            strcpy(details->name, interface);
            freeifaddrs(ifa_list);
            return true;
        }
    }
    freeifaddrs(ifa_list);
    return false;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <wireless interface>\n", argv[0]);
        return 1;
    }
    struct interface interface_details;
    if (!get_interface_details(argv[1], &interface_details)) {
        fprintf(stderr, "Error: interface %s not found or not a wireless interface\n", argv[1]);
        return 2;
    }
    printf("Interface: %s\n", interface_details.name);
    printf("IP Address: %s\n", interface_details.ip_address);
    printf("Netmask: %s\n", interface_details.netmask);
    printf("Broadcast Address: %s\n", interface_details.broadcast_address);
    printf("Scanning for wireless networks...\n");
    struct wireless_network networks[MAX_INTERFACES];
    int num_networks = get_wireless_networks(argv[1], networks, MAX_INTERFACES);
    if (num_networks == -1) {
        fprintf(stderr, "Error: could not scan for wireless networks\n");
        return 3;
    }
    printf("Found %d wireless networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%d. SSID: %s, BSSID: %s, Channel: %d, Signal Strength: %d\n", i+1, networks[i].ssid, networks[i].bssid, networks[i].channel, networks[i].signal_strength);
    }
    return 0;
}