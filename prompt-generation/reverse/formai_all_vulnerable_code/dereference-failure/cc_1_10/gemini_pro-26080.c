//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: paranoid
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

#define PARANOID

int main(int argc, char *argv[]) {
    char *device = NULL;
    char *filter_exp = NULL;
    bpf_u_int32 net = 0, mask = 0;
    struct bpf_program fp;
    pcap_t *handle = NULL;
    struct pcap_pkthdr *header = NULL;
    const u_char *data = NULL;
    int ret;

    printf("Paranoid packet capturer\n");

    if (argc == 3) {
        device = argv[1];
        filter_exp = argv[2];
    } else {
        fprintf(stderr, "Usage: %s <device> <filter expression>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ret = pcap_lookupnet(device, &net, &mask, NULL);
    if (ret == -1) {
        fprintf(stderr, "pcap_lookupnet(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    ret = pcap_compile(handle, &fp, filter_exp, 0, net);
    if (ret == -1) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    ret = pcap_setfilter(handle, &fp);
    if (ret == -1) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    while (1) {
        ret = pcap_next_ex(handle, &header, &data);
        if (ret == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        } else if (ret == 0) {
            continue;
        }

        printf("Packet captured: ");
        for (int i = 0; i < header->caplen; i++) {
            printf("%02X ", data[i]);
        }
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}