//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold information about a network packet
typedef struct packet {
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
    char protocol[4];
    char payload[256];
} packet;

// A function to parse a string containing a packet and populate the packet structure
void parse_packet(char* raw_packet, packet* parsed_packet) {
    char* token;
    token = strtok(raw_packet, ",");
    strcpy(parsed_packet->source_ip, token);
    token = strtok(NULL, ",");
    strcpy(parsed_packet->dest_ip, token);
    token = strtok(NULL, ",");
    parsed_packet->source_port = atoi(token);
    token = strtok(NULL, ",");
    parsed_packet->dest_port = atoi(token);
    token = strtok(NULL, ",");
    strcpy(parsed_packet->protocol, token);
    token = strtok(NULL, ",");
    strcpy(parsed_packet->payload, token);
}

// A function to check if a packet is suspicious
int is_suspicious(packet* current_packet, packet* previous_packet) {
    if (strcmp(current_packet->source_ip, previous_packet->source_ip) == 0 &&
        strcmp(current_packet->dest_ip, previous_packet->dest_ip) == 0 &&
        current_packet->source_port == previous_packet->source_port &&
        current_packet->dest_port == previous_packet->dest_port &&
        strcmp(current_packet->protocol, previous_packet->protocol) == 0 &&
        strcmp(current_packet->payload, previous_packet->payload) == 0) {
            return 1; // if the current packet is identical to the previous packet, it's suspicious
        }
    return 0; // otherwise, it's not suspicious
}

int main() {
    // initialize variables
    char raw_packet[512];
    packet current_packet, previous_packet;
    int first_packet_seen = 0;

    // read in packets from standard input
    while (fgets(raw_packet, sizeof(raw_packet), stdin) != NULL) {
        parse_packet(raw_packet, &current_packet);

        if (first_packet_seen) { // if this isn't the first packet, check if it's suspicious
            if (is_suspicious(&current_packet, &previous_packet)) {
                printf("Intrusion detected!\n"); // if it's suspicious, print a message
            }
        } else {
            first_packet_seen = 1;
        }

        previous_packet = current_packet; // update the previous packet
    }

    return 0;
}