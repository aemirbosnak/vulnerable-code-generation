//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/socket.h>

#define BUFFER_SIZE 65536
#define BLOCKED_IP "192.168.1.10"  // Your desired blocked IP address

// Function to calculate the checksum of the packet
unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to check if the packet should be blocked
int should_block(struct iphdr *ip_header) {
    char source_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip_header->saddr), source_ip, INET_ADDRSTRLEN);
    printf("Packet from: %s\n", source_ip);
    
    return strcmp(source_ip, BLOCKED_IP) == 0;
}

int main() {
    int sock_raw;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    char *buffer = (char *)malloc(BUFFER_SIZE);

    // Create a raw socket that listens to IP packets 
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket creation failed");
        return 1;
    }

    printf("Firewall is running. Listening for packets...\n");

    // Infinite loop to keep the firewall running
    while (1) {
        // Receive packets and store in buffer
        ssize_t packet_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t *)&saddr_len);
        if (packet_size < 0) {
            perror("Packet receive failed");
            continue;
        }
        
        struct iphdr *ip_header = (struct iphdr *)buffer;

        // Check if the packet should be blocked
        if (should_block(ip_header)) {
            printf("Blocked packet from %s\n", BLOCKED_IP);
            // Normally, we would drop the packet here but in raw socket mode, we cannot do that.
            // In a real firewall, you would handle packet dropping and logging.
        } else {
            printf("Allowed packet from %s\n", BLOCKED_IP);
        }
        
        // To prevent the program from getting too fast and flooding the output
        sleep(1);
    }

    close(sock_raw);
    free(buffer);
    return 0;
}