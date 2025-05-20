//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: romantic
#include <pcap.h>
#include <stdio.h>

int main() {
    char *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;

    printf("Welcome to the Romantic Packet Capturer!\n");
    printf("Let's dance with the ethereal melodies of the network.\n");

    device = pcap_lookupdev(errbuf);
    if (device == NULL) {
        printf("Oops! Failed to find a suitable network device.\n");
        return -1;
    }

    printf("Our stage is set: %s\n", device);

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Uh-oh! Failed to open the device.\n");
        return -1;
    }

    printf("Ready to capture the love letters of the network!\n");

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);

        switch (res) {
            case 1:
                printf("\nCaught a packet! Let's decode its secrets...\n");
                printf("Received at: %s\n", ctime((const time_t *) &header->ts.tv_sec));
                printf("Length: %d\n", header->len);

                int i;
                for (i = 0; i < header->len; i++) {
                    if (i % 16 == 0) {
                        printf("\n");
                    }
                    printf("%02x ", packet[i]);
                }
                printf("\n");

                break;
            case 0:
                printf(".");
                fflush(stdout);
                break;
            case -1:
                printf("Oops! An error occurred while capturing.\n");
                break;
            case -2:
                printf("No more packets to capture. Time for a break!\n");
                break;
        }
    }

    pcap_close(handle);
    return 0;
}