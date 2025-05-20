//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

// Define colors for output
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char *argv[]) {

    int sock_fd;
    struct iwreq iw;
    char buffer[IW_ESSID_MAX_SIZE + 1];

    // Open socket for wireless interface
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set interface name
    strcpy(iw.ifr_name, "wlan0");

    // Set up the request for scanning
    iw.u.data.pointer = NULL;
    iw.u.data.length = 0;
    iw.u.data.flags = 1;

    // Perform the scan
    if (ioctl(sock_fd, SIOCSIWSCAN, &iw) < 0) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    // Sleep for a bit to allow the scan to complete
    sleep(5);

    // Set up the request for getting the scan results
    iw.u.data.pointer = (caddr_t) malloc(sizeof(char) * IW_SCAN_MAX_DATA);
    iw.u.data.length = IW_SCAN_MAX_DATA;
    if (ioctl(sock_fd, SIOCGIWSCAN, &iw) < 0) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    // Get the scan results
    struct iw_event *event = (struct iw_event *) iw.u.data.pointer;
    while (event->cmd != SIOCGIWSCAN) {
        // Only process wireless events
        if (event->cmd == SIOCGIWRATE) {
            // Get the ESSID
            struct iw_event essid_event;
            memcpy(&essid_event, event, sizeof(struct iw_event));
            memcpy(buffer, essid_event.u.essid.pointer, essid_event.u.essid.length);
            buffer[essid_event.u.essid.length] = '\0';

            // Get the signal strength
            struct iw_event signal_event;
            memcpy(&signal_event, event + 1, sizeof(struct iw_event));
            int signal_strength = (signal_event.u.qual.level * 100) / 255;

            // Display the network information in a cheerful way
            printf(ANSI_COLOR_GREEN "✓ Found network %s with signal strength %d%%\n" ANSI_COLOR_RESET, buffer, signal_strength);
        }

        // Move to next event
        event = (struct iw_event *) ((char *) event + event->len);
    }

    // Clean up
    free(iw.u.data.pointer);
    close(sock_fd);

    return 0;
}