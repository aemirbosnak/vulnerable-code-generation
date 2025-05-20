//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: configurable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PACKET_LEN 65535

struct filter_args {
    char *filter_expr;
    bool verbose;
};

void usage(char *progname) {
    fprintf(stderr, "Usage: %s [options] <interface>\n", progname);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -f <filter>      Packet filter expression\n");
    fprintf(stderr, "  -v               Verbose output\n");
    fprintf(stderr, "  -h               Help\n");
    exit(EXIT_FAILURE);
}

struct filter_args parse_args(int argc, char **argv) {
    struct filter_args args = {NULL, false};

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-f")) {
            if (i + 1 < argc) {
                args.filter_expr = argv[++i];
            } else {
                usage(argv[0]);
            }
        } else if (!strcmp(argv[i], "-v")) {
            args.verbose = true;
        } else if (!strcmp(argv[i], "-h")) {
            usage(argv[0]);
        } else {
            usage(argv[0]);
        }
    }

    return args;
}

void print_packet(const u_char *packet, unsigned int len, struct filter_args args) {
    if (args.verbose) {
        printf("Packet length: %u\n", len);
        for (unsigned int i = 0; i < len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    } else {
        printf("Packet captured: %u bytes\n", len);
    }
}

int main(int argc, char **argv) {
    struct filter_args args = parse_args(argc, argv);

    if (argc < 2) {
        usage(argv[0]);
    }

    char *dev = argv[argc - 1];

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(dev, MAX_PACKET_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    if (args.filter_expr != NULL) {
        struct bpf_program filter;
        if (pcap_compile(handle, &filter, args.filter_expr, 1, 0) == -1) {
            fprintf(stderr, "pcap_compile: %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }
        if (pcap_setfilter(handle, &filter) == -1) {
            fprintf(stderr, "pcap_setfilter: %s\n", pcap_geterr(handle));
            exit(EXIT_FAILURE);
        }
    }

    struct pcap_pkthdr *header;
    const u_char *packet;
    int status;

    while ((status = pcap_next_ex(handle, &header, &packet)) != -1) {
        if (status == 0) {
            fprintf(stderr, "pcap_next_ex: timeout\n");
            continue;
        }
        print_packet(packet, header->caplen, args);
    }

    if (status == -1) {
        fprintf(stderr, "pcap_next_ex: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}