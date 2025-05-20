//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_HOPS 30
#define MAX_PACKET_SIZE 1024

typedef struct {
    struct sockaddr_in addr;
    int hops;
} Host;

Host* hosts[MAX_HOPS];
int num_hosts = 0;

int sockfd;

void usage() {
    printf("Usage: ./ntm <target IP address>\n");
    exit(1);
}

int create_socket() {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    return sockfd;
}

int set_TTL(int sockfd, int hops) {
    int ttl = hops;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("Error setting TTL");
        exit(1);
    }
    return ttl;
}

int send_ping(struct sockaddr_in* addr, int hops) {
    char packet[MAX_PACKET_SIZE];
    struct timeval timeout;
    fd_set readfds;
    int nbytes;

    // Send ping request
    sprintf(packet, "PING %d", hops);
    nbytes = sendto(sockfd, packet, strlen(packet), 0, (struct sockaddr*)addr, sizeof(*addr));
    if (nbytes < 0) {
        perror("Error sending ping request");
        return -1;
    }

    // Set timeout
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    // Wait for ping response
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) < 0) {
        perror("Error waiting for ping response");
        return -1;
    }

    // Receive ping response
    if (FD_ISSET(sockfd, &readfds)) {
        nbytes = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (nbytes < 0) {
            perror("Error receiving ping response");
            return -1;
        }
        packet[nbytes] = '\0';
        printf("%s\n", packet);
        return 0;
    } else {
        printf("Request timed out.\n");
        return -1;
    }
}

void add_host(struct sockaddr_in* addr, int hops) {
    Host* host = malloc(sizeof(Host));
    host->addr = *addr;
    host->hops = hops;
    hosts[num_hosts++] = host;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage();
    }

    struct sockaddr_in target_addr;
    if (inet_pton(AF_INET, argv[1], &target_addr.sin_addr) != 1) {
        perror("Error converting target IP address");
        exit(1);
    }
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(0);

    sockfd = create_socket();

    for (int hops = 1; hops <= MAX_HOPS; hops++) {
        int ttl = set_TTL(sockfd, hops);

        if (send_ping(&target_addr, hops) == 0) {
            break;
        }

        struct sockaddr_in recv_addr;
        socklen_t recv_addr_len = sizeof(recv_addr);
        char recv_buffer[MAX_PACKET_SIZE];
        int nbytes = recvfrom(sockfd, recv_buffer, MAX_PACKET_SIZE, 0, (struct sockaddr*)&recv_addr, &recv_addr_len);
        if (nbytes < 0) {
            perror("Error receiving ICMP error message");
            continue;
        }

        if (recv_addr.sin_addr.s_addr == target_addr.sin_addr.s_addr) {
            break;
        }

        add_host(&recv_addr, hops);
    }

    for (int i = 0; i < num_hosts; i++) {
        Host* host = hosts[i];
        printf("%d hops to %s\n", host->hops, inet_ntoa(host->addr.sin_addr));
    }

    close(sockfd);
    return 0;
}