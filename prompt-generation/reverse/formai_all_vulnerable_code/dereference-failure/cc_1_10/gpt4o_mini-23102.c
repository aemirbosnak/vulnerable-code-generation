//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 20
#define QUEUE_SIZE MAX_DEVICES

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    int id;
    struct Device* connections[MAX_DEVICES];
    int connection_count;
} Device;

typedef struct Queue {
    Device* devices[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int is_queue_empty(Queue* q) {
    return q->front == q->rear;
}

int is_queue_full(Queue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

void enqueue(Queue* q, Device* device) {
    if (!is_queue_full(q)) {
        q->devices[q->rear] = device;
        q->rear = (q->rear + 1) % QUEUE_SIZE;
    }
}

Device* dequeue(Queue* q) {
    if (!is_queue_empty(q)) {
        Device* device = q->devices[q->front];
        q->front = (q->front + 1) % QUEUE_SIZE;
        return device;
    }
    return NULL;
}

Device* create_device(const char* name, int id) {
    Device* device = (Device*)malloc(sizeof(Device));
    strncpy(device->name, name, MAX_NAME_LENGTH);
    device->id = id;
    device->connection_count = 0;
    return device;
}

void connect_devices(Device* d1, Device* d2) {
    d1->connections[d1->connection_count++] = d2;
    d2->connections[d2->connection_count++] = d1;
}

void print_network_topology(Device* start_device) {
    int visited[MAX_DEVICES] = {0};
    Queue q;
    init_queue(&q);
    
    enqueue(&q, start_device);
    visited[start_device->id] = 1;

    printf("Network Topology starting from %s:\n", start_device->name);

    while (!is_queue_empty(&q)) {
        Device* current_device = dequeue(&q);
        printf("Device %s (ID: %d) is connected to: ", current_device->name, current_device->id);

        for (int i = 0; i < current_device->connection_count; i++) {
            Device* connected_device = current_device->connections[i];
            printf("%s (ID: %d) ", connected_device->name, connected_device->id);
            if (!visited[connected_device->id]) {
                visited[connected_device->id] = 1;
                enqueue(&q, connected_device);
            }
        }
        printf("\n");
    }
}

int main() {
    Device* devices[MAX_DEVICES];

    // Create devices
    devices[0] = create_device("Router", 0);
    devices[1] = create_device("Switch", 1);
    devices[2] = create_device("PC_A", 2);
    devices[3] = create_device("PC_B", 3);
    devices[4] = create_device("Server", 4);

    // Connect devices
    connect_devices(devices[0], devices[1]); // Router <-> Switch
    connect_devices(devices[1], devices[2]); // Switch <-> PC_A
    connect_devices(devices[1], devices[3]); // Switch <-> PC_B
    connect_devices(devices[0], devices[4]); // Router <-> Server

    // Print network topology starting from the Router
    print_network_topology(devices[0]);

    // Free allocated memory
    for (int i = 0; i < 5; i++) {
        free(devices[i]);
    }

    return 0;
}