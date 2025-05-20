//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SNAPLEN 1518

static volatile int running = 1;

static void signal_handler(int sig) {
    running = 0;
}

int main(int argc, char **argv) {
    char *device = NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    struct pcap_pkthdr *header = NULL;
    const u_char *packet = NULL;
    int socket_fd = -1;
    struct sockaddr_in addr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    device = argv[1];

    if ((handle = pcap_open_live(device, SNAPLEN, 1, 0, errbuf)) == NULL) {
        fprintf(stderr, "pcap_open_live: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    if ((socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, signal_handler);

    while (running) {
        if ((header = pcap_next(handle, &packet)) == NULL) {
            continue;
        }

        if (sendto(socket_fd, packet, header->len, 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("sendto");
        }
    }

    pcap_close(handle);
    close(socket_fd);

    return EXIT_SUCCESS;
}