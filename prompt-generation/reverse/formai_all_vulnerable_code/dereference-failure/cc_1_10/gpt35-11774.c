//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

typedef struct packet {
    int id;
    int length;
    int priority;
    int timestamp;
} Packet;

typedef struct qos {
    int max_delay;
    int max_packet_loss;
    int min_throughput;
    int max_jitter;
} QoS;

QoS calculate_qos(Packet *packets, int num_packets) {
    QoS result;

    // Initialize QoS values
    result.max_delay = 0;
    result.max_packet_loss = 0;
    result.min_throughput = 0;
    result.max_jitter = 0;

    if (num_packets == 0) {
        return result;
    }

    int total_length = 0;
    int total_delay = 0;
    int total_jitter = 0;

    int last_timestamp = packets[0].timestamp;
    int packet_loss_count = 0;

    for (int i = 0; i < num_packets; i++) {
        total_length += packets[i].length;

        if (packets[i].priority == 1) {
            total_delay += packets[i].timestamp - last_timestamp;
        }

        if (i > 0) {
            total_jitter += abs(packets[i].timestamp - packets[i-1].timestamp - 100);
        }

        last_timestamp = packets[i].timestamp;

        if (packets[i].id != i) {
            packet_loss_count++;
        }
    }

    int total_time = packets[num_packets-1].timestamp - packets[0].timestamp;

    result.max_delay = total_delay / num_packets;
    result.max_packet_loss = (packet_loss_count * 100) / num_packets;
    result.min_throughput = (total_length / total_time) * 1000;
    result.max_jitter = total_jitter / num_packets;

    return result;
}

int main() {

    char buffer[BUFFER_SIZE];
    Packet packets[BUFFER_SIZE];
    int count = 0;

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {

        // Parse packet information from input
        char *token = strtok(buffer, ",");
        packets[count].id = atoi(token);

        token = strtok(NULL, ",");
        packets[count].length = atoi(token);

        token = strtok(NULL, ",");
        packets[count].priority = atoi(token);

        token = strtok(NULL, ",");
        packets[count].timestamp = atoi(token);

        count++;
    }

    QoS qos = calculate_qos(packets, count);

    printf("The network QoS for this session is:\n");
    printf("Maximum Delay: %d ms\n", qos.max_delay);
    printf("Maximum Packet Loss: %d%%\n", qos.max_packet_loss);
    printf("Minimum Throughput: %d kbps\n", qos.min_throughput);
    printf("Maximum Jitter: %d ms\n", qos.max_jitter);

    return 0;
}