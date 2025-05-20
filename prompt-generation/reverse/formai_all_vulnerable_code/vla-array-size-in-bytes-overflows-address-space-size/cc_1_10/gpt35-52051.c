//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PACKETS 100
#define MIN_PACKET_SIZE 32
#define MAX_PACKET_SIZE 1500

// Function to check the validity of the packet size
bool isValidPacketSize(int packetSize) {
    if(packetSize < MIN_PACKET_SIZE || packetSize > MAX_PACKET_SIZE) {
        printf("Invalid Packet Size! Valid packet size range is 32 - 1500 bytes.\n");
        return false;
    }
    return true;
}

// Main function
int main() {
    // Initializing Variables
    int totalPackets, packetSize, i;
    float avgPacketSize;
    
    // Prompting the user to enter the number of packets
    printf("Number of Packets: ");
    scanf("%d", &totalPackets);
    
    // Initializing the array to store the packet sizes
    int packetSizes[totalPackets];
    
    // Loop to prompt the user to enter the packet size for each packet
    for(i=0; i<totalPackets; i++) {
        printf("Packet Size for Packet %d: ", i+1);
        scanf("%d", &packetSize);
        
        // Checking the validity of the packet size
        while(!isValidPacketSize(packetSize)) {
            printf("Packet Size for Packet %d: ", i+1);
            scanf("%d", &packetSize);
        }
        
        // Storing the packet size in the array
        packetSizes[i] = packetSize;
    }
    
    // Calculating the Average Packet Size
    for(i=0; i<totalPackets; i++) {
        avgPacketSize += packetSizes[i];
    }
    avgPacketSize /= totalPackets;
    
    // Displaying the QoS Statistics
    printf("\nQoS Statistics:\n");
    printf("Total Number of Packets: %d\n", totalPackets);
    printf("Average Packet Size: %.2f bytes\n", avgPacketSize);
    
    return 0;
}