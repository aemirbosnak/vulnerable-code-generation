//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h> // Hey there! Look at me, including the pcap header like a boss!

char errbuf[PCAP_ERRBUF_SIZE];  // We'll keep our error messages nice and tidy!

int main() {
    char *device = "eth0"; // Buckle up, 'cause we're spying on eth0 (or any other network interface you fancy)!

    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);  // Let's open the door to the network!

    if (handle == NULL) {  // Oops, something went wrong. Let's throw a tantrum!
        fprintf(stderr, "Bah! Couldn't open %s: %s\n", device, errbuf);
        return EXIT_FAILURE;
    }

    printf("Ta-da! We've got our ears on %s!\n", device);  // Time to celebrate our network-monitoring triumph!

    while (1) {  // Let's keep this party going forever (or until the user gets bored)!
        struct pcap_pkthdr *header;  // We'll use this fancy struct to keep track of our packets!
        const u_char *packet;  // And this one to store the actual data!

        int res = pcap_next_ex(handle, &header, &packet);  // Let's grab the next packet!

        switch (res) {
            case 1:  // Bingo! We caught a packet!
                printf("Yahoo! We've got a packet with a length of %d bytes!\n", header->len);
                break;

            case 0:  // Uh-oh, no packets in sight!
                printf("Aww, no packets for now. Let's take a breather and try again!\n");
                break;

            case -1:  // Oh no, something went wrong! We need to bail!
                fprintf(stderr, "Houston, we have a problem: %s\n", pcap_geterr(handle));
                pcap_close(handle);  // Let's close up shop and get out of here!
                return EXIT_FAILURE;

            case -2:  // The user got bored and told us to stop!
                printf("Alright, I'll stop being a network detective. Hasta la vista!\n");
                pcap_close(handle);  // We're done, so let's pack up and go home!
                return EXIT_SUCCESS;
        }
    }

    // We didn't get here, but just in case, let's close the handle!
    pcap_close(handle);

    return EXIT_SUCCESS;
}