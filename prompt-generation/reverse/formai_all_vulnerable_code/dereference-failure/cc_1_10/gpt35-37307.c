//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    // Check if the user entered a network interface
    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Get the network interface from the user input
    char *interface = argv[1];
    printf("Monitoring Wi-Fi signal strength on interface %s...\n", interface);

    // Create a socket for the network interface
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Get the IP address of the network interface
    struct ifreq ifr;
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name));
    if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl");
        return 1;
    }
    struct sockaddr_in *sa = (struct sockaddr_in *)&ifr.ifr_addr;
    char *ip = inet_ntoa(sa->sin_addr);
    printf("IP address of interface %s is %s\n", interface, ip);

    // Get the Wi-Fi signal strength every second
    while (1) {
        // Get the Wi-Fi signal strength
        char cmd[256];
        snprintf(cmd, sizeof(cmd), "iwconfig %s", interface);
        FILE *fp = popen(cmd, "r");
        if (!fp) {
            perror("popen");
            return 1;
        }
        char buf[256];
        int signal_strength = 0;
        while (fgets(buf, sizeof(buf), fp)) {
            char *p = strstr(buf, "Signal level=");
            if (p) {
                int level;
                if (sscanf(p + strlen("Signal level="), "%d", &level) != 1) {
                    fprintf(stderr, "Failed to get signal level from '%s'\n", p);
                    break;
                }
                signal_strength = level;
                break;
            }
        }
        pclose(fp);

        // Print the Wi-Fi signal strength
        printf("Wi-Fi signal strength on interface %s is %d dBm\n", interface, signal_strength);

        // Wait for one second
        sleep(1);
    }

    // Close the socket
    close(sock);

    return 0;
}