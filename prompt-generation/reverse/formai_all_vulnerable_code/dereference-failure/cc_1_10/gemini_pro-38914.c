//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

// Maximum number of hops to trace
#define MAX_HOPS 30

// Maximum size of a packet
#define MAX_PACKET_SIZE 1024

// Default port to use
#define DEFAULT_PORT 33434

// Structure to store the results of a trace
typedef struct {
    int hop_count;
    struct sockaddr_in *addrs;
} trace_result;

// Function to print the results of a trace
void print_trace_result(trace_result *result) {
    printf("Trace result:\n");
    for (int i = 0; i < result->hop_count; i++) {
        char *addr_str = inet_ntoa(result->addrs[i].sin_addr);
        printf("  Hop %d: %s\n", i + 1, addr_str);
    }
}

// Function to perform a network trace
void *trace_network(void *arg) {
    // Get the arguments
    char *hostname = (char *)arg;
    int port = DEFAULT_PORT;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create a sockaddr_in structure for the destination address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Create a buffer for the packet
    char packet[MAX_PACKET_SIZE];
    memset(packet, 0, sizeof(packet));

    // Send the packet
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
        perror("sendto");
        exit(1);
    }

    // Create a buffer for the response
    char response[MAX_PACKET_SIZE];
    memset(response, 0, sizeof(response));

    // Receive the response
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    int nbytes = recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr *)&src_addr, &src_addr_len);
    if (nbytes == -1) {
        perror("recvfrom");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Parse the response
    trace_result *result = malloc(sizeof(trace_result));
    result->hop_count = 0;
    result->addrs = malloc(sizeof(struct sockaddr_in) * MAX_HOPS);

    char *ptr = response;
    while (ptr < response + nbytes) {
        struct sockaddr_in *addr = (struct sockaddr_in *)ptr;
        result->addrs[result->hop_count] = *addr;
        result->hop_count++;
        ptr += sizeof(struct sockaddr_in);
    }

    // Return the result
    return result;
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    // Create a thread to perform the network trace
    pthread_t thread;
    if (pthread_create(&thread, NULL, trace_network, argv[1]) != 0) {
        perror("pthread_create");
        exit(1);
    }

    // Wait for the thread to finish
    void *result;
    if (pthread_join(thread, &result) != 0) {
        perror("pthread_join");
        exit(1);
    }

    // Print the results of the trace
    print_trace_result((trace_result *)result);

    // Free the memory allocated for the result
    free(((trace_result *)result)->addrs);
    free(result);

    return 0;
}