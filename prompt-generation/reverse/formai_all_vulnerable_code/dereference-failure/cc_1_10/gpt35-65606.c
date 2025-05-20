//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SCAN_INTERVAL 10 // Scan interval in seconds
#define MAX_DEVICES 50 // Maximum number of devices to store
#define MAX_NAME_LENGTH 50 // Maximum device name length
#define MAX_IP_LENGTH 16 // Maximum IP Address length

struct device {
    char name[MAX_NAME_LENGTH];
    char ip_address[MAX_IP_LENGTH];
};

int main() {
    struct device devices[MAX_DEVICES];
    int num_devices = 0;
    struct addrinfo hints, *res;
    int sockfd, rv;
    char ipstr[INET6_ADDRSTRLEN];

    // Set up hints for getaddrinfo
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP

    while (1) {
        printf("\nScanning network...\n");

        // Iterate over all IP addresses in the subnet
        for (uint8_t i = 1; i <= 254; i++) {
            char ip[16];
            sprintf(ip, "192.168.1.%d", i);

            // Try to resolve IP address
            if ((rv = getaddrinfo(ip, NULL, &hints, &res)) == 0) {
                struct in_addr *addr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;

                // Check if this device has already been added
                int exists = 0;
                for (int j = 0; j < num_devices; j++) {
                    if (strcmp(devices[j].ip_address, inet_ntoa(*addr)) == 0) {
                        exists = 1;
                        break;
                    }
                }
                if (exists) continue;

                // Get device name from reverse DNS lookup
                char *hostname = malloc(256);
                if (getnameinfo(res->ai_addr, res->ai_addrlen, hostname, 256, NULL, 0, 0) == 0) {
                    strcpy(devices[num_devices].name, hostname);
                } else {
                    // Otherwise use IP address as name
                    strcpy(devices[num_devices].name, inet_ntoa(*addr));
                }

                // Save device IP address
                strcpy(devices[num_devices].ip_address, inet_ntoa(*addr));

                // Print device information
                printf("%s (%s) is online.\n", devices[num_devices].name, devices[num_devices].ip_address);

                num_devices++;
            }
        }

        // Wait for the next scan interval
        sleep(SCAN_INTERVAL);
    }

    return 0;
}