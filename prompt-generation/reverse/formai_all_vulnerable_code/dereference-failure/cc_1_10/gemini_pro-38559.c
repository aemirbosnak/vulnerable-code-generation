//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <time.h>

#define MAX_INTERFACES 10
#define MAX_BUFF_SIZE 65535

struct pcap_pkthdr *header;
const u_char *data;

// Function to print the error message and exit the program.
void die(const char *err) {
    perror(err);
    exit(EXIT_FAILURE);
}

// Function to get the list of network interfaces.
char **get_interfaces() {
    char **interfaces = malloc(sizeof(char *) * MAX_INTERFACES);
    int num_interfaces = 0;
    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) die("socket");

    for (int i = 0; i < MAX_INTERFACES; i++) {
        sprintf(ifr.ifr_name, "eth%d", i);
        if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) == 0) {
            interfaces[num_interfaces++] = strdup(ifr.ifr_name);
        }
    }
    close(sockfd);
    return interfaces;
}

// Function to open a pcap handle for a given network interface.
pcap_t *open_pcap(char *interface) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(interface, 96, 0, 100, errbuf);
    if (handle == NULL) die(errbuf);
    return handle;
}

// Function to capture packets from a network interface.
void capture(pcap_t *handle) {
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) continue; // Timeout
        if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK) die(pcap_geterr(handle));
        struct in_addr src_ip, dst_ip;
        memcpy(&src_ip.s_addr, &data[12], 4);
        memcpy(&dst_ip.s_addr, &data[16], 4);
        printf("%s:%d -> %s:%d\n", inet_ntoa(src_ip), ntohs(data[20]), inet_ntoa(dst_ip), ntohs(data[22]));
    }
}

int main() {
    char **interfaces = get_interfaces();
    for (int i = 0; i < MAX_INTERFACES && interfaces[i] != NULL; i++) {
        pcap_t *handle = open_pcap(interfaces[i]);
        capture(handle);
        pcap_close(handle);
    }
    return 0;
}