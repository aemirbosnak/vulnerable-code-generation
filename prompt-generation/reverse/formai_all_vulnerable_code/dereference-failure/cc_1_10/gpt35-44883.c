//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65536
#define MAX_CONNECTIONS 100

int socket_fd;
char *target_ip;
int target_port;
struct sockaddr_in target_addr;
struct connection_info {
    char *ip;
    int port;
};
struct connection_info connections[MAX_CONNECTIONS];
int num_connections = 0;

int add_connection(char *ip, int port) {
    if (num_connections == MAX_CONNECTIONS) {
        return -1;
    }
    connections[num_connections].ip = ip;
    connections[num_connections].port = port;
    num_connections++;
    return 0;
}

int handle_packet(char *packet, int packet_size, struct sockaddr_in *src_addr) {
    struct iphdr *ip_header = (struct iphdr*) packet;
    int header_len = ip_header->ihl * 4;
    struct tcphdr *tcp_header = (struct tcphdr*) (packet + header_len);
    struct udphdr *udp_header = (struct udphdr*) (packet + header_len);
    struct icmphdr *icmp_header = (struct icmphdr*) (packet + header_len);

    if (ip_header->protocol == IPPROTO_TCP) {
        for (int i = 0; i < num_connections; i++) {
            if (strcmp(inet_ntoa(src_addr->sin_addr), connections[i].ip) == 0
                && ntohs(tcp_header->source) == connections[i].port) {
                printf("Blocked connection from %s:%d\n", inet_ntoa(src_addr->sin_addr), ntohs(tcp_header->source));
                return 1;
            }
        }
        return 0;
    } else if (ip_header->protocol == IPPROTO_UDP) {
        // Implement UDP firewall rules here
        return 0;
    } else if (ip_header->protocol == IPPROTO_ICMP) {
        // Implement ICMP firewall rules here
        return 0;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    uint8_t buffer[MAX_PACKET_SIZE];

    if (argc != 3) {
        printf("Usage: %s <target IP> <target port>\n", argv[0]);
        exit(1);
    }

    target_ip = argv[1];
    target_port = atoi(argv[2]);

    if ((socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    if (inet_aton(target_ip, &target_addr.sin_addr) == 0) {
        printf("Invalid IP address: %s\n", target_ip);
        exit(1);
    }

    while (1) {
        ssize_t packet_size = recv(socket_fd, buffer, MAX_PACKET_SIZE, 0);
        if (packet_size == -1 && errno == EINTR) {
            continue;
        } else if (packet_size < 0) {
            perror("Error while receiving packet");
            continue;
        }
        struct sockaddr_in src_addr;
        socklen_t addr_len = sizeof(src_addr);
        if (getsockname(socket_fd, (struct sockaddr*) &src_addr, &addr_len) < 0) {
            perror("Failed to get source address of socket");
            continue;
        }
        if (handle_packet(buffer, packet_size, &src_addr)) {
            continue;
        }
        if (sendto(socket_fd, buffer, packet_size, 0, (struct sockaddr*) &target_addr, sizeof(target_addr)) < 0) {
            perror("Failed to resend packet");
            continue;
        }
    }
    return 0;
}