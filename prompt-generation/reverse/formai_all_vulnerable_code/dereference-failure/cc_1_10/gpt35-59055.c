//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// packet struct to hold data
typedef struct {
    int id;         // packet id
    int priority;   // packet priority level
    int size;       // packet size in bytes
} Packet;

// initialize mutex and condition variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// global variables to keep track of network usage
int packets_sent = 0;
int total_bytes = 0;
int priority_packets = 0;

// function to send packets
void send_packet(Packet *pkt) {
    // acquire the mutex lock
    pthread_mutex_lock(&mutex);

    // simulate packet sending by sleeping for a random amount of time
    usleep(rand() % 1000);

    // update network usage statistics
    packets_sent++;
    total_bytes += pkt->size;
    if (pkt->priority > 5) {
        priority_packets++;
    }

    // signal waiting threads
    pthread_cond_broadcast(&cond);

    // release the mutex lock
    pthread_mutex_unlock(&mutex);
}

// function to monitor network QoS
void *qos_monitor(void *arg) {
    while (1) {
        // acquire the mutex lock
        pthread_mutex_lock(&mutex);

        // wait for packets to be sent
        while (packets_sent == 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        // calculate QoS metrics
        float prop_priority = (float)priority_packets / packets_sent;
        float avg_size = (float)total_bytes / packets_sent;

        // print out QoS metrics
        printf("QoS Metrics:\n");
        printf("Priority Packet Proportion: %.2f%%\n", prop_priority * 100);
        printf("Average Packet Size: %.2f bytes\n", avg_size);

        // reset counters
        packets_sent = 0;
        total_bytes = 0;
        priority_packets = 0;

        // release the mutex lock
        pthread_mutex_unlock(&mutex);
    }

    // exit thread
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // create qos_monitor thread
    pthread_t tid;
    pthread_create(&tid, NULL, qos_monitor, NULL);

    // send packets
    for (int i = 0; i < 100; i++) {
        Packet *pkt = malloc(sizeof(Packet));
        pkt->id = i;
        pkt->priority = rand() % 10;
        pkt->size = 100 + rand() % 900;
        send_packet(pkt);
    }

    // wait for qos_monitor thread to finish
    pthread_join(tid, NULL);

    return 0;
}