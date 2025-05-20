//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pcap.h>
#include <pcap/pcap.h>

int main() {
    char *dev = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    bpf_u_int32 netmask;
    bpf_u_int32 ip;
    struct pcap_pkthdr *header;
    const u_char *data;
    struct in_addr addr;
    char ip_str[INET_ADDRSTRLEN];
    int i;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "pcap_lookupdev: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, ip) == -1) {
        fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
            break;
        }

        memcpy(&addr, &data[26], sizeof(addr));
        inet_ntop(AF_INET, &addr, ip_str, sizeof(ip_str));
        printf("%s\n", ip_str);

        if (data[12] == 6) {
            for (i = 34; i < header->caplen; i += 20) {
                memcpy(&addr, &data[i + 12], sizeof(addr));
                inet_ntop(AF_INET, &addr, ip_str, sizeof(ip_str));
                printf("\t%s\n", ip_str);
            }
        }
    }

    pcap_close(handle);
    return 0;
}