//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>

struct route_info {
    int              dst_ip;
    int              gw_ip;
    int              netmask;
    char             device[IFNAMSIZ];
};

struct topology {
    int              num_routes;
    struct route_info routes[16];
};

static int get_topology(struct topology *topo)
{
    struct ifreq      ifreq;
    struct sockaddr_in sin;
    int               sock;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        return -1;

    memset(&ifreq, 0, sizeof(ifreq));
    strncpy(ifreq.ifr_name, "lo", IFNAMSIZ);

    if (ioctl(sock, SIOCGIFADDR, &ifreq) != 0) {
        perror("ioctl(SIOCGIFADDR)");
        close(sock);
        return -1;
    }

    sin = *(struct sockaddr_in *)&ifreq.ifr_addr;
    topo->routes[0].dst_ip = sin.sin_addr.s_addr;
    topo->routes[0].gw_ip = sin.sin_addr.s_addr;
    topo->routes[0].netmask = 0xFFFFFFFF;
    strncpy(topo->routes[0].device, "lo", IFNAMSIZ);
    topo->num_routes = 1;

    memset(&ifreq, 0, sizeof(ifreq));
    strncpy(ifreq.ifr_name, "eth0", IFNAMSIZ);

    if (ioctl(sock, SIOCGIFADDR, &ifreq) != 0) {
        perror("ioctl(SIOCGIFADDR)");
        close(sock);
        return -1;
    }

    sin = *(struct sockaddr_in *)&ifreq.ifr_addr;
    topo->routes[1].dst_ip = sin.sin_addr.s_addr;
    topo->routes[1].gw_ip = sin.sin_addr.s_addr;
    topo->routes[1].netmask = 0xFFFFFFFF;
    strncpy(topo->routes[1].device, "eth0", IFNAMSIZ);
    topo->num_routes = 2;

    close(sock);
    return 0;
}

int main(int argc, char **argv)
{
    struct topology topo;

    if (get_topology(&topo) != 0) {
        perror("get_topology()");
        return EXIT_FAILURE;
    }

    printf("Network Topology:\n");
    for (int i = 0; i < topo.num_routes; i++) {
        printf("  Route %d:\n", i + 1);
        printf("    Destination IP: %s\n", inet_ntoa(topo.routes[i].dst_ip));
        printf("    Gateway IP: %s\n", inet_ntoa(topo.routes[i].gw_ip));
        printf("    Netmask: %s\n", inet_ntoa(topo.routes[i].netmask));
        printf("    Device: %s\n", topo.routes[i].device);
    }

    return EXIT_SUCCESS;
}