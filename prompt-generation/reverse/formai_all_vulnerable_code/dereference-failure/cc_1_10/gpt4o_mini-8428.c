//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>

#define MAX_INTERFACES 10
#define BUFFER_SIZE 1024
#define SLEEP_INTERVAL 2

typedef struct {
    char name[IFNAMSIZ];
    unsigned long rx_bytes;
    unsigned long tx_bytes;
    unsigned long rx_packets;
    unsigned long tx_packets;
} InterfaceStats;

void print_interface_stats(InterfaceStats *interfaces, int count) {
    printf("\nNetwork Quality of Service Monitor\n");
    printf("------------------------------------\n");
    printf("%-15s %-10s %-10s %-10s %-10s\n", "Interface", "RX Bytes", "TX Bytes", "RX Packets", "TX Packets");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-10lu %-10lu %-10lu %-10lu\n",
            interfaces[i].name,
            interfaces[i].rx_bytes,
            interfaces[i].tx_bytes,
            interfaces[i].rx_packets,
            interfaces[i].tx_packets);
    }
}

int get_interface_stats(const char *ifname, InterfaceStats *stats) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/net/dev");
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Could not open /proc/net/dev");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, ifname)) {
            found = 1;
            sscanf(buffer, "%[^:]: %lu %lu %lu %lu", 
                stats->name,
                &stats->rx_bytes,
                &stats->rx_packets,
                &stats->tx_bytes,
                &stats->tx_packets);
            break;
        }
    }

    fclose(file);
    return found ? 0 : -1;
}

void monitor_qos(const char *ifnames[], int if_count) {
    InterfaceStats interfaces[MAX_INTERFACES];
    for (int i = 0; i < if_count; i++) {
        if (get_interface_stats(ifnames[i], &interfaces[i]) < 0) {
            printf("Error retrieving stats for %s\n", ifnames[i]);
            continue;
        }
    }

    while (1) {
        sleep(SLEEP_INTERVAL);
        for (int i = 0; i < if_count; i++) {
            if (get_interface_stats(ifnames[i], &interfaces[i]) < 0) {
                printf("Error retrieving stats for %s\n", ifnames[i]);
                continue;
            }
        }
        print_interface_stats(interfaces, if_count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <interface_name1> <interface_name2> ...\n", argv[0]);
        return 1;
    }

    int if_count = argc - 1;
    char *ifnames[MAX_INTERFACES];

    for (int i = 0; i < if_count; i++) {
        ifnames[i] = argv[i + 1];
    }

    monitor_qos(ifnames, if_count);

    return 0;
}