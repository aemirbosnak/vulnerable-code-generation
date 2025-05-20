//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <time.h>

#define MAX_INTERVAL 5
#define MAX_RETRANSMITS 10
#define TARGET_IP "8.8.8.8" // Example target (Google DNS)

typedef struct {
    char interface[20];
    unsigned long sent_packets;
    unsigned long received_packets;
    unsigned long lost_packets;
    double send_time;
    double receive_time;
    double latency;
} QosData;

void get_interface() {
    struct ifaddrs *ifaddr, *ifa;
    char addr[INET_ADDRSTRLEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("Available network interfaces:\n");
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, addr, sizeof(addr));
            printf("Interface: %s \t Address: %s\n", ifa->ifa_name, addr);
        }
    }
    freeifaddrs(ifaddr);
}

double calc_latency(double start_time, double end_time) {
    return (end_time - start_time) * 1000; // Convert to milliseconds
}

int ping_target(const char *ip_address) {
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(0);
    inet_pton(AF_INET, ip_address, &target.sin_addr);

    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    char packet[64] = {0}; 
    struct timeval start, end;
    unsigned short seq = 0;

    for (int i = 0; i < MAX_RETRANSMITS; i++) {
        gettimeofday(&start, NULL);
        if (sendto(sock, packet, sizeof(packet), 0, (struct sockaddr*)&target, sizeof(target)) == -1) {
            perror("sendto");
            close(sock);
            return -1;
        }
        seq++;

        fd_set read_fds;
        struct timeval tv;
        tv.tv_sec = 1; // 1 second timeout
        tv.tv_usec = 0;

        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);

        int status = select(sock + 1, &read_fds, NULL, NULL, &tv);
        if (status > 0) {
            gettimeofday(&end, NULL);
            double latency = calc_latency(start.tv_sec + start.tv_usec / 1e6, end.tv_sec + end.tv_usec / 1e6);
            printf("Ping %d -> %s: %.2f ms\n", seq, ip_address, latency);
        } else if (status == 0) {
            printf("Ping %d -> %s: Time Out\n", seq, ip_address);
        } else {
            perror("select");
        }
        usleep(1000000); // Sleep for 1 second between pings
    }
    close(sock);
    return 0;
}

void qos_monitor(QosData *data) {
    data->send_time = 0;
    data->receive_time = 0;
    data->sent_packets = 0;
    data->received_packets = 0;
    data->lost_packets = 0;
    printf("Starting QoS Monitor...\n");
    while (1) {
        ping_target(TARGET_IP);
        printf("Monitoring interface: %s\n", data->interface);
        data->sent_packets += MAX_RETRANSMITS; // Assume all packets sent
        sleep(MAX_INTERVAL);
    }
}

int main() {
    QosData data;
    strcpy(data.interface, "eth0"); // Replace with desired interface
    get_interface();
    qos_monitor(&data);
    return 0;
}