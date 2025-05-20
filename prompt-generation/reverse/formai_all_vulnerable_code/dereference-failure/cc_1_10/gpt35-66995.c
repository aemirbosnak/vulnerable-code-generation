//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multivariable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to hold variable information */
struct packet_vars {
    int num_packets;
    char* filter_expression;
};

/* A callback function to process the captured packets */
void packet_handler(u_char *args, const struct pcap_pkthdr *packet_header, const u_char *packet_data) {
    struct packet_vars* vars = (struct packet_vars*)args;
    vars->num_packets += 1;
    printf("Packet Number: %d\n", vars->num_packets);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    struct packet_vars vars = {0, "tcp"};
    pcap_t *pcap_handle;
    pcap_if_t *all_devices;
    pcap_if_t *device;

    /* Get all available devices */
    if (pcap_findalldevs(&all_devices, errbuf) == -1) {
        printf("Error finding devices: %s\n", errbuf);
        return 1;
    }

    /* Print out available devices */
    for (device = all_devices; device != NULL; device = device->next) {
        printf("Device: %s\n", device->name);
    }

    /* Open device for packet capture */
    if ((pcap_handle = pcap_open_live(all_devices->name, BUFSIZ, 1, 1000, errbuf)) == NULL) {
        printf("Error opening device: %s\n", errbuf);
        pcap_freealldevs(all_devices);
        return 1;
    }

    printf("Starting packet capture on device: %s\n", all_devices->name);

    /* Compile and apply the filter */
    struct bpf_program filter_program;
    if (pcap_compile(pcap_handle, &filter_program, vars.filter_expression, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(pcap_handle));
        pcap_freealldevs(all_devices);
        pcap_close(pcap_handle);
        return 1;
    }
    if (pcap_setfilter(pcap_handle, &filter_program) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(pcap_handle));
        pcap_freecode(&filter_program);
        pcap_freealldevs(all_devices);
        pcap_close(pcap_handle);
        return 1;
    }

    /* Start packet capture loop */
    if (pcap_loop(pcap_handle, -1, packet_handler, (u_char*)&vars) == -1) {
        printf("Error capturing packets: %s\n", pcap_geterr(pcap_handle));
        pcap_freecode(&filter_program);
        pcap_freealldevs(all_devices);
        pcap_close(pcap_handle);
        return 1;
    }

    /* Free resources and close handle */
    pcap_freecode(&filter_program);
    pcap_freealldevs(all_devices);
    pcap_close(pcap_handle);

    return 0;
}