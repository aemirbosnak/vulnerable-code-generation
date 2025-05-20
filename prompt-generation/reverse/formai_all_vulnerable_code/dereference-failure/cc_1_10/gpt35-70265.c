//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <net/if.h>

#define MAX_INTERFACES 8
#define MAX_WIRELESS_NETWORKS 100

struct wireless_network {
    char ssid[32];
    int signal;
};

struct interface {
    char name[IFNAMSIZ];
    struct sockaddr_in ip_addr;
    struct wireless_network networks[MAX_WIRELESS_NETWORKS];
    int num_networks;
};

struct interface interfaces[MAX_INTERFACES];
int num_interfaces = 0;

int get_interfaces() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return 0;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (num_interfaces == MAX_INTERFACES) {
            break;
        }

        if (ifa->ifa_addr == NULL) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET) {
            s = socket(AF_INET, SOCK_STREAM, 0);

            if (s == -1) {
                perror("socket");
                continue;
            }

            if (setsockopt(s, SOL_SOCKET, SO_BINDTODEVICE, ifa->ifa_name, strlen(ifa->ifa_name)) == -1) {
                close(s);
                continue;
            }

            struct sockaddr_in *addr = (struct sockaddr_in*)ifa->ifa_addr;
            struct interface iface;

            strcpy(iface.name, ifa->ifa_name);
            iface.ip_addr = *addr;
            iface.num_networks = 0;

            interfaces[num_interfaces++] = iface;

            close(s);
        }
    }

    freeifaddrs(ifaddr);

    return num_interfaces;
}

int get_signal_strength(char *ssid) {
    FILE *fp;
    char buffer[1024];
    char command[64];

    sprintf(command, "iwconfig 2>&1 | grep -A3 '%s' | grep Signal", ssid);

    fp = popen(command, "r");

    if (fp == NULL) {
        perror("popen");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        char *signal_str = strstr(buffer, "Signal level=");
        char *dbm_str = strstr(signal_str, "dBm");

        if (signal_str != NULL && dbm_str != NULL) {
            int signal = atoi(signal_str + 14);

            fclose(fp);

            return signal;
        }
    }

    fclose(fp);

    return 0;
}

int scan_wireless_networks(struct interface *iface) {
    FILE *fp;
    char buffer[1024];
    char command[64];

    sprintf(command, "iwlist %s scan 2>&1 | grep ESSID", iface->name);

    fp = popen(command, "r");

    if (fp == NULL) {
        perror("popen");
        return 0;
    }

    iface->num_networks = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        char *ssid_str = strstr(buffer, "ESSID:");
        char *quote1_str, *quote2_str;

        if (ssid_str != NULL) {
            struct wireless_network network;

            memset(&network, 0, sizeof(network));

            quote1_str = strchr(ssid_str, '"');

            if (quote1_str == NULL) {
                continue;
            }

            quote2_str = strchr(quote1_str + 1, '"');

            if (quote2_str == NULL) {
                continue;
            }

            memcpy(network.ssid, quote1_str + 1, quote2_str - quote1_str - 1);
            network.signal = get_signal_strength(network.ssid);

            iface->networks[iface->num_networks++] = network;
        }
    }

    fclose(fp);

    return iface->num_networks;
}

int main() {
    get_interfaces();

    for (int i = 0; i < num_interfaces; i++) {
        if (scan_wireless_networks(&interfaces[i]) > 0) {
            printf("Wireless networks found on interface %s:\n", interfaces[i].name);

            for (int j = 0; j < interfaces[i].num_networks; j++) {
                printf("\t%s (Signal strength: %ddBm)\n", interfaces[i].networks[j].ssid, interfaces[i].networks[j].signal);
            }
        }
    }

    return 0;
}