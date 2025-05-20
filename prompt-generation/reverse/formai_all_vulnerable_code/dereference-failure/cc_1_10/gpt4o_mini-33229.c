//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SNAP_LEN 65535
#define THEM_ALL 6 // Number of gods lost in the chaos

// Structure for recording packets. An echo from the lost souls.
struct packet_record {
    struct pcap_pkthdr header;
    const u_char *data;
};

// Function to print the time as humans once did
void print_current_time() {
    time_t now = time(NULL);
    struct tm *tm_now = gmtime(&now);
    printf("[TIME] %04d-%02d-%02dT%02d:%02d:%02dZ: ", 
           tm_now->tm_year + 1900, tm_now->tm_mon + 1, 
           tm_now->tm_mday, tm_now->tm_hour, 
           tm_now->tm_min, tm_now->tm_sec);
}

// Callback function to be invoked upon receiving packets, a ritual of remembrance
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("[PACKET CAPTURED] Length: %d bytes\n", header->len);
    
    // Might print more detailed structure later if the spirits allow
    print_current_time();
    printf("Packet content (hex): ");
    for (int i = 0; i < header->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n\n");
}

// The survivor's main function, catching the fragments of the old world
int main(int argc, char *argv[]) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device_index = 0;

    // Insufficient soul power, we need to find the devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "[ERROR] Unable to find devices: %s\n", errbuf);
        return 1;
    }

    // Display possible interface(s) to the inhabitants, just echoes in the void
    printf("[INFO] The remainders of the realms:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" [%d] %s\n", ++device_index, device->name);
    }

    // No devices left to capture
    if (device_index == 0) {
        printf("[ERROR] No devices found! Fated to capture nothing.\n");
        return 2;
    }

    // Selecting the interface chosen by the fates
    printf("[CHOICE] Enter the number of the device to capture: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > device_index) {
        printf("[ERROR] Invalid choice! The spirits are restless...\n");
        return 3;
    }

    // Rewinding to the selected device
    for (device = alldevs, device_index = 0; device_index < choice - 1; device = device->next, device_index++);

    // Open the device for capturing packets
    handle = pcap_open_live(device->name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "[ERROR] Couldn't open device %s: %s\n", device->name, errbuf);
        return 4;
    }

    // Start the capturing process
    printf("[LISTENING] The winds of the ether are restless on %s...\n", device->name);

    // The final loop, until we run out of energy
    pcap_loop(handle, 0, packet_handler, NULL);

    // Clean up and free the memory that remains
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}