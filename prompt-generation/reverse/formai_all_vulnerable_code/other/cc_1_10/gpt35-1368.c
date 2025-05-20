//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define MAX_TRY 3

bool is_valid_ip(const char *ip) {
    if (ip == NULL || strlen(ip) < 7 || strlen(ip) > 15) {
        return false;
    }

    struct sockaddr_in sa;
    int res = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return res != 0;
}

int main() {
    printf("Welcome to the Wireless Network Scanner program\n");
    
    int sockfd;
    char buf[BUF_SIZE];
    int numbytes;
    char *iface = "wlan0";

    // create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // get IP address of WLAN interface
    struct ifreq ifr;
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, iface, IFNAMSIZ-1);
    ioctl(sockfd, SIOCGIFADDR, &ifr);
    char* ip_addr = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
    printf("Local IP address: %s\n", ip_addr);

    // prepare broadcast address
    char *broadcast_addr = malloc(strlen(ip_addr) + 3);
    sprintf(broadcast_addr, "%s255", strtok(ip_addr, "."));

    // create UDP socket for broadcasting
    int broadcast_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (broadcast_sock < 0) {
        perror("socket");
        exit(1);
    }

    // set broadcast option
    int optval = 1;
    if (setsockopt(broadcast_sock, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // send broadcast packets and listen for responses
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(broadcast_addr);
    server_addr.sin_port = htons(5000);

    bool found_devices = false;
    int i = 0;
    while (i < MAX_TRY && !found_devices) {
        printf("Sending broadcast packet %d...\n", i+1);
        int res = sendto(broadcast_sock, "HELLO", 5, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        
        // wait for responses
        fd_set fds;
        struct timeval timeout;
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);

        select(sockfd+1, &fds, NULL, NULL, &timeout);
        if (FD_ISSET(sockfd, &fds)) {
            numbytes = recv(sockfd, buf, BUF_SIZE-1, 0);
            if (numbytes > 0) {
                buf[numbytes] = '\0';
                printf("Found device at %s\n", buf);
                found_devices = true;
            }
        }
        i++;
    }

    if (!found_devices) {
        printf("No devices found\n");
    }

    close(sockfd);
    close(broadcast_sock);
    free(broadcast_addr);
    return 0;
}