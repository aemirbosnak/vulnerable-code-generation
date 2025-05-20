//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PING_COUNT 5
#define TIME_INTERVAL 1

void get_local_ip(char *buffer, size_t size) {
    struct ifaddrs *addresses;
    if (getifaddrs(&addresses) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    
    for (struct ifaddrs *addr = addresses; addr != NULL; addr = addr->ifa_next) {
        if (addr->ifa_addr->sa_family == AF_INET) {
            inet_ntop(AF_INET, &((struct sockaddr_in *)addr->ifa_addr)->sin_addr, buffer, size);
            break;
        }
    }
    freeifaddrs(addresses);
}

void ping_host(const char *host) {
    char command[BUFFER_SIZE];
    sprintf(command, "ping -c %d %s", PING_COUNT, host);
    system(command);
}

void calculate_latency(const char *host) {
    char command[BUFFER_SIZE];
    sprintf(command, "ping -c %d -q %s", PING_COUNT, host);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(EXIT_FAILURE);
    }

    char result[BUFFER_SIZE];
    while (fgets(result, sizeof(result)-1, fp) != NULL) {
        if (strstr(result, "avg") != NULL) {
            printf("Average Latency to %s: %s", host, result);
            break;
        }
    }
    pclose(fp);
}

void print_qos_report(const char *ip) {
    printf("Quality of Service Report for IP: %s\n", ip);
    printf("Pinging...\n");
    ping_host(ip);
    sleep(TIME_INTERVAL);

    printf("Calculating latency...\n");
    calculate_latency(ip);
    printf("QoS monitoring finished.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname_or_IP>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char local_ip[INET_ADDRSTRLEN];
    get_local_ip(local_ip, sizeof(local_ip));
    printf("Local IP Address: %s\n", local_ip);

    char *target = argv[1];
    print_qos_report(target);
    
    return EXIT_SUCCESS;
}