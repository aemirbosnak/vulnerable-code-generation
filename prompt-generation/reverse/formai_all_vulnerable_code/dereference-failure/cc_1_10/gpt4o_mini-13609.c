//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>

#define MAX_SERVERS 10
#define BUFFER_SIZE 1024
#define PING_COUNT 4
#define TIMEOUT 1

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int response_time;
} Server;

void ping_server(const char *ip, Server *server) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c %d -W %d %s | tail -1 | awk -F '/' '{print $(NF-2)}'", PING_COUNT, TIMEOUT, ip);
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        server->response_time = -1;
        return;
    }

    // Get response time from ping command
    if (fgets(command, sizeof(command), fp) != NULL) {
        server->response_time = atoi(command);
    } else {
        server->response_time = -1;
    }
    pclose(fp);
}

void print_report(Server servers[], int count) {
    printf("\nQuality of Service Report\n");
    printf("---------------------------------------\n");
    printf("%-15s %-15s\n", "IP Address", "Response Time (ms)");
    printf("---------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %-15d\n", servers[i].ip, servers[i].response_time);
    }
    printf("---------------------------------------\n");
}

void monitor_qos(Server servers[], int count) {
    while (1) {
        for (int i = 0; i < count; i++) {
            ping_server(servers[i].ip, &servers[i]);
        }
        print_report(servers, count);
        sleep(5); // Wait 5 seconds before the next check
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server_ip1> <server_ip2> ... <server_ipN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Server servers[MAX_SERVERS];
    int total_servers = 0;

    for (int i = 1; i < argc && i < MAX_SERVERS + 1; i++) {
        strncpy(servers[total_servers].ip, argv[i], INET_ADDRSTRLEN);
        servers[total_servers].response_time = -1; // Initialize to -1 (unknown)
        total_servers++;
    }

    printf("Monitoring Quality of Service for %d servers...\n", total_servers);
    monitor_qos(servers, total_servers);

    return EXIT_SUCCESS;
}