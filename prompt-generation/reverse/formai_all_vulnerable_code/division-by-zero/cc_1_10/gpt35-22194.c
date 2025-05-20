//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: mathematical
/*
 * Program: MathPacketCapture.c
 * Purpose: A mathematical style packet capture program using the pcap library
 * Author: [Your Name]
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PACKETS 100

int main(int argc, char *argv[])
{
    pcap_t *handle;         /* Session handle */
    char *dev;              /* The device to capture on */
    char errbuf[PCAP_ERRBUF_SIZE];  /* Error string */
    struct bpf_program fp;      /* The compiled filter */
    char filter_exp[] = "port 80";  /* The filter expression */
    bpf_u_int32 mask;       /* Our netmask */
    bpf_u_int32 net;        /* Our IP */
    struct pcap_pkthdr header;  /* The header that pcap gives us */
    const u_char *packet;       /* The actual packet */
    int packetCount = 0;
    int packetSize[MAX_PACKETS];
    int i;
    
    printf("MathPacketCapture v1.0\n");
    printf("----------------------\n");

    /* Define the device */
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
  
    /* Find the properties for the device */
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    /* Open the session in promiscuous mode */
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }

    /* Compile and apply the filter */
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }

    /* Capture packets */
    while (packetCount < MAX_PACKETS && (packet = pcap_next(handle, &header))) {
    
        packetSize[packetCount] = header.len;
        
        /* Increment packet count */
        packetCount++;
    }

    /* Print results */
    
    printf("Packet Count: %d\n", packetCount);

    /* Calculate and print mean */
    int sum = 0;
    for (i = 0; i < packetCount; i++) {
        sum += packetSize[i];
    }
    double mean = sum / packetCount;
    printf("Mean Packet Size: %f\n", mean);

    /* Calculate and print standard deviation */
    double variance = 0;
    for (i = 0; i < packetCount; i++) {
        variance += pow((packetSize[i] - mean), 2);
    }
    double stdDev = sqrt(variance / packetCount);
    printf("Standard Deviation: %f\n", stdDev);

    /* Close the session */
    pcap_close(handle);
    printf("MathPacketCapture has successfully captured and analyzed packets.\n");

    return 0;
}