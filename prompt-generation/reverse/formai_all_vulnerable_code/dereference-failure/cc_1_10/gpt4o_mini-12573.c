//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

#define MAX_ADDRESSES 10
#define BUFFER_SIZE 1024

typedef struct {
    char address[INET_ADDRSTRLEN];
    int packet_count;
    int lost_count;
} Peer;

Peer peers[MAX_ADDRESSES];
int peer_count = 0;
int running = 1;

void sigint_handler(int signum) {
    running = 0;
}

void add_peer(const char *address) {
    if (peer_count < MAX_ADDRESSES) {
        strcpy(peers[peer_count].address, address);
        peers[peer_count].packet_count = 0;
        peers[peer_count].lost_count = 0;
        peer_count++;
    } else {
        printf("Max peer limit reached!\n");
    }
}

void print_qos_report() {
    printf("\n----- Quality of Service Report -----\n");
    for (int i = 0; i < peer_count; i++) {
        printf("Address: %s\n", peers[i].address);
        printf("Packets Sent: %d\n", peers[i].packet_count);
        printf("Packets Lost: %d\n", peers[i].lost_count);
        float loss_rate = (peers[i].packet_count == 0) ? 0 : ((float)peers[i].lost_count / peers[i].packet_count) * 100;
        printf("Loss Rate: %.2f%%\n\n", loss_rate);
    }
}

void ping_peer(const char *address) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c 1 -W 1 %s > /dev/null", address);
    int status = system(command);
    
    for (int i = 0; i < peer_count; i++) {
        if (strcmp(peers[i].address, address) == 0) {
            peers[i].packet_count++;
            if (status != 0) {
                peers[i].lost_count++;
            }
            break;
        }
    }
}

void monitor_qos(const char *addresses[], int interval) {
    while (running) {
        for (int i = 0; i < peer_count; i++) {
            ping_peer(peers[i].address);
        }
        print_qos_report();
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip_address1> <ip_address2> ... <ip_addressN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sigint_handler);
    
    for (int i = 1; i < argc; i++) {
        add_peer(argv[i]);
    }
    
    int interval = 5; // Interval in seconds
    printf("Monitoring QoS for the following addresses:\n");
    for (int i = 0; i < peer_count; i++) {
        printf("- %s\n", peers[i].address);
    }

    monitor_qos((const char**)argv + 1, interval);

    printf("QoS Monitoring stopped. Thank you for using this tool!\n");
    return 0;
}