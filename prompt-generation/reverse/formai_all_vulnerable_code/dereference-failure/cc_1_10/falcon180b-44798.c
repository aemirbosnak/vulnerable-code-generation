//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_INTERFACES 10

struct interface {
    char name[IF_NAMESIZE];
    char mac[18];
    char ip[16];
};

struct network {
    char name[IF_NAMESIZE];
    char mac[18];
    char ip[16];
};

int get_interface_list(struct interface *interfaces, int max_interfaces) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    struct ifreq ifr;
    strcpy(ifr.ifr_name, "eth0");

    if (ioctl(sock, SIOCGIFHWADDR, &ifr) == -1) {
        perror("ioctl");
        close(sock);
        return -1;
    }

    strcpy(interfaces[0].name, "eth0");
    strcpy(interfaces[0].mac, ifr.ifr_hwaddr.sa_data);

    close(sock);
    return 1;
}

int get_network_list(struct network *networks, int max_networks) {
    struct sockaddr_in sin;
    struct ifreq ifr;
    char buffer[BUFFER_SIZE];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        perror("socket");
        return -1;
    }

    strcpy(ifr.ifr_name, "eth0");
    if (ioctl(sock, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl");
        close(sock);
        return -1;
    }

    strcpy(networks[0].name, "eth0");
    strcpy(networks[0].mac, ifr.ifr_hwaddr.sa_data);
    strcpy(networks[0].ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

    close(sock);
    return 1;
}

int main() {
    struct interface interfaces[MAX_INTERFACES];
    int num_interfaces = get_interface_list(interfaces, MAX_INTERFACES);

    struct network networks[MAX_INTERFACES];
    int num_networks = get_network_list(networks, MAX_INTERFACES);

    printf("Interfaces:\n");
    for (int i = 0; i < num_interfaces; i++) {
        printf("Name: %s\nMAC: %s\n", interfaces[i].name, interfaces[i].mac);
    }

    printf("\nNetworks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("Name: %s\nMAC: %s\nIP: %s\n", networks[i].name, networks[i].mac, networks[i].ip);
    }

    return 0;
}