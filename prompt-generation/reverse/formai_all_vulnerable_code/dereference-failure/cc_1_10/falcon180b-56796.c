//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PCAP_ERRBUF_SIZE 256

// Function to print error message
void print_err(const char *errmsg) {
    fprintf(stderr, "Error: %s\n", errmsg);
    exit(1);
}

// Function to process each packet
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received!\n");
}

// Main function
int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_expr[100];
    int net = 0;
    int mask = 0;
    struct bpf_program fp;
    char *dev = "eth0";

    // Open the network device
    handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
    if (handle == NULL) {
        print_err(errbuf);
    }

    // Set the filter expression
    sprintf(filter_expr, "tcp or udp");
    if (pcap_compile(handle, &fp, filter_expr, 1, net)!= 0) {
        print_err("Error compiling filter expression");
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp)!= 0) {
        print_err("Error setting filter");
    }

    // Loop to capture packets
    while (TRUE) {
        int ret = pcap_loop(handle, 0, process_packet, NULL);
        if (ret == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                print_err("Error during packet capture");
            }
        } else if (ret == -2) {
            print_err("Packet capture stopped due to buffer overflow");
        }
    }

    return 0;
}