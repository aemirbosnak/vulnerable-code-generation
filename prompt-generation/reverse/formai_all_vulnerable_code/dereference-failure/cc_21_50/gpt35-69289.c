//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 1024
#define MAX_HOSTNAME 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Open a raw socket
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set the receiving timeout to 5 seconds
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Resolve the target IP address to hostname
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(0);
    if (inet_pton(AF_INET, argv[1], &address.sin_addr) < 0) {
        perror("inet_pton");
        return 1;
    }

    struct hostent *host = gethostbyaddr((const char*)&address.sin_addr, sizeof(address.sin_addr), AF_INET);
    if (host == NULL) {
        printf("%s\n", argv[1]);
    } else {
        printf("%s (%s)\n", host->h_name, argv[1]);
    }

    // Send ICMP echo requests with increasing TTL
    char buffer[64];
    memset(buffer, 0, sizeof(buffer));
    buffer[0] = 8; // Type
    buffer[1] = 0; // Code
    buffer[2] = 0; // Checksum (filled in later)
    buffer[3] = 0;
    buffer[4] = 0; // Identifier (arbitrary)
    buffer[5] = 1;
    buffer[6] = 0; // Sequence number (arbitrary)
    buffer[7] = 1;
    int size = 8;
    int ttl = 1;

    struct sockaddr_in recipient;
    recipient.sin_family = AF_INET;
    recipient.sin_port = htons(0);

    int num_hosts = 0;
    char hosts[MAX_HOSTS][MAX_HOSTNAME];

    while (ttl < 30 && num_hosts < MAX_HOSTS) {
        recipient.sin_addr = address.sin_addr;

        // Set TTL for outgoing packets
        if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
            perror("setsockopt");
            return 1;
        }

        // Send the echo request
        unsigned short *p_checksum = (unsigned short*)&buffer[2];
        *p_checksum = 0;
        unsigned int checksum = 0;
        for (int i = 0; i < size; i += 2) {
            checksum += (unsigned short)buffer[i] << 8 | buffer[i + 1];
        }
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
        checksum = ~checksum;
        *p_checksum = htons((unsigned short)checksum);
        if (sendto(sock, buffer, size, 0, (struct sockaddr*)&recipient, sizeof(recipient)) < 0) {
            perror("sendto");
            return 1;
        }

        // Receive the echo replies
        while (1) {
            struct sockaddr_in sender;
            socklen_t sender_len = sizeof(sender);
            int recv_size = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender, &sender_len);
            if (recv_size < 0) {
                break; // No more replies within timeout
            }

            // Parse the ICMP header
            unsigned char *p_header = (unsigned char*)buffer;
            if (p_header[0] == 0 && p_header[1] == 0) { // Echo reply
                char *ip = inet_ntoa(sender.sin_addr);
                if (strcmp(ip, argv[1]) != 0) { // Ignore own IP address
                    struct hostent *host = gethostbyaddr((const char*)&sender.sin_addr, sizeof(sender.sin_addr), AF_INET);
                    if (host == NULL) {
                        strncpy(hosts[num_hosts++], ip, MAX_HOSTNAME);
                        printf("%s (%s)\n", ip, ip);
                    } else {
                        strncpy(hosts[num_hosts++], host->h_name, MAX_HOSTNAME);
                        printf("%s (%s)\n", host->h_name, ip);
                    }
                }
            } else if (p_header[0] == 11 && p_header[1] == 0) { // TTL exceeded
                char *ip = inet_ntoa(sender.sin_addr);
                if (strcmp(ip, argv[1]) != 0) { // Ignore own IP address
                    struct hostent *host = gethostbyaddr((const char*)&sender.sin_addr, sizeof(sender.sin_addr), AF_INET);
                    if (host == NULL) {
                        strncpy(hosts[num_hosts++], ip, MAX_HOSTNAME);
                        printf("%s (%s) [TTL=%d]\n", ip, ip, ttl);
                    } else {
                        strncpy(hosts[num_hosts++], host->h_name, MAX_HOSTNAME);
                        printf("%s (%s) [TTL=%d]\n", host->h_name, ip, ttl);
                    }
                }
            }
        }

        ttl++;
        size += 8;
    }

    // Print the list of hosts discovered
    if (num_hosts > 0) {
        printf("\nHosts discovered:\n");
        for (int i = 0; i < num_hosts; i++) {
            printf("%s\n", hosts[i]);
        }
    }

    close(sock);

    return 0;
}