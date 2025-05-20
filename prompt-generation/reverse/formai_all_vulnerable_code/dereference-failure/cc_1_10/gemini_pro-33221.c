//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to get the IP address of the host
char *get_ip_address(char *interface) {
    int fd;
    struct ifreq ifr;
    char *ip_address = NULL;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("socket");
        return NULL;
    }

    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);

    if (ioctl(fd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl");
        close(fd);
        return NULL;
    }

    close(fd);

    ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);

    return ip_address;
}

// Function to get the MAC address of the host
char *get_mac_address(char *interface) {
    int fd;
    struct ifreq ifr;
    char *mac_address = NULL;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd == -1) {
        perror("socket");
        return NULL;
    }

    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);

    if (ioctl(fd, SIOCGIFHWADDR, &ifr) == -1) {
        perror("ioctl");
        close(fd);
        return NULL;
    }

    close(fd);

    mac_address = ether_ntoa((struct ether_addr *)ifr.ifr_hwaddr.sa_data);

    return mac_address;
}

// Function to scan the network for wireless networks
void scan_network(char *interface) {
    char *ip_address = get_ip_address(interface);
    char *mac_address = get_mac_address(interface);

    if (ip_address == NULL || mac_address == NULL) {
        printf("Error getting IP address or MAC address\n");
        return;
    }

    // Create a socket for sending and receiving data
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }

    // Set the socket to broadcast mode
    int broadcast = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(int)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return;
    }

    // Prepare the broadcast message
    char message[] = "DISCOVER_REQUEST";
    struct sockaddr_in broadcast_addr;
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_addr.s_addr = inet_addr("255.255.255.255");
    broadcast_addr.sin_port = htons(5353);

    // Send the broadcast message
    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
        perror("sendto");
        close(sockfd);
        return;
    }

    // Receive responses from wireless networks
    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);
    char buffer[1024];
    while (1) {
        int recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sender_addr, &sender_addr_len);
        if (recv_len == -1) {
            perror("recvfrom");
            close(sockfd);
            return;
        }

        // Parse the response message
        char *ssid = NULL;
        char *bssid = NULL;
        char *channel = NULL;
        char *security = NULL;
        char *rssi = NULL;

        char *ptr = buffer;
        while (*ptr != '\0') {
            char *key = ptr;
            while (*ptr != ':' && *ptr != '\0') {
                ptr++;
            }
            *ptr = '\0';
            ptr++;

            char *value = ptr;
            while (*ptr != ';' && *ptr != '\0') {
                ptr++;
            }
            *ptr = '\0';
            ptr++;

            if (strcmp(key, "SSID") == 0) {
                ssid = value;
            } else if (strcmp(key, "BSSID") == 0) {
                bssid = value;
            } else if (strcmp(key, "CHANNEL") == 0) {
                channel = value;
            } else if (strcmp(key, "SECURITY") == 0) {
                security = value;
            } else if (strcmp(key, "RSSI") == 0) {
                rssi = value;
            }
        }

        // Print the network information
        printf("SSID: %s\n", ssid);
        printf("BSSID: %s\n", bssid);
        printf("CHANNEL: %s\n", channel);
        printf("SECURITY: %s\n", security);
        printf("RSSI: %s\n\n", rssi);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_network(argv[1]);

    return EXIT_SUCCESS;
}