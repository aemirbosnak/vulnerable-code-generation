//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 16
#define MAX_BUFFER_SIZE 2048

void printHeader(int maxLen, char* title) {
    int len = strlen(title);
    int diff = (maxLen - len)/2;

    printf("\n\n");
    for(int i = 0; i < maxLen; i++) {
        if(i == 0 || i == maxLen-1) {
            printf("+");
        } else if(i == diff) {
            printf("%s", title);
            i += len-1;
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int main() {
    struct ifconf ifc;
    struct ifreq buffer[MAX_INTERFACES];
    char message[MAX_BUFFER_SIZE];
    int sock;

    // initialize socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sock < 0) {
        printf("Could not initialize socket\n");
        return 1;
    }

    // get all interfaces and their addresses
    ifc.ifc_len = sizeof(buffer);
    ifc.ifc_req = buffer;
    if (ioctl(sock, SIOCGIFCONF, &ifc) < 0) {
        printf("Could not get interfaces\n");
        return 1;
    }

    // loop over all interfaces
    for (int i = 0; i < ifc.ifc_len / sizeof(struct ifreq); i++) {
        struct ifreq* ifr = &buffer[i];

        // get interface flags
        if (ioctl(sock, SIOCGIFFLAGS, ifr) < 0) {
            printf("Could not get interface %s flags\n", ifr->ifr_name);
            continue;
        }

        // check if interface is up and running
        if (ifr->ifr_flags & IFF_UP && ifr->ifr_flags & IFF_RUNNING) {
            // get interface name and address
            char* name = ifr->ifr_name;
            struct sockaddr_in* addr = (struct sockaddr_in*)&ifr->ifr_addr;
            char* ip = inet_ntoa(addr->sin_addr);

            // initialize socket for interface
            int sock2 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            if (sock2 < 0) {
                printf("Could not initialize socket for interface %s\n", name);
                continue;
            }

            // bind socket to interface address
            struct sockaddr_in bind_addr;
            memset(&bind_addr, 0, sizeof(bind_addr));
            bind_addr.sin_family = AF_INET;
            bind_addr.sin_port = htons(0);
            bind_addr.sin_addr.s_addr = addr->sin_addr.s_addr;
            if (bind(sock2, (struct sockaddr*)&bind_addr, sizeof(bind_addr)) < 0) {
                printf("Could not bind socket to interface %s\n", name);
                close(sock2);
                continue;
            }

            // get broadcast address for network
            struct sockaddr_in bcast_addr;
            memset(&bcast_addr, 0, sizeof(bcast_addr));
            bcast_addr.sin_family = AF_INET;
            bcast_addr.sin_port = htons(1234);
            bcast_addr.sin_addr.s_addr = (addr->sin_addr.s_addr & 0xFFFFFF00) | 0xFF;

            // create message to send
            sprintf(message, "Hello, world! This message was sent from interface %s with IP address %s\n", name, ip);

            // set socket options to broadcast datagrams
            int enable = 1;
            if (setsockopt(sock2, SOL_SOCKET, SO_BROADCAST, &enable, sizeof(enable)) < 0) {
                printf("Could not set socket options for interface %s\n", name);
                close(sock2);
                continue;
            }

            // send message to broadcast address
            if (sendto(sock2, message, strlen(message), 0, (struct sockaddr*)&bcast_addr, sizeof(bcast_addr)) < 0) {
                printf("Could not send message from interface %s\n", name);
                close(sock2);
                continue;
            }

            // receive response
            char recv_msg[MAX_BUFFER_SIZE];
            struct sockaddr_in recv_addr;
            memset(&recv_addr, 0, sizeof(recv_addr));
            socklen_t addr_len = sizeof(recv_addr);
            if (recvfrom(sock2, recv_msg, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&recv_addr, &addr_len) < 0) {
                printf("Could not receive message from interface %s\n", name);
                close(sock2);
                continue;
            }

            // print response
            char* recv_ip = inet_ntoa(recv_addr.sin_addr);
            printf("Received message from interface %s with IP address %s: %s\n", name, recv_ip, recv_msg);

            close(sock2);
        }
    }

    close(sock);

    return 0;
}