//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define WLAN_INTERFACE "wlan0" // Change accordingly based on your network interface
#define SCAN_TIMEOUT 5 // seconds

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void display_ap_info(char *buffer, int length) {
    // Extract basic AP information from received data 
    printf("Received %d bytes:\n", length);
    for (int i = 0; i < length; i++) {
        printf("%02x ", buffer[i]);
        if((i+1) % 16 == 0)
            printf("\n");
    }
    printf("\n");
}

void scan_wireless_networks() {
    int sockfd;
    struct ifreq ifr;
    struct sockaddr_in sin;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW); 
    if (sockfd < 0)
        error_exit("Error creating socket");

    strncpy(ifr.ifr_name, WLAN_INTERFACE, IFNAMSIZ-1);
    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0)
        error_exit("Error getting interface index");

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(0);
    if (bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
        error_exit("Bind failed");

    // Set socket options to enable promiscuous mode
    int flags = 1; 
    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0)
        error_exit("Error getting interface flags");
    ifr.ifr_flags |= IFF_PROMISC;
    if (ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0)
        error_exit("Error setting interface flags");

    printf("Scanning for wireless networks...\n");

    // Scan loop
    for (int i = 0; i < SCAN_TIMEOUT; i++) {
        int recv_len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (recv_len < 0) {
            if (errno == EINTR) continue; // Interrupted system call 
            error_exit("Error receiving data");
        }
        display_ap_info(buffer, recv_len);
        sleep(1);
    }

    // Reset promiscuous mode
    ifr.ifr_flags &= ~IFF_PROMISC;
    if (ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0)
        error_exit("Error resetting interface flags");

    close(sockfd);
    printf("Finished scanning.\n");
}

int main() {
    scan_wireless_networks();
    return 0;
}