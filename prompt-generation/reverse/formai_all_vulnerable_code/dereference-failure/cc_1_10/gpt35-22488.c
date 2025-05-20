//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

int main(int argc, char* argv[])
{
    // Check for command-line argument (network interface name)
    if(argc < 2)
    {
        printf("Usage: %s [network interface name]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Open socket for wireless interface
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1)
    {
        printf("Error: Failed to open socket.\n");
        exit(EXIT_FAILURE);
    }
    
    // Get wireless interface index
    struct iwreq wrq;
    strncpy(wrq.ifr_name, argv[1], IFNAMSIZ);
    if(ioctl(sock, SIOCGIWNAME, &wrq) == -1)
    {
        printf("Error: Invalid network interface name.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // Get wireless interface info
    struct iw_statistics stats;
    if(ioctl(sock, SIOCGIWSTATS, &wrq) == -1)
    {
        printf("Error: Failed to get wireless interface info.\n");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // Print wireless interface info
    printf("---- Wireless Interface Info ----\n");
    printf("Interface name: %s\n", argv[1]);
    printf("Link quality: %d/%d\n", stats.qual.qual, stats.qual.level);
    printf("Signal level: %d dBm\n", stats.qual.level - 0x100);
    printf("Noise level: %d dBm\n", stats.qual.noise - 0x100);
    
    // Close socket and exit
    close(sock);
    exit(EXIT_SUCCESS);
}