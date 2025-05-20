//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <pthread.h>

// Intrusion detection threshold
#define THRESHOLD 10

// Packet capture handle
pcap_t *handle;

// Thread data structure
typedef struct thread_data {
    int sockfd;
    struct sockaddr_in addr;
} thread_data;

// Thread function to handle packets
void *handle_packets(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sockfd = data->sockfd;
    struct sockaddr_in addr = data->addr;

    // Packet buffer
    char buffer[4096];

    // Intrusion detection counter
    int counter = 0;

    // Main loop
    while (1) {
        // Receive packet
        int len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr));
        if (len < 0) {
            perror("recvfrom()");
            exit(1);
        }

        // Check for SYN flood attack
        if (len > 40 && buffer[12] == 2 && buffer[13] == 0 && buffer[14] == 0 && buffer[15] == 0) {
            counter++;

            // Threshold reached, trigger alarm
            if (counter > THRESHOLD) {
                printf("SYN flood attack detected from %s!\n", inet_ntoa(addr.sin_addr));
                break;
            }
        }
    }

    // Close socket
    close(sockfd);

    // Free thread data
    free(data);

    // Exit thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Open network interface
    handle = pcap_open_live("eth0", 65535, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live()");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket()");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) < 0) {
        perror("setsockopt()");
        exit(1);
    }

    // Set socket address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind()");
        exit(1);
    }

    // Create thread pool
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->sockfd = sockfd;
        data->addr = addr;
        pthread_create(&threads[i], NULL, handle_packets, (void *)data);
    }

    // Join threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close socket
    close(sockfd);

    // Close network interface
    pcap_close(handle);

    return 0;
}