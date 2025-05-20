//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define PACKET_SIZE 65535

typedef struct {
    pcap_t *handle;
    int sockfd;
    struct sockaddr_in addr;
} thread_args;

void *packet_handler(void *args) {
    thread_args *arg = (thread_args *)args;
    char packet[PACKET_SIZE];
    while (1) {
        int len = pcap_next_ex(arg->handle, NULL, (const u_char **)&packet);
        if (len == -1) {
            perror("pcap_next_ex");
            break;
        } else if (len == 0) {
            continue;
        }
        sendto(arg->sockfd, packet, len, 0, (struct sockaddr *)&arg->addr, sizeof(arg->addr));
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <interface> <ip address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char *ip_addr = argv[2];
    int port = atoi(argv[3]);

    pcap_t *handle = pcap_open_live(interface, PACKET_SIZE, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);

    thread_args args;
    args.handle = handle;
    args.sockfd = sockfd;
    args.addr = addr;

    pthread_t tid;
    if (pthread_create(&tid, NULL, packet_handler, &args) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    pthread_join(tid, NULL);

    pcap_close(handle);
    close(sockfd);

    return EXIT_SUCCESS;
}