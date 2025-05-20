//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_PACKET_SIZE 4096
#define ETH_LEN 14
#define IP_LEN 20
#define UDP_LEN 8

int stop_signal = 0;
int timeout = 5;
char *interface = "wlan0";

struct in_addr source_ip;
struct in_addr dest_ip;

struct thread_data {
    int thread_id;
    int sock_fd;
    uint8_t *packet;
    size_t packet_len;
};

void sig_int_handler(int signum)
{
    stop_signal = 1;
}

void *send_packets(void *data)
{
    struct thread_data *thread_data = (struct thread_data*)data;
    int sock_fd = thread_data->sock_fd;

    while (!stop_signal) {
        if(send(sock_fd, thread_data->packet, thread_data->packet_len, 0) < 0) {
            perror("send");
            break;
        }
        sleep(timeout);
    }

    close(sock_fd);
    free(thread_data->packet);
    free(thread_data);

    pthread_exit(NULL);
}

void *recv_packets(void *data)
{
    int sock_fd = (int)(intptr_t)data;
    char buffer[MAX_PACKET_SIZE];

    while(!stop_signal) {
        struct sockaddr_in src_addr;
        socklen_t addrlen = sizeof(src_addr);
        int num_bytes = recvfrom(sock_fd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&src_addr, &addrlen);

        if(num_bytes < 0) {
            if(errno != EINTR) {
                perror("recvfrom");
                break;
            }
        } else {
            uint8_t *eth_pkt = (uint8_t*)buffer;

            // Check Ethernet protocol
            uint16_t protocol = (uint16_t)eth_pkt[12] << 8 | eth_pkt[13];

            if(protocol == ETH_P_IP) {
                uint8_t *ip_pkt = &eth_pkt[ETH_LEN];

                // Check IP protocol
                uint8_t ip_hdr_len = ip_pkt[0] & 0x0F;
                uint8_t ip_proto = ip_pkt[9];

                if(ip_proto == IPPROTO_UDP) {
                    uint16_t src_port = ntohs(*((uint16_t*)&ip_pkt[ip_hdr_len + 0]));
                    uint16_t dst_port = ntohs(*((uint16_t*)&ip_pkt[ip_hdr_len + 2]));

                    // Check for packet from source to destination
                    if(memcmp(&((struct in_addr*)&ip_pkt[12])->s_addr, &source_ip.s_addr, sizeof(source_ip.s_addr)) == 0 &&
                       memcmp(&((struct in_addr*)&ip_pkt[16])->s_addr, &dest_ip.s_addr, sizeof(dest_ip.s_addr)) == 0 &&
                       src_port == 1234 && dst_port == 5678) {

                        uint8_t *udp_pkt = &ip_pkt[ip_hdr_len + UDP_LEN];

                        printf("Received packet from IP: %s, Signal Strength: %d dBm\n",
                            inet_ntoa(*(struct in_addr *)&ip_pkt[12]),
                            (int8_t)*(udp_pkt + 6));
                    }
                }
            }
        }
    }

    close(sock_fd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <source_IP> <destination_IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inet_aton(argv[1], &source_ip);
    inet_aton(argv[2], &dest_ip);

    int sock_fd;
    if((sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set network interface
    if(setsockopt(sock_fd, SOL_SOCKET, SO_BINDTODEVICE, interface, strlen(interface)) < 0) {
        perror("setsockopt");
        goto error;
    }

    // Set IP_HDRINCL to enable sending custom IP headers
    int one = 1;
    if(setsockopt(sock_fd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
        perror("setsockopt");
        goto error;
    }

    // Disable kernel mode address resolution
    int zero = 0;
    if(setsockopt(sock_fd, IPPROTO_IP, IP_RECVERR, &zero, sizeof(zero)) < 0) {
        perror("setsockopt");
        goto error;
    }

    // Bind to local address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        goto error;
    }

    // Set signal handler for SIGINT
    struct sigaction sig_int;
    memset(&sig_int, 0, sizeof(sig_int));
    sig_int.sa_handler = &sig_int_handler;

    if(sigaction(SIGINT, &sig_int, NULL) < 0) {
        perror("sigaction");
        goto error;
    }

    // Construct UDP packet
    uint8_t udp_pkt[] = {
        0x30, 0x39, 0x01, 0xc3, 0x00, 0x7c, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x51, 0x04, 0xb8, 0x33,
        0x22, 0xff, 0x05, 0x00, 0x06, 0xec, 0xa4, 0x66,
        0x23, 0x7a, 0x00, 0x00, 0x00, 0x00
    };

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = dest_ip;
    dest_addr.sin_port = htons(5678);

    // Create send/receive threads
    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->sock_fd = sock_fd;

        // Randomize packet timestamp
        srand(time(NULL));
        uint32_t random_time = rand() % 100;

        udp_pkt[0] = (uint8_t)(0x30 + random_time);
        udp_pkt[1] = (uint8_t)(0x39 + random_time);

        uint8_t *ip_pkt = (uint8_t*)malloc(IP_LEN + UDP_LEN + sizeof(udp_pkt));
        memset(ip_pkt, 0, IP_LEN + UDP_LEN + sizeof(udp_pkt));

        ip_pkt[0] = 0x45; // IPv4, Header Length = 20 bytes
        ip_pkt[1] = 0x00; // Type of Service
        *((uint16_t*)&ip_pkt[2]) = htons(IP_LEN + UDP_LEN + sizeof(udp_pkt)); // Total Length
        *((uint16_t*)&ip_pkt[4]) = 0x0000; // Identification
        ip_pkt[6] = 0x00; ip_pkt[7] = 0x00; // Flags and Fragment Offset
        ip_pkt[8] = 0x40; // Time To Live
        ip_pkt[9] = IPPROTO_UDP; // Protocol = UDP
        *((uint16_t*)&ip_pkt[10]) = 0x0000; // Header Checksum (will be computed by kernel)
        *((struct in_addr*)&ip_pkt[12]) = source_ip; // Source Address
        *((struct in_addr*)&ip_pkt[16]) = dest_ip; // Destination Address

        uint16_t udp_len = UDP_LEN + sizeof(udp_pkt);
        uint16_t udp_checksum = 0;

        uint16_t *src_port = (uint16_t*)&ip_pkt[20];
        *src_port = htons(1234);
        uint16_t *dst_port = (uint16_t*)&ip_pkt[22];
        *dst_port = htons(5678);
        *((uint16_t*)&ip_pkt[24]) = htons(udp_len); // UDP Length
        *((uint16_t*)&ip_pkt[26]) = udp_checksum; // UDP Checksum (not used)

        memcpy(&ip_pkt[IP_LEN + UDP_LEN], udp_pkt, sizeof(udp_pkt));

        data->packet = ip_pkt;
        data->packet_len = IP_LEN + UDP_LEN + sizeof(udp_pkt);

        if(pthread_create(&threads[i], NULL, send_packets, (void*)data) < 0) {
            perror("pthread_create");
            goto error;
        }
    }

    if(pthread_create(&threads[NUM_THREADS], NULL, recv_packets, (void *)(intptr_t)sock_fd) < 0) {
        perror("pthread_create");
        goto error;
    }

    for(int i = 0; i < NUM_THREADS + 1; i++) {
        if(pthread_join(threads[i], NULL) < 0) {
            perror("pthread_join");
            goto error;
        }
    }

    close(sock_fd);
    exit(EXIT_SUCCESS);

error:
    close(sock_fd);
    exit(EXIT_FAILURE);
}