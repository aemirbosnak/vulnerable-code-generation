//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <ctype.h>

void scan_wifi_networks(char*);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [interface]\n", argv[0]);
        return 1;
    }

    printf("Scanning for wireless networks...\n");
    printf("Press Ctrl+C to terminate the program.\n\n");

    scan_wifi_networks(argv[1]);

    return 0;
}

void scan_wifi_networks(char *interface) {
    int sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock_fd < 0) {
        perror("socket");
        return;
    }

    struct ifreq ifr;
    strncpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name));
    ifr.ifr_name[sizeof(ifr.ifr_name)-1] = '\0';

    if (ioctl(sock_fd, SIOCGIFFLAGS, &ifr) < 0) {
        perror("ioctl");
        close(sock_fd);
        return;
    }

    ifr.ifr_flags |= IFF_PROMISC;
    if (ioctl(sock_fd, SIOCSIFFLAGS, &ifr) < 0) {
        perror("ioctl");
        close(sock_fd);
        return;
    }

    char buf[1024];
    struct sockaddr_in sender_addr;
    socklen_t sender_addr_len = sizeof(sender_addr);
    while (1) {
        memset(buf, 0, sizeof(buf));
        ssize_t len = recvfrom(sock_fd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&sender_addr, &sender_addr_len);

        if (len < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("recvfrom");
            break;
        }

        char *p = buf;
        while (*p) {
            if (isprint(*p)) {
                putchar(*p);
            }
            else {
                putchar('.');
            }
            p++;
        }
        printf("\n");
    }

    ifr.ifr_flags &= ~IFF_PROMISC;
    if (ioctl(sock_fd, SIOCSIFFLAGS, &ifr) < 0) {
        perror("ioctl");
        close(sock_fd);
        return;
    }

    close(sock_fd);
}