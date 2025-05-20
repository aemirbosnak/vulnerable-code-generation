//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_INTERFACES 16
#define BUFF_SIZE 1024

struct interface {
    char name[32];
    int socket;
    struct sockaddr addr;
};

int main(void) {
    struct interface interfaces[MAX_INTERFACES];

    // Gather interfaces
    int if_count = 0;
    struct if_nameindex *if_nidx, *intf;
    if_nidx = if_nameindex();
    if (if_nidx != NULL) {
        for (intf = if_nidx; intf->if_index != 0 && if_count < MAX_INTERFACES; intf++, if_count++) {
            strncpy(interfaces[if_count].name, intf->if_name, sizeof(interfaces[if_count].name) - 1);
            interfaces[if_count].name[sizeof(interfaces[if_count].name) - 1] = '\0';

            // Create socket
            interfaces[if_count].socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);

            // Get interface address
            struct ifreq ifr;
            memset(&ifr, 0, sizeof(ifr));
            strncpy(ifr.ifr_name, interfaces[if_count].name, IFNAMSIZ - 1);
            ioctl(interfaces[if_count].socket, SIOCGIFADDR, &ifr);
            memcpy(&interfaces[if_count].addr, &ifr.ifr_addr, sizeof(struct sockaddr));
        }

        if_freenameindex(if_nidx);
    } else {
        perror("if_nameindex");
        exit(EXIT_FAILURE);
    }

    // Scan wireless networks
    printf("Scanning wireless networks...\n");
    char buf[BUFF_SIZE];
    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    int on = 1;
    setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2222);
    addr.sin_addr.s_addr = INADDR_BROADCAST;

    for (int i = 0; i < if_count; i++) {
        struct sockaddr_in *iface_addr = (struct sockaddr_in *)&interfaces[i].addr;
        addr.sin_addr.s_addr = iface_addr->sin_addr.s_addr | ~iface_addr->sin_addr.s_addr;
        sendto(fd, "SCAN", strlen("SCAN"), 0, (struct sockaddr *)&addr, sizeof(addr));
        printf("Sent SCAN command on interface: %s\n", interfaces[i].name);
    }

    // Receive scan results
    printf("Receiving scan results...\n");
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(fd, &fds);
    select(FD_SETSIZE, &fds, NULL, NULL, &tv);

    if (FD_ISSET(fd, &fds)) {
        struct sockaddr_in recv_addr;
        socklen_t recv_addr_len = sizeof(recv_addr);
        int bytes = recvfrom(fd, buf, BUFF_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_addr_len);
        if (bytes > 0) {
            buf[bytes] = '\0';
            printf("Scan results received from: %s\n", inet_ntoa(recv_addr.sin_addr));
            printf("%s\n", buf);
        }
    } else {
        printf("Scan results not received within timeout.\n");
    }

    // Clean up
    for (int i = 0; i < if_count; i++) {
        close(interfaces[i].socket);
    }
    close(fd);

    return 0;
}