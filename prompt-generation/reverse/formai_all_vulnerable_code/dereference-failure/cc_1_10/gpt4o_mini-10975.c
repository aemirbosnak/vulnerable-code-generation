//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/wireless.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_NETWORKS 128
#define MAX_SSID_LEN 32
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} Network;

void print_intro() {
    printf("== Welcome to the Wireless Network Scanner ==\n");
    printf(" A noble quest to unveil the hidden networks...\n\n");
}

void print_networks(Network networks[], int count) {
    printf("=== Behold the Networks Unveiled ===\n");
    for (int i = 0; i < count; i++) {
        printf(" %d. SSID: '%s' | Signal Strength: %d dBm\n", 
            i + 1, networks[i].ssid, networks[i].signal_strength);
    }
    printf("====================================\n");
}

int scan_wireless_networks(Network networks[]) {
    struct iwreq wrq;
    int sock;
    char buffer[MAX_BUFFER_SIZE];
    int count = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror(" The socket cannot be forged, seek help!");
        return -1;
    }

    strncpy(wrq.ifr_name, "wlan0", IFNAMSIZ);

    while (count < MAX_NETWORKS) {
        if (ioctl(sock, SIOCGIWSCAN, &wrq) < 0) {
            if (errno == ENOSR) break;  // No more networks
            perror(" The scanning has failed, consult the wizard!");
            close(sock);
            return -1;
        }
        
        // Parsing networks from buffer
        struct iw_event event;
        memset(buffer, 0, sizeof(buffer));
        while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
            memcpy(&event, buffer, sizeof(event));
            if (event.cmd == SIOCGIWNAME) {
                // Extracting SSID and signal strength
                memcpy(networks[count].ssid, event.u.essid.pointer, event.u.essid.length);
                networks[count].signal_strength = event.u.qual.level;
                count++;
            }
        }
    }
    close(sock);
    return count;
}

int main() {
    print_intro();

    Network networks[MAX_NETWORKS];
    int num_networks = scan_wireless_networks(networks);
    
    if (num_networks < 0) {
        printf(" Alas! The scanning could not be completed!\n");
        return EXIT_FAILURE;
    }

    if (num_networks == 0) {
        printf(" No networks found, the realm is barren...\n");
    } else {
        print_networks(networks, num_networks);
    }

    printf(" Thank you for embarking on this quest! Fare thee well!\n");
    return EXIT_SUCCESS;
}