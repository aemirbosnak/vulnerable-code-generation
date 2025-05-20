//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/wireless.h>
#include <errno.h>

#define MAX_SSID_LEN 32
#define MAX_NETWORKS 50

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WifiNetwork;

void scan_networks(WifiNetwork networks[], int *count, const char *interface) {
    int sockfd;
    struct iwreq request;
    struct iw_scan_req scan_req;
    struct iw_event iwe;
    char buffer[4096];

    *count = 0;

    // Create a socket for the specified interface
    sockfd = socket(AF_IEEE802154, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the interface name
    strncpy(request.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sockfd, SIOCGIWSCAN, &request) < 0) {
        perror("Failed to scan for networks");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Get scan results
    while (1) {
        // Check if we reached max networks
        if (*count >= MAX_NETWORKS) {
            break;
        }

        // Get event from the buffer
        if (read(sockfd, &iwe, sizeof(iwe)) < 0) {
            if (errno == EINTR) {
                continue; // Interrupted, try again
            } else {
                break; // End of scan
            }
        }

        // Read SSID and signal strength
        switch (iwe.cmd) {
        case SIOCGIWESSID:
            if (iwe.u.essid.length > 0) {
                strncpy(networks[*count].ssid, iwe.u.essid.pointer, MAX_SSID_LEN);
                networks[*count].signal_strength = iwe.u.qual.level * (-1); // Convert to dBm
                (*count)++;
            }
            break;
        default:
            break;
        }
    }

    close(sockfd);
}

void print_networks(WifiNetwork networks[], int count) {
    printf("Found %d networks:\n", count);
    for (int i = 0; i < count; i++) {
        printf("SSID: %-32s | Signal Strength: %ddBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main(int argc, char *argv[]) {
    WifiNetwork networks[MAX_NETWORKS];
    int count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *interface = argv[1];

    printf("Scanning for wireless networks on interface: %s\n", interface);
    scan_networks(networks, &count, interface);
    print_networks(networks, count);

    return EXIT_SUCCESS;
}