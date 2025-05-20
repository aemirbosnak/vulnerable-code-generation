//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_THREADS 10

typedef struct {
    char ip[16];
    char mask[16];
    char network[16];
    char broadcast[16];
    char first_host[16];
    char last_host[16];
} subnet_info;

void* calculate_subnet(void* arg) {
    subnet_info* info = (subnet_info*)arg;

    struct sockaddr_in ip_addr;
    struct sockaddr_in mask_addr;
    struct sockaddr_in network_addr;
    struct sockaddr_in broadcast_addr;

    // Convert strings to network byte ordered binary
    inet_pton(AF_INET, info->ip, &ip_addr.sin_addr);
    inet_pton(AF_INET, info->mask, &mask_addr.sin_addr);

    // Calculate the network address
    network_addr.sin_addr.s_addr = ip_addr.sin_addr.s_addr & mask_addr.sin_addr.s_addr;
    inet_ntop(AF_INET, &network_addr.sin_addr, info->network, sizeof(info->network));

    // Calculate the broadcast address
    broadcast_addr.sin_addr.s_addr = network_addr.sin_addr.s_addr | ~mask_addr.sin_addr.s_addr;
    inet_ntop(AF_INET, &broadcast_addr.sin_addr, info->broadcast, sizeof(info->broadcast));

    // Calculate the first host address
    struct in_addr first_host_addr;
    first_host_addr.s_addr = network_addr.sin_addr.s_addr + 1;
    inet_ntop(AF_INET, &first_host_addr, info->first_host, sizeof(info->first_host));

    // Calculate the last host address
    struct in_addr last_host_addr;
    last_host_addr.s_addr = broadcast_addr.sin_addr.s_addr - 1;
    inet_ntop(AF_INET, &last_host_addr, info->last_host, sizeof(info->last_host));

    return NULL;
}

void print_subnet_info(subnet_info info) {
    printf("IP Address: %s\n", info.ip);
    printf("Subnet Mask: %s\n", info.mask);
    printf("Network Address: %s\n", info.network);
    printf("Broadcast Address: %s\n", info.broadcast);
    printf("First Host: %s\n", info.first_host);
    printf("Last Host: %s\n", info.last_host);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Subnet Mask> [<IP Address> <Subnet Mask> ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[MAX_THREADS];
    subnet_info info[MAX_THREADS];
    int thread_count = (argc - 1) / 2;

    if (thread_count > MAX_THREADS) {
        thread_count = MAX_THREADS;
    }

    // Prepare and create threads
    for (int i = 0; i < thread_count; ++i) {
        strncpy(info[i].ip, argv[i * 2 + 1], sizeof(info[i].ip));
        strncpy(info[i].mask, argv[i * 2 + 2], sizeof(info[i].mask));

        if (pthread_create(&threads[i], NULL, calculate_subnet, (void*)&info[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
        print_subnet_info(info[i]);
    }

    return 0;
}