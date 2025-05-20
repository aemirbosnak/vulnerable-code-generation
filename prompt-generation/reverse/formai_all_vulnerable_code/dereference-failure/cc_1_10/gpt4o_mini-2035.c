//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_FILE "ids_log.txt"
#define BUFFER_SIZE 256

typedef struct {
    time_t timestamp;
    char source_ip[16];
    char destination_ip[16];
    char protocol[8];
    int size;
    char data[BUFFER_SIZE];
} Packet;

void log_attack(const Packet *packet) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(log_file, "[%ld] Attack detected from %s to %s using %s protocol, size: %d bytes\n",
            packet->timestamp, packet->source_ip, packet->destination_ip, packet->protocol, packet->size);
    fclose(log_file);
}

int analyze_packet(const Packet *packet) {
    // A very rudimentary check: if packet size exceeds a threshold or if protocol is invalid
    if (packet->size > 1500) {
        return 1; // Possible attack due to large packet size
    }
    if (strcmp(packet->protocol, "ICMP") == 0) {
        return 1; // Possible attack from echo request
    }
    return 0; // No threat detected
}

void simulate_packet_reception(Packet *packet) {
    // Simulate a packet being received
    packet->timestamp = time(NULL);

    snprintf(packet->source_ip, sizeof(packet->source_ip), "192.168.1.%d", rand() % 255);
    snprintf(packet->destination_ip, sizeof(packet->destination_ip), "192.168.1.100");
    snprintf(packet->protocol, sizeof(packet->protocol), rand() % 2 ? "TCP" : "UDP");
    packet->size = rand() % 2000;  // Random packet size between 0 and 2000
    snprintf(packet->data, sizeof(packet->data), "Sample packet data: %d", rand());
}

void print_usage() {
    printf("Usage: ./ids [options]\n");
    printf("Options:\n");
    printf("  -h               Show this help message\n");
    printf("  -n <num_packets> Specify number of packets to simulate\n");
}

int main(int argc, char *argv[]) {
    int num_packets = 10; // Default number of packets to simulate
    Packet packet;

    // Parsing command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_usage();
            return 0;
        } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            num_packets = atoi(argv[++i]);
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    // Start simulation of packet reception and analysis
    for (int i = 0; i < num_packets; i++) {
        simulate_packet_reception(&packet);
        printf("Received Packet: Source: %s, Dest: %s, Protocol: %s, Size: %d bytes\n", 
               packet.source_ip, packet.destination_ip, packet.protocol, packet.size);

        if (analyze_packet(&packet)) {
            printf("Attack detected!\n");
            log_attack(&packet);
        } else {
            printf("No threat detected\n");
        }

        sleep(1); // Simulate delay between packet receptions
    }

    return 0;
}