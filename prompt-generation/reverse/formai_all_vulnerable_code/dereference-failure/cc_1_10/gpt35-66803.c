//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 1024
#define CAPTURE_TIMEOUT_MS 1000

/* Mutex variable for packet queue */
pthread_mutex_t queueMutex = PTHREAD_MUTEX_INITIALIZER;

/* Condition variable for packet queue */
pthread_cond_t queueCond = PTHREAD_COND_INITIALIZER;

/* Packet buffer structure */
typedef struct {
    uint8_t* data;
    size_t size;
} PacketBuffer;

/* Queue structure */
typedef struct {
    PacketBuffer* buffer;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
} PacketQueue;

/* Initialize a new packet buffer */
PacketBuffer* newPacketBuffer(size_t size) {
    PacketBuffer* buffer = (PacketBuffer*) malloc(sizeof(PacketBuffer));
    buffer->data = (uint8_t*) malloc(size);
    buffer->size = size;
    return buffer;
}

/* Free a packet buffer */
void freePacketBuffer(PacketBuffer* buffer) {
    free(buffer->data);
    free(buffer);
}

/* Initialize a new packet queue */
PacketQueue* newPacketQueue(size_t capacity) {
    PacketQueue* queue = (PacketQueue*) malloc(sizeof(PacketQueue));
    queue->buffer = (PacketBuffer*) malloc(sizeof(PacketBuffer) * capacity);
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

/* Free a packet queue */
void freePacketQueue(PacketQueue* queue) {
    while (queue->size > 0) {
        PacketBuffer* buffer = queue->buffer + queue->head;
        freePacketBuffer(buffer);
        queue->size--;
        queue->head = (queue->head + 1) % queue->capacity;
    }
    free(queue->buffer);
    free(queue);
}

/* Enqueue a packet buffer */
void enqueuePacket(PacketQueue* queue, PacketBuffer* buffer) {
    /* Wait for a slot in the queue */
    pthread_mutex_lock(&queueMutex);
    while (queue->size == queue->capacity) {
        pthread_cond_wait(&queueCond, &queueMutex);
    }

    /* Add the buffer to the queue and signal other threads */
    queue->buffer[queue->tail] = *buffer;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
    pthread_cond_signal(&queueCond);

    pthread_mutex_unlock(&queueMutex);
}

/* Dequeue a packet buffer */
PacketBuffer* dequeuePacket(PacketQueue* queue) {
    PacketBuffer* buffer;

    /* Wait for a packet in the queue */
    pthread_mutex_lock(&queueMutex);
    while (queue->size == 0) {
        pthread_cond_wait(&queueCond, &queueMutex);
    }

    /* Remove the buffer from the queue and signal other threads */
    buffer = queue->buffer + queue->head;
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;
    pthread_cond_signal(&queueCond);

    pthread_mutex_unlock(&queueMutex);

    return buffer;
}

/* Packet capture thread function */
void* packetCaptureFn(void* arg) {
    pcap_t* handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    PacketQueue* queue = (PacketQueue*) arg;

    /* Open the pcap handle */
    handle = pcap_open_live("eth0", BUFSIZE, 1, CAPTURE_TIMEOUT_MS, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Unable to open pcap handle: %s\n", errbuf);
        pthread_exit(NULL);
    }

    /* Compile the filter expression */
    if (pcap_compile(handle, &filter, "tcp port 80", 1, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Unable to compile pcap filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        pthread_exit(NULL);
    }

    /* Apply the filter */
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Unable to set pcap filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        pthread_exit(NULL);
    }

    /* Start the packet capture loop */
    while (1) {
        struct pcap_pkthdr header;
        const uint8_t* packet;
        PacketBuffer* buffer;

        packet = pcap_next(handle, &header);
        if (packet == NULL) continue;

        /* Create a new packet buffer and copy the packet data */
        buffer = newPacketBuffer(header.len);
        memcpy(buffer->data, packet, header.len);

        /* Enqueue the packet buffer */
        enqueuePacket(queue, buffer);
    }

    /* Cleanup and exit */
    pcap_close(handle);
    pthread_exit(NULL);
}

/* Packet processing thread function */
void* packetProcessFn(void* arg) {
    PacketQueue* queue = (PacketQueue*) arg;

    while (1) {
        PacketBuffer* buffer = dequeuePacket(queue);

        /* Process the packet buffer */
        printf("Received packet of size %zu\n", buffer->size);

        /* Free the packet buffer */
        freePacketBuffer(buffer);
    }

    /* Cleanup and exit */
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    PacketQueue* queue;
    pthread_t captureThread;
    pthread_t processThread;

    /* Initialize the packet queue */
    queue = newPacketQueue(10);

    /* Start the packet capture thread */
    if (pthread_create(&captureThread, NULL, packetCaptureFn, queue)) {
        fprintf(stderr, "Unable to start capture thread\n");
        exit(EXIT_FAILURE);
    }

    /* Start the packet processing thread */
    if (pthread_create(&processThread, NULL, packetProcessFn, queue)) {
        fprintf(stderr, "Unable to start process thread\n");
        exit(EXIT_FAILURE);
    }

    /* Wait for the threads to finish */
    pthread_join(captureThread, NULL);
    pthread_join(processThread, NULL);

    /* Free the packet queue */
    freePacketQueue(queue);

    return 0;
}