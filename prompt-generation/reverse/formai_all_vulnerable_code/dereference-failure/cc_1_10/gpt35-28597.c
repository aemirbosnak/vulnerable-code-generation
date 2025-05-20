//FormAI DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PING_TIMEOUT 1  // 1 second timeout for ping response
#define MAX_PING_LEN 100  // maximum length of the ping reply message
#define MAX_HOPS 30  // maximum number of hops for the ping test

// Recursive function to perform ping test
int ping_test(char* dest_ip, int ttl) {
    struct sockaddr_in server_addr;
    struct timeval tv;
    int sock, status, rtt, len, icmp_type, icmp_code;
    char ping_msg[MAX_PING_LEN];
    char recv_buf[MAX_PING_LEN];
    fd_set readfds;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0 ) {
        perror("socket error");
        return -1;
    }
    
    // Set timeout for socket
    tv.tv_sec = PING_TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    // Set TTL value for IP packet
    setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));
    
    // Set ping message
    snprintf(ping_msg, MAX_PING_LEN, "PING %s: ttl=%d\n", dest_ip, ttl);
    
    // Send ping message
    if ((status = sendto(sock, ping_msg, strlen(ping_msg), 0, (struct sockaddr*)&server_addr, sizeof(server_addr))) < 0) {
        perror("sendto error");
        close(sock);
        return -1;
    }

    // Initialize FD set for select
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    
    // Wait for response or timeout
    if (select(sock+1, &readfds, NULL, NULL, &tv) < 0) {
        perror("select error");
        close(sock);
        return -1;
    }
    
    if (FD_ISSET(sock, &readfds)) {
        // Ping response received
        len = sizeof(server_addr);
        
        // Receive ping reply message
        if ((status = recvfrom(sock, recv_buf, MAX_PING_LEN, 0, (struct sockaddr*)&server_addr, &len)) < 0) {
            perror("recvfrom error");
            close(sock);
            return -1;
        }
        
        // Extract ICMP type and code from reply message
        icmp_type = recv_buf[20];
        icmp_code = recv_buf[21];
        
        if (icmp_type == 0 && icmp_code == 0) {
            // Ping successful
            printf("PING %s: ttl=%d, rtt=%d\n", dest_ip, ttl, rtt);
            close(sock);
            return 1;
        } else {
            // Ping failed (received ICMP error message)
            close(sock);
            return 0;
        }
    } else {
        // Ping timed out
        close(sock);
        return 0;
    }
}

int main(int argc, char* argv[]) {
    char* dest_ip;
    int ttl;
    
    if (argc != 3) {
        printf("Usage: %s <destination_ip> <initial_ttl>\n", argv[0]);
        return -1;
    }
    
    dest_ip = argv[1];
    ttl = atoi(argv[2]);
    
    if (ttl > MAX_HOPS) {
        printf("Maximum number of hops exceeded\n");
        return -1;
    }
    
    printf("Starting ping test for %s with initial TTL=%d\n", dest_ip, ttl);
    
    // Call recursive function to perform ping test
    ping_test(dest_ip, ttl);
    
    return 0;
}