//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cryptic
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT_MS 500
#define MAXBYTES2CAPTURE 2048

struct ether_header {
    u_int8_t ether_dhost[6];
    u_int8_t ether_shost[6];
    u_int16_t ether_type;
};

struct ip_header {
    unsigned char iph_ihl : 4, iph_ver : 4;
    unsigned char iph_tos;
    unsigned short int iph_len;
    unsigned short int iph_ident;
    unsigned short int iph_flag : 3, iph_offset : 13;
    unsigned char iph_ttl;
    unsigned char iph_protocol;
    unsigned short int iph_chksum;
    struct in_addr iph_sourceip;
    struct in_addr iph_destip;
};

void ProcessPacket(u_char *, const struct pcap_pkthdr *, const u_char *);
void print_payload(const u_char *, int);

int main() {

    int i, count = 0;
    char errbuf[PCAP_ERRBUF_SIZE], *device;
    pcap_t *handle;
    pcap_if_t *all_devices;

    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 subnet_mask, ip;

    memset(errbuf, 0, PCAP_ERRBUF_SIZE);

    if (pcap_findalldevs(&all_devices, errbuf) == -1) {
        printf("Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    printf("Available devices:\n");

    for (i = 0; all_devices != NULL; all_devices = all_devices->next) {
        printf("%d: %s\n", ++i, all_devices->name);
    }

    printf("\nEnter the number of the device you wish to use: ");
    scanf("%d", &i);

    if (!(device = pcap_lookupdev(errbuf))) {
        printf("Error finding device: %s\n", errbuf);
        return 1;
    }

    if (pcap_lookupnet(device, &ip, &subnet_mask, errbuf) == -1) {
        printf("Error finding netmask for device: %s\n", errbuf);
        ip = 0;
        subnet_mask = 0;
    }

    printf("Using device: %s\n", device);

    handle = pcap_create(device, errbuf);

    if (handle == NULL) {
        printf("Error creating handle: %s\n", errbuf);
        return 1;
    }

    if (pcap_set_snaplen(handle, MAXBYTES2CAPTURE) != 0) {
        printf("Error setting snaplen: %s\n", errbuf);
        pcap_close(handle);
        return 1;
    }

    if (pcap_set_promisc(handle, 1) != 0) {
        printf("Error setting promisc mode: %s\n", errbuf);
        pcap_close(handle);
        return 1;
    }

    if (pcap_set_timeout(handle, TIMEOUT_MS) != 0) {
        printf("Error setting timeout: %s\n", errbuf);
        pcap_close(handle);
        return 1;
    }

    if (pcap_activate(handle) != 0) {
        printf("Error activating handle: %s\n", errbuf);
        pcap_close(handle);
        return 1;
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return 1;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return 1;
    }

    printf("Capture session starting on device: %s\n", device);

    pcap_loop(handle, -1, ProcessPacket, (u_char *) &count);

    pcap_close(handle);

    return 0;
}

void ProcessPacket(u_char *args, const struct pcap_pkthdr *header, const u_char *buffer) {

    int size = header->len;
    struct ether_header *eth_header;
    struct ip_header *ip_header;
    int ip_header_size;

    eth_header = (struct ether_header *) buffer;

    ip_header = (struct ip_header *) (buffer + sizeof(struct ether_header));
    ip_header_size = ip_header->iph_ihl * 4;

    printf("Packet %d:\n", ++(*((int *) args)));
    printf("\tEthernet Header:\n");
    printf("\t\tDestination MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_header->ether_dhost[0],
           eth_header->ether_dhost[1],
           eth_header->ether_dhost[2],
           eth_header->ether_dhost[3],
           eth_header->ether_dhost[4],
           eth_header->ether_dhost[5]);
    printf("\t\tSource MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           eth_header->ether_shost[0],
           eth_header->ether_shost[1],
           eth_header->ether_shost[2],
           eth_header->ether_shost[3],
           eth_header->ether_shost[4],
           eth_header->ether_shost[5]);
    printf("\t\tType: %hu\n", eth_header->ether_type);

    printf("\tIP Header:\n");
    printf("\t\tIP Version: %d\n", ip_header->iph_ver);
    printf("\t\tIP Header Length: %d bytes\n", ip_header_size);
    printf("\t\tType of Service: %d\n", ip_header->iph_tos);
    printf("\t\tTotal Length: %d bytes\n", ntohs(ip_header->iph_len));
    printf("\t\tIdentification: %d\n", ntohs(ip_header->iph_ident));
    printf("\t\tFlags: %d\n", ip_header->iph_flag);
    printf("\t\tFragmentation Offset: %d\n", ip_header->iph_offset);
    printf("\t\tTime To Live: %d\n", ip_header->iph_ttl);
    printf("\t\tProtocol: %d\n", ip_header->iph_protocol);

    printf("\t\tSource IP Address: %s\n", inet_ntoa(ip_header->iph_sourceip));
    printf("\t\tDestination IP Address: %s\n", inet_ntoa(ip_header->iph_destip));

    print_payload(buffer + sizeof(struct ether_header) + ip_header_size, (size - sizeof(struct ether_header) - ip_header_size));
}

void print_payload(const u_char *payload, int len) {

    int i;
    printf("\tPayload:\n");
    for (i = 0; i < len; i++) {
        if (isprint(*payload)) {
            printf("%c", *payload);
        } else {
            printf(".");
        }
        payload++;
    }
    printf("\n");
}