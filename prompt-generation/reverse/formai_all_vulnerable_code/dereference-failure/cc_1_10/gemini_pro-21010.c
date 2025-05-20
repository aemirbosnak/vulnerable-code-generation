//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// Our QoS monitor will use ICMP packets to measure network quality

// Define the ICMP packet header
struct icmp_header {
	unsigned char type;
	unsigned char code;
	unsigned short checksum;
	unsigned short id;
	unsigned short sequence;
	// ... other fields omitted for brevity
};

// The ICMP packet we'll be sending
char icmp_packet[sizeof(struct icmp_header) + sizeof(struct timeval)];

// The IP header we'll be using
struct ip_header {
	unsigned char version:4;
	unsigned char internet_header_length:4;
	unsigned char type_of_service;
	unsigned short total_length;
	unsigned short identification;
	unsigned short flags:3;
	unsigned short fragment_offset:13;
	unsigned char time_to_live;
	unsigned char protocol;
	unsigned short checksum;
	unsigned int source_address;
	unsigned int destination_address;
	// ... other fields omitted for brevity
};

// The UDP header we'll be using
struct udp_header {
	unsigned short source_port;
	unsigned short destination_port;
	unsigned short length;
	unsigned short checksum;
};

// A simple function to calculate the checksum of an ICMP packet
unsigned short calculate_icmp_checksum(struct icmp_header *icmp_header) {
	unsigned short *icmp_data = (unsigned short *)icmp_header;
	unsigned int sum = 0;
	for (int i = 0; i < sizeof(struct icmp_header) / sizeof(unsigned short); i++) {
		sum += *icmp_data++;
	}
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	return ~sum;
}

// A simple function to send an ICMP packet
int send_icmp_packet(int sockfd, struct sockaddr_in *dest_addr, int packet_size) {
	// Fill in the ICMP packet
	struct icmp_header *icmp_header = (struct icmp_header *)icmp_packet;
	icmp_header->type = 8; // ICMP Echo Request
	icmp_header->code = 0;
	icmp_header->checksum = 0;
	icmp_header->id = getpid(); // Set the ID to our process ID
	icmp_header->sequence = 0;
	// ... other fields omitted for brevity
	
	// Calculate the ICMP checksum
	icmp_header->checksum = calculate_icmp_checksum(icmp_header);
	
	// Send the ICMP packet
	int bytes_sent = sendto(sockfd, icmp_packet, packet_size, 0, (struct sockaddr *)dest_addr, sizeof(struct sockaddr_in));
	if (bytes_sent < 0) {
		perror("sendto");
		return -1;
	}
	
	return bytes_sent;
}

// A simple function to receive an ICMP packet
int receive_icmp_packet(int sockfd, struct sockaddr_in *src_addr, int *packet_size) {
	// Receive the ICMP packet
	int bytes_received = recvfrom(sockfd, icmp_packet, sizeof(icmp_packet), 0, (struct sockaddr *)src_addr, (socklen_t *)packet_size);
	if (bytes_received < 0) {
		perror("recvfrom");
		return -1;
	}
	
	return bytes_received;
}

// The main function
int main(int argc, char **argv) {
	// Check the arguments
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <destination IP address> <packet size>\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	// Create a raw socket
	int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0) {
		perror("socket");
		return EXIT_FAILURE;
	}
	
	// Set the socket options
	int one = 1;
	if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
		perror("setsockopt");
		return EXIT_FAILURE;
	}
	
	// Get the destination IP address
	struct sockaddr_in dest_addr;
	memset(&dest_addr, 0, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
	
	// Get the packet size
	int packet_size = atoi(argv[2]);
	
	// Send an ICMP packet
	int bytes_sent = send_icmp_packet(sockfd, &dest_addr, packet_size);
	if (bytes_sent < 0) {
		return EXIT_FAILURE;
	}
	
	// Receive an ICMP packet
	struct sockaddr_in src_addr;
	memset(&src_addr, 0, sizeof(src_addr));
	int bytes_received;
	if ((bytes_received = receive_icmp_packet(sockfd, &src_addr, &packet_size)) < 0) {
		return EXIT_FAILURE;
	}
	
	// Calculate the round-trip time
	struct timeval *tv_recv = (struct timeval *)(icmp_packet + sizeof(struct icmp_header));
	struct timeval tv_send;
	gettimeofday(&tv_send, NULL);
	long rtt = (tv_recv->tv_sec - tv_send.tv_sec) * 1000000 + (tv_recv->tv_usec - tv_send.tv_usec);
	
	// Print the results
	printf("Sent %d bytes to %s\n", bytes_sent, inet_ntoa(dest_addr.sin_addr));
	printf("Received %d bytes from %s\n", bytes_received, inet_ntoa(src_addr.sin_addr));
	printf("Round-trip time: %ld microseconds\n", rtt);
	
	// Close the socket
	close(sockfd);
	
	return EXIT_SUCCESS;
}