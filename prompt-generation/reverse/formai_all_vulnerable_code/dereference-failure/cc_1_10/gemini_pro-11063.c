//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 1024

struct qos_monitor {
    int sockfd;
    struct sockaddr_in addr;
    int port;
    char *ip;
    pthread_t tid;
    int running;
};

struct qos_data {
    int latency;
    int jitter;
    int packet_loss;
};

void *qos_monitor_thread(void *arg) {
    struct qos_monitor *monitor = (struct qos_monitor *)arg;
    char buf[BUF_SIZE];
    struct timeval start, end;
    int seq = 0;
    int prev_latency = 0;
    int prev_jitter = 0;
    int prev_packet_loss = 0;

    while (monitor->running) {
        // Send a probe packet
        gettimeofday(&start, NULL);
        sprintf(buf, "ping %d", seq);
        sendto(monitor->sockfd, buf, strlen(buf), 0, (struct sockaddr *)&monitor->addr, sizeof(monitor->addr));

        // Receive the response
        int n = recvfrom(monitor->sockfd, buf, BUF_SIZE, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        // Measure the latency
        gettimeofday(&end, NULL);
        int latency = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

        // Calculate the jitter
        int jitter = abs(latency - prev_latency);

        // Calculate the packet loss
        int packet_loss = 0;
        if (seq != atoi(buf)) {
            packet_loss = 1;
        }

        // Print the results
        printf("Latency: %d ms, Jitter: %d ms, Packet loss: %d%%\n", latency, jitter, packet_loss);

        // Update the previous values
        prev_latency = latency;
        prev_jitter = jitter;
        prev_packet_loss = packet_loss;

        // Increment the sequence number
        seq++;
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    // Create a QoS monitor
    struct qos_monitor monitor;
    monitor.ip = argv[1];
    monitor.port = atoi(argv[2]);
    monitor.sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (monitor.sockfd < 0) {
        perror("socket");
        return 1;
    }
    monitor.addr.sin_family = AF_INET;
    monitor.addr.sin_addr.s_addr = inet_addr(monitor.ip);
    monitor.addr.sin_port = htons(monitor.port);
    monitor.running = 1;

    // Start the QoS monitor thread
    pthread_create(&monitor.tid, NULL, qos_monitor_thread, &monitor);

    // Wait for the user to press Enter
    getchar();

    // Stop the QoS monitor thread
    monitor.running = 0;
    pthread_join(monitor.tid, NULL);

    // Close the socket
    close(monitor.sockfd);

    return 0;
}