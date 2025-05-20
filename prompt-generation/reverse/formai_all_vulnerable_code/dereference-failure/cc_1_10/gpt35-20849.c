//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PACKET_SIZE 1000 // Packet size in bits
#define DATA_RATE 100 // Data rate in kbps
#define PACKET_DELAY 50 // Delay between packets in ms
#define SIMULATION_TIME 60*1000 // Simulation time in ms

struct packet {
    int id;
    int size;
    int delay;
};

int main() {
    srand(time(0));

    // Calculate the number of packets that can be transmitted in a second
    int packets_per_second = DATA_RATE/((float)PACKET_SIZE/1000);
    printf("Number of packets that can be transmitted in a second: %d\n", packets_per_second);

    // Calculate the delay between each packet transmission
    int delay_between_packets = 1000/packets_per_second;
    printf("Delay between each packet transmission: %d ms\n", delay_between_packets);

    // Create an array of packets
    int num_packets = (SIMULATION_TIME/PACKET_DELAY)+1;
    struct packet *packets = malloc(num_packets*sizeof(struct packet));
    for (int i = 0; i < num_packets; i++) {
        packets[i].id = i+1;
        packets[i].size = PACKET_SIZE;
        packets[i].delay = PACKET_DELAY;
    }

    // Simulate the transmission of packets
    int packets_transmitted = 0;
    int packets_dropped = 0;
    int total_delay = 0;
    float avg_delay = 0.0;
    int start_time = clock();
    int end_time = start_time + SIMULATION_TIME;
    while (clock() < end_time) {
        // Check if there are any packets waiting to be transmitted
        if (packets_transmitted < num_packets) {
            // Transmit the next packet
            int packet_id = packets[packets_transmitted].id;
            printf("Transmission of packet %d started\n", packet_id);
            int transmission_start_time = clock();
            // Simulate the time taken to transmit the packet
            int transmission_time = packets[packets_transmitted].size/DATA_RATE*1000;
            while (clock() < transmission_start_time + transmission_time);
            int transmission_end_time = clock();
            // Calculate the delay between transmission of the current packet and the next packet
            int delay = delay_between_packets - (transmission_end_time - transmission_start_time);
            if (delay < 0) {
                delay = 0;
                packets_dropped++;
                printf("Packet %d dropped\n", packet_id);
            } else {
                packets[packets_transmitted].delay = delay;
                total_delay += delay;
            }
            printf("Transmission of packet %d ended\n", packet_id);
            packets_transmitted++;
        } else {
            // No more packets to transmit
            break;
        }
        // Wait for the delay before transmitting the next packet
        while (clock() < end_time && clock() < start_time + PACKET_DELAY + packets[packets_transmitted-1].delay);
    }

    // Calculate average delay
    if (packets_transmitted > 0) {
        avg_delay = (float)total_delay/packets_transmitted;
    }

    printf("Packets transmitted: %d\n", packets_transmitted);
    printf("Packets dropped: %d\n", packets_dropped);
    printf("Average delay: %.2f ms\n", avg_delay);

    // Free memory allocated for packets
    free(packets);

    return 0;
}