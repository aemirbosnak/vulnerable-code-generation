//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

// Structure to store the signal strength data
typedef struct {
    int quality;
    int level;
    int noise;
} SignalStrength;

// Function to get the signal strength of a specific interface
SignalStrength getSignalStrength(char *interface) {
    // Create a socket for communication with the kernel
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the interface index
    struct ifreq ifr;
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) == -1) {
        perror("ioctl");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Get the wireless statistics
    struct iwreq wrq;
    memset(&wrq, 0, sizeof(wrq));
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);
    wrq.u.data.pointer = (caddr_t) malloc(IW_MAX_SPY);
    wrq.u.data.length = IW_MAX_SPY;
    wrq.u.data.flags = 1; // Set the spy flag
    if (ioctl(sock, SIOCGIWSPY, &wrq) == -1) {
        perror("ioctl");
        free(wrq.u.data.pointer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Parse the wireless statistics
    SignalStrength signalStrength;
    char *data = wrq.u.data.pointer;
    sscanf(data, "quality=%d  level=%d  noise=%d", &signalStrength.quality, &signalStrength.level, &signalStrength.noise);

    // Free the allocated memory
    free(wrq.u.data.pointer);

    // Close the socket
    close(sock);

    return signalStrength;
}

// Function to print the signal strength data
void printSignalStrength(SignalStrength signalStrength) {
    printf("Quality: %d%%\n", signalStrength.quality);
    printf("Level: %d dBm\n", signalStrength.level);
    printf("Noise: %d dBm\n", signalStrength.noise);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user provided an interface name
    if (argc != 2) {
        fprintf(stderr, "Usage: %s interface\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the signal strength of the specified interface
    SignalStrength signalStrength = getSignalStrength(argv[1]);

    // Print the signal strength data
    printSignalStrength(signalStrength);

    return 0;
}