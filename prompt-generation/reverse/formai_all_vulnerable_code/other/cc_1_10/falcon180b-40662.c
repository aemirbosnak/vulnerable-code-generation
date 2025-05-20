//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define BUF_SIZE 1024

void print_usage(char *prog) {
    printf("Usage: %s [interface]\n", prog);
}

int main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    struct ifreq ifr;
    int sock, ret;
    struct sockaddr_in *sin;
    char *ifname = NULL;

    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    ifname = argv[1];

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    strcpy(ifr.ifr_name, ifname);
    ret = ioctl(sock, SIOCGIFHWADDR, &ifr);
    if (ret < 0) {
        perror("ioctl");
        return 1;
    }

    sin = (struct sockaddr_in *)&ifr.ifr_hwaddr.sa_data;
    printf("MAC address of %s: ", ifname);
    for (int i = 0; i < 6; i++) {
        printf("%02x%c", sin->sin_addr.s_addr >> (5 - i * 2) * 8, i < 5? ':' : '\n');
    }

    close(sock);
    return 0;
}