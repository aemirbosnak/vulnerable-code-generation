//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/if_ether.h>

#define BUFSIZE 4096

int main(int argc, char *argv[])
{
    int sockfd;
    struct ifreq ifr;
    struct sockaddr_in *sin;
    char buf[BUFSIZE];
    int i, j, k;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < argc; i++) {
        strcpy(ifr.ifr_name, argv[i]);

        if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
            perror("ioctl");
            exit(EXIT_FAILURE);
        }

        sin = (struct sockaddr_in *)&ifr.ifr_addr;
        printf("%s: %s\n", argv[i], inet_ntoa(sin->sin_addr));

        if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1) {
            perror("ioctl");
            exit(EXIT_FAILURE);
        }

        printf("MAC: ");
        for (j = 0; j < 6; j++) {
            printf("%02x", (unsigned char)ifr.ifr_hwaddr.sa_data[j]);
            if (j < 5) {
                printf(":");
            }
        }
        printf("\n");

        if (ioctl(sockfd, SIOCGIFNETMASK, &ifr) == -1) {
            perror("ioctl");
            exit(EXIT_FAILURE);
        }

        sin = (struct sockaddr_in *)&ifr.ifr_netmask;
        printf("Netmask: %s\n", inet_ntoa(sin->sin_addr));

        if (ioctl(sockfd, SIOCGIFBRDADDR, &ifr) == -1) {
            perror("ioctl");
            exit(EXIT_FAILURE);
        }

        sin = (struct sockaddr_in *)&ifr.ifr_broadaddr;
        printf("Broadcast: %s\n", inet_ntoa(sin->sin_addr));
    }

    close(sockfd);

    return EXIT_SUCCESS;
}