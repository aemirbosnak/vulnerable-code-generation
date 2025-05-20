//FormAI DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>

// Define message type for ICMP packets.
#define ICMP_TYPE 8

// Define message code for ICMP packets.
#define ICMP_CODE 0

// Define packet size.
#define PACKET_SIZE 64

// Define number of packets to send.
#define NUM_PACKETS 3

// Define timeout for receiving an ICMP response in microseconds.
#define TIMEOUT 2000000

// Calculate checksum for ICMP packets.
unsigned short calculate_checksum(unsigned short *seq_num, int len) {
    unsigned long sum = 0;
    
    while (len > 1) {
        sum += *seq_num++;
        len -= 2;
    }
    
    if (len == 1) {
        sum += *(unsigned char *)seq_num;
    }
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    return (unsigned short)(~sum);
}

// Print error message and exit program in case of errors.
void handle_error(char *error) {
    perror(error);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    struct hostent *host_info = gethostbyname(hostname);
    
    if (host_info == NULL) {
        handle_error("gethostbyname error");
    }
    
    struct in_addr **address_list = (struct in_addr **)host_info->h_addr_list;
    struct sockaddr_in socket_address;
    
    memset(&socket_address, 0, sizeof(socket_address));
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr = *address_list[0];
    
    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (socket_fd == -1) {
        handle_error("socket error");
    }
    
    printf("PING %s (%s) %d bytes of data\n", hostname, inet_ntoa(socket_address.sin_addr), PACKET_SIZE);
    
    char send_buffer[PACKET_SIZE];
    char recv_buffer[PACKET_SIZE];
    struct icmphdr *icmp_header;
    socklen_t sock_length = sizeof(socket_address);
    struct timeval start_time, end_time, elapsed_time;
    int seq_num = 0, num_sent = 0, num_received = 0;
    float total_time = 0;
    
    while (num_sent < NUM_PACKETS) {
        icmp_header = (struct icmphdr *)send_buffer;
        icmp_header->type = ICMP_TYPE;
        icmp_header->code = ICMP_CODE;
        icmp_header->un.echo.id = htons(getpid());
        icmp_header->un.echo.sequence = htons(seq_num++);
        memset(&icmp_header->checksum, 0, sizeof(icmp_header->checksum));
        icmp_header->checksum = calculate_checksum((unsigned short *)icmp_header, PACKET_SIZE);
        
        if (gettimeofday(&start_time, NULL) < 0) {
            handle_error("gettimeofday error");
        }
        
        if (sendto(socket_fd, &send_buffer, sizeof(send_buffer), 0, (struct sockaddr *)&socket_address, sizeof(socket_address)) < 0) {
            handle_error("sendto error");
        }
        
        num_sent++;
        
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(socket_fd, &readfds);
        
        struct timeval timeout = {0, TIMEOUT};
        int select_retval = select(socket_fd + 1, &readfds, NULL, NULL, &timeout);
        
        if (select_retval < 0) {
            handle_error("select error");
        } else if (select_retval == 0) {
            printf("Request timed out\n");
        } else {
            if (recvfrom(socket_fd, &recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *)&socket_address, &sock_length) < 0) {
                handle_error("recvfrom error");
            }
            
            if (gettimeofday(&end_time, NULL) < 0) {
                handle_error("gettimeofday error");
            }
            
            timersub(&end_time, &start_time, &elapsed_time);
            total_time += elapsed_time.tv_sec * 1000 + elapsed_time.tv_usec / 1000;
            
            num_received++;
            
            struct iphdr *ip_header = (struct iphdr *)recv_buffer;
            icmp_header = (struct icmphdr *)(recv_buffer + (ip_header->ihl * 4));
            
            if (icmp_header->type == ICMP_ECHOREPLY) {
                printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.2f ms\n", PACKET_SIZE, inet_ntoa(socket_address.sin_addr), ntohs(icmp_header->un.echo.sequence), ip_header->ttl, elapsed_time.tv_usec / 1000.0);
            } else {
                printf("Response code: %d\n", icmp_header->code);
            }
        }
        
        usleep(500000);
    }
    
    printf("\n--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %.0f%% packet loss, time=%.0fms\n", num_sent, num_received, ((float)(num_sent - num_received) / num_sent) * 100, total_time);
    
    close(socket_fd);
    return 0;
}