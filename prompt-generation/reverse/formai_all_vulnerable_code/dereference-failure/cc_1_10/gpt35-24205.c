//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_DEVICES 1000
#define MAX_PORT 65535
#define TIMEOUT 2

struct device {
    int id;
    char* ip_address;
    char* mac_address;
    char* vendor;
    char* hostname;
    int num_open_ports;
    int open_ports[MAX_PORT];
};

int num_devices = 0;
struct device devices[MAX_DEVICES];

int get_next_device_id() {
    return num_devices++;
}

// scapy like print function for ip address
void print_ip(uint32_t address) {
    struct in_addr addr = { address };
    char* ip = inet_ntoa(addr);
    printf("%s", ip);
}

// scapy like print function for mac address
void print_mac(const uint8_t* mac_address) {
    printf("%02x:%02x:%02x:%02x:%02x:%02x", mac_address[0], mac_address[1], mac_address[2], mac_address[3], mac_address[4], mac_address[5]);
}

// check if device with the given ip exists
struct device* get_device_by_ip(char* ip) {
    for (int i = 0; i < num_devices; ++i) {
        struct device* d = &devices[i];
        if (strcmp(d->ip_address, ip) == 0) {
            return d;
        }
    }
    return NULL;
}

// print information about an open port
void print_open_port(int port) {
    printf("  |__ Port %d: OPEN\n", port);
}

// scan for open ports
void scan_open_ports(int device_id) {
    struct device* device = &devices[device_id];
    printf("\n[+] Scanning open ports on %s (%s):\n", device->ip_address, device->hostname);

    // create a raw socket for SYN scan
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("\n[-] Error creating raw socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(struct sockaddr_in));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(device->ip_address);

    struct tcphdr tcp_header;
    memset(&tcp_header, 0, sizeof(struct tcphdr));
    tcp_header.th_sport = htons(1234);
    tcp_header.th_flags = TH_SYN;

    for (int port = 1; port <= MAX_PORT; ++port) {
        // set the destination port
        tcp_header.th_dport = htons(port);

        // send a SYN packet
        if (sendto(sockfd, &tcp_header, sizeof(struct tcphdr), MSG_NOSIGNAL, (struct sockaddr*)&target, sizeof(target)) < 0) {
            printf("\n[-] Error sending SYN packet to %s:%d\n", device->ip_address, port);
            continue;
        }

        // receive packet
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        int n = select(sockfd + 1, &fds, NULL, NULL, &timeout);
        if (n <= 0) {
            // timeout or error
            continue;
        }
        char buffer[65535];
        ssize_t len = recv(sockfd, buffer, sizeof(buffer), MSG_DONTWAIT);
        if (len <= 0) {
            continue;
        }

        // analyze the packet
        struct ip* ip_header = (struct ip*)buffer;
        if (ip_header->ip_p != IPPROTO_TCP) {
            continue;
        }
        struct tcphdr* tcp_header = (struct tcphdr*)(buffer + ip_header->ip_hl * 4);
        if (!(tcp_header->th_flags & (TH_SYN | TH_ACK))) {
            continue;
        }

        // port is open
        device->num_open_ports++;
        device->open_ports[device->num_open_ports - 1] = port;
        print_open_port(port);
    }

    close(sockfd);
}

// print device information
void print_device(int device_id) {
    struct device* device = &devices[device_id];
    printf("%d. %s\n", device_id + 1, device->hostname);
    printf("  |- IP Address:\t%s\n", device->ip_address);
    printf("  |- MAC Address:\t");
    print_mac(ether_aton(device->mac_address));
    printf("\n");
    printf("  |- Vendor:\t\t%s\n", device->vendor);
    if (device->num_open_ports > 0) {
        printf("  |- Open Ports:\n");
        for (int i = 0; i < device->num_open_ports; ++i) {
            printf("  |__ Port %d: OPEN\n", device->open_ports[i]);
        }
    }
    printf("\n");
}

// print all device information
void print_all_devices() {
    printf("Network Topology:\n\n");
    for (int i = 0; i < num_devices; ++i) {
        print_device(i);
    }
}

int main() {
    printf("+-----------------------------------------+\n");
    printf("| C Network Topology Mapper Example Program |\n");
    printf("+-----------------------------------------+\n\n");

    // read input file
    printf("[+] Reading input file...\n");
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("[-] Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // parse ip address
        char* ip_address = strtok(line, " ");

        // check if device already exists
        struct device* device = get_device_by_ip(ip_address);
        int device_id = get_next_device_id();
        if (device != NULL) {
            device_id = device->id;
        }

        // update device info
        devices[device_id].id = device_id;
        devices[device_id].ip_address = ip_address;
        devices[device_id].mac_address = strtok(NULL, " ");
        devices[device_id].vendor = strtok(NULL, " ");
        devices[device_id].hostname = strtok(NULL, "\n");

        // scan for open ports
        scan_open_ports(device_id);
    }

    fclose(file);

    // print all devices
    print_all_devices();

    return 0;
}