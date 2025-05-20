//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <linux/if_ether.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define DEFAULT_INTERFACE "wlan0"

void list_available_interfaces() {
    system("iw dev | grep Interface");
}

char *get_interface() {
    char *interface = (char *)malloc(IFNAMSIZ);
    if(interface == NULL) {
        perror("Unable to allocate memory for interface");
        exit(EXIT_FAILURE);
    }
    snprintf(interface, IFNAMSIZ, DEFAULT_INTERFACE);
    return interface;
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void setup_socket(int sock, char *interface) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Binding socket to interface failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (ioctl(sock, SIOCGIFINDEX, interface) < 0) {
        perror("Getting interface index failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
}

void scan_networks(int sock) {
    unsigned char buffer[BUFFER_SIZE];

    while (1) {
        int n = recv(sock, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("Packet receive failed");
            close(sock);
            exit(EXIT_FAILURE);
        }

        struct ethhdr *eth = (struct ethhdr *)buffer;
        if (ntohs(eth->h_proto) == ETH_P_ALL) {
            unsigned char *ssid = buffer + 36; // Skip the Ethernet header to get to the SSID

            // Assume we are interested in scanning for WiFi networks
            printf("Detected SSID: %.*s\n", 32, ssid);
            fflush(stdout);
        }
    }
}

int main() {
    printf("Available wireless interfaces:\n");
    list_available_interfaces();

    char *interface = get_interface();
    printf("Using interface: %s\n", interface);
    
    int sock = create_socket();
    setup_socket(sock, interface);
    
    printf("Scanning for wireless networks...\n");
    scan_networks(sock);
    
    free(interface);
    close(sock);
    return 0;
}