//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3
#define QOS_THRESHOLD 80

volatile int network_latency = 0;
volatile int packet_loss = 0;
volatile int bandwidth_utilization = 0;

pthread_mutex_t mutex; // Mutex to protect shared variables
pthread_cond_t cond; // Condition variable to signal when QoS threshold is breached

void *latency_test(void *arg) {
  while (1) {
    // Ping a server to get the current network latency
    sleep(1);
    int latency = rand() % 50 + 1; // Simulate latency between 1 and 50 ms
    pthread_mutex_lock(&mutex);
    network_latency = latency;
    pthread_mutex_unlock(&mutex);
  }
}

void *packet_loss_test(void *arg) {
  while (1) {
    // Send packets and count the number of lost packets
    sleep(2);
    int num_packets_sent = rand() % 100 + 1; // Simulate sending between 1 and 100 packets
    int num_packets_lost = rand() % num_packets_sent + 1; // Simulate losing between 1 and num_packets_sent packets
    pthread_mutex_lock(&mutex);
    packet_loss = (num_packets_lost * 100) / num_packets_sent;
    pthread_mutex_unlock(&mutex);
  }
}

void *bandwidth_test(void *arg) {
  while (1) {
    // Download a file and calculate the bandwidth utilization
    sleep(5);
    int file_size = rand() % 1000 + 1; // Simulate file size between 1 and 1000 MB
    int download_time = rand() % 10 + 1; // Simulate download time between 1 and 10 seconds
    int bandwidth = (file_size * 8) / download_time; // Calculate bandwidth in Mbps
    pthread_mutex_lock(&mutex);
    bandwidth_utilization = bandwidth;
    pthread_mutex_unlock(&mutex);
  }
}

void *qos_monitor(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex);
    int qos_score = network_latency + packet_loss + bandwidth_utilization;
    if (qos_score > QOS_THRESHOLD) {
      printf("QoS threshold breached! QoS score: %d\n", qos_score);
      pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);
  }
}

int main() {
  pthread_t threads[NUM_THREADS];
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);

  // Create threads for latency, packet loss, bandwidth tests, and QoS monitoring
  pthread_create(&threads[0], NULL, latency_test, NULL);
  pthread_create(&threads[1], NULL, packet_loss_test, NULL);
  pthread_create(&threads[2], NULL, bandwidth_test, NULL);
  pthread_create(&threads[3], NULL, qos_monitor, NULL);

  // Wait for all threads to finish
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}