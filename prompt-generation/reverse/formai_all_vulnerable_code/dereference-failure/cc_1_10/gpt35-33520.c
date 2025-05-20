//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Struct defining a packet
typedef struct {
    int id;
    int size;
} Packet;

//Function to generate a random packet
Packet generate_packet() {
    Packet packet;
    packet.id = rand() % 100;
    packet.size = rand() % 100;
    return packet;
}

//Function to simulate the network
int simulate_network(Packet packet, int bandwidth) {
    int time_to_send = packet.size / bandwidth + 1;
    printf("Sending packet %d with size %d. Time to send: %d\n", packet.id, packet.size, time_to_send);
    return time_to_send;
}

//Function to calculate the average delay of packets
double calculate_average_delay(int* delays, int num_packets) {
    double total_delay = 0;
    for(int i=0; i<num_packets; i++) {
        total_delay += delays[i];
    }
    return total_delay / num_packets;
}

int main() {
    srand(time(NULL)); //Seed random generator with current time

    //Initialize variables
    int num_packets = 10;
    int bandwidth = 10;
    int* delays = (int*) malloc(num_packets * sizeof(int));

    //Generate and send packets
    for(int i=0; i<num_packets; i++) {
        Packet packet = generate_packet();
        int delay = simulate_network(packet, bandwidth);
        delays[i] = delay;
    }

    //Calculate and display results
    double average_delay = calculate_average_delay(delays, num_packets);
    printf("Average delay: %.2f seconds\n", average_delay);

    free(delays); //Free allocated memory

    return 0; //Exit program
}