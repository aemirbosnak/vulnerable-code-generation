//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>

#define MAX_BUFF 1024

struct pkt_info {
    uint64_t time;
    int size;
};

struct ioctl_data {
    struct ifreq ifr;
    char buff[MAX_BUFF];
};

struct sockaddr_ll sock_addr;

int main(int argc, char *argv[])
{
    int sockfd;
    int ret;
    int i;
    char *dev;
    struct ioctl_data ioctl_info;
    struct pkt_info *pkt_info;

    if (argc < 2) {
        printf("Usage: %s <device>", argv[0]);
        return -1;
    }

    dev = argv[1];

    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    memset(&ioctl_info.ifr, 0, sizeof(ioctl_info.ifr));
    strncpy(ioctl_info.ifr.ifr_name, dev, IFNAMSIZ);
    ret = ioctl(sockfd, SIOCGIFINDEX, &ioctl_info.ifr);
    if (ret == -1) {
        perror("ioctl");
        return -1;
    }

    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sll_family = AF_PACKET;
    sock_addr.sll_ifindex = ioctl_info.ifr.ifr_ifindex;

    ret = bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
    if (ret == -1) {
        perror("bind");
        return -1;
    }

    while (1) {
        ret = read(sockfd, ioctl_info.buff, MAX_BUFF);
        if (ret == -1) {
            perror("read");
            return -1;
        }

        pkt_info = (struct pkt_info *)ioctl_info.buff;
        printf("Time: %llu\n", pkt_info->time);
        printf("Size: %d\n", pkt_info->size);

        for (i = 0; i < 6; i++) {
            printf("%02x:", (unsigned char)ioctl_info.buff[i + 6]);
        }
        printf("%02x\n", (unsigned char)ioctl_info.buff[12]);
    }

    close(sockfd);
    return 0;
}