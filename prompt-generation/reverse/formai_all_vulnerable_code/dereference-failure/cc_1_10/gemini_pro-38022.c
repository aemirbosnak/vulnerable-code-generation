//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/wireless.h>

#define MAX_SSID_LEN        32
#define MAX_BSSID_LEN       6

// Function to get signal strength
int get_signal_strength(char *interface)
{
    int sockfd;
    struct iwreq wrq;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set the interface name
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);

    // Get the signal strength
    if (ioctl(sockfd, SIOCGIWSTATS, &wrq) < 0) {
        perror("ioctl");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    // Return the signal strength
    return wrq.u.qual.qual;
}

// Function to get SSID
char *get_ssid(char *interface)
{
    int sockfd;
    struct iwreq wrq;
    char *ssid = NULL;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return NULL;
    }

    // Set the interface name
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);

    // Get the SSID
    if (ioctl(sockfd, SIOCGIWESSID, &wrq) < 0) {
        perror("ioctl");
        close(sockfd);
        return NULL;
    }

    // Allocate memory for the SSID
    ssid = malloc(MAX_SSID_LEN + 1);
    if (ssid == NULL) {
        perror("malloc");
        close(sockfd);
        return NULL;
    }

    // Copy the SSID to the buffer
    strncpy(ssid, wrq.u.essid.pointer, MAX_SSID_LEN);

    close(sockfd);

    // Return the SSID
    return ssid;
}

// Function to get BSSID
char *get_bssid(char *interface)
{
    int sockfd;
    struct iwreq wrq;
    char *bssid = NULL;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return NULL;
    }

    // Set the interface name
    strncpy(wrq.ifr_name, interface, IFNAMSIZ);

    // Get the BSSID
    if (ioctl(sockfd, SIOCGIWAP, &wrq) < 0) {
        perror("ioctl");
        close(sockfd);
        return NULL;
    }

    // Allocate memory for the BSSID
    bssid = malloc(MAX_BSSID_LEN + 1);
    if (bssid == NULL) {
        perror("malloc");
        close(sockfd);
        return NULL;
    }

    // Copy the BSSID to the buffer
    strncpy(bssid, wrq.u.ap_addr.sa_data, MAX_BSSID_LEN);

    close(sockfd);

    // Return the BSSID
    return bssid;
}

// Main function
int main(int argc, char **argv)
{
    int signal_strength;
    char *ssid;
    char *bssid;

    // Check if the user has provided an interface name
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the signal strength
    signal_strength = get_signal_strength(argv[1]);
    if (signal_strength < 0) {
        perror("get_signal_strength");
        return EXIT_FAILURE;
    }

    // Get the SSID
    ssid = get_ssid(argv[1]);
    if (ssid == NULL) {
        perror("get_ssid");
        return EXIT_FAILURE;
    }

    // Get the BSSID
    bssid = get_bssid(argv[1]);
    if (bssid == NULL) {
        perror("get_bssid");
        return EXIT_FAILURE;
    }

    // Print the results
    printf("Interface: %s\n", argv[1]);
    printf("Signal strength: %d%%\n", signal_strength);
    printf("SSID: %s\n", ssid);
    printf("BSSID: %s\n", bssid);

    // Free the allocated memory
    free(ssid);
    free(bssid);

    return EXIT_SUCCESS;
}