//FormAI DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define ICMP_HEADER_SIZE 8
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define PACKET_SIZE 64
#define PORT_NUMBER 0
#define MAX_PACKET_SIZE 1024

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;
} icmp_hdr;

typedef struct {
    struct sockaddr_in address;
    int sockfd;
    int ttl;
    long rtt;
} ping_response;

uint16_t calculate_checksum(uint16_t *data, size_t size) {
    uint32_t sum = 0;
    while (size > 1) {
        sum += *data;
        data++;
        size -= sizeof(uint16_t);
    }
    if (size) {
        sum += *(uint8_t *)data;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

int send_ping(int sockfd, struct sockaddr_in *address, uint16_t id, uint16_t sequence) {
    char packet[MAX_PACKET_SIZE];
    icmp_hdr *icmp_hdr_ptr = (icmp_hdr *) packet;
    icmp_hdr_ptr->type = ICMP_ECHO_REQUEST;
    icmp_hdr_ptr->code = 0;
    icmp_hdr_ptr->id = id;
    icmp_hdr_ptr->sequence = sequence;
    icmp_hdr_ptr->checksum = 0;
    memset(packet + ICMP_HEADER_SIZE, rand() % 256, PACKET_SIZE - ICMP_HEADER_SIZE);
    icmp_hdr_ptr->checksum = calculate_checksum((uint16_t *) icmp_hdr_ptr, PACKET_SIZE);
    ssize_t bytes_sent = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *) address, sizeof(*address));
    return bytes_sent;
}

long receive_ping(int sockfd, uint16_t id, uint16_t sequence, struct sockaddr_in *address) {
    unsigned char buffer[MAX_PACKET_SIZE];
    uint8_t ttl = 255;
    struct timeval receive_time;
    ssize_t bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    gettimeofday(&receive_time, NULL);
    if (bytes_received > ICMP_HEADER_SIZE) {
        icmp_hdr *icmp_hdr_ptr = (icmp_hdr *) buffer;
        if (icmp_hdr_ptr->type == ICMP_ECHO_REPLY && icmp_hdr_ptr->id == id && icmp_hdr_ptr->sequence == sequence) {
            ping_response response;
            response.address = *address;
            response.sockfd = sockfd;
            response.ttl = ttl;
            response.rtt = (receive_time.tv_sec - receive_time.tv_sec) * 1000000 + (receive_time.tv_usec - receive_time.tv_usec);
            return response.rtt;
        }
    }
    return -1;
}

ping_response *ping(char *host) {
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    struct hostent *hostent_ptr = gethostbyname(host);
    if (hostent_ptr == NULL) {
        return NULL;
    }
    memcpy(&address.sin_addr.s_addr, hostent_ptr->h_addr_list[0], sizeof(address.sin_addr.s_addr));
    ping_response *response = (ping_response *) malloc(sizeof(ping_response));
    response->address = address;
    response->rtt = -1;
    response->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (response->sockfd < 0) {
        free(response);
        return NULL;
    }
    int ttl = 255;
    setsockopt(response->sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
    struct timeval timeout = {1, 0};
    setsockopt(response->sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &timeout, sizeof(timeout));
    uint16_t id = (uint16_t) getpid();
    uint16_t sequence = 0;
    int send_status = send_ping(response->sockfd, &address, id, sequence);
    if (send_status < 0) {
        close(response->sockfd);
        free(response);
        return NULL;
    }
    long rtt_usec = receive_ping(response->sockfd, id, sequence, &address);
    if (rtt_usec < 0) {
        close(response->sockfd);
        free(response);
        return NULL;
    }
    response->rtt = rtt_usec;
    return response;
}

int main() {
    char *host = "google.com";
    ping_response *response = ping(host);
    if (response) {
        printf("Ping Success on %s (%s), RTT:%ldus\n", host, inet_ntoa(response->address.sin_addr), response->rtt);
        free(response);
    } else {
        printf("Ping Failed on %s\n", host);
    }
    return 0;
}