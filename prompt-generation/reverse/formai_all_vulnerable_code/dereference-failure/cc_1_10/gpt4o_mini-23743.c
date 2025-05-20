//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>

#define PING_PACK_SIZE 64
#define PING_INTERVAL 1
#define TIMEOUT_SEC 2
#define MAX_PINGS 10

typedef struct {
    char *address;
    int count;
    int interval;
} PingParams;

void print_usage() {
    printf("\n");
    printf("   🎨 Artistic Network Ping Test 🎨\n");
    printf("   A simple yet elegant program to test the network.\n");
    printf("\n");
    printf("   Usage: ./ping_test <hostname> [options]\n");
    printf("   Options:\n");
    printf("       -c <count>    Number of pings [default: 10]\n");
    printf("       -i <interval> Time interval between pings in seconds [default: 1]\n");
    printf("\n");
}

double get_time_difference(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

void ping_host(PingParams params) {
    struct sockaddr_in server_addr;
    struct hostent *host_entity;
    int sockfd, ping_count = 0;
    char packet[PING_PACK_SIZE];
    struct timespec start, end;
    
    host_entity = gethostbyname(params.address);
    if (host_entity == NULL) {
        perror("Failed to resolve hostname");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host_entity->h_addr, 
          (char *)&server_addr.sin_addr.s_addr,
          host_entity->h_length);
    server_addr.sin_port = htons(0);  // We won't actually connect

    printf("Pinging %s:\n", params.address);
    
    while (ping_count < params.count) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        // Prepare ping packet
        snprintf(packet, PING_PACK_SIZE, "Ping %d bytes from %s # %d", PING_PACK_SIZE, params.address, ping_count + 1);
        
        // Simulate sending a packet (actual socket programming would go here)
        printf("Sending packet: %s\n", packet);
        
        fflush(stdout);
        usleep(params.interval * 1000000);  // Simulating packet send time
        
        // Simulate receiving a reply
        if (ping_count % 2 == 0) {  // Simulate successful replies
            clock_gettime(CLOCK_MONOTONIC, &end);
            double elapsed = get_time_difference(start, end);
            printf("Reply from %s: bytes=%d time=%.3f ms\n", params.address, PING_PACK_SIZE, elapsed * 1000);
        } else {
            printf("Request timed out for packet %d\n", ping_count + 1);
        }
        
        ping_count++;
        sleep(1);  // Wait before sending the next packet
    }
    
    printf("\n🎉 Finished pinging %s with %d packets! 🎉\n", params.address, ping_count);
}

int main(int argc, char *argv[]) {
    PingParams params = {NULL, MAX_PINGS, PING_INTERVAL};
    
    if (argc < 2) {
        print_usage();
        return 1;
    }

    params.address = argv[1];

    // Parse optional arguments
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            params.count = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            params.interval = atoi(argv[++i]);
        }
    }

    ping_host(params);
    return 0;
}