//MISTRAL-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 65536
#define NORMAL_MIN_SIZE 50
#define NORMAL_MAX_SIZE 1500
#define PRIORITY_MIN_SIZE 20
#define PRIORITY_MAX_RATE 100
#define PRIORITY_THRESHOLD 25

typedef struct {
    u_int8_t priority;
    u_int16_t size;
} packet_t;

pcap_t* handle;
int linktype;
int num_packets = 0;
int normal_packets = 0;
int priority_packets = 0;
int total_size = 0;
int normal_size = 0;
int priority_size = 0;
double priority_percent = 0.0;

void print_stats() {
    double normal_avg_size = (double) normal_size / num_packets;
    double priority_avg_size = (double) priority_size / priority_packets;

    printf("Current priority traffic percentage: %.2f%%\n", priority_percent * 100);
    printf("Current average packet size for normal traffic: %d bytes\n", (int) normal_avg_size);
    printf("Current average packet size for priority traffic: %d bytes\n", (int) priority_avg_size);
}

void handle_packet(const u_char* packet, const struct pcap_pkthdr* header) {
    packet_t* packet_data = (packet_t*) packet;

    if (packet_data->size < NORMAL_MIN_SIZE || packet_data->size > NORMAL_MAX_SIZE) {
        if (priority_percent * 100 < PRIORITY_THRESHOLD) {
            priority_percent += ((double) (header->len - normal_size) / total_size) * (PRIORITY_MAX_RATE / 100.0);
        }
        normal_size += packet_data->size;
        normal_packets++;
    } else {
        priority_size += packet_data->size;
        priority_packets++;
        num_packets++;
    }

    total_size += header->len;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s interface normal_min_size normal_max_size priority_min_size priority_max_rate\n", argv[0]);
        exit(1);
    }

    char* dev = argv[1];
    int normal_min = atoi(argv[2]);
    int normal_max = atoi(argv[3]);
    int priority_min = atoi(argv[4]);

    handle = pcap_open_live(dev, MAX_PACKET_SIZE, 1, 1000, &linktype);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, handle_packet, NULL);
    pcap_close(handle);

    print_stats();

    return 0;
}