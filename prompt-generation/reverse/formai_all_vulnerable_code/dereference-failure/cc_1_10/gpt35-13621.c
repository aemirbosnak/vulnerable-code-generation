//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, status, buflen;
    struct ifreq ifr;
    char *interface;
    unsigned char *buffer;
    struct sockaddr_in sin;
    int open_ports = 0;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s interface\n", argv[0]);
        exit(1);
    }

    interface = argv[1];
    buflen = 1024;

    // create a socket to use for the wireless network scan
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        error("Failed to create socket");
    }

    // get the IP address of the specified interface
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(sock, SIOCGIFADDR, &ifr) < 0) {
        error("ioctl failed: could not retrieve IP address");
    }
    memcpy(&sin, &ifr.ifr_addr, sizeof(sin));

    // print out some information about the network
    printf("Wireless Network Scanner by Sherlock Holmes\n");
    printf("Scanning network on interface %s with IP address %s\n", interface, inet_ntoa(sin.sin_addr));
    printf("Please wait...\n");

    // allocate a buffer for the scan data
    buffer = (unsigned char *) malloc(buflen);
    if (buffer == NULL) {
        error("malloc failed: could not allocate memory");
    }

    // loop through the scan results and print any open ports
    for (i = 1; i <= 65535; i++) {
        memset(buffer, 0, buflen);
        sin.sin_port = htons(i);
        status = sendto(sock, buffer, buflen, 0, (struct sockaddr *)&sin, sizeof(sin));
        if (status < 0) {
            error("sendto failed");
        }
        status = recvfrom(sock, buffer, buflen, 0, NULL, NULL);
        if (status < 0) {
            continue;
        }
        if (status > 0) {
            printf("Port %d is open\n", i);
            open_ports++;
        }
    }

    // clean up and exit
    free(buffer);
    close(sock);
    if (open_ports == 0) {
        printf("No open ports found on network.\n");
    } else {
        printf("Scan complete: %d open ports found on network.\n", open_ports);
    }
    return 0;
}