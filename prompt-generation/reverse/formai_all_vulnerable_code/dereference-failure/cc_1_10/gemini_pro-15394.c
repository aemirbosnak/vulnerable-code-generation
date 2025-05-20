//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_PORT 5001
#define MAX_BUFFER_SIZE 1024

// Function to get the host name
char *get_host_name() {
    char *hostname = malloc(256);
    gethostname(hostname, 256);
    return hostname;
}

// Function to generate a random string
char *generate_random_string(int length) {
    char *random_string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        random_string[i] = (char) (rand() % 26 + 97);
    }
    random_string[length] = '\0';
    return random_string;
}

// Function to create a UDP socket
int create_udp_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }
    return sockfd;
}

// Function to send a UDP packet
void send_udp_packet(int sockfd, char *hostname, int port, char *data, int length) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(hostname);
    addr.sin_port = htons(port);
    if (sendto(sockfd, data, length, 0, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("Error sending packet");
        exit(1);
    }
}

// Function to receive a UDP packet
char *receive_udp_packet(int sockfd) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int recv_len = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *) &addr, &addr_len);
    if (recv_len == -1) {
        perror("Error receiving packet");
        exit(1);
    }
    return buffer;
}

// Function to measure the latency of a UDP connection
int measure_latency(char *hostname, int port) {
    int sockfd = create_udp_socket(0);
    char *random_string = generate_random_string(100);
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    send_udp_packet(sockfd, hostname, port, random_string, strlen(random_string));
    char *response = receive_udp_packet(sockfd);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    int latency = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000;
    close(sockfd);
    free(random_string);
    free(response);
    return latency;
}

// Function to measure the bandwidth of a UDP connection
int measure_bandwidth(char *hostname, int port) {
    int sockfd = create_udp_socket(0);
    char *random_string = generate_random_string(100000);
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    send_udp_packet(sockfd, hostname, port, random_string, strlen(random_string));
    char *response = receive_udp_packet(sockfd);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    int bandwidth = (strlen(random_string) * 8) / ((end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000);
    close(sockfd);
    free(random_string);
    free(response);
    return bandwidth;
}

// Function to print the results
void print_results(char *hostname, int port, int latency, int bandwidth) {
    printf("Host: %s\n", hostname);
    printf("Port: %d\n", port);
    printf("Latency: %d ms\n", latency);
    printf("Bandwidth: %d kbps\n", bandwidth);
}

int main() {
    char *hostname = get_host_name();
    int port = DEFAULT_PORT;
    int latency = measure_latency(hostname, port);
    int bandwidth = measure_bandwidth(hostname, port);
    print_results(hostname, port, latency, bandwidth);
    return 0;
}