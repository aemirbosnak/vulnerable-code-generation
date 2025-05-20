//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define MAX_PINGS 5
#define TIMEOUT 1
#define BUFFER_SIZE 64

typedef struct {
    char *ip_address;
    int ping_count;
} PingData;

void *ping_host(void *arg) {
    PingData *ping_data = (PingData *)arg;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in addr;
    int sock;
    
    // Create a UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ping_data->ip_address);
    
    for (int i = 0; i < ping_data->ping_count; i++) {
        ssize_t sent_size = sendto(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr));
        if (sent_size < 0) {
            perror("Failed to send ping");
        } else {
            printf("Ping sent to %s\n", ping_data->ip_address);
        }
        
        // Simulate waiting for a response
        sleep(TIMEOUT);
        
        ssize_t received_size = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (received_size < 0) {
            perror("Failed to receive response");
        } else {
            printf("Response received from %s\n", ping_data->ip_address);
        }
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP1> <IP2> ... <IPn> <COUNT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_hosts = argc - 2;
    int ping_count = atoi(argv[argc - 1]);
    
    // Allocate threads
    pthread_t threads[num_hosts];
    PingData ping_data[num_hosts];

    for (int i = 0; i < num_hosts; i++) {
        ping_data[i].ip_address = argv[i + 1];
        ping_data[i].ping_count = ping_count;

        if (pthread_create(&threads[i], NULL, ping_host, (void *)&ping_data[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_hosts; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All ping operations completed.\n");
    return 0;
}