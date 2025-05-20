//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: ultraprecise
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE_ETHERNET 14
#define MAXPACKETSIZE 65536

struct sniff_ip {
    u_char  ip_vhl;       //Version << 4 | Header Length >> 2
    u_char  ip_tos;       //Type of Service
    u_short ip_len;       //Total Length
    u_short ip_id;        //Identifier
    u_short ip_off;       //Fragment Offset Field
    u_char  ip_ttl;       //Time to Live
    u_char  ip_p;         //Protocol
    u_short ip_sum;       //Checksum
    struct  in_addr ip_src, ip_dst; //Source and Destionation address
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct sniff_ip *ip;

    ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
    
    // Displaying the captured packet info
    printf("Packet Length: %d\n", header->len);
    printf("IP Source: %s\n", inet_ntoa(ip->ip_src));
    printf("IP Destination: %s\n", inet_ntoa(ip->ip_dst));
    printf("------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    int status;
    
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev_name;
    
    // Check for user input to specify device
    if (argc > 1) {
        dev_name = argv[1];
    } else {
        // Retrieve the device list
        if(pcap_findalldevs(&alldevs, errbuf) == -1) {
            fprintf(stderr, "Couldn't find devices: %s\n", errbuf);
            return 1;
        }
        
        printf("Available devices:\n");
        for(device = alldevs; device != NULL; device = device->next) {
            printf(" - %s\n", device->name);
        }
        printf("Select a device to capture packets from: ");
        char selected_device[100];
        fgets(selected_device, sizeof(selected_device), stdin);
        selected_device[strcspn(selected_device, "\n")] = 0; // Removing newline character
        
        dev_name = selected_device;
        pcap_freealldevs(alldevs); // Free the device list
    }

    // Open the selected device
    pcap_t *handle = pcap_open_live(dev_name, MAXPACKETSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev_name, errbuf);
        return 2;
    }

    // Set a filter for capturing only IP packets
    struct bpf_program fp;
    char filter_exp[] = "ip";
    
    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }

    // Start the packet capture loop
    printf("Starting packet capture on device %s...\n", dev_name);
    pcap_loop(handle, 0, packet_handler, NULL);

    // Close the session
    pcap_freecode(&fp);
    pcap_close(handle);
    
    return 0;
}