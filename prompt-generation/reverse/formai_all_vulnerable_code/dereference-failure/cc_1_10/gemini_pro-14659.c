//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: energetic
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Let's rock the firewall world with our super-charged C program!

// Our firewall's superpowers:
#define BLOCKED_PORTS  "25,110,143,465,587"  // Ports we'll keep a watchful eye on
#define MAX_CONNECTIONS 10                 // Maximum number of concurrent connections allowed

// Our firewall's fortress:
struct firewall_config {
    int sockfd;
    char *blocked_ports;
    int max_connections;
};

void die(char *msg) {
    perror(msg);
    exit(1);
}

int parse_blocked_ports(char *ports, char *parsed_ports[]) {
    char *port_str = strtok(strdup(ports), ",");
    int num_ports = 0;
    while (port_str) {
        parsed_ports[num_ports++] = port_str;
        port_str = strtok(NULL, ",");
    }
    return num_ports;
}

void handle_connection(struct firewall_config *fwc, int client_sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Receive incoming data for inspection
    char recv_buf[256];
    int recv_len = recvfrom(client_sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) &client_addr, &client_addr_len);
    if (recv_len < 0) { die("Error receiving data"); }

    // Check if connection is trying to break through our blocked ports
    struct iphdr *ip_hdr = (struct iphdr *) recv_buf;
    if (ip_hdr->protocol == IPPROTO_UDP) {
        struct udphdr *udp_hdr = (struct udphdr *) (recv_buf + (ip_hdr->ihl * 4));
        int port = ntohs(udp_hdr->uh_dport);
        for (int i = 0; i < fwc->max_connections; i++) {
            if (!strcmp(fwc->blocked_ports, port)) {
                sendto(client_sockfd, "Connection refused", 17, 0, (struct sockaddr *) &client_addr, client_addr_len);
                close(client_sockfd);
                return;
            }
        }
    }

    // Connection passed our security checks, so proceed as usual
    sendto(client_sockfd, recv_buf, recv_len, 0, (struct sockaddr *) &client_addr, client_addr_len);
    close(client_sockfd);
}

int main() {
    // Construct our firewall configuration
    struct firewall_config fwc;
    fwc.blocked_ports = BLOCKED_PORTS;
    fwc.max_connections = MAX_CONNECTIONS;

    // Become a firewall master with our mighty socket
    fwc.sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if (fwc.sockfd < 0) die("Error creating socket");

    // Bind our socket to the firewall's throne
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(0);

    if (bind(fwc.sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) die("Error binding socket");

    // Let the firewall reign supreme, guarding the realm from evil packets
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        // Accept incoming connections and handle them with grace
        int client_sockfd = accept(fwc.sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) { die("Error accepting connection"); }

        // Spawn a firewall champion to deal with the connection
        if (!fork()) handle_connection(&fwc, client_sockfd);
        close(client_sockfd);
    }

    return 0;
}