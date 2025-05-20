//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <time.h>

#define MAX_INTERFACES 10
#define MAX_BUFFER_SIZE 256

typedef struct {
    char name[IFNAMSIZ];
    int rx_packets;
    int tx_packets;
    int rx_bytes;
    int tx_bytes;
} NetworkInterface;

void get_network_interfaces(NetworkInterface *interfaces, int *count) {
    struct ifaddrs *ifaddr, *ifa;
    *count = 0;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            if (*count < MAX_INTERFACES) {
                strncpy(interfaces[*count].name, ifa->ifa_name, IFNAMSIZ);
                interfaces[*count].rx_packets = 0;
                interfaces[*count].tx_packets = 0;
                interfaces[*count].rx_bytes = 0;
                interfaces[*count].tx_bytes = 0;
                (*count)++;
            }
        }
    }

    freeifaddrs(ifaddr);
}

void display_statistics(NetworkInterface *interfaces, int count) {
    printf("\nNetwork Quality of Service Statistics:\n");
    printf("%-20s %-15s %-15s %-15s %-15s\n", "Interface", "RX Packets", "TX Packets", "RX Bytes", "TX Bytes");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-15d %-15d %-15d %-15d\n", 
                interfaces[i].name, 
                interfaces[i].rx_packets, 
                interfaces[i].tx_packets, 
                interfaces[i].rx_bytes, 
                interfaces[i].tx_bytes);
    }
}

void random_data_generator(NetworkInterface *interfaces, int count) {
    for (int i = 0; i < count; i++) {
        interfaces[i].rx_packets += rand() % 100;
        interfaces[i].tx_packets += rand() % 100;
        interfaces[i].rx_bytes += (rand() % 1000) + 1;
        interfaces[i].tx_bytes += (rand() % 1000) + 1;
    }
}

int main() {
    srand(time(NULL));
    NetworkInterface interfaces[MAX_INTERFACES];
    int count = 0;

    get_network_interfaces(interfaces, &count);

    if (count == 0) {
        printf("No network interfaces found.\n");
        return EXIT_FAILURE;
    }

    while (1) {
        random_data_generator(interfaces, count);
        display_statistics(interfaces, count);
        sleep(1);
    }

    return EXIT_SUCCESS;
}