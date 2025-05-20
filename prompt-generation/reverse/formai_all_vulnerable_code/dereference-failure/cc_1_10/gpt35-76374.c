//FormAI DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOPS 64
#define MAX_PACKET_SIZE 4096

char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con);
void send_packet(int sockfd, char *ping_msg, struct sockaddr_in *addr_con);
void receive_packet(int sockfd, struct sockaddr_in *addr_con, char *buffer, int timeout);

// Function to perform reverse lookup on the hostname
char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con) {
    struct hostent *host_entity;
    char *ip = (char *) malloc (INET_ADDRSTRLEN * sizeof(char));
    int i;

    if ((inet_pton(AF_INET, addr_host, &addr_con->sin_addr)) <= 0) {
        return NULL;
    }

    if ((host_entity = gethostbyaddr((char *)&addr_con->sin_addr, sizeof(addr_con->sin_addr), AF_INET)) == NULL) {
        return NULL;
    }

    strcpy(ip, inet_ntoa(*(struct in_addr *)host_entity->h_addr_list[0]));

    return ip;
}

// Function to send ping messages to the target
void send_packet(int sockfd, char *ping_msg, struct sockaddr_in *addr_con) {
    int msg_count;
    int i;
    int len = sizeof(addr_con);
    struct timeval tv_out;
    tv_out.tv_sec = 3;
    tv_out.tv_usec = 0;

    // Set timeout of 3 seconds for waiting for read function
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out)) < 0) {
        printf("\nError in setting socket options\n");
        return;
    }

    msg_count = 0;
    for (i = 0; i < sizeof(ping_msg) - 1; i++) {
        ping_msg[i] = i + '0';
    }

    ping_msg[i] = 0;

    while (msg_count < 7) {
        sendto(sockfd, ping_msg, sizeof(ping_msg), 0, (struct sockaddr *)addr_con, len);
        msg_count++;
    }
}

// Function to receive ping messages from the target
void receive_packet(int sockfd, struct sockaddr_in *addr_con, char *buffer, int timeout) {
    struct timeval tv_out;
    fd_set set;
    int i, len = sizeof(addr_con);
    tv_out.tv_sec = timeout;
    tv_out.tv_usec = 0;

    // Set timeout for 3 seconds for waiting for read function
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv_out, sizeof(tv_out)) < 0) {
        printf("\nError in setting socket options\n");
        return;
    }

    FD_ZERO(&set);
    FD_SET(sockfd, &set);

    if (select(sockfd + 1, &set, NULL, NULL, &tv_out) == 1) {
        recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)addr_con, &len);
    } else {
        printf("\nPacket Lost\n");
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAX_PACKET_SIZE];
    char *ip_addr, *reverse_hostname;
    int ttl = 1, hop_count = 1;
    struct sockaddr_in addr_con;
    struct icmp *icmp_req;
    struct timeval tv_out;

    if (argc != 2) {
        printf("\nInvalid Arguments\n");
        return -1;
    }

    // Create socket for sending and receiving data
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        printf("\nSocket file descriptor not received\n");
        return 1;
    }

    memset(&addr_con, 0, sizeof(addr_con));

    addr_con.sin_family = AF_INET;
    addr_con.sin_port = 0;
    addr_con.sin_addr.s_addr = inet_addr(argv[1]);

    // Perform reverse lookup on the target hostname
    reverse_hostname = dns_lookup(argv[1], &addr_con);

    // Print the target hostname and IP address
    printf("\nTarget Hostname: %s", reverse_hostname);
    printf("\nTarget IP: %s\n", argv[1]);

    while (ttl <= MAX_HOPS) {
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
        bzero(buffer, MAX_PACKET_SIZE);

        // Create ICMP request packet
        icmp_req = (struct icmp *)buffer;

        icmp_req->icmp_type = ICMP_ECHO;
        icmp_req->icmp_code = 0;
        icmp_req->icmp_id = getpid();
        icmp_req->icmp_seq = hop_count++;
        icmp_req->icmp_cksum = 0;
        icmp_req->icmp_cksum = htons((unsigned short) ~ (icmp_req->icmp_cksum));

        // Send ICMP request packet
        send_packet(sockfd, buffer, &addr_con);

        // Receive and print the response packet
        receive_packet(sockfd, &addr_con, buffer, 3);

        struct iphdr *iph = (struct iphdr *)buffer;
        struct sockaddr_in source_addr;

        source_addr.sin_addr.s_addr = iph->saddr;

        ip_addr = dns_lookup(inet_ntoa(source_addr.sin_addr), &addr_con);

        printf("%s", ip_addr);

        if (strcmp(ip_addr, reverse_hostname) == 0) {
            printf("\tReached Destination\n");
            break;
        } else {
            printf("\n");
        }

        // Increase the Time-to-live (TTL) value
        ttl++;
    }

    return 0;
}