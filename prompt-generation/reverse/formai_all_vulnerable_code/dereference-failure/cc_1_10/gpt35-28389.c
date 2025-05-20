//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void print_header() {
    printf("\n###############################\n");
    printf("##                           ##\n");
    printf("##     HAPPY PING PROGRAM    ##\n");
    printf("##                           ##\n");
    printf("###############################\n\n");
}

void print_usage() {
    printf("Usage: ping <hostname> [options]\n\n");
    printf("Options:\n");
    printf("  -c <count>    Number of packets to send (default: 4)\n");
    printf("  -i <interval> Interval between packets (in seconds) (default: 1)\n");
    printf("  -t <timeout>  Timeout for each packet (in seconds) (default: 5)\n\n");
}

void ping(char *hostname, int count, int interval, int timeout) {
    struct hostent *host;
    struct sockaddr_in addr;
    int sock, status, seq = 0;
    char buffer[1024];
    double rtt;
    struct timeval start, end;
    
    printf("Pinging %s with %d packets...\n\n", hostname, count);
    
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve %s\n", hostname);
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = *((unsigned long*)host->h_addr_list[0]);
    
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    
    memset(buffer, 0, sizeof(buffer));
    buffer[0] = 8; // ICMP_ECHO
    buffer[1] = 0; // Code
    buffer[2] = 0; // Checksum (set later)
    buffer[3] = 0;
    buffer[4] = seq & 0xff; // Sequence number
    buffer[5] = seq >> 8;
    
    while (count > 0) {
        gettimeofday(&start, NULL);
        
        if (sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
            perror("sendto");
            exit(1);
        }
        
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        
        struct timeval tv;
        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        
        status = select(sock + 1, &readfds, NULL, NULL, &tv);
        if (status == -1) {
            perror("select");
            exit(1);
        }
        else if (status == 0) {
            printf("Request timed out.\n");
        }
        else {
            status = recv(sock, buffer, sizeof(buffer), 0);
            if (status < 0) {
                perror("recv");
                exit(1);
            }
            
            gettimeofday(&end, NULL);
            
            rtt = (double)(end.tv_sec - start.tv_sec) * 1000.0 + (double)(end.tv_usec - start.tv_usec) / 1000.0;
            
            printf("Reply from %s: bytes=32 time=%.2fms TTL=%d\n", inet_ntoa(addr.sin_addr), rtt, buffer[8]);
        }
        
        count--;
        seq++;
        
        if (count > 0) {
            sleep(interval);
        }
    }
    
    printf("\nPing complete.\n");
    
    close(sock);
}

int main(int argc, char *argv[]) {
    print_header();
    
    if (argc < 2) {
        print_usage();
        exit(1);
    }
    
    int count = 4, interval = 1, timeout = 5;
    char *hostname = argv[1];
    
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            count = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-i") == 0) {
            interval = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-t") == 0) {
            timeout = atoi(argv[++i]);
        }
        else {
            printf("Error: Unknown option %s\n\n", argv[i]);
            print_usage();
            exit(1);
        }
    }
    
    ping(hostname, count, interval, timeout);
    
    return 0;
}