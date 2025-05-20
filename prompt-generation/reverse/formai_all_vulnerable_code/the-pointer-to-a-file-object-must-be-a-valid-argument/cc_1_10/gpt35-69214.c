//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_PACKETS 1000
#define MAX_CONNECTIONS 50

// A structure representing a connection
typedef struct connection {
    unsigned int source_ip;
    unsigned int dest_ip;
    unsigned short source_port;
    unsigned short dest_port;
    time_t last_packet_time;
    int packet_count;
    int bytes_in;
    int bytes_out;
} Connection;

// A structure representing a packet
typedef struct packet {
    unsigned int source_ip;
    unsigned int dest_ip;
    unsigned short source_port;
    unsigned short dest_port;
    int bytes_in;
    int bytes_out;
} Packet;

// An array to store connections
Connection connections[MAX_CONNECTIONS];

// An array to store packets
Packet packet_buffer[MAX_PACKETS];

// The index of the next packet in the buffer to be processed
int packet_index = 0;

// The total number of packets in the buffer
int packet_count = 0;

// A function to print usage instructions
void print_usage() {
    printf("Usage: ids <input_file>\n");
}

// A function to process a packet
void process_packet(Packet p) {
    // Check if we already have a connection for this packet
    int connection_index = -1;
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].source_ip == p.source_ip && connections[i].dest_ip == p.dest_ip && connections[i].source_port == p.source_port && connections[i].dest_port == p.dest_port) {
            connection_index = i;
            break;
        }
    }
    // If we don't have a connection, create a new one
    if (connection_index == -1) {
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].source_ip == 0 && connections[i].dest_ip == 0 && connections[i].source_port == 0 && connections[i].dest_port == 0) {
                connections[i].source_ip = p.source_ip;
                connections[i].dest_ip = p.dest_ip;
                connections[i].source_port = p.source_port;
                connections[i].dest_port = p.dest_port;
                connections[i].last_packet_time = time(NULL);
                connections[i].packet_count = 1;
                connections[i].bytes_in = p.bytes_in;
                connections[i].bytes_out = p.bytes_out;
                break;
            }
        }
    }
    // If we have a connection, update it
    else {
        connections[connection_index].last_packet_time = time(NULL);
        connections[connection_index].packet_count++;
        connections[connection_index].bytes_in += p.bytes_in;
        connections[connection_index].bytes_out += p.bytes_out;
    }
}

// A function to process all packets in the buffer
void process_packets() {
    for (int i = 0; i < packet_count; i++) {
        process_packet(packet_buffer[i]);
    }
    // Reset the packet buffer
    packet_count = 0;
    packet_index = 0;
}

// A function to read packets from a file
void read_packets(char* input_file) {
    FILE* f = fopen(input_file, "r");
    char line[MAX_PACKET_SIZE];
    while (fgets(line, MAX_PACKET_SIZE, f)) {
        Packet p;
        char* token = strtok(line, ",");
        p.source_ip = atoi(token);
        token = strtok(NULL, ",");
        p.dest_ip = atoi(token);
        token = strtok(NULL, ",");
        p.source_port = atoi(token);
        token = strtok(NULL, ",");
        p.dest_port = atoi(token);
        token = strtok(NULL, ",");
        p.bytes_in = atoi(token);
        token = strtok(NULL, ",");
        p.bytes_out = atoi(token);
        packet_buffer[packet_count++] = p;
        // If the packet buffer is full, process the packets
        if (packet_count == MAX_PACKETS) {
            process_packets();
        }
    }
    // Process any remaining packets in the buffer
    process_packets();
    fclose(f);
}

// A function to print information about a connection
void print_connection(Connection c) {
    char source_ip[16];
    snprintf(source_ip, sizeof(source_ip), "%d.%d.%d.%d", (c.source_ip >> 24) & 0xFF, (c.source_ip >> 16) & 0xFF, (c.source_ip >> 8) & 0xFF, c.source_ip & 0xFF);
    char dest_ip[16];
    snprintf(dest_ip, sizeof(dest_ip), "%d.%d.%d.%d", (c.dest_ip >> 24) & 0xFF, (c.dest_ip >> 16) & 0xFF, (c.dest_ip >> 8) & 0xFF, c.dest_ip & 0xFF);
    printf("%s:%d -> %s:%d\n", source_ip, c.source_port, dest_ip, c.dest_port);
    printf("  Packets processed: %d\n", c.packet_count);
    printf("  Bytes in: %d\n", c.bytes_in);
    printf("  Bytes out: %d\n", c.bytes_out);
    time_t now = time(NULL);
    double time_diff = difftime(now, c.last_packet_time);
    printf("  Seconds since last packet: %f\n", time_diff);
    if (time_diff > 60 && c.packet_count > 10) {
        printf("  ALERT: Potential intrusion detected!\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }
    char* input_file = argv[1];
    memset(connections, 0, sizeof(connections));
    read_packets(input_file);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].source_ip != 0 && connections[i].dest_ip != 0 && connections[i].source_port != 0 && connections[i].dest_port != 0) {
            print_connection(connections[i]);
        }
    }
    return 0;
}