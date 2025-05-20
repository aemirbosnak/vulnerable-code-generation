//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

// Define the maximum number of hops for the ping test
#define MAX_HOPS 30

// Define the maximum packet size for the ping test
#define MAX_PACKET_SIZE 1024

// Define the default timeout for the ping test in seconds
#define DEFAULT_TIMEOUT 1

// Define the default number of pings to send
#define DEFAULT_NUM_PINGS 10

// Define the message to send in the ping packet
#define PING_MESSAGE "PING"

// Define the format of the ping packet
#define PING_PACKET_FORMAT "%s %d %d %d %d"

// Define the colors for the ping test output
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"
#define COLOR_RESET "\x1b[0m"

// Define the structure of a ping packet
typedef struct ping_packet {
    char message[MAX_PACKET_SIZE];
    int sequence_number;
    int ttl;
    int timestamp;
    int size;
} ping_packet;

// Define the function to create a ping packet
ping_packet *create_ping_packet(int sequence_number, int ttl, int size) {
    ping_packet *packet = malloc(sizeof(ping_packet));
    if (packet == NULL) {
        perror("malloc");
        exit(1);
    }
    strcpy(packet->message, PING_MESSAGE);
    packet->sequence_number = sequence_number;
    packet->ttl = ttl;
    packet->timestamp = time(NULL);
    packet->size = size;
    return packet;
}

// Define the function to send a ping packet
int send_ping_packet(int sockfd, struct sockaddr_in *dest_addr, ping_packet *packet) {
    int bytes_sent = sendto(sockfd, packet, packet->size, 0, (struct sockaddr *)dest_addr, sizeof(struct sockaddr_in));
    if (bytes_sent < 0) {
        perror("sendto");
        return -1;
    }
    return bytes_sent;
}

// Define the function to receive a ping packet
int receive_ping_packet(int sockfd, struct sockaddr_in *src_addr, ping_packet *packet) {
    int bytes_received = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)src_addr, sizeof(struct sockaddr_in));
    if (bytes_received < 0) {
        perror("recvfrom");
        return -1;
    }
    return bytes_received;
}

// Define the function to parse a ping packet
int parse_ping_packet(ping_packet *packet) {
    int sequence_number, ttl, timestamp, size;
    if (sscanf(packet->message, PING_PACKET_FORMAT, &sequence_number, &ttl, &timestamp, &size) != 4) {
        return -1;
    }
    packet->sequence_number = sequence_number;
    packet->ttl = ttl;
    packet->timestamp = timestamp;
    packet->size = size;
    return 0;
}

// Define the function to print the results of a ping test
void print_ping_results(ping_packet *packet, struct sockaddr_in *src_addr, int rtt) {
    char src_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &src_addr->sin_addr, src_ip, sizeof(src_ip));
    printf("%s %d bytes from %s (%s): icmp_seq=%d ttl=%d time=%d ms\n", COLOR_GREEN, packet->size, src_ip, src_addr->sin_addr.s_addr, packet->sequence_number, packet->ttl, rtt);
}

// Define the main function
int main(int argc, char **argv) {
    // Check if the user has specified the destination IP address
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <destination IP address>\n", argv[0]);
        exit(1);
    }

    // Get the destination IP address
    char *dest_ip_addr = argv[1];

    // Create a socket for the ping test
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int timeout = DEFAULT_TIMEOUT;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Get the destination IP address in binary form
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(dest_ip_addr);

    // Create a ping packet
    ping_packet *packet = create_ping_packet(1, 64, strlen(PING_MESSAGE));

    // Send the ping packet
    int bytes_sent = send_ping_packet(sockfd, &dest_addr, packet);
    if (bytes_sent < 0) {
        perror("send_ping_packet");
        exit(1);
    }

    // Receive the ping packet
    struct sockaddr_in src_addr;
    memset(&src_addr, 0, sizeof(src_addr));
    int bytes_received = receive_ping_packet(sockfd, &src_addr, packet);
    if (bytes_received < 0) {
        perror("receive_ping_packet");
        exit(1);
    }

    // Parse the ping packet
    int rtt = time(NULL) - packet->timestamp;
    if (parse_ping_packet(packet) < 0) {
        perror("parse_ping_packet");
        exit(1);
    }

    // Print the results of the ping test
    print_ping_results(packet, &src_addr, rtt);

    // Close the socket
    close(sockfd);

    return 0;
}