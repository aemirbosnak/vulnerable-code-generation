//FormAI DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 5

char* WHAT_THE_PING[] = {
    "You call that a ping?! My grandma could ping faster than that!",
    "Hey, are you pinging from Mars or something?",
    "I bet you're using a potato for a modem",
    "Do you need me to lend you some bandwidth?",
    "Ping me once, shame on you. Ping me twice, shame on your internet.",
    "I'm starting to think you're pinging a rock instead of a server",
    "Did you forget to plug in your Ethernet cable?",
    "Your ping just gave me a midlife crisis.",
    "I haven't seen a ping this bad since the 90s"
};

int pack_num = 0;
int sent_count = 0;
int recv_count = 0;
int sockfd = 0;
pid_t pid = 0;

struct sockaddr_in dest_addr;

bool is_same_addr(const struct sockaddr_in* addr1, const struct sockaddr_in* addr2) {
    return memcmp(&addr1->sin_addr, &addr2->sin_addr, sizeof(addr1->sin_addr)) == 0;
}

unsigned short get_checksum(unsigned short* buffer, int size) {
    unsigned long cksum = 0;
    while (size > 1) {
        cksum += *buffer++;
        size -= sizeof(unsigned short);
    }
    if (size) {
        cksum += *(unsigned char*)buffer;
    }
    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);
    return (unsigned short)(~cksum);
}

void send_packet() {
    char packet[PACKET_SIZE];
    struct icmp* icmp_hdr = (struct icmp*)packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = pid;
    icmp_hdr->icmp_seq = pack_num++;
    memset(icmp_hdr->icmp_data, 'E', PACKET_SIZE - sizeof(struct icmp));
    icmp_hdr->icmp_cksum = get_checksum((unsigned short*)icmp_hdr, PACKET_SIZE);
    int res = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
    if (res < 0) {
        printf("Failed to send packet. Error code: %d\n", res);
    }
    sent_count++;
}

void recv_packet() {
    char buffer[PACKET_SIZE];
    memset(buffer, 0, PACKET_SIZE);
    struct sockaddr_in from;
    socklen_t from_len = sizeof(from);
    int res = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr*)&from, &from_len);
    if (res < 0) {
        printf("Failed to receive packet. Error code: %d\n", res);
    }
    if (is_same_addr(&from, &dest_addr)) {
        struct iphdr* ip_hdr = (struct iphdr*)buffer;
        struct icmp* icmp_hdr = (struct icmp*)(buffer + (ip_hdr->ihl << 2));
        if (icmp_hdr->icmp_type == ICMP_ECHOREPLY && icmp_hdr->icmp_id == pid) {
            recv_count++;
            printf("PING: %d bytes from %s: icmp_seq=%d ttl=%d time=%d ms\n", PACKET_SIZE, inet_ntoa(from.sin_addr), icmp_hdr->icmp_seq, ip_hdr->ttl, rand() % 100 + 1);
            printf("%s\n", WHAT_THE_PING[rand() % 9]);
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <hostname/ip address>\n", argv[0]);
        return -1;
    }
    struct hostent* host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Failed to resolve hostname. Error code: %d\n", h_errno);
        return -1;
    }
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Failed to create socket. Error code: %d\n", sockfd);
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    memcpy(&dest_addr.sin_addr, host->h_addr, host->h_length);
    pid = getpid();
    while (sent_count < 10) {
        send_packet();
        recv_packet();
        sleep(rand() % MAX_WAIT_TIME + 1);
    }
    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d packets received, %.0f%% packet loss\n", sent_count, recv_count, (float)(sent_count - recv_count) / sent_count * 100);
    close(sockfd);
    return 0;
}