//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: cheerful
#include<stdio.h>
#include<pcap.h>

int main(int argc, char *argv[])
{
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;
    int packetCount = 0;
    
    //open pcap session for the specified interface
    handle = pcap_open_live(argv[1], 65536, 1, 0, errorBuffer);

    //check for errors
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errorBuffer);
        return 1;
    }

    //start listening for incoming packets
    while (1) {
        packet = pcap_next(handle, &header);

        //check if packet is NULL
        if (packet == NULL) {
            continue;
        }

        //print packet information
        printf("Packet #%d\n", ++packetCount);
        printf("Length: %d bytes\n", header.len);

        //print packet contents in hex and ASCII format
        for (int i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
            if ((i + 1) % 16 == 0) {
                printf("  ");
                for (int j = i - 15; j <= i; j++) {
                    if (packet[j] >= 32 && packet[j] <= 126)
                        printf("%c", packet[j]);
                    else
                        printf(".");
                }
                printf("\n");
            }
        }
        printf("\n");
    }

    //close pcap session
    pcap_close(handle);

    return 0;
}