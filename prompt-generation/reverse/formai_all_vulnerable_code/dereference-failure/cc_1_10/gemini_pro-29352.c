//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
// Linus Torvalds Style Wi-Fi Signal Strength Analyzer

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

int main(int argc, char **argv)
{
    int sockfd;
    struct iwreq wrq;
    int ret;

    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get interface name
    strncpy(wrq.ifr_name, argv[1], IFNAMSIZ);

    // Request signal strength
    wrq.u.data.pointer = NULL;
    wrq.u.data.length = 0;
    wrq.u.data.flags = 0;
    ret = ioctl(sockfd, SIOCGIWSTATS, &wrq);
    if (ret < 0) {
        perror("ioctl");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Parse signal strength
    char *signal = (char *)wrq.u.data.pointer;
    int strength = atoi(signal);
    close(sockfd);

    // Display signal strength
    printf("Signal strength: %d dBm\n", strength);

    // Exit
    return EXIT_SUCCESS;
}