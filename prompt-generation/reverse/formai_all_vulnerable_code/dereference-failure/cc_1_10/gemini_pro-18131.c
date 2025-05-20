//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

// Our hero, the Intrusion Detection System (IDS)
char *IDS_name = "SuperIDS";

// The realm we're protecting, our network
char *network_name = "CyberFortress";

// Let's watch for these naughty patterns
char *attack_patterns[] = {
    "SYN Flood",
    "Port Scan",
    "Buffer Overflow",
    "SQL Injection",
    "XSS"
};

// Ready our weapons, the alerts
char *alerts[] = {
    "INTRUSION ALERT! SYN Flood detected on port 80!",
    "INTRUSION ALERT! Port Scan detected on port range 1000-2000!",
    "INTRUSION ALERT! Buffer Overflow detected on service ftp!",
    "INTRUSION ALERT! SQL Injection detected on database server!",
    "INTRUSION ALERT! XSS detected on website homepage!"
};

// The magic that helps us sniff out the bad guys
pcap_t *pcap_handle;

// Let's get this party started!
int main() {
    // Initialize our mighty IDS
    printf("Behold, the almighty %s, sworn protector of %s!\n", IDS_name, network_name);
    printf("Brace yourselves, evildoers, for I am always vigilant!\n");

    // Open the gates to our network's traffic
    pcap_handle = pcap_open_live("en0", 65535, 1, 1000, NULL);
    if (pcap_handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", pcap_geterr(pcap_handle));
        return EXIT_FAILURE;
    }

    // Loop forever, tirelessly guarding our realm
    while (1) {
        // Grab a single network packet, our potential foe
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(pcap_handle, &header, &packet);
        if (res == PCAP_ERROR) {
            fprintf(stderr, "pcap_next_ex() failed: %s\n", pcap_geterr(pcap_handle));
            continue;
        }

        // Time to analyze the captured packet
        printf("Packet captured at %s, length %d bytes\n", ctime(&header->ts.tv_sec), header->len);

        // Check if it matches any of our known attack patterns
        for (int i = 0; i < sizeof(attack_patterns) / sizeof(char *); i++) {
            if (strstr((char *)packet, attack_patterns[i])) {
                // Oh no, an intruder! Time to raise the alarm!
                printf("%s\n", alerts[i]);
                break;
            }
        }
    }

    // We never sleep, for the safety of our network depends on it!
    return 0;
}