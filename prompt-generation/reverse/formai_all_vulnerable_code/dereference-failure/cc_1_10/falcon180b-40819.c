//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <pcap.h>
#include <pthread.h>

#define MAX_PKT_SIZE 65535
#define MAX_FILTER_STR_LEN 100

typedef struct {
    bool is_running;
    pthread_t thread_id;
    pcap_t *pcap_handle;
    char filter_str[MAX_FILTER_STR_LEN];
    int pkt_count;
} PacketMonitor;

void packet_handler(u_char *user, const struct pcap_pkthdr *h, const u_char *pkt_data) {
    PacketMonitor *monitor = (PacketMonitor *) user;
    monitor->pkt_count++;
}

int start_monitor(PacketMonitor *monitor) {
    char errbuf[PCAP_ERRBUF_SIZE];
    monitor->pcap_handle = pcap_open_live(monitor->filter_str, BUFSIZ, 1, 0, errbuf);
    if (monitor->pcap_handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        return -1;
    }

    pcap_loop(monitor->pcap_handle, -1, packet_handler, (u_char *) monitor);

    pcap_close(monitor->pcap_handle);
    return 0;
}

int stop_monitor(PacketMonitor *monitor) {
    monitor->is_running = false;
    return 0;
}

int main(int argc, char *argv[]) {
    PacketMonitor monitor;
    memset(&monitor, 0, sizeof(PacketMonitor));

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <capture_device> <filter_string>\n", argv[0]);
        return -1;
    }

    strncpy(monitor.filter_str, argv[2], MAX_FILTER_STR_LEN - 1);
    monitor.filter_str[MAX_FILTER_STR_LEN - 1] = '\0';

    pthread_create(&monitor.thread_id, NULL, start_monitor, &monitor);

    while (monitor.is_running) {
        sleep(1);
    }

    pthread_join(monitor.thread_id, NULL);

    printf("Total packets captured: %d\n", monitor.pkt_count);

    return 0;
}