//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>


// Introspecting struct pcap_pkthdr

static const char *foo(int seconds) {
    static char *names[] = {"one", "two", "three"};
    return names[seconds];
}

int main(int argc, char **argv) {

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <interface> <filter>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *device = argv[1];
    char *filter = argv[2];

    // Create a new capture handle
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", device, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Compile the filter expression
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Set the filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Introspection on a pcap_pkthdr struct
    // The loop below will print the first 10 elements within a pcap_pkthdr struct and their values
    printf("pcap_pkthdr Fields:\n");
    printf("%-16s %-15s %-5s\n", "Field Name", "Field Type", "Field Value");
    printf("------------------------------------\n");
    #define NUM_PKTHDR_FIELDS 10

    // Cast the pointer of the struct to a char pointer so it can be indexed by known offsets
    char *ptr = (char *)&fp.bf_insns;
    for (int i = 0; i < NUM_PKTHDR_FIELDS; i++) {
        printf("%-16s %-15s ", foo(i), "int");
        printf("%d\n", *(int *)(ptr + (4*i)));
    }

    // Free the capture handle
    pcap_close(handle);

    return EXIT_SUCCESS;
}