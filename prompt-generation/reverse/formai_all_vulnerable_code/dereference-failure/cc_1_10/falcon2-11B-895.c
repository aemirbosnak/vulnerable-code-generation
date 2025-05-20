//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <linux/sockios.h>
#include <ifaddrs.h>

// Function to get the network interface details
void get_network_interfaces(char** interface_list, int* num_interfaces) {
    struct ifaddrs *ifaddr, *ifa;
    char *if_name;
    char *if_buf;
    int interface_count = 0;

    *num_interfaces = 0;
    if (getifaddrs(&ifaddr) == -1) {
        perror("Error in getting network interfaces");
        exit(1);
    }

    if (ifaddr == NULL) {
        printf("No network interfaces found\n");
        return;
    }

    for (ifa = ifaddr; ifa!= NULL; ifa = ifa->ifa_next) {
        if_name = ifa->ifa_name;
        if (strncmp(if_name, "lo", 2) == 0) {
            continue;
        }
        interface_count++;
        *num_interfaces = interface_count;
        interface_list[interface_count - 1] = strdup(if_name);
    }

    freeifaddrs(ifaddr);
}

// Function to check the Wi-Fi signal strength
int get_signal_strength(char* interface_name) {
    char *cmd = "iwconfig ";
    cmd = strcat(cmd, interface_name);
    cmd = strcat(cmd, " | grep 'Signal level' | awk -F '[ =]' '{print $4}'" );
    FILE* fp = popen(cmd, "r");
    if (!fp) {
        perror("Error in executing iwconfig command");
        return -1;
    }
    int signal_level = 0;
    if (fscanf(fp, "%d", &signal_level)!= 1) {
        perror("Error in reading signal level");
        return -1;
    }
    pclose(fp);
    return signal_level;
}

// Function to print Wi-Fi signal strength details
void print_signal_strength_details(char* interface_name, int signal_level) {
    printf("Interface: %s\n", interface_name);
    printf("Signal Level: %d\n", signal_level);
}

int main() {
    char* interface_list[100];
    int num_interfaces;

    get_network_interfaces(interface_list, &num_interfaces);

    for (int i = 0; i < num_interfaces; i++) {
        int signal_level = get_signal_strength(interface_list[i]);
        if (signal_level == -1) {
            printf("Failed to get signal level for %s\n", interface_list[i]);
            continue;
        }
        print_signal_strength_details(interface_list[i], signal_level);
    }

    return 0;
}