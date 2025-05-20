//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_NUM_PACKETS 100
#define MAX_PACKET_SIZE 1024
#define MAX_QUEUE_SIZE 20
#define MAX_WAIT_TIME 5

typedef struct Packet {
    int size;
    time_t arrival_time;
} Packet;

typedef struct Queue {
    Packet packets[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

Queue create_queue() {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.count = 0;
    return q;
}

void enqueue(Queue *q, Packet packet) {
    if (q->count >= MAX_QUEUE_SIZE) {
        printf("Queue is full. Dropping Packet with size %d\n", packet.size);
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->packets[q->rear] = packet;
    q->count++;
}

Packet dequeue(Queue *q) {
    if (q->count <= 0) {
        Packet empty_packet;
        empty_packet.size = -1;
        return empty_packet;
    }
    Packet packet = q->packets[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return packet;
}

int wait_for_packet(Queue *q) {
    int waited_time = 0;
    while (q->count <= 0 && waited_time < MAX_WAIT_TIME) {
        sleep(1);
        waited_time++;
    }
    return waited_time;
}

int main() {
    Queue queue = create_queue();
    int num_packets = rand() % MAX_NUM_PACKETS;
    int total_packet_size = 0;
    for (int i = 0; i < num_packets; i++) {
        Packet packet;
        packet.size = rand() % MAX_PACKET_SIZE;
        packet.arrival_time = time(NULL);
        enqueue(&queue, packet);
        total_packet_size += packet.size;
    }
    int average_packet_size = total_packet_size / num_packets;

    printf("Number of packets in queue: %d\n", queue.count);
    printf("Average packet size: %d\n", average_packet_size);

    Packet packet;
    int received_packet_count = 0;
    while (received_packet_count < num_packets) {
        int wait_time = wait_for_packet(&queue);
        if (wait_time >= MAX_WAIT_TIME) {
            printf("No new packets received in last %d seconds\n", MAX_WAIT_TIME);
            break;
        }
        packet = dequeue(&queue);
        if (packet.size != -1) {
            printf("Received Packet[%d] with size %d at time %ld\n", received_packet_count+1, packet.size, packet.arrival_time);
            received_packet_count++;
        }
    }

    if (received_packet_count == num_packets) {
        printf("All packets received successfully!\n");
    } else {
        printf("Packets lost during transmission\n");
    }

    return 0;
}