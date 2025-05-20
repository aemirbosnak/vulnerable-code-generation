//FormAI DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PACKET_SIZE 64
#define MAX_WAIT_MS 1000

bool get_packet(int socket_fd, struct sockaddr *address, int address_len){
    ssize_t bytes_received;
    char rcv_buffer[PACKET_SIZE];
    struct sockaddr_in packet_address;
    socklen_t packet_address_len = sizeof(packet_address);

    bytes_received = recvfrom(socket_fd, rcv_buffer, PACKET_SIZE, MSG_WAITALL, (struct sockaddr*)&packet_address, &packet_address_len);

    if(bytes_received < 0){
        printf("ERROR: failed to receive packet from %s (%s)\n", inet_ntoa(packet_address.sin_addr), strerror(errno));
        return false;
    }

    struct icmp *icmp_packet = (struct icmp*)rcv_buffer;
    if(icmp_packet->icmp_type != ICMP_ECHOREPLY){
        printf("ERROR: invalid packet type received (expected type %d, received type %d)\n", ICMP_ECHOREPLY, icmp_packet->icmp_type);
        return false;
    }

    return true;
}

bool send_packet(int socket_fd, struct sockaddr *address, int address_len, uint16_t id, uint16_t sequence){
    char send_buffer[PACKET_SIZE];
    struct icmp *icmp_packet = (struct icmp*)send_buffer;

    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = id;
    icmp_packet->icmp_seq = sequence;
    memset(icmp_packet->icmp_data, (char)(sequence % 256), PACKET_SIZE - sizeof(struct icmp));

    ssize_t send_length = sendto(socket_fd, send_buffer, PACKET_SIZE, 0, address, address_len);

    if(send_length < 0){
        printf("ERROR: failed to send packet to %s (%s)\n", inet_ntoa(((struct sockaddr_in*)address)->sin_addr), strerror(errno));
        return false;
    }

    return true;
}

void ping_host(const char *host){
    struct in_addr addr;

    if(inet_aton(host, &addr) == 0){
        struct hostent *he;
        struct in_addr **addr_list;

        if((he = gethostbyname(host)) == NULL){
            printf("ERROR: failed to resolve %s (%s)\n", host, hstrerror(h_errno));
            return;
        }

        addr_list = (struct in_addr**)he->h_addr_list;
        addr = *addr_list[0];
    }

    printf("Pinging %s (%s)...\n", host, inet_ntoa(addr));

    struct timeval start_time, end_time, wait_time;
    int sent_count = 0, recv_count = 0;
    double min_time = MAX_WAIT_MS, max_time = 0.0, avg_time = 0.0;
    uint16_t id = rand() % UINT16_MAX;

    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(socket_fd < 0){
        printf("ERROR: could not open UDP socket (%s)\n", strerror(errno));
        return;
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr = addr;

    for(int seq_num = 0; seq_num < 10; seq_num++){
        if(!send_packet(socket_fd, (struct sockaddr*)&address, sizeof(address), id, seq_num)){
            continue;
        }
        sent_count++;

        gettimeofday(&start_time, NULL);
        
        fd_set input_fds;
        FD_ZERO(&input_fds);
        FD_SET(socket_fd, &input_fds);

        wait_time.tv_sec = MAX_WAIT_MS / 1000;
        wait_time.tv_usec = (MAX_WAIT_MS % 1000) * 1000;

        int activity = select(socket_fd + 1, &input_fds, NULL, NULL, &wait_time);
        gettimeofday(&end_time, NULL);
        recv_count += (bool)activity;

        double rtt_time = (double)(end_time.tv_sec - start_time.tv_sec) * 1000.0 + (double)(end_time.tv_usec - start_time.tv_usec) / 1000.0;

        if(activity > 0 && get_packet(socket_fd, (struct sockaddr*)&address, sizeof(address))){
            printf("%d bytes from %s seq=%d time=%.2f ms\n", PACKET_SIZE, inet_ntoa(addr), seq_num, rtt_time);
            if(rtt_time < min_time){
                min_time = rtt_time;
            }
            if(rtt_time > max_time){
                max_time = rtt_time;
            }
            avg_time = (double)((sent_count - 1) * avg_time + rtt_time) / (double)(sent_count);
        } else {
            printf("Request timed out.\n");
        }

        fflush(stdout);
        usleep(1000000);
    }

    close(socket_fd);

    double loss_rate = 100.0 * (double)(sent_count - recv_count) / (double)sent_count;
    printf("\n--- %s ping statistics ---\n", host);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n", sent_count, recv_count, loss_rate);
    printf("round-trip min/avg/max = %.2f/%.2f/%.2f ms\n", min_time, avg_time, max_time);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("USAGE: %s <hostname or IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping_host(argv[1]);

    return EXIT_SUCCESS;
}