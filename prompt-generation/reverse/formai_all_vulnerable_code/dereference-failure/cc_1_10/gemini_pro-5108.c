//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <net/if.h>

#include <sys/socket.h>
#include <sys/ioctl.h>

#define RomeoPort ((unsigned short)54321)
#define JulietPort ((unsigned short)54322)

#define BufferSize (1024 * 10)
#define MaxIfaceLength (16)

struct QosMonitor {
    int sockfd;
    struct sockaddr_in addr;
    struct ifreq ifr;
};

static struct QosMonitor Romeo, Juliet;

static void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static void sigint_handler(int sig) {
    close(Romeo.sockfd);
    close(Juliet.sockfd);
    exit(EXIT_SUCCESS);
}

static void init_QosMonitor(struct QosMonitor *mon, const char *ifname, unsigned short port) {
    mon->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (mon->sockfd < 0) error("socket");

    memset(&mon->addr, 0, sizeof(mon->addr));
    mon->addr.sin_family = AF_INET;
    mon->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    mon->addr.sin_port = htons(port);

    if (bind(mon->sockfd, (struct sockaddr *)&mon->addr, sizeof(mon->addr)) < 0) error("bind");

    strcpy(mon->ifr.ifr_name, ifname);
    if (ioctl(mon->sockfd, SIOCGIFFLAGS, &mon->ifr) < 0) error("ioctl");
}

static void start_QosMonitor(struct QosMonitor *mon) {
    mon->ifr.ifr_flags |= IFF_UP;
    if (ioctl(mon->sockfd, SIOCSIFFLAGS, &mon->ifr) < 0) error("ioctl");
}

static void stop_QosMonitor(struct QosMonitor *mon) {
    mon->ifr.ifr_flags &= ~IFF_UP;
    if (ioctl(mon->sockfd, SIOCSIFFLAGS, &mon->ifr) < 0) error("ioctl");
}

static void monitor_Qos(struct QosMonitor *mon) {
    char buffer[BufferSize];
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);

    while (1) {
        int n = recvfrom(mon->sockfd, buffer, BufferSize, 0, (struct sockaddr *)&src_addr, &src_addr_len);
        if (n < 0) {
            if (errno == EINTR) continue;
            error("recvfrom");
        }

        printf("Received %d bytes from %s:%d\n", n, inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
    }
}

int main(int argc, char **argv) {
    if (argc != 3) error("Usage: qos-monitor <interface> <ifname>");

    signal(SIGINT, sigint_handler);

    init_QosMonitor(&Romeo, argv[1], RomeoPort);
    init_QosMonitor(&Juliet, argv[2], JulietPort);

    start_QosMonitor(&Romeo);
    start_QosMonitor(&Juliet);

    monitor_Qos(&Romeo);
    monitor_Qos(&Juliet);

    return EXIT_SUCCESS;
}