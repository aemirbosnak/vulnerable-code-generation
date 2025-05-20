//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packetHandler(unsigned char *userData, const struct pcap_pkthdr* pkthdr, const unsigned char* packet)
{
    // payload data
    int i=0;
    for(i=0;i<pkthdr->len;i++)
    {
        printf("%.2x ", packet[i]);
        if((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

int main(int argc, char* argv[])
{
    char devName[] = "eth0";
    char errBuffer[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    pcap_if_t* alldevs;
    pcap_if_t* temp;
    int i=0;
    
    // Retrieve network devices list
    if(pcap_findalldevs(&alldevs, errBuffer) == -1)
    {
        printf("Error in pcap_findalldevs(): %s\n", errBuffer);
        exit(EXIT_FAILURE);
    }
    
    // Print available devices
    printf("Available Devices:\n");
    for(temp=alldevs;temp;temp=temp->next)
    {
        printf("%d. %s - %s\n", ++i, temp->name, temp->description ? temp->description : "N/A");
    }
    
    // Select the device
    printf("Enter the device number to sniff: ");
    int deviceNumber;
    scanf("%d", &deviceNumber);
    if(deviceNumber<1 || deviceNumber>i)
    {
        printf("Invalid device number selected.\n");
        pcap_freealldevs(alldevs);
        exit(EXIT_FAILURE);
    }
    for(temp=alldevs,i=1;i<deviceNumber;temp=temp->next,i++);
    
    // Open the device for sniffing
    if((handle = pcap_open_live(temp->name, 65536, 1, 0, errBuffer)) == NULL)
    {
        printf("Error opening %s: %s\n", temp->name, errBuffer);
        pcap_freealldevs(alldevs);
        exit(EXIT_FAILURE);
    }
    
    // Free the device list
    pcap_freealldevs(alldevs);

    // Start Packet capture loop
    pcap_loop(handle, -1, packetHandler, NULL);
    
    // Cleanup
    pcap_close(handle);
    return 0;
}