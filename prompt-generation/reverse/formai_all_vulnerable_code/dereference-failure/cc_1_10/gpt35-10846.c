//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_BUFFER_SIZE 8192

typedef struct Packet {
    unsigned int seqNum;
    unsigned int length;
    double startTime;
    double endTime;
} Packet;

typedef struct Buffer {
    Packet* packets[MAX_BUFFER_SIZE];
    int head;
    int tail;
    int size;
} Buffer;

typedef struct Queue {
    Packet* packets[MAX_BUFFER_SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct Statistics {
    unsigned int packetsSent;
    unsigned int packetsLost;
    unsigned int packetsReceived;
    double totalTime;
    double avgThroughput;
} Statistics;

void initBuffer(Buffer* buffer);
bool isBufferFull(Buffer* buffer);
bool isBufferEmpty(Buffer* buffer);
void enqueueBuffer(Buffer* buffer, Packet* packet);
Packet* dequeueBuffer(Buffer* buffer);
void initQueue(Queue* queue);
bool isQueueFull(Queue* queue);
bool isQueueEmpty(Queue* queue);
void enqueueQueue(Queue* queue, Packet* packet);
Packet* dequeueQueue(Queue* queue);
void sendPacket(Packet* packet);
bool receivePacket(Packet* packet);
void updateStatistics(Packet* packet, Statistics* stats);

int main() {
    srand(time(NULL));
    Buffer buffer;
    initBuffer(&buffer);
    Queue queue;
    initQueue(&queue);
    Statistics stats = {0, 0, 0, 0.0, 0.0};
    double timer = 0.0;
    double interval = 1.0;
    while (true) {
        while (!isBufferFull(&buffer)) {
            Packet* packet = (Packet*) malloc(sizeof(Packet));
            packet->seqNum = rand() % 10000;
            packet->length = rand() % MAX_PACKET_SIZE;
            packet->startTime = timer;
            packet->endTime = 0.0;
            enqueueBuffer(&buffer, packet);
        }
        while (!isQueueFull(&queue) && !isBufferEmpty(&buffer)) {
            Packet* packet = dequeueBuffer(&buffer);
            enqueueQueue(&queue, packet);
        }
        while (!isQueueEmpty(&queue)) {
            Packet* packet = dequeueQueue(&queue);
            sendPacket(packet);
            if (receivePacket(packet)) {
                updateStatistics(packet, &stats);
            }
            else {
                stats.packetsLost++;
            }
            free(packet);
        }
        timer += interval;
        stats.totalTime += interval;
        stats.avgThroughput = stats.packetsReceived / stats.totalTime;
        printf("Packets Sent: %u\nPackets Lost: %u\nPackets Received: %u\nTotal Time: %.2f seconds\nAverage Throughput: %.2f packets per second\n",
               stats.packetsSent, stats.packetsLost, stats.packetsReceived, stats.totalTime, stats.avgThroughput);
    }
    return 0;
}

void initBuffer(Buffer* buffer) {
    buffer->head = 0;
    buffer->tail = 0;
    buffer->size = 0;
}

bool isBufferFull(Buffer* buffer) {
    return buffer->size == MAX_BUFFER_SIZE;
}

bool isBufferEmpty(Buffer* buffer) {
    return buffer->size == 0;
}

void enqueueBuffer(Buffer* buffer, Packet* packet) {
    if (isBufferFull(buffer)) {
        return;
    }
    buffer->packets[buffer->tail] = packet;
    buffer->tail = (buffer->tail + 1) % MAX_BUFFER_SIZE;
    buffer->size++;
}

Packet* dequeueBuffer(Buffer* buffer) {
    if (isBufferEmpty(buffer)) {
        return NULL;
    }
    Packet* packet = buffer->packets[buffer->head];
    buffer->head = (buffer->head + 1) % MAX_BUFFER_SIZE;
    buffer->size--;
    return packet;
}

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
}

bool isQueueFull(Queue* queue) {
    return queue->size == MAX_BUFFER_SIZE;
}

bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueueQueue(Queue* queue, Packet* packet) {
    if (isQueueFull(queue)) {
        return;
    }
    queue->packets[queue->rear] = packet;
    queue->rear = (queue->rear + 1) % MAX_BUFFER_SIZE;
    queue->size++;
}

Packet* dequeueQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    Packet* packet = queue->packets[queue->front];
    queue->front = (queue->front + 1) % MAX_BUFFER_SIZE;
    queue->size--;
    return packet;
}

void sendPacket(Packet* packet) {
    packet->endTime = packet->startTime + (double) packet->length;
}

bool receivePacket(Packet* packet) {
    return (rand() % 100) < 90; // 90% chance of receiving packet
}

void updateStatistics(Packet* packet, Statistics* stats) {
    stats->packetsSent++;
    stats->packetsReceived++;
    stats->totalTime += packet->endTime - packet->startTime;
    stats->avgThroughput = stats->packetsReceived / stats->totalTime;
}