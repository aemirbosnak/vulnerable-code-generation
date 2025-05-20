//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 1518

//Structure to store the scanned network information
typedef struct {
    char essid[33];
    char bssid[18];
    char channel;
    long long int signal_level;
    int frequency;
    int security;
} network_info;

//Function prototypes
int get_interfaces();
pcap_t * open_interface(char *interface);
void print_network_info(network_info *network);
char *get_essid(unsigned char *frame);
char *get_bssid(unsigned char *frame);
int get_channel(unsigned char *frame);
long long int get_signal_level(unsigned char *frame);
int get_frequency(unsigned char *frame);
int get_security(unsigned char *frame);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <interface>\n\nExample:\n%s wlan0", argv[0], argv[0]);
        return -1;
    }

    char *interface = argv[1];

    //Get the interfaces available on the system
    if (get_interfaces() == -1) {
        printf("Error: could not get the interfaces available on the system.\n");
        return -1;
    }

    //Open the interface
    pcap_t *handle = open_interface(interface);
    if (handle == NULL) {
        printf("Error: could not open the interface %s.\n", interface);
        return -1;
    }

    //Start capturing packets
    int ret = pcap_loop(handle, -1, NULL, NULL);
    if (ret == -1) {
        printf("Error: could not start capturing packets.\n");
        pcap_close(handle);
        return -1;
    }

    //Close the interface
    pcap_close(handle);

    return 0;
}

int get_interfaces() {
    //Get a list of all the interfaces available on the system
    char *error = NULL;
    pcap_if_t *alldevs;
    if (pcap_findalldevs(&alldevs, &error) == -1) {
        printf("Error: %s\n", error);
        pcap_freealldevs(alldevs);
        return -1;
    }

    //Print the list of interfaces
    printf("Available interfaces:\n");
    for (pcap_if_t *d = alldevs; d->next != NULL; d = d->next) {
        printf("%s\n", d->name);
    }

    //Free the memory allocated for the list of interfaces
    pcap_freealldevs(alldevs);

    return 0;
}

pcap_t * open_interface(char *interface) {
    //Open the interface
    char *error = NULL;
    pcap_t *handle = pcap_open_live(interface, MAX_PACKET_SIZE, 1, 1000, &error);
    if (handle == NULL) {
        printf("Error: %s\n", error);
        return NULL;
    }

    //Set the interface in promiscuous mode
    if (pcap_set_promisc(handle, 1) == -1) {
        printf("Error: could not set the interface in promiscuous mode.\n");
        pcap_close(handle);
        return NULL;
    }

    //Set the interface in monitor mode
    if (pcap_set_rfmon(handle, 1) == -1) {
        printf("Error: could not set the interface in monitor mode.\n");
        pcap_close(handle);
        return NULL;
    }

    return handle;
}

void print_network_info(network_info *network) {
    printf("ESSID: %s\n", network->essid);
    printf("BSSID: %s\n", network->bssid);
    printf("Channel: %d\n", network->channel);
    printf("Signal level: %lld dBm\n", network->signal_level);
    printf("Frequency: %d MHz\n", network->frequency);
    printf("Security: %d\n", network->security);
}

char *get_essid(unsigned char *frame) {
    //Get the length of the ESSID
    int length = frame[2] + frame[3]*256;

    //Get the ESSID
    char *essid = malloc(length + 1);
    memcpy(essid, frame + 4, length);
    essid[length] = '\0';

    return essid;
}

char *get_bssid(unsigned char *frame) {
    //Get the BSSID
    char *bssid = malloc(18);
    snprintf(bssid, 18, "%02x:%02x:%02x:%02x:%02x:%02x", frame[4], frame[5], frame[6], frame[7], frame[8], frame[9]);

    return bssid;
}

int get_channel(unsigned char *frame) {
    //Get the channel
    return frame[14];
}

long long int get_signal_level(unsigned char *frame) {
    //Get the signal level
    long long int signal_level = (long long int)frame[23] - 256;
    return signal_level;
}

int get_frequency(unsigned char *frame) {
    //Get the frequency
    int frequency = frame[18] + frame[19]*256;
    return frequency;
}

int get_security(unsigned char *frame) {
    //Get the security
    int security = 0;

    //Check if the frame is encrypted
    if (frame[18] & 0x01) {
        security = 1;
    }

    //Check if the frame is using WEP
    if (frame[18] & 0x02) {
        security = 2;
    }

    //Check if the frame is using WPA
    if (frame[18] & 0x04) {
        security = 3;
    }

    //Check if the frame is using WPA2
    if (frame[18] & 0x08) {
        security = 4;
    }

    return security;
}