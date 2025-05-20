//FormAI DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define DEFAULT_PACKET_SIZE 64
#define DEFAULT_SEND_COUNT 4
#define DEFAULT_RECV_TIMEOUT 2

// Structure of IP header
typedef struct {
    unsigned char iph_ihl:5, iph_ver:4;
    unsigned char iph_tos;
    unsigned short iph_len;
    unsigned short iph_id;
    unsigned short iph_offset;
    unsigned char iph_ttl;
    unsigned char iph_protocol;
    unsigned short iph_chksum;
    unsigned int iph_source_ip;
    unsigned int iph_dest_ip;
} ip_header;

// Structure of ICMP header
typedef struct {
    unsigned char icmp_type;
    unsigned char icmp_code;
    unsigned short icmp_chksum;
    unsigned short icmp_id;
    unsigned short icmp_seq;
    struct timeval icmp_send_time;
} icmp_header;

// Function to calculate checksum
unsigned short calculate_checksum(unsigned short *buffer, int length) {
    unsigned long checksum = 0;
    while(length > 1) {
        checksum += *buffer++;
        length -= sizeof(unsigned short);
    }
    if(length) {
        checksum += *(unsigned char*)buffer;
    }
    checksum = (checksum & 0xFFFF) + (checksum >> 16);
    checksum = ~checksum;
    return (unsigned short)checksum;
}

// Function to receive the ICMP response
int receive_response(int sockfd, struct sockaddr_in *addr, unsigned char *buffer, int buffer_size, int timeout) {
    struct timeval tv;
    fd_set readfds;
    int retval;
    
    // Set timeout value
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    
    // Clear file descriptor set
    FD_ZERO(&readfds);
    
    // Add sockfd to file descriptor set
    FD_SET(sockfd, &readfds);
    
    // Wait for the sockfd to be ready for reading
    retval = select(sockfd+1, &readfds, NULL, NULL, &tv);
    if(retval == -1) {
        perror("select()");
        return -1;
    }
    else if(retval == 0) {
        return 0;
    }
    
    // Receive the ICMP response
    socklen_t addr_len = sizeof(*addr);
    int bytes_received = recvfrom(sockfd, buffer, buffer_size, 0, (struct sockaddr*)addr, &addr_len);
    if(bytes_received < 0) {
        perror("recvfrom()");
        return -1;
    }
    
    return bytes_received;
}

// Function to send the ICMP request
int send_request(int sockfd, struct sockaddr_in *addr, unsigned short icmp_id, unsigned short icmp_seq) {
    unsigned char send_buffer[DEFAULT_PACKET_SIZE] = {0};
    icmp_header *icmp = (icmp_header*)send_buffer;
    
    // Assign ICMP type and code
    icmp->icmp_type = ICMP_ECHO_REQUEST;
    icmp->icmp_code = 0;
    
    // Assign ICMP identification and sequence numbers
    icmp->icmp_id = icmp_id;
    icmp->icmp_seq = icmp_seq;
    
    // Get current time and assign it to ICMP send time
    if(gettimeofday(&icmp->icmp_send_time, NULL) < 0) {
        perror("gettimeofday()");
        return -1;
    }
    
    // Calculate ICMP checksum
    icmp->icmp_chksum = 0;
    icmp->icmp_chksum = calculate_checksum((unsigned short*)icmp, DEFAULT_PACKET_SIZE);
    
    // Send the ICMP request
    int bytes_sent = sendto(sockfd, send_buffer, DEFAULT_PACKET_SIZE, 0, (struct sockaddr*)addr, sizeof(*addr));
    if(bytes_sent < 0) {
        perror("sendto()");
        return -1;
    }
    return 0;
}

// Function to print statistics
void print_statistics(int count, double rtt_min, double rtt_max, double rtt_avg, double rtt_stddev) {
    printf("\n--- Ping statistics ---\n");
    printf("%d packets transmitted, %d received, %.f%% packet loss\n", count, count, ((count - count)*100.0/count));
    printf("round-trip min/avg/max/stddev = %.3f/%.3f/%.3f/%.3f ms\n", rtt_min,rtt_avg, rtt_max, rtt_stddev);
}

// Function to calculate round-trip time statistics
void calculate_statistics(double *rtt_list, int count, double *rtt_min, double *rtt_max, double *rtt_avg, double *rtt_stddev) {
    *rtt_min = rtt_list[0];
    *rtt_max = rtt_list[0];
    double sum = rtt_list[0];
    int i;
    for(i=1;i<count;i++) {
        if(rtt_list[i] < *rtt_min) {
            *rtt_min = rtt_list[i];
        }
        if(rtt_list[i] > *rtt_max) {
            *rtt_max = rtt_list[i];
        }
        sum += rtt_list[i];
    }
    *rtt_avg = sum / count;
    double variance = 0;
    for(i=0;i<count;i++) {
        variance += (rtt_list[i] - *rtt_avg) * (rtt_list[i] - *rtt_avg);
    }
    variance /= count;
    *rtt_stddev = sqrt(variance);
}

// Main function
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s host\n", argv[0]);
        return 0;
    }
    
    // Get host IP address
    struct hostent *host = gethostbyname(argv[1]);
    if(!host) {
        perror("gethostbyname()");
        return -1;
    }
    
    // Create socket for ICMP request and response
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        perror("socket()");
        return -1;
    }
    
    // Set socket option to reuse address and port
    int optval = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt()");
        return -1;
    }
    
    // Set timeout value for recvfrom() operation
    struct timeval timeout = {DEFAULT_RECV_TIMEOUT,0};
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval)) < 0) {
        perror("setsockopt()");
        return -1;
    }
    
    // Set destination address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    memcpy(&dest_addr.sin_addr, host->h_addr_list[0], host->h_length);
    
    unsigned int delay = 0;
    int count = DEFAULT_SEND_COUNT;
    int seq = 0;
    int packets_sent = 0;
    int packets_received = 0;
    double rtt_list[count];
    
    // Send ICMP requests and receive ICMP responses
    while(packets_sent < count) {
        if(send_request(sockfd, &dest_addr, getpid(), seq++) < 0) {
            continue;
        }
        
        packets_sent++;
        unsigned char recv_buffer[DEFAULT_PACKET_SIZE];
        int bytes_received = receive_response(sockfd, &dest_addr, recv_buffer, DEFAULT_PACKET_SIZE, DEFAULT_RECV_TIMEOUT);
        if(bytes_received < 0) {
            delay += DEFAULT_RECV_TIMEOUT * 1000;
        }
        else if(bytes_received > 0) {
            icmp_header *icmp = (icmp_header*)recv_buffer;
            double rtt = ((double)(icmp->icmp_send_time.tv_sec)*1000.0 + (double)(icmp->icmp_send_time.tv_usec)/1000.0) - ((double)(icmp->icmp_send_time.tv_sec)*1000.0 + (double)(icmp->icmp_send_time.tv_usec)/1000.0);
            rtt_list[packets_received] = rtt;
            packets_received++;
            delay += rtt;
        }
        else {
            delay += DEFAULT_RECV_TIMEOUT * 1000;
        }
        usleep(1000000 - (delay % 1000000));
    }
    
    // Calculate round-trip time statistics
    if(packets_received > 0) {
        double rtt_min, rtt_max, rtt_avg, rtt_stddev;
        calculate_statistics(rtt_list, packets_received, &rtt_min, &rtt_max, &rtt_avg, &rtt_stddev);
        print_statistics(packets_sent, rtt_min, rtt_max, rtt_avg, rtt_stddev);
    }
    else {
        printf("\nNo response received\n");
    }
    
    // Close the socket
    close(sockfd);
    
    return 0;
}