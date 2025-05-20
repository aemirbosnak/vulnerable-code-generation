//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: surprised
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Woohoo, I got a packet!\n");
    int i = 0;
    for(i=0; i<pkthdr->len; i++)
    {
        printf("%.2x ", packet[i]);
        if( (i+1) % 16 == 0 )
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    printf("Initializing packet capturer...\n");
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        printf("Uh oh, failed to open pcap handle...\n");
        return 1;
    }
    printf("Packet capturer initialized successfully!\n");

    printf("Setting up packet filter...\n");
    struct bpf_program filter;
    char* filterString = "tcp";
    if( pcap_compile(handle, &filter, filterString, 0, PCAP_NETMASK_UNKNOWN) == -1 )
    {
        printf("Uh oh, failed to compile filter string...\n");
        pcap_close(handle);
        return 1;
    }
    if( pcap_setfilter(handle, &filter) == -1 )
    {
        printf("Uh oh, failed to set filter string...\n");
        pcap_close(handle);
        return 1;
    }
    printf("Packet filter set up successfully!\n");

    printf("Begin packet capture...\n");
    struct pcap_pkthdr header;
    const u_char* packet;
    int ret;
    while( (ret = pcap_next_ex(handle, &header, &packet)) >= 0 )
    {
        if(ret == 0)
        {
            continue;
        }
        packetHandler(NULL, &header, packet);
    }
    printf("End packet capture...\n");

    pcap_close(handle);

    return 0;
}