//FormAI DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define BUFFSIZE 1024

void handler(int num) {
    printf("Interrupted signal %d received, exiting...", num);
    exit(0);
}

int main(int argc, char *argv[]) {
    int fd, ret, n, len;
    char buffer[BUFFSIZE], ipstr[INET_ADDRSTRLEN];
    struct sockaddr_in sa;
    struct ifreq ifr;

    signal(SIGINT, handler);

    if(argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Open a raw socket
    if((fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("socket() error");
        return -1;
    }

    // Set socket options to allow it to receive all packets
    int flag = 1;
    if(setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &flag, sizeof(flag)) == -1) {
        perror("setsockopt() error");
        return -1;
    }

    // Bind socket to specified interface
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, argv[1], IFNAMSIZ - 1);
    if(ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
        perror("ioctl() error");
        return -1;
    }

    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(0);
    sa.sin_addr.s_addr = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;
    if(bind(fd, (struct sockaddr *)&sa, sizeof(struct sockaddr_in)) == -1) {
        perror("bind() error");
        return -1;
    }

    printf("Listening on interface %s...\n", argv[1]);

    // Loop to receive and process packets
    for(;;) {
        memset(buffer, 0, sizeof(buffer));
        len = sizeof(sa);

        if((n = recvfrom(fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&sa, &len)) < 0) {
            if(errno == EINTR) {
                continue;
            }
            perror("recvfrom() error");
            return -1;
        }

        // Print source and destination IP address and port
        printf("Received %d bytes from %s:%d to %s:%d\n", n, 
        inet_ntop(AF_INET, &(sa.sin_addr), ipstr, INET_ADDRSTRLEN), htons(sa.sin_port), 
        inet_ntop(AF_INET, &(sa.sin_addr), ipstr, INET_ADDRSTRLEN), htons(sa.sin_port));
    }

    return 0;
}