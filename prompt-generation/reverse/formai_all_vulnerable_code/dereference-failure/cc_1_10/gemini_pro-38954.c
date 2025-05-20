//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

// Function to get the local IP address
char *get_local_ip() {
    char *ip;
    struct sockaddr_in sa;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return NULL;
    }
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
        perror("connect");
        close(sockfd);
        return NULL;
    }
    ip = inet_ntoa(sa.sin_addr);
    close(sockfd);
    return ip;
}

// Function to scan for wireless networks
void scan_wireless_networks() {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_lookupdev: %s\n", errbuf);
        return;
    }
    pcap_t *handle = pcap_open_live(dev, 1500, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        return;
    }
    struct bpf_program fp;
    char filter_exp[] = "type mgt subtype probe-req";
    if (pcap_compile(handle, &fp, filter_exp, 0, 0) < 0) {
        fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return;
    }
    if (pcap_setfilter(handle, &fp) < 0) {
        fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return;
    }
    struct pcap_pkthdr *header;
    const unsigned char *data;
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) continue;
        if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        }
        printf("SSID: %s\n", data + 36);
        printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\n", data[4], data[5], data[6], data[7], data[8], data[9]);
        printf("Channel: %d\n", data[74]);
    }
    pcap_close(handle);
}

int main() {
    char *local_ip = get_local_ip();
    if (local_ip == NULL) {
        fprintf(stderr, "Could not get local IP address\n");
        return EXIT_FAILURE;
    }
    printf("Local IP: %s\n", local_ip);
    scan_wireless_networks();
    free(local_ip);
    return EXIT_SUCCESS;
}