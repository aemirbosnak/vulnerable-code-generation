//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: happy
#include <pcap.h> // Include pcap library
#include <stdio.h>

// Define the maximum length of a captured packet
#define MAX_PACKET_LENGTH 1514

// Define a function to handle incoming packets
void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    // Cast the user data back to a FILE pointer
    FILE *stream = (FILE*) userData;

    // Write the packet data to the file
    fwrite(packet, pkthdr->len, 1, stream);
}

int main(int argc, char *argv[]) {
    // Define the filename to save captured packets
    char filename[64];
    sprintf(filename, "capture.pcap");

    // Open the capture file for writing
    FILE *captureFile = fopen(filename, "wb");

    // Check if file was opened successfully
    if (captureFile == NULL) {
        printf("Error: Unable to open capture file for writing.\n");
        return 1;
    }

    // Find the first active network interface
    pcap_if_t *devices;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_findalldevs(&devices, errbuf);

    // Open the first active network interface for capturing
    pcap_t *captureHandle = pcap_open_live(devices->name, MAX_PACKET_LENGTH, 1, 1000, errbuf);

    // Check if capture handle was opened successfully
    if (captureHandle == NULL) {
        printf("Error: Unable to open network interface for capturing.\n");
        return 1;
    }

    // Start capturing packets
    printf("Starting packet capture...\n");
    pcap_loop(captureHandle, 0, packetHandler, (u_char*) captureFile);

    // Close the capture handle and file
    pcap_close(captureHandle);
    fclose(captureFile);

    // Exit program
    printf("Packet capture complete.\n");
    return 0;
}