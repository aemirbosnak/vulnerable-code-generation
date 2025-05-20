//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> 

#define MAX_TRIES 10
#define MAX_SSID_LENGTH 32

typedef struct wifi_stats {
    char ssid[MAX_SSID_LENGTH];
    float signal_strength;
} wifi_stats_t;

int main(int argc, char* argv[]) {
    int sock, tries, i;
    float signal_strength_avg;
    char *address, *port_str, buffer[1024];
    struct sockaddr_in server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    address = argv[1];
    port_str = argv[2];

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port_str));

    if (inet_pton(AF_INET, address, &server.sin_addr) <= 0) {
        perror("Failed to create address.\n");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket.\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Failed to connect to server.\n");
        exit(1);
    }

    printf("Connected to server %s on port %s\n", address, port_str);

    for (tries = 0; tries < MAX_TRIES; tries++) {
        wifi_stats_t wifi_stats[10];
        float signal_strength_sum = 0.0;

        for (i = 0; i < 10; i++) {
            read(sock, buffer, 1024);
            sscanf(buffer, "%s %f", wifi_stats[i].ssid, &wifi_stats[i].signal_strength);
            signal_strength_sum += wifi_stats[i].signal_strength;
        }

        signal_strength_avg = signal_strength_sum / 10.0;

        printf("Averaged Wi-Fi signal strength: %f\n", signal_strength_avg);

        for (i = 0; i < 10; i++) {
            if (wifi_stats[i].signal_strength >= signal_strength_avg) {
                printf("Strong signal from %s\n", wifi_stats[i].ssid);
            } else {
                printf("Weak signal from %s\n", wifi_stats[i].ssid);
            }
        }

        sleep(5);
    }

    close(sock);

    return 0;
}